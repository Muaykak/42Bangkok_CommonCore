#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool _isSigned;
		const int _requiredGradeSign;
		const int _requiredGradeExecute;

	public:
		// Orthodox
		Form();
		Form(const Form& obj);
		Form& operator=(const Form& obj);
		~Form();

		Form(const std::string& name);
		Form(int grade);
		Form(const std::string& name, int grade);
		Form(const std::string& name, int requireGradeSign, int requireGradeExecute);

		const std::string& getName() const;
		bool isSigned() const;
		int getRequireGradeSign() const;
		int getRequireGradeExecute() const;

		void beSigned(const Bureaucrat& bureaucrat);


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
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif