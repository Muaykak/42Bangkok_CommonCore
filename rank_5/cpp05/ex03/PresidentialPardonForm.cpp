#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
:
AForm("PresidentialPardonForm", 25, 5),
_target("default_target")
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj)
:
AForm("PresidentialPardonForm", 25, 5),
_target(obj._target)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj)
{
	if (this != &obj)
	{
		AForm::operator=(obj);
		_target = obj._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
:
AForm("PresidentialPardonForm", 25, 5),
_target(target.empty() ? "default_target" : target)
{
}

void PresidentialPardonForm::executeApply() const
{
	std::cout << _target << " has beed pardoned by Zaphod Beeblebrox" << std::endl;
}
