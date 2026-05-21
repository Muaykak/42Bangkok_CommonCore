#include "ScalarConverter.hpp"

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

# include <cstdlib>
/* string to each type conversion */

# include <cctype> //for isprint()

# include <iostream>
# include <iomanip>
# include <cmath>

void printFloatConvert(float num)
{
	/* because 0 need to be 0.0*/


	/* if floor equally then it's something .0 */
	if (std::floor(num) == num)
	{
		std::ios_base::fmtflags oldflags = std::cout.flags();
		std::streamsize defaultPrecis = std::cout.precision();
		std::cout << std::fixed;
		std::cout << std::setprecision(1) << num << 'f';
		std::cout << std::setprecision(defaultPrecis) << std::endl;
		std::cout.flags(oldflags);
		std::cout.precision(defaultPrecis);
	}
	else
	{
		std::cout << num << 'f';
	}
}

void printDoubleConvert(double num)
{
	/* because 0 need to be 0.0*/

	/* if floor equally then it's something .0 */
	if (std::floor(num) == num)
	{
		std::ios_base::fmtflags oldflags = std::cout.flags();
		std::streamsize defaultPrecis = std::cout.precision();
		std::cout << std::fixed;
		std::cout << std::setprecision(1) << num;
		std::cout << std::setprecision(defaultPrecis) << std::endl;
		std::cout.flags(oldflags);
		std::cout.precision(defaultPrecis);
	}
	else
	{
		std::cout << num;
	}
}

void oneCharConvert(char c)
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
		{
			trimmedString = stringLiteral.substr(frontPos, backPos - frontPos + 1);

			/* then convert tolower */
			for (size_t i = 0; i < trimmedString.size(); i++)
				trimmedString[i] = static_cast<unsigned char>(std::tolower(trimmedString[i]));
		}
	}

	if (trimmedString.empty())
		return ;

	if (trimmedString.size() == 1)
	{
		oneCharConvert(trimmedString[0]);
		return ;
	}

	if (trimmedString == "nan")
	{
		std::cout << "char: impossible" << std::endl << "int: impossible" << std::endl << "float: nanf" << std::endl << "double: nan"<<	std::endl;
		return ;
	}


	std::cout << "trimmed string: \"" << trimmedString << "\"" << std::endl;


}
