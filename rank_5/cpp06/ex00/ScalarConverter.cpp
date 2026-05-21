#include "ScalarConverter.hpp"

# include <cstdlib>
/* string to each type conversion */

// # include <cctype> //for isprint()

# include <iostream>
# include <iomanip>
# include <cmath>
# include <cfloat>
# include <limits>
# include <cerrno>

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter& obj)
{
	(void)obj;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj)
{
	(void)obj;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{

}


static void printFloatConvert(float num)
{
	/* because 0 need to be 0.0*/


	/* if floor equally then it's something .0 */
	if (std::floor(num) == num)
	{
		std::ios_base::fmtflags oldflags = std::cout.flags();
		std::streamsize defaultPrecis = std::cout.precision();
		std::cout << std::fixed;
		std::cout << std::setprecision(1) << num << 'f';
		std::cout << std::setprecision(defaultPrecis);
		std::cout.flags(oldflags);
		std::cout.precision(defaultPrecis);
	}
	else
	{
		std::cout << num << 'f';
	}
}

static void printDoubleConvert(double num)
{
	/* because 0 need to be 0.0*/

	/* if floor equally then it's something .0 */
	if (std::floor(num) == num)
	{
		std::ios_base::fmtflags oldflags = std::cout.flags();
		std::streamsize defaultPrecis = std::cout.precision();
		std::cout << std::fixed;
		std::cout << std::setprecision(1) << num;
		std::cout << std::setprecision(defaultPrecis);
		std::cout.flags(oldflags);
		std::cout.precision(defaultPrecis);
	}
	else
	{
		std::cout << num;
	}
}

static void oneCharConvert(char c)
{
	int intnum = static_cast<int>(c);
	float floatnum = static_cast<float>(c);
	double doublenum = static_cast<double>(c);


	std::cout << "char: ";

	if (std::isprint(c) == 0)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << '\'' << c  << '\'' << std::endl;

	std::cout << "int: " << intnum << std::endl;
	std::cout << "float: ";
	printFloatConvert(floatnum);
	std::cout << std::endl << "double: ";
	printDoubleConvert(doublenum);
	std::cout << std::endl;
	return ;
}

/* so string conversion */
void ScalarConverter::convert(const std::string& stringLiteral)
{
	/* just the case for single char*/
	if (stringLiteral.size() == 1)
	{
		oneCharConvert(stringLiteral[0]);
		return ;
	}

	std::string trimmedString;
	/* let's trim the white space*/
	{

		size_t frontPos = stringLiteral.find_first_not_of(" \t\n\v\f\r");
		size_t backPos = stringLiteral.find_last_not_of(" \t\n\v\f\r");

		if (frontPos != std::string::npos && backPos != std::string::npos)
			trimmedString = stringLiteral.substr(frontPos, backPos - frontPos + 1);
		
	}

	if (trimmedString.empty())
		return ;

	if (trimmedString.size() == 1)
	{
		oneCharConvert(trimmedString[0]);
		return ;
	}

	char *p = NULL;

	errno = 0;
	double convertNum = std::strtod(trimmedString.c_str(), &p);

	if (errno == ERANGE)
	{
		if (convertNum == HUGE_VAL || convertNum == -HUGE_VAL)
		{
			std::cerr << "Error::Overflow Detected" << std::endl;
		}
		else if (convertNum > -DBL_MIN && convertNum < DBL_MIN)
		{
			std::cerr << "Error::Underflow Detected" << std::endl;
		}
		else
			std::cerr << "Error:: Detected" << std::endl;
		return ;
	}

	if (p && *p == 'f' && trimmedString.find_first_of('.') != std::string::npos)
		++p;

	if (!p || *p != '\0')
	{
		std::cout << "wrong value!" << std::endl;
		return ;
	}

	{

		/* handle nan first */
		if (convertNum != convertNum)
		{
			/* NaN is the only number that does not equal to itself */
			std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan" << std::endl;
			return ;
		}

		/* handle inf */
		{
			double positiveInf = std::numeric_limits<double>::infinity();
			double negativeInf = -std::numeric_limits<double>::infinity();

			if (convertNum == positiveInf)
			{
				std::cout << "char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf" << std::endl;
				return ;
			}
			else if (convertNum == negativeInf)
			{
				std::cout << "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf" << std::endl;
				return ;
			}
		}


		/* limits */
		double charMin = static_cast<double>(std::numeric_limits<char>::min());
		double charMax = static_cast<double>(std::numeric_limits<char>::max());
		double intMin = static_cast<double>(std::numeric_limits<int>::min());
		double intMax = static_cast<double>(std::numeric_limits<int>::max());
		double floatMin = static_cast<double>(-std::numeric_limits<float>::max());
		double floatMax = static_cast<double>(std::numeric_limits<float>::max());

		// std::cout << "limits" << std::endl;
		// std::cout << "charmin: " << charMin << std::endl;
		// std::cout << "charmax: " << charMax << std::endl;
		// std::cout << "intmin: " << intMin << std::endl;
		// std::cout << "intmax: " << intMax << std::endl;
		// std::cout << "floatmin: " << floatMin << std::endl;
		// std::cout << "floatmax: " << floatMax << std::endl;

		if (convertNum < charMin || convertNum > charMax)
			std::cout << "char: impossible" << std::endl;
		else
		{
			char c = static_cast<char>(convertNum);
			if (std::isprint(c))
				std::cout << "char: \'" << c << '\'' << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
		}

		if (convertNum < intMin || convertNum > intMax)
			std::cout << "int: impossible" << std::endl;
		else
		{
			int intnum = static_cast<int>(convertNum);
			std::cout << "int: " << intnum << std::endl;
		}

		if (convertNum < floatMin || convertNum > floatMax)
			std::cout << "float: impossible" << std::endl;
		else
		{
			float floatnum = static_cast<float>(convertNum);
			std::cout << "float: ";
			printFloatConvert(floatnum);
			std::cout << std::endl;
		}

		/* explicitly cast*/
		double doublenum = static_cast<double>(convertNum);
		std::cout << "double: ";
		printDoubleConvert(doublenum);
		std::cout << std::endl;

	}

}
