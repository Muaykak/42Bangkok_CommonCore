#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat()
:
_name("default_name"),
_grade(150) /*assign the lowest possible grade on default*/
{
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj)
:
_name(obj._name),
_grade(obj._grade)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
	if (this != &obj)
	{
		/* const name cannot be re-assign */
		_grade = obj._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}


Bureaucrat::Bureaucrat(const std::string& name, int grade)
:
_name(name.empty() ? "default_name" : name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();

	_grade = grade;
}

Bureaucrat::Bureaucrat(const std::string& name)
:
_name(name.empty() ? "default_name" : name),
_grade(150)
{
}

Bureaucrat::Bureaucrat(int grade)
:
_name("default_name")
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	
	_grade = grade;
}


const std::string& Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::upGrade()
{
	/* up the grade mean decrementing */
	--_grade;
	if (_grade < 1)
		throw GradeTooHighException();
}

void Bureaucrat::downGrade()
{
	/* up the grade mean decrementing */
	++_grade;
	if (_grade > 150)
		throw GradeTooLowException();
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat Error::assigning grade too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat Error::assigning grade too low");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << '.';
	return (os);
}
