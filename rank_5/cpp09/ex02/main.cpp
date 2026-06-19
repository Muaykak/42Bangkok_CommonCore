#include "PmergeMe.hpp"
#include <iostream>
#include <sys/time.h>

void timevalcalculate(const timeval& starttime, const timeval& endtime, timeval& out)
{
	out.tv_sec = endtime.tv_sec - starttime.tv_sec;
	if (endtime.tv_usec < starttime.tv_usec)
	{
		out.tv_usec = (endtime.tv_usec + 1000000) - starttime.tv_usec;
		--out.tv_sec;
	}
	else
		out.tv_usec = endtime.tv_usec - starttime.tv_usec;
}

void printTimeval(const timeval& time)
{
	double millisecond = time.tv_sec * 1000.0;
	millisecond += time.tv_usec / 1000.0;

	std::cout << millisecond << " ms";
}

int main(int argc, char** argv)
{
	try
	{

		std::vector<std::string> stringVec;
		for (int i = 1; i < argc; i++)
		{
			PmergeMe::stringsplit(argv[i], "\t\v\n\f\r ", stringVec);
		}

		std::vector<unsigned int> out;
		PmergeMe::extractUINTfromStringVec(stringVec, out);

		std::cout << "Before:\t";
		for (size_t i = 0; i < out.size(); i++)
		{
			if (i != 0)
				std::cout << " ";
			std::cout << out[i];
		}
		std::cout << '\n';

		std::vector<unsigned int> sortVec;
		std::vector<unsigned int> sortDeque;

		timeval starttime, stoptime, vectime, dequetime;
		// PmergeMe::vectorsort(out, sort);
		gettimeofday(&starttime, NULL);
		PmergeMe::vectorsort(out, sortVec);
		gettimeofday(&stoptime, NULL);
		timevalcalculate(starttime, stoptime, vectime);
		gettimeofday(&starttime, NULL);
		PmergeMe::dequesort(out, sortDeque);
		gettimeofday(&stoptime, NULL);
		timevalcalculate(starttime, stoptime, dequetime);

		std::cout << "After:\t";
		for (size_t i = 0; i < sortVec.size(); i++)
		{
			if (i != 0)
				std::cout << " ";
			std::cout << sortVec[i];
		}
		std::cout << '\n';

		std::cout << "Time to process a range of " << sortVec.size() << " elements with std::vector : ";
		printTimeval(vectime);
		std::cout << '\n';
		// std::cout << "Comparision count: " << comparison_count() << '\n';
		std::cout << "Time to process a range of " << sortDeque.size() << " elements with std::deque : ";
		printTimeval(dequetime);
		std::cout << '\n';
		// std::cout << "Comparision count: " << comparison_count() << '\n';
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error\n";
		return (1);
	}

}
