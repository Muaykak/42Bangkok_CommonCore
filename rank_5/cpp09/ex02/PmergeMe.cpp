#include "PmergeMe.hpp"

#include <iostream>

void PmergeMe::vectorsort(const std::vector<unsigned int>& inputVec, std::vector<unsigned int>& outVec)
{
	comparison_count() = 0;

	if (inputVec.size() == 0)
		return ;

	std::vector<std::vector<unsigned> > nodeVec;

	/* put into dedicated structure */
	std::vector<unsigned int> temp(1);
	for (size_t i = 0; i < inputVec.size(); i++)
	{
		temp[0] = inputVec[i];
		nodeVec.push_back(temp);
	}

	vectorsortRecursive(nodeVec);

	/* copy the sorted to outvec*/
	for (size_t i = 0; i < nodeVec.size(); i++)
	{
		outVec.push_back(nodeVec[i][0]);
	}

	return ;
}

void PmergeMe::dequesort(const std::vector<unsigned int>& inputVec, std::vector<unsigned int>& outVec)
{
	comparison_count() = 0;

	if (inputVec.size() == 0)
		return ;

	std::deque<std::deque<unsigned> > nodeList;

	/* put into dedicated structure */
	std::deque<unsigned int> temp(1);
	for (size_t i = 0; i < inputVec.size(); i++)
	{
		temp[0] = inputVec[i];
		nodeList.push_back(temp);
	}

	dequesortRecursive(nodeList);

	/* copy the sorted to outvec*/
	std::deque<std::deque<unsigned int> >::const_iterator it = nodeList.begin();
	while (it != nodeList.end())
	{
		outVec.push_back(it->front());
		++it;
	}
	return ;
}

void PmergeMe::vectorsortRecursive(std::vector<std::vector<unsigned int> >& sortVec)
{
	if (sortVec.size() <= 1)
		return ;

	bool isLeftover = sortVec.size() % 2 == 1;
	std::vector<unsigned int> leftover;
	if (isLeftover)
		leftover = sortVec[sortVec.size() - 1];

	std::vector<std::vector<unsigned int> > temp(1);
	std::vector<std::vector<unsigned int> > newPairVec;
	for (size_t i = 0; i + 1 < sortVec.size(); i+=2)
	{
		if (sortVec[i][0] < sortVec[i + 1][0])
		{
			temp[0].insert(temp[0].end(), sortVec[i + 1].begin(), sortVec[i + 1].end());
			temp[0].insert(temp[0].end(), sortVec[i].begin(), sortVec[i].end());
			newPairVec.push_back(temp[0]);
			temp[0].clear();
		}
		else
		{
			temp[0].insert(temp[0].end(), sortVec[i].begin(), sortVec[i].end());
			temp[0].insert(temp[0].end(), sortVec[i + 1].begin(), sortVec[i + 1].end());
			newPairVec.push_back(temp[0]);
			temp[0].clear();
		}
		comparison_count()++;
	}
	sortVec.clear();

	vectorsortRecursive(newPairVec);

	std::vector<std::vector<unsigned int> > mainChain(1);
	std::vector<std::vector<unsigned int> > sideChain(newPairVec.size());

	/* add the b1 first*/
	mainChain[0].insert(mainChain[0].end(), newPairVec[0].begin() + (newPairVec[0].size() / 2), newPairVec[0].end());
	/*iterate through newPairVec*/
	for (size_t j = 0; j < newPairVec.size(); j++)
	{
		temp[0].insert(temp[0].end(), newPairVec[j].begin(), newPairVec[j].begin() + (newPairVec[j].size() / 2));
		mainChain.push_back(temp[0]);
		temp[0].clear();
		// mainChain[i].insert(mainChain[i].end(), newPairVec[j].begin(), newPairVec[j].begin() + (newPairVec[j].size() / 2));
		sideChain[j].insert(sideChain[j].end(), newPairVec[j].begin() + (newPairVec[j].size() / 2), newPairVec[j].end());
	}


	size_t jacobIndex = 3;
	size_t end;
	size_t start;
	size_t maxBinarySearch;
	std::vector<std::vector<unsigned int> >::iterator found;
	bool stop = false;
	while (stop == false)
	{
		end = jacobsthalValue(jacobIndex - 1);
		start = jacobsthalValue(jacobIndex);
		maxBinarySearch = end + start;
		while (start > end)
		{
			if (start > sideChain.size())
			{
				if (isLeftover)
				{
					found = binarySearchToInsert(mainChain, leftover[0], mainChain.size());
					temp[0].insert(temp[0].end(), leftover.begin(), leftover.end());
					mainChain.insert(found, temp.begin(), temp.end());
					temp[0].clear();
				}
				start = sideChain.size();
				stop = true;
			}
			--start;
			if (start + 1 > end)
			{
				found = binarySearchToInsert(mainChain, sideChain[start][0], maxBinarySearch);
				temp[0].insert(temp[0].end(), sideChain[start].begin(), sideChain[start].end());
				mainChain.insert(found, temp.begin(), temp.end());
				temp[0].clear();
			}
		}
		jacobIndex++;
	}

	sortVec = mainChain;
}

