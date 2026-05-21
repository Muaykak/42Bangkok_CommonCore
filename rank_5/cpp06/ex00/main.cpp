#include "ScalarConverter.hpp"

# include <cstdlib>
/* string to each type conversion */

# include <cctype> //for isprint()
# include <iostream>

int main(int argc, char** argv)
{
	(void)argc;
	(void)argv;

	if (argc != 2)
		return (0);

	ScalarConverter::convert(argv[1]);
}
