#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj)
:
_database(obj._database),
_databasePath(obj._databasePath)
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj)
{
	if (this != &obj)
	{
		_database = obj._database;
		_databasePath = obj._databasePath;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const std::string& databasePath)
{
	if (databasePath.empty())
		throw BitcoinExchange::Exception(std::string("BitcoinExchange::databasePath: ") + databasePath + " must not empty");
	_databasePath = databasePath;

	std::ifstream file(databasePath.c_str());
	if (file.is_open() == false)
		throw BitcoinExchange::Exception(std::string("BitcoinExchange::databasePath: ") + databasePath + " cannot open to read");

	std::string tempLine;
	double value;
	std::string date;
	size_t lineCount = 1;
	while (std::getline(file, tempLine))
	{
		/* skip empty line */
		if (tempLine.empty())
		{
			lineCount++;
			continue;
		}
		try
		{
			splitdateandvalue(tempLine, ",", date, value, checkDatabaseValue);
			if (_database.find(date) != _database.end())
			{
				throw BitcoinExchange::Exception("BitcoinExchange::assigning value to same data is forbidden");
			}
			_database[date] = value;
		}
		catch (const BitcoinExchange::Exception& e)
		{
			if (lineCount == 1)
			{
				lineCount++;
				continue;
			}
			throw BitcoinExchange::Exception("line[" + toString(lineCount) + "]: " + e.what());
		}
		lineCount++;
	}
	file.close();
	if (_database.empty())
		throw BitcoinExchange::Exception(std::string("BitcoinExchange::database file must not empty"));
}

void BitcoinExchange::executeExchangeRate(const std::string& exchangeRateDataFilePath) const
{
	try
	{
		if (_database.empty())

		if (exchangeRateDataFilePath.empty())
			throw BitcoinExchange::Exception(exchangeRateDataFilePath + " must not empty");

		std::ifstream file(exchangeRateDataFilePath.c_str());
		if (file.is_open() == false)
			throw BitcoinExchange::Exception(exchangeRateDataFilePath + " cannot open the exchange data file");

		/* execute line by line, if any line is wrong, then show the error on that line */
		std::string tempLine;
		std::string date;
		double value;
		size_t lineCount = 1;
		std::map<std::string, double>::const_iterator found;
		while (std::getline(file, tempLine, '\n'))
		{
			if (tempLine.empty())
			{
				lineCount++;
				continue;
			}
			try
			{
				splitdateandvalue(tempLine, " | ", date, value, checkExchangeValue);
				found = _database.upper_bound(date);
				/* upperbound step down by 1 would reach to
				what we want*/
				if (found == _database.begin())
					std::cout << "Error: date too old\n";
				else
				{
					--found;
					printExchangeRate(date, value, found->second);
				}
			}
			catch (const BitcoinExchange::Exception &e)
			{
				if (lineCount == 1)
				{
					lineCount++;
					continue;
				}
				std::cout << "Error: " << e.what() << '\n';
			}
			lineCount++;
		}

		file.close();
	}
	catch (const BitcoinExchange::Exception &e)
	{
		throw BitcoinExchange::Exception(std::string("BitcoinExchange::executeExchangeRate::") + e.what());
	}
}

void BitcoinExchange::printDatabase() const
{
	std::map<std::string, double>::const_iterator it = _database.begin();

	std::cout << "----------- Database: " << _databasePath << "-------\n";
	while (it != _database.end())
	{
		std::cout << it->first << " = " << it->second << '\n';
		++it;
	}
	std::cout << "-------------------------------------------------------\n";
}

void BitcoinExchange::printExchangeRate(const std::string& date, double exchangeValue, double databaseValue)
{
	std::cout << date << " => ";
	printdouble(exchangeValue);
	std::cout << " = ";
	printdouble(exchangeValue * databaseValue);
	std::cout << '\n';
}

void BitcoinExchange::printdouble(double value)
{
	if (std::floor(value) == value)
	{
		std::ios_base::fmtflags oldflags = std::cout.flags();
		std::streamsize defaultPrecis = std::cout.precision();
		std::cout << std::fixed;
		std::cout << std::setprecision(0) << value;
		std::cout << std::setprecision(defaultPrecis);
		std::cout.flags(oldflags);
		std::cout.precision(defaultPrecis);
	}
	else
	{
		std::cout << value;
	}
}

void BitcoinExchange::splitdateandvalue(const std::string& inputLine, const std::string& middle, std::string& outDate, double& outValue, bool (*checkValFunc)(double))
{
	if (middle.empty())
		throw BitcoinExchange::Exception("BitcoinExchange::Internal logic Error");

	if (inputLine.size() <= 3)
		throw BitcoinExchange::Exception("BitcoinExchange::splitdateandvalue::invalid format:: allow only \"YYYY-MM-DD" + middle + "value\"");


	size_t sepPos = inputLine.find(middle);
	if (sepPos == std::string::npos
	|| sepPos == 0
	|| sepPos + middle.size() >= inputLine.size()
	)
		throw BitcoinExchange::Exception("BitcoinExchange::splitdateandvalue::invalid format:: allow only \"YYYY-MM-DD" + middle + "value\"");

	std::string dateString = inputLine.substr(0, sepPos);
	std::string valueString = inputLine.substr(sepPos + middle.size());

	if (dateString.empty() || valueString.empty())
		throw BitcoinExchange::Exception("BitcoinExchange::splitdateandvalue::empty date or value is not allowed");

	checkDateString(dateString);
	outValue = convertValueString(valueString, checkValFunc);
	outDate = dateString;
}

double BitcoinExchange::convertValueString(const std::string& valueString, bool (*func)(double))
{
	const std::string	charSet = "+0123456789.";
	const double positiveInf = std::numeric_limits<double>::infinity();
	const double negativeInf = -std::numeric_limits<double>::infinity();

	if (valueString.find_first_not_of(charSet) != std::string::npos)
	{
		throw BitcoinExchange::Exception("BitcoinExchange::convertValueString::invalid value");
	}

	char *p = NULL;
	/* set for the strtod*/
	errno = 0;
	double return_value = std::strtod(valueString.data(), &p);

	/* no conversion is performed */
	/* because assuming the string is already trimmed, after convert must
	be at the null character */
	if (p == NULL || p == valueString.data() || *p != '\0')
	{
		throw BitcoinExchange::Exception("BitcoinExchange::convertValueString::invalid value");
	}

	/* check overflow and underflow*/
	if (errno == ERANGE)
	{
		if (return_value == HUGE_VAL || return_value == -HUGE_VAL)
		{
			throw BitcoinExchange::Exception("BitcoinExchange::convertValueString::value causing overflow");
		}
		else
		{
			throw BitcoinExchange::Exception("BitcoinExchange::convertValueString::value causing underflow");
		}
	}

	/* do not allow nan or inf*/
	if (return_value != return_value || return_value == positiveInf || return_value == negativeInf)
	{
		throw BitcoinExchange::Exception("BitcoinExchange::convertValueString::not allowed inf or nan");
	}

	/* subject states that value must exist between 0 and 1000*/
	if (func(return_value) == false)
	{
		throw BitcoinExchange::Exception("BitcoinExchange::convertValueString::value must be in range");
	}

	return (return_value);
}

void BitcoinExchange::checkDateString(const std::string& dateString)
{
	if (dateString.size() != 10)
		throw BitcoinExchange::Exception("BitcointExchange::checkDateString::dateString must have format YYYY-MM-DD");

	const std::string digitCharSet = "0123456789";

	std::string yearString = dateString.substr(0, 4);
	std::string monthString = dateString.substr(5, 2);
	std::string dayString = dateString.substr(8, 2);

	/* all string must contain only digit */
	if (yearString.find_first_not_of(digitCharSet) != std::string::npos
	|| monthString.find_first_not_of(digitCharSet) != std::string::npos
	|| dayString.find_first_not_of(digitCharSet) != std::string::npos
	)
		throw BitcoinExchange::Exception("BitcointExchange::checkDateString::dateString must have format YYYY-MM-DD");
	
	int year = std::atoi(yearString.c_str());
	int month = std::atoi(monthString.c_str());
	int day = std::atoi(dayString.c_str());

	/*
	How to Know it is a Leap Year:
		Leap Years are any year that can be exactly divided by 4 (such as 2020, 2024, 2028, etc)
 			 - but if it can be exactly divided by 100, then it isn't (such as 2100, 2200, etc)
 	 	except if it can be exactly divided by 400, then it is (such as 2000, 2400)	
	*/
	bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	if ((month > 12 ? true : (month < 1)) || day < 1)
		throw BitcoinExchange::Exception("BitcointExchange::checkDateString::invalid month");
	else if (month == 2 && (isLeapYear == true ? (day > 29) : (day > 28)))
		throw BitcoinExchange::Exception("BitcointExchange::checkDateString::invalid date");
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		throw BitcoinExchange::Exception("BitcointExchange::checkDateString::invalid date");
	else if (day > 31)
		throw BitcoinExchange::Exception("BitcointExchange::checkDateString::invalid date");
}

bool BitcoinExchange::checkDatabaseValue(double value)
{
	(void)value;
	return (true);
}

bool BitcoinExchange::checkExchangeValue(double value)
{
	return (!(value < 0.0 || value > 1000.0));
}

/* EXCEPTION CLASS */
BitcoinExchange::Exception::Exception()
{}

BitcoinExchange::Exception::Exception(const Exception& obj)
{
	operator=(obj);
}

BitcoinExchange::Exception& BitcoinExchange::Exception::operator=(const BitcoinExchange::Exception& obj)
{
	if (this != &obj)
	{
		errMsg = obj.errMsg;
	}
	return (*this);
}

BitcoinExchange::Exception::~Exception() throw()
{
}

BitcoinExchange::Exception::Exception(const std::string& error_message)
:
errMsg(error_message)
{
}

const char * BitcoinExchange::Exception::what() const throw()
{
	return (errMsg.c_str());
}

