#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& obj)
{
	(void)obj;
}

Intern& Intern::operator=(const Intern& obj)
{
	(void)obj;
	return (*this);
}

Intern::~Intern()
{

}

AForm* Intern::makePresidentialPardonForm(const std::string& target) const
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeRobotomyRequestForm(const std::string& target) const
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::makeShrubberyCreationForm(const std::string& target) const
{
	return new ShrubberyCreationForm(target);
}



AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
	std::string formNameArray[3][3];

	formNameArray[0][0] = "PresidentialPardonForm";
	formNameArray[0][1] = "presidential pardon";
	formNameArray[0][2] = "presidential";
	formNameArray[1][0] = "RobotomyRequestForm";
	formNameArray[1][1] = "robotomy request";
	formNameArray[1][2] = "robotomy";
	formNameArray[2][0] = "ShrubberyCreationForm";
	formNameArray[2][1] = "shrubbery creation";
	formNameArray[2][2] = "shrubbery";

	AForm* (Intern::*funcArray[3])(const std::string& target) const;

	funcArray[0] = &Intern::makePresidentialPardonForm;
	funcArray[1] = &Intern::makeRobotomyRequestForm;
	funcArray[2] = &Intern::makeShrubberyCreationForm;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (formNameArray[i][j] == formName)
			{
				std::cout << "Interns creates " << formName << std::endl;
				return (this->*funcArray[i])(target);
			}
		}
	}

	std::cerr << "Interns cannot make form! the request form name doesn't exist!" << std::endl;
	return (NULL);
}
