#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
	public:
		// Orthodox 
		Bureaucrat();
		Bureaucrat(const Bureaucrat& obj);
		Bureaucrat& operator=(const Bureaucrat& obj);
		~Bureaucrat();


		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const std::string& name);
		Bureaucrat(int grade);

		const std::string& getName() const;
		int getGrade() const;

		void upGrade();
		void downGrade();

		bool signForm(AForm& form) const;
		bool executeForm(AForm const & form) const;

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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif
