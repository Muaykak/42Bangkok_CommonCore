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

	std::cout << "input: \"" << argv[1] << "\"" << std::endl;
	
	{
		std::cout << "======= SCALAR TEST =======" << std::endl;

		ScalarConverter::convert(argv[1]);

		std::cout << "===========================" << std::endl;
	}
	
	
	std::cout << "converted: " << std::strtod(argv[1], NULL) << std::endl;
}
