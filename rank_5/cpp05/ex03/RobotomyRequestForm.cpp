#include "RobotomyRequestForm.hpp"

/* this one is for random function std::rand() and std::srand()*/
#include <cstdlib>

#include <ctime>
/* typically people in internet and also example of cppreference.com use
		the current time as a seed for generate random number*/

RobotomyRequestForm::RobotomyRequestForm()
:
AForm("RobotomyRequestForm", 72, 45),
_target("default_target")
{
	std::srand(std::time(NULL)); /* setting up the seed */
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj)
:
AForm("RobotomyRequestForm", 72, 45),
_target(obj._target)
{
	std::srand(std::time(NULL)); /* setting up the seed */
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
	if (this != &obj)
	{
		AForm::operator=(obj);
		_target = obj._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}



RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
:
AForm("RobotomyRequestForm", 72, 45),
_target(target.empty() ? "default_target" : target)
{
	std::srand(std::time(NULL)); /* setting up the seed */
}


void RobotomyRequestForm::executeApply() const
{
	std::cout << _target << ": <*Making some Drilling Noise*>" << std::endl;

	
	int randomNumRaw = std::rand(); /* getting random raw number */

	/* divide the max possible number by 2 and check with random number
	now it's 50/50*/
	if (randomNumRaw >= RAND_MAX / 2)
	{
		std::cout << _target << ", has been robotomized successfully" << std::endl;
	}
	else
	{
		std::cout << _target << ", has failed desperately" << std::endl;
	}

}
