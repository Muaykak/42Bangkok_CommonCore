#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <exception>
# include <algorithm>

class Span
{
	private:
		unsigned int	_maxSize;
		std::vector<int> numbers;
	public:
		Span();
		Span(const Span& obj);
		Span& operator=(const Span& obj);
		~Span();

		Span(unsigned int spanSize);
		void addNumber(int num);

		template <typename iterator>
		void addNumber(iterator begin, iterator end)
		{
			size_t iteratorsize = static_cast<size_t>(std::distance(begin, end));
			if (iteratorsize > static_cast<size_t>(_maxSize)
			|| (static_cast<size_t>(_maxSize) - numbers.size()) < iteratorsize)
				throw FullException();

			numbers.insert(numbers.end(), begin, end);
		}

		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;

		class FullException : public std::exception
		{
			virtual const char * what() const throw ();
		};

		class TooFewNumberException : public std::exception
		{
			virtual const char * what() const throw ();
		};


};

#endif
