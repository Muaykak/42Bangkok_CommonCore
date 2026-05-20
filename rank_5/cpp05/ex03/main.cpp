
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

void functionalityTest();
void throwExceptionTest();
void allocationTest();

int main()
{
	Intern someRandomIntern;

	AForm* rff;

	rff = someRandomIntern.makeForm("robotomy request", "Bender");

	if (rff)
		delete rff;
	return (0);
}
