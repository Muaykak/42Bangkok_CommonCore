#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
:
AForm("ShrubberyCreationForm", 145, 137),
_target("default_target")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj)
:
AForm("ShrubberyCreationForm", 145, 137),
_target(obj._target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{
	if (this != &obj)
	{
		AForm::operator=(obj);
		_target = obj._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
:
AForm("ShrubberyCreationForm", 145, 137),
_target(target.empty() ? "default_target" : target)
{
}

void ShrubberyCreationForm::executeApply() const
{
	std::cout << _target << " has beed pardoned by Zaphod Beeblebrox" << std::endl;
}