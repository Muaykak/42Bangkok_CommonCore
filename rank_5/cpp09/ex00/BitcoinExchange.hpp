#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <map>
# include <string>
# include <exception>
# include <fstream>
# include <cstdlib>
# include <limits>
# include <cmath> // for HUGE_VAL
# include <iostream>
# include <iomanip>
# include <sstream>

# ifndef BITCOIN_EXCHANGE_DATABASE_PATH
#  define BITCOIN_EXCHANGE_DATABASE_PATH "./data.csv"
# endif

class BitcoinExchange
{
	private:
		std::map<std::string, double> _database;
		std::string	_databasePath;

		static bool checkDatabaseValue(double value);
		static bool checkExchangeValue(double value);
		static void splitdateandvalue(const std::string& inputLine, const std::string& middle, std::string& outDate, double& outValue, bool (*checkValFunc)(double));
		static void checkDateString(const std::string& dateString);
		static double convertValueString(const std::string& valueString, bool (*func)(double));
		static void printExchangeRate(const std::string& date, double exchangeValue, double databaseValue);
		static void printdouble(double value);

		template <typename T>
		static std::string toString(const T &value)
		{
			std::stringstream ss;
			ss << value;
			return (ss.str());
		}

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& obj);
		BitcoinExchange& operator=(const BitcoinExchange& obj);
		~BitcoinExchange();

		BitcoinExchange(const std::string& databasePath);

		void executeExchangeRate(const std::string& exchangeRateDataFilePath) const;

		void printDatabase() const;

		/* i don't know whether custom exception class need Orthodox Canonical form */
		class Exception : public std::exception
		{
			private:
				std::string errMsg;

			public:
				Exception();
				Exception(const Exception& obj);
				Exception& operator=(const Exception& obj);
				virtual ~Exception() throw();

				Exception(const std::string& error_message);
				virtual const char * what() const throw();
		};
};

#endif
