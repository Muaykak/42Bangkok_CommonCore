#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool _isSigned;
		const int _requiredGradeSign;
		const int _requiredGradeExecute;

		virtual void executeApply() const = 0;

	public:
		// Orthodox
		AForm();
		AForm(const AForm& obj);
		AForm& operator=(const AForm& obj);
		virtual ~AForm();

		AForm(const std::string& name);
		AForm(int grade);
		AForm(const std::string& name, int grade);
		AForm(const std::string& name, int requireGradeSign, int requireGradeExecute);

		const std::string& getName() const;
		bool isSigned() const;
		int getRequireGradeSign() const;
		int getRequireGradeExecute() const;

		void beSigned(const Bureaucrat& bureaucrat);

		void execute(Bureaucrat const & executor) const;


		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class NotSignedException : public std::exception
		{
			public:
				const char* what() const throw();
		};


};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif
