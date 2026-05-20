#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		void executeApply() const;

		std::string _target;
	public:
		// orthodox
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& obj);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& obj);
		~ShrubberyCreationForm();

		ShrubberyCreationForm(const std::string& target);


};

#endif
