#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>
# include <exception>
# include <vector>
# include <cstdlib>
# include <deque>
# include <limits>
# include <cerrno>
# include <sys/time.h>

size_t& comparison_count();

class PmergeMe
{
	public:

		static void extractUINTfromStringVec(const std::vector<std::string>& numstring, std::vector<unsigned int>& outContainer);
		static void stringsplit(const std::string& toSplit, const std::string& charSet, std::vector<std::string>& outStringVec);

		static void vectorsort(const std::vector<unsigned int>& inputVec, std::vector<unsigned int>& outputVec);
		static void dequesort(const std::vector<unsigned int>& inputList, std::vector<unsigned int>& outputVec);

		class Exception : public std::exception
		{
			private:
				std::string errorMessage;

			public:
				Exception();
				Exception(const Exception& obj);
				Exception& operator=(const Exception& obj);
				virtual ~Exception() throw();

				Exception(const std::string& errorMsg);
				virtual const char * what() const throw();
		};
	private:
		
		/* return the iterator that can immediately use with std::vector::insert() */
		static std::vector<std::vector<unsigned int> >::iterator binarySearchToInsert(std::vector<std::vector<unsigned int> >& toSearch, unsigned int number, size_t size);
		static std::deque<std::deque<unsigned int> >::iterator binarySearchToInsert(std::deque<std::deque<unsigned int> >& toSearch, unsigned int number, size_t size);

		static size_t jacobsthalValue(size_t index);

		static void vectorsortRecursive(std::vector<std::vector<unsigned int> >& sortVec);
		static void dequesortRecursive(std::deque<std::deque<unsigned int> >& sortVec);


	private:
		PmergeMe();
		PmergeMe(const PmergeMe& obj);
		PmergeMe& operator=(const PmergeMe& obj);
		~PmergeMe();
};

#endif
