#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class Intern
{
	private:
		AForm* makePresidentialPardonForm(const std::string& target) const;
		AForm* makeRobotomyRequestForm(const std::string& target) const;
		AForm* makeShrubberyCreationForm(const std::string& target) const;

	public:
		Intern();
		Intern(const Intern& obj);
		Intern& operator=(const Intern& obj);
		~Intern();

		/* allocate the AForm object yeah */

		AForm* makeForm(const std::string& formName, const std::string& target) const;
};

#endif
