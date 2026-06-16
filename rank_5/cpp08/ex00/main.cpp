#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main()
{
	std::vector<int> intArr;
	const unsigned int vecSize = 10;
	const unsigned int toFind = 10;

	for (unsigned int i = 0; i < vecSize; i++)
	{
		intArr.push_back(i);
	}

	try
	{
		std::vector<int>::iterator found = easyfind(intArr, toFind);
		std::cout << "found: " << *found << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (0);
	}
}
