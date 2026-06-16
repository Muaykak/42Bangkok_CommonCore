#include "PmergeMe.hpp"

void PmergeMe::vectorsortRecursive(std::vector<PmergeMe::VecNode>& nodeVec)
{
	if (nodeVec.size() <= 1)
		return ;

	std::vector<PmergeMe::VecNode> bigVec;
	std::vector<PmergeMe::VecNode> smallVec;
	bool isLeftover = false;

	if (nodeVec.size() % 2 != 0)
	{
		isLeftover = true;
	}

	for (size_t i = 0; i * 2 < nodeVec.size(); i++)
	{
		bigVec.push_back(PmergeMe::VecNode(nodeVec[i].value, nodeVec[i].original_index, i));
		smallVec.push_back(PmergeMe::VecNode(nodeVec[i + 1].value, nodeVec[i + 1].original_index, i + 1));
	}
	/* two vector act as breaking into pairs */

	unsigned temp;
	for (size_t i = 0; i < bigVec.size(); i++)
	{
		/*  This is to make left side of pair bigger than right side*/
		if (bigVec[i].value < smallVec[i].value)
		{
			temp = bigVec[i].value;
			bigVec[i].value = smallVec[i].value;
			smallVec[i].value = temp;
		}
	}

	/* recursion of merge until we reach the smallest*/
	PmergeMe::vectorsortRecursive(bigVec);

	size_t jacobIndex = 1;
	size_t end;
	size_t start;
	while (true)
	{
		start =  jacobsthalValue(jacobIndex);
		end = jacobsthalValue(jacobIndex - 1);
		while (start > end)
		{
			if (start > smallVec.size())
			{

			}
			else
			{
				
			}
		}
	}
	/* according to document i need to do it with specific
	sequence */

}

void PmergeMe::vectorsort(const std::vector<unsigned int>& inputVec, std::vector<unsigned int>& outVec)
{

	if (inputVec.size() == 0)
		return ;

	std::vector<PmergeMe::VecNode> nodeVec;

	/* put into dedicated structure */
	for (size_t i = 0; i < inputVec.size(); i++)
		nodeVec.push_back(PmergeMe::VecNode(inputVec[i], i , i));

	vectorsortRecursive(nodeVec);

	/* copy the sorted to outvec*/
	for (size_t i = 0; i < nodeVec.size(); i++)
		outVec.push_back(nodeVec[i].value);

	return ;

	std::vector<PmergeMe::VecNode> smallVec;
	bool isLeftover = false;
	unsigned int leftnum = 0;

	if (inputVec.size() % 2 != 0)
	{
		isLeftover = true;
		leftnum = inputVec[inputVec.size() - 1];
	}

	for (size_t i = 0; i * 2 < inputVec.size(); i++)
	{
		bigVec.push_back(PmergeMe::VecNode(inputVec[i], i));
		smallVec.push_back(PmergeMe::VecNode(inputVec[i + 1], i + 1));
	}


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

size_t PmergeMe::jacobsthalValue(size_t index)
{
	return (((1 << index) - (index % 2 == 0 ? 1 : - 1)) / 3);
}

/* ###################################################### */

PmergeMe::VecNode::VecNode()
:
value(0),
original_index(0),
array_index(0)
{}
PmergeMe::VecNode::VecNode(const PmergeMe::VecNode& obj)
:
value(obj.value),
original_index(obj.original_index),
array_index(obj.array_index)
{}
PmergeMe::VecNode& PmergeMe::VecNode::operator=(const PmergeMe::VecNode& obj)
{
	if (this != &obj)
	{
		value = obj.value;
		original_index = obj.original_index;
		array_index = obj.array_index;
	}
	return (*this);
}
PmergeMe::VecNode::~VecNode()
{}
PmergeMe::VecNode::VecNode(unsigned int newvalue, size_t neworiginal_index, size_t newarrayindex)
:
value(newvalue),
original_index(neworiginal_index),
array_index(newarrayindex)
{}

/* ############################################ */

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