void PmergeMe::dequesortRecursive(std::deque<std::deque<unsigned int> >& sortVec)
{
	if (sortVec.size() <= 1)
		return ;

	bool isLeftover = sortVec.size() % 2 == 1;
	std::deque<unsigned int> leftover;
	if (isLeftover)
		leftover = sortVec[sortVec.size() - 1];

	std::deque<std::deque<unsigned int> > temp(1);
	std::deque<std::deque<unsigned int> > newPairVec;
	for (size_t i = 0; i + 1 < sortVec.size(); i+=2)
	{
		if (sortVec[i][0] < sortVec[i + 1][0])
		{
			temp[0].insert(temp[0].end(), sortVec[i + 1].begin(), sortVec[i + 1].end());
			temp[0].insert(temp[0].end(), sortVec[i].begin(), sortVec[i].end());
			newPairVec.push_back(temp[0]);
			temp[0].clear();
		}
		else
		{
			temp[0].insert(temp[0].end(), sortVec[i].begin(), sortVec[i].end());
			temp[0].insert(temp[0].end(), sortVec[i + 1].begin(), sortVec[i + 1].end());
			newPairVec.push_back(temp[0]);
			temp[0].clear();
		}
		comparison_count()++;
	}
	sortVec.clear();

	dequesortRecursive(newPairVec);

	std::deque<std::deque<unsigned int> > mainChain(1);
	std::deque<std::deque<unsigned int> > sideChain(newPairVec.size());

	/* add the b1 first*/
	mainChain[0].insert(mainChain[0].end(), newPairVec[0].begin() + (newPairVec[0].size() / 2), newPairVec[0].end());
	/*iterate through newPairVec*/
	for (size_t j = 0; j < newPairVec.size(); j++)
	{
		temp[0].insert(temp[0].end(), newPairVec[j].begin(), newPairVec[j].begin() + (newPairVec[j].size() / 2));
		mainChain.push_back(temp[0]);
		temp[0].clear();
		// mainChain[i].insert(mainChain[i].end(), newPairVec[j].begin(), newPairVec[j].begin() + (newPairVec[j].size() / 2));
		sideChain[j].insert(sideChain[j].end(), newPairVec[j].begin() + (newPairVec[j].size() / 2), newPairVec[j].end());
	}


	size_t jacobIndex = 3;
	size_t end;
	size_t start;
	size_t maxBinarySearch;
	std::deque<std::deque<unsigned int> >::iterator found;
	bool stop = false;
	while (stop == false)
	{
		end = jacobsthalValue(jacobIndex - 1);
		start = jacobsthalValue(jacobIndex);
		maxBinarySearch = end + start;
		while (start > end)
		{
			if (start > sideChain.size())
			{
				if (isLeftover)
				{
					found = binarySearchToInsert(mainChain, leftover[0], mainChain.size());
					temp[0].insert(temp[0].end(), leftover.begin(), leftover.end());
					mainChain.insert(found, temp.begin(), temp.end());
					temp[0].clear();
				}
				start = sideChain.size();
				stop = true;
			}
			--start;
			if (start + 1 > end)
			{
				found = binarySearchToInsert(mainChain, sideChain[start][0], maxBinarySearch);
				temp[0].insert(temp[0].end(), sideChain[start].begin(), sideChain[start].end());
				mainChain.insert(found, temp.begin(), temp.end());
				temp[0].clear();
			}
		}
		jacobIndex++;
	}

	sortVec = mainChain;
}



