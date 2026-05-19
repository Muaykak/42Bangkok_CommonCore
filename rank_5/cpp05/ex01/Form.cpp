#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form()
:
_name("default_formname"),
_isSigned(false),
_requiredGradeSign(150),
_requiredGradeExecute(150)
{
}

Form::Form(const Form& obj)
:
_name(obj._name),
_isSigned(obj._isSigned),
_requiredGradeSign(obj._requiredGradeSign),
_requiredGradeExecute(obj._requiredGradeExecute)
{
}

Form& Form::operator=(const Form& obj)
{
	if (this != &obj)
	{
		_isSigned = obj._isSigned;
	}
	return (*this);
}

Form::~Form()
{

}

Form::Form(const std::string& name)
:
_name(name.empty() ? "default_formname" : name),
_isSigned(false),
_requiredGradeSign(150),
_requiredGradeExecute(150)
{

}

Form::Form(int grade)
:
_name("default_formname"),
_isSigned(false),
_requiredGradeSign(grade),
_requiredGradeExecute(grade)
{
	if (_requiredGradeSign < 1)
		throw GradeTooHighException();
	else if (_requiredGradeSign > 150)
		throw GradeTooLowException();
}

Form::Form(const std::string& name, int grade)
:
_name(name.empty() ? "default_formname" : name),
_isSigned(false),
_requiredGradeSign(grade),
_requiredGradeExecute(grade)
{
	if (_requiredGradeSign < 1)
		throw GradeTooHighException();
	else if (_requiredGradeSign > 150)
		throw GradeTooLowException();
}

Form::Form(const std::string& name, int requireGradeSign, int requiredGradeExecute)
:
_name(name.empty() ? "default_formname" : name),
_isSigned(false),
_requiredGradeSign(requireGradeSign),
_requiredGradeExecute(requiredGradeExecute)
{
	if (_requiredGradeSign < 1 || _requiredGradeExecute < 1)
		throw GradeTooHighException();
	else if (_requiredGradeSign > 150 || _requiredGradeExecute > 150)
		throw GradeTooLowException();
}

const std::string& Form::getName() const
{
	return (_name);
}

bool Form::isSigned() const
{
	return (_isSigned);
}

int Form::getRequireGradeSign() const
{
	return (_requiredGradeSign);
}

int Form::getRequireGradeExecute() const
{
	return (_requiredGradeExecute);
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	int buGrade = bureaucrat.getGrade();

	if (buGrade > _requiredGradeSign)
		throw GradeTooLowException();

	_isSigned = true;
	return ;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form Error::assigning grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form Error::assigning grade too low");
}

std::ostream& operator<<(std::ostream& os, const Form& obj)
{
	os << obj.getName() << " Form, Sign Required Grade: " << obj.getRequireGradeSign() << ", Execute Require Grade: " << obj.getRequireGradeExecute() << ", status: " << (obj.isSigned() == true ? "Signed." : "Not Signed.");
	return (os);
}

