#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int randomnum(unsigned int index, unsigned int vecsize)
{
	(void)index;
	(void)vecsize;
	return (std::rand());
}

int ascend(unsigned int index, unsigned int vecsize)
{
	(void)vecsize;
	return (index);
}

int descend(unsigned int index, unsigned int vecsize)
{
	return (index <= vecsize ? vecsize - index : 0);
}

void generateVector(std::vector<int>& outVec, unsigned int vecsize, int (*gen)(unsigned int index, unsigned int size))
{
	outVec.clear();
	outVec.reserve(vecsize);

	for (unsigned int i = 0; i < vecsize; i ++)
		outVec.push_back(gen(i, vecsize));
}

int main()
{
	std::srand(clock());
	const unsigned int maxsize = 50000;

	std::vector<int> randomVec;
	generateVector(randomVec, maxsize, ascend);

	Span sp(maxsize);

	sp.addNumber(randomVec.begin(), randomVec.end());

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	try
	{
		Span a(0);

		std::cout << a.shortestSpan() << std::endl;
		std::cout << a.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Span a(0);

		a.addNumber(4);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Span a(2);

		a.addNumber(4);

		std::vector<int> temp;
		temp.push_back(9);
		temp.push_back(7);

		a.addNumber(temp.begin(), temp.end());

		std::cout << a.shortestSpan() << std::endl;
		std::cout << a.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Span a(3);

		a.addNumber(4);

		std::vector<int> temp;
		temp.push_back(9);
		temp.push_back(7);

		a.addNumber(temp.begin(), temp.end());

		std::cout << a.shortestSpan() << std::endl;
		std::cout << a.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}
