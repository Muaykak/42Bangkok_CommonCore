#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm()
:
_name("default_formname"),
_isSigned(false),
_requiredGradeSign(150),
_requiredGradeExecute(150)
{
}

AForm::AForm(const AForm& obj)
:
_name(obj._name),
_isSigned(obj._isSigned),
_requiredGradeSign(obj._requiredGradeSign),
_requiredGradeExecute(obj._requiredGradeExecute)
{
}

AForm& AForm::operator=(const AForm& obj)
{
	if (this != &obj)
	{
		_isSigned = obj._isSigned;
	}
	return (*this);
}

AForm::~AForm()
{

}

AForm::AForm(const std::string& name)
:
_name(name.empty() ? "default_formname" : name),
_isSigned(false),
_requiredGradeSign(150),
_requiredGradeExecute(150)
{

}

AForm::AForm(int grade)
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

AForm::AForm(const std::string& name, int grade)
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

AForm::AForm(const std::string& name, int requireGradeSign, int requiredGradeExecute)
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

const std::string& AForm::getName() const
{
	return (_name);
}

bool AForm::isSigned() const
{
	return (_isSigned);
}

int AForm::getRequireGradeSign() const
{
	return (_requiredGradeSign);
}

int AForm::getRequireGradeExecute() const
{
	return (_requiredGradeExecute);
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	int buGrade = bureaucrat.getGrade();

	if (buGrade > _requiredGradeSign)
		throw GradeTooLowException();

	_isSigned = true;
	return ;
}

void AForm::execute(Bureaucrat const & executor) const
{

	if (executor.getGrade() > _requiredGradeExecute)
		throw GradeTooLowException();

	executeApply();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("AForm Error::assigning grade too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("AForm Error::assigning grade too low");
}

std::ostream& operator<<(std::ostream& os, const AForm& obj)
{
	os << obj.getName() << " AForm, Sign Required Grade: " << obj.getRequireGradeSign() << ", Execute Require Grade: " << obj.getRequireGradeExecute() << ", status: " << (obj.isSigned() == true ? "Signed." : "Not Signed.");
	return (os);
}

