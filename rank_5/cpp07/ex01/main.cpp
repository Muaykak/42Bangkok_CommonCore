#include "iter.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cctype>

void plus3(size_t& num)
{
	num += 3;
}

void add_hello(std::string& str)
{
	str += "hello";
}

template<typename T>
void print(const T& data)
{
	std::cout << "data: "<< data << "\n";
}

int main( void ) {
	const size_t array_length = 20;
	size_t array[array_length];
	for (size_t i = 0; i < array_length; i++)
	{
		array[i] = i * 2;
	}

	iter(array, array_length, plus3);
	std::cout << "=====================\n";
	iter(array, array_length, print<size_t>);
	std::cout << "=====================\n";

	std::srand(std::clock());

	std::string strArray[array_length];
	for (size_t i = 0; i < array_length; i++)
	{
		size_t  innerLoopSize = static_cast<size_t>(std::rand() % 20);
		for (size_t j = 0; j < innerLoopSize; j++)
		{
			unsigned char randomChar = static_cast<unsigned char>(std::rand() % 256);

			if (std::isprint(randomChar))
				strArray[i] += randomChar;
		}
	}

	std::cout << "=====================\n";
	iter(strArray, array_length, print<std::string>);
	std::cout << "=====================\n";
	iter(strArray, array_length, add_hello);
	std::cout << "=====================\n";
	iter(strArray, array_length, print<std::string>);
	std::cout << "=====================\n";
	return 0;
}