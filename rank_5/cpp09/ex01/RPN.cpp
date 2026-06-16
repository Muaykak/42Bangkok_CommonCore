#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN& obj)
{
	operator=(obj);
}

RPN& RPN::operator=(const RPN& obj)
{
	if (this != &obj)
	{
		(void)obj;
	}
	return (*this);
}

RPN::~RPN()
{
}

void RPN::performRPN(std::stack<double>& performStack, char input)
{
	const std::string operationCharset = "+-*/";
	const std::string digitCharset = "0123456789";
	const double positiveInf = std::numeric_limits<double>::infinity();
	const double negativeInf = -std::numeric_limits<double>::infinity();

	if (digitCharset.find_first_of(input) != std::string::npos)
	{
		performStack.push(static_cast<double>(input - 48));
	}
	else if (operationCharset.find_first_of(input) != std::string::npos)
	{
		if (performStack.size() < 2)
			throw std::exception();
		
		double right = performStack.top();
		performStack.pop();
		double left = performStack.top();
		performStack.pop();
		double result;

		switch (input)
		{
			case '+':
			{
				result = left + right;
				break;
			}
			case '-':
			{
				result = left - right;
				break;
			}
			case '*':
			{
				result = left * right;
				break;
			}
			default:
			{
				result = left / right;
				break;
			}
		}

		/* nan or inf not allowed*/
		if (result != result || result == positiveInf || result == negativeInf)
			throw std::exception();
		
		/* put back into stack */
		performStack.push(result);
	}
	else
		throw std::exception();
}

double	RPN::calculate(const std::string& rpn_string)
{
	const std::string whitespaceCharSet = "\t\v\n\f\r ";
	const std::string digitCharset = "0123456789";
	const std::string operationCharset = "+-*/";
	const std::string rpnCharSet = digitCharset + operationCharset;
	const std::string allCharSet = whitespaceCharSet + rpnCharSet;

	if (rpn_string.find_first_not_of(allCharSet) != std::string::npos)
		throw std::exception();

	std::stack<double> rpn_stack;

	size_t currPos = 0;
	currPos = rpn_string.find_first_of(rpnCharSet, currPos);
	while (currPos != std::string::npos)
	{
		if (currPos + 1 < rpn_string.size()
		&& whitespaceCharSet.find_first_of(rpn_string[currPos + 1]) == std::string::npos )
			throw std::exception();
		
		performRPN(rpn_stack, rpn_string[currPos]);
		currPos = rpn_string.find_first_of(rpnCharSet, currPos + 1);
	}

	if (rpn_stack.size() != 1)
		throw std::exception();

	return (rpn_stack.top());
}