void PmergeMe::extractUINTfromStringVec(const std::vector<std::string>& numstring, std::vector<unsigned int>& outContainer)
{
	const std::string allowCharSet = "+0123456789";
	if (numstring.empty())
		return ;

	char *p;
	unsigned int converted_num = 0;
	for (size_t i = 0; i < numstring.size(); i++)
	{
		if (numstring[i].find_first_not_of(allowCharSet) != std::string::npos)
			throw PmergeMe::Exception("extractUINTfromStringVec::string consists of unallowed characters");
		p = NULL;
		errno = 0;
		converted_num = std::strtoul(numstring[i].data(), &p, 10);
		/* if no conversion is performed or not point to null charracter*/
		if (!p || p == numstring[i].data() || *p != '\0')
			throw PmergeMe::Exception("extractUINTfromString::invalid number conversion");

		/* overflow */
		if (errno == ERANGE)
			throw PmergeMe::Exception("extractUINTfromString::number causing overflow");

		outContainer.push_back(converted_num);
	}
}

void PmergeMe::stringsplit(const std::string& toSplit, const std::string& charSet, std::vector<std::string>& outStringVec)
{
	/* assume the container is already empty and it is not
	this function's responsible*/

	if (toSplit.empty())
		return ;
	if (charSet.empty())
	{
		outStringVec.push_back(toSplit);
	}

	size_t frontPos = 0;
	size_t backPos;
	frontPos = toSplit.find_first_not_of(charSet, frontPos);
	while (frontPos != std::string::npos)
	{
		backPos = toSplit.find_first_of(charSet, frontPos);
		if (backPos == std::string::npos)
			outStringVec.push_back(toSplit.substr(frontPos));
		else
			outStringVec.push_back(toSplit.substr(frontPos, backPos - frontPos));
		frontPos = backPos == std::string::npos ? backPos : toSplit.find_first_not_of(charSet, backPos);
	}
}

size_t& comparison_count()
{
	static size_t count = 0;
	return (count);
}

size_t PmergeMe::jacobsthalValue(size_t index)
{
	return (((1 << index) - (index % 2 == 0 ? 1 : - 1)) / 3);
}

/* return the iterator to immediately use with std::vector::insert()*/
std::vector<std::vector<unsigned int> >::iterator PmergeMe::binarySearchToInsert(std::vector<std::vector<unsigned int> >& toSearch, unsigned int number, size_t size)
{
	size_t left = 0;
	size_t right = size > toSearch.size() ? toSearch.size() : size;
	size_t mid;
	while (left < right)
	{
		mid = left + ((right - left) / 2);
		comparison_count()++;
		if (toSearch[mid][0] < number)
		{
			left = mid + 1;
		}
		else
			right = mid;
	}

	return (toSearch.begin() + left);
}

std::deque<std::deque<unsigned int> >::iterator PmergeMe::binarySearchToInsert(std::deque<std::deque<unsigned int> >& toSearch, unsigned int number, size_t size)
{
	size_t left = 0;
	size_t right = size > toSearch.size() ? toSearch.size() : size;
	size_t mid;
	while (left < right)
	{
		mid = left + ((right - left) / 2);
		comparison_count()++;
		if (toSearch[mid].front() < number)
			left = mid + 1;
		else
			right = mid;
	}

	return (toSearch.begin() + left);
}

/* ###################################################### */

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe& obj)
{
	operator=(obj);
}

PmergeMe& PmergeMe::operator=(const PmergeMe& obj)
{
	if (this != &obj)
	{
		(void)obj;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{}



/* ##################################### */
PmergeMe::Exception::Exception()
:
std::exception()
{

}

PmergeMe::Exception::Exception(const PmergeMe::Exception& obj)
:
std::exception()
{
	operator=(obj);
}

PmergeMe::Exception& PmergeMe::Exception::operator=(const PmergeMe::Exception& obj)
{
	if (this != &obj)
	{
		errorMessage = obj.errorMessage;
	}
	return (*this);
}

PmergeMe::Exception::~Exception() throw()
{
}

PmergeMe::Exception::Exception(const std::string& errorMsg)
:
std::exception(),
errorMessage(errorMsg)
{
}

const char * PmergeMe::Exception::what() const throw()
{
	return (errorMessage.c_str());
}
