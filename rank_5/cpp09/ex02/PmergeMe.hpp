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

class PmergeMe
{
	private:
		class VecNode
		{
			public:
				unsigned int value;
				size_t original_index;
				size_t array_index;

				VecNode();
				VecNode(const VecNode& obj);
				VecNode& operator=(const VecNode& obj);
				~VecNode();

				VecNode(unsigned int value, size_t original_index, size_t array_index);

		};

	private:
		static void vectorsortRecursive(std::vector<PmergeMe::VecNode>& nodeVec);
		static size_t jacobsthalValue(size_t index);

		PmergeMe();
		PmergeMe(const PmergeMe& obj);
		PmergeMe& operator=(const PmergeMe& obj);
		~PmergeMe();
	public:

		static void extractUINTfromStringVec(const std::vector<std::string>& numstring, std::vector<unsigned int>& outContainer);
		static void stringsplit(const std::string& toSplit, const std::string& charSet, std::vector<std::string>& outStringVec);

		static void vectorsort(const std::vector<unsigned int>& inputVec, std::vector<unsigned int>& outputVec);
		static void dequesort(const std::deque<unsigned int>& inputList, std::deque<unsigned int>& outputList);

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
};

#endif
