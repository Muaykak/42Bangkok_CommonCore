#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char** argv)
{
	if (argc < 2)
		return (1);

	try
	{
		std::vector<std::string> splitStringVec;

		for (int i = 1; i < argc; i++)
		{
			if (std::string(argv[i]).find_first_not_of("\t\v\n\f\r +0123456789") != std::string::npos)
				throw PmergeMe::Exception("arguments contains unallowed characters");

			PmergeMe::stringsplit(argv[i], " \t\v\n\f\r", splitStringVec);
		}

		std::vector<unsigned int> uintvector;
		std::deque<unsigned int> uintdeque;

		PmergeMe::extractUINTfromStringVec(splitStringVec, uintvector);
		uintdeque.insert(uintdeque.end(), uintvector.begin(), uintvector.end());

		(void)uintvector;
		(void)uintdeque;
		std::cout << "number: ";
		for (size_t i = 0; i < uintvector.size(); i++)
		{
			if (i != 0)
				std::cout << ", ";
			std::cout << uintvector[i];
		}
		std::cout << '\n';
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error::" << e.what() << '\n';
		return (1);
	}

}
