#include "Span.hpp"

Span::Span()
:
_maxSize(0)
{
}

Span::Span(const Span& obj)
{
	operator=(obj);
}

Span& Span::operator=(const Span& obj)
{
	if (this != &obj)
	{
		_maxSize = obj._maxSize;
		numbers = obj.numbers;
	}

	return (*this);
}

Span::~Span()
{

}

Span::Span(unsigned int spanSize)
:
_maxSize(spanSize)
{
}

void Span::addNumber(int num)
{
	if (numbers.size() + 1 > _maxSize)
		throw FullException();
	numbers.push_back(num);
}

unsigned int Span::shortestSpan() const
{
	if (numbers.size() < 2)
		throw TooFewNumberException();

	std::vector<int> temp = numbers;

	std::sort(temp.begin(), temp.end());

	unsigned int shortest = temp[1] - temp[0];
	unsigned int d;
	for (unsigned int i = 2; i < temp.size(); i++)
	{
		d = temp[i] - temp[i - 1];
		shortest = d < shortest ? d : shortest;
	}

	return (shortest);
}

unsigned int Span::longestSpan() const
{
	if (numbers.size() < 2)
		throw TooFewNumberException();

	std::vector<int> temp = numbers;

	std::sort(temp.begin(), temp.end());

	return (temp[temp.size() - 1] - temp[0]);
}

const char * Span::TooFewNumberException::what() const throw()
{
	return ("Span::TooFewNumber for the operation");
}

const char * Span::FullException::what() const throw()
{
	return ("Span::Full span size is not enough");
}
