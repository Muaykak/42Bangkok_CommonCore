#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
:
AForm("RobotomyRequestForm", 72, 45),
_target("default_target")
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj)
:
AForm("RobotomyRequestForm", 72, 45),
_target(obj._target)
{
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
}

void RobotomyRequestForm::executeApply() const
{
	std::cout << _target << " has beed pardoned by Zaphod Beeblebrox" << std::endl;
}