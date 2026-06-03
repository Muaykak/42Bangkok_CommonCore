
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

#include <vector>
#include <utility>

void functionalityTest();
void throwExceptionTest();
void allocationTest();
void InternTest();

template<typename T>
void printTest(const T* obj);

void printFakeComment(const std::string& comment)
{
	std::cout << "/* " << comment << " */" << std::endl;
}

int main()
{
	void (*arr[])() = {
		&functionalityTest,
		&throwExceptionTest,
		&allocationTest,
		&InternTest,
		NULL
	};

	for (int i = 0; arr[i] != NULL; i++)
	{
		std::cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << std::endl;
		arr[i]();
	}
	std::cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << std::endl;
	return (0);
}

void InternTest()
{
	std::cout << "	Intern Testing" << std::endl << std::endl;

	printFakeComment("No need to test memory because intern holds only functions");
	std::cout << std::endl << std::endl;

	std::vector<AForm *> formArray;
	std::cout << "	try useing the intern to make form" << std::endl;

	Intern clark_kent;
	std::cout << "Intern clark_kent;" << std::endl;

	std::vector<std::pair<std::string, std::string> >  pairStringVec;
	{
		pairStringVec.push_back(std::make_pair("shrubbery", "Bob Ross"));
		pairStringVec.push_back(std::make_pair("shrubbery creation", "John Cena"));
		pairStringVec.push_back(std::make_pair("ShrubberyCreationForm", "Peter Parker"));
		pairStringVec.push_back(std::make_pair("presidential", "Obamium"));
		pairStringVec.push_back(std::make_pair("presidential pardon", "Clinton"));
		pairStringVec.push_back(std::make_pair("PresidentialPardonForm", "Iron Man"));
		pairStringVec.push_back(std::make_pair("robotomy", "Rick Sanchez"));
		pairStringVec.push_back(std::make_pair("robotomy request", "Morty"));
		pairStringVec.push_back(std::make_pair("RobotomyRequestForm", "The Rock"));

		pairStringVec.push_back(std::make_pair("Obviously a wwrong form", "Joker"));
		pairStringVec.push_back(std::make_pair("Fighting Form", "Hanma Baki"));
		pairStringVec.push_back(std::make_pair("", ""));
		pairStringVec.push_back(std::make_pair("asdf;jkahweflkjqweb", "13245134tqefgdadsfgvsa"));
		pairStringVec.push_back(std::make_pair("", "lkeqwfjlowekfhqloewwf"));
		pairStringVec.push_back(std::make_pair("asdflasdlfkajsdl", ""));
	}

	for (size_t i = 0; i < pairStringVec.size(); i++)
	{
		std::pair<std::string, std::string>& target = pairStringVec[i];
		std::cout << "formArray.push_back(clark_kent.makeForm(\"" << target.first << "\", " << target.second << "\"));" << std::endl << std::endl;
		formArray.push_back(clark_kent.makeForm(target.first, target.second));
	}

	printFakeComment("	Iterating check whole array -> sign and execute ");
	Bureaucrat pm("Trumpt", 1);

	for (size_t i = 0; i < formArray.size(); i++)
	{
		std::cout << "..............." << "[" << i << "]" << "................." << std::endl;
		if (formArray[i])
		{
			printTest(formArray[i]);
			pm.signForm(*formArray[i]);
			pm.executeForm(*formArray[i]);
		}
		else
			std::cout << "Intern Made INVALID form!!" << std::endl;
	}
	std::cout << "................................" << std::endl;

	std::cout << std::endl;
	printFakeComment("	deallocating array");
	for (size_t i = 0; i < formArray.size(); i++)
	{
		if (formArray[i])
			delete formArray[i];
	}
}

template<typename T>
void printTest(const T* obj)
{
	std::cout << "======== Print Test ======" << std::endl;
	if (obj)
		std::cout << *obj << std::endl;
	else
		std::cout << "This AForm is NULL!!!" << std::endl;

	std::cout << "==========================" << std::endl;
}


void functionalityTestAForm()
{
	std::cout << "	AForm Functionality test" << std::endl;

	std::cout << "you can try to wrongly use Aform here" << std::endl << std::endl;

	/* cannot instantiate */
	//AForm a;

	AForm* a = NULL; /* AForm pointer is possible */
	std::cout << "AForm *a = NULL;" << std::endl;
	a = new PresidentialPardonForm("Audy");
	std::cout << "a = new PresidentialPardonForm(\"Audy\");" << std::endl;
	printTest(a);
	// a = new AForm(); /* cannot allocate new abstract object*/

	std::cout << "\'delete\' a; will deallocate and call the proper destructor correctly, try to remove the \'virtual\' keyword to the destructor of AForm" << std::endl;
	delete a; /* successfully */
}

void functionalityPresidentialPardonForm()
{
	std::cout << "	PresidentialPardonForm Functionality Test" << std::endl << std::endl;

	PresidentialPardonForm a("John");
	std::cout << "PresidentialPardonForm a(\"John\");" << std::endl;
	printTest(&a);
	printFakeComment("Require some bureaucrat so sign the form");
	Bureaucrat bu1("Steven", 25);
	std::cout << "Bureaucrat bu1(\"Steven\", 25);" << std::endl;
	a.beSigned(bu1);
	printTest(&a);
	printFakeComment("Require Bureaucrat to execute the form");
	Bureaucrat bu2("Trump", 3);
	std::cout << "Bureaucrat bu2(\"Trump\", 3);" << std::endl;
	a.execute(bu2);
}

void functionalityShrubberyCreationForm()
{
	std::cout << "	ShrubberyCreationForm Functionality Test" << std::endl << std::endl;

	ShrubberyCreationForm a("Santa");
	std::cout << "ShrubberyCreationForm a(\"Santa\");" << std::endl;
	printTest(&a);
	printFakeComment("Require some bureaucrat so sign the form");
	Bureaucrat bu1("Kage", 145);
	std::cout << "Bureaucrat bu1(\"Kage\", 145);" << std::endl;
	a.beSigned(bu1);
	printTest(&a);
	printFakeComment("Require Bureaucrat to execute the form");
	Bureaucrat bu2("Obamium", 137);
	std::cout << "Bureaucrat bu2(\"Obamium\", 137)" << std::endl;
	a.execute(bu2);
}

void functionalityRobotomyRequestForm()
{
	std::cout << "	RobotomyRequestForm Functionality Test" << std::endl << std::endl;

	RobotomyRequestForm a("2B");
	std::cout << "RobotomyRequestForm a(\"2B\");" << std::endl;
	printTest(&a);
	printFakeComment("Require some bureaucrat so sign the form");
	Bureaucrat bu1("Luffy", 72);
	std::cout << "Bureaucrat bu1(\"Luffy\", 72);" << std::endl;
	a.beSigned(bu1);
	printTest(&a);
	printFakeComment("Require Bureaucrat to execute the form");
	Bureaucrat bu2("Zoro", 45);
	std::cout << "Bureaucrat bu2(\"Zoro\", 45)" << std::endl << std::endl;

	printFakeComment("execute multiple times to see that it is random");
	for (int i = 0; i < 10; i++)
		a.execute(bu2);
}

void functionalityBureaucrat()
{
	std::cout << "	Bureaucrat Functionality" << std::endl;

	printFakeComment(" test new executeForm() functionality");
	Bureaucrat bu1("Bravo", 2);
	std::cout << "Bureaucrat bu1(\"Bravo\", 2);" << std::endl;
	printTest(&bu1);
	PresidentialPardonForm a("Bill Grades");
	std::cout << "PresidentialPardonForm a (\"Bill Grades\");" << std::endl;
	std::cout << "	Signing" << std::endl;
	bu1.signForm(a);
	std::cout << "	execute" << std::endl;
	bu1.executeForm(a);
}

void functionalityTest()
{
	void (*funcArr[])() = {
		&functionalityTestAForm,
		&functionalityPresidentialPardonForm,
		&functionalityShrubberyCreationForm,
		&functionalityRobotomyRequestForm,
		&functionalityBureaucrat,
		NULL
	};

	std::cout << "         OVERALL FUNCTIONALITY TEST " << std::endl;

	for (int i = 0; funcArr[i] != NULL ; i++)
	{
		std::cout << "*******************************************************" << std::endl;
		funcArr[i]();
		std::cout << "*******************************************************\n\n\n";
	}
}

void AformSignFailedExceptionTest()
{
	std::cout << " -> Sign Failed" << std::endl;

	try {

		ShrubberyCreationForm a;
		std::cout << "ShrubberyCreationForm a;" << std::endl;
		printTest(&a);

		Bureaucrat Worker("Jack", 150);
		std::cout << "Bureaucrat Worker(\"Jack\", 150);" << std::endl;
		std::cout << "	signing..." << std::endl;
		a.beSigned(Worker);
		printTest(&a);
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception Catch!:: " << e.what() << std::endl;
	}
}

void AformExecuteNotSignedFailedExceptionTest()
{
	std::cout << " -> Execute Failed Not Sign Form" << std::endl;

	try {

		ShrubberyCreationForm a;
		std::cout << "ShrubberyCreationForm a;" << std::endl;
		printTest(&a);

		Bureaucrat Worker("Jack", 145);
		std::cout << "Bureaucrat Worker(\"Jack\", 145);" << std::endl;
		std::cout << "	executing..." << std::endl;
		a.execute(Worker);
		printTest(&a);
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception Catch!:: " << e.what() << std::endl;
	}
}

void AformExecuteFailedExceptionTest()
{
	std::cout << " -> Execute With Too Low Grade" << std::endl;

	try {

		ShrubberyCreationForm a;
		std::cout << "ShrubberyCreationForm a;" << std::endl;
		printTest(&a);

		Bureaucrat Worker("Jack", 145);
		std::cout << "Bureaucrat Worker(\"Jack\", 145);" << std::endl;
		std::cout << "	signing.." << std::endl;
		a.beSigned(Worker);
		std::cout << "	executing..." << std::endl;
		a.execute(Worker);
		printTest(&a);
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception Catch!:: " << e.what() << std::endl;
	}
}

void AFormExceptionTest()
{
	/* would only be able to test grade too high and not signed exception class */
	std::cout << "	AForm Exception Test" << std::endl;

	void (*funcArr[])() = {
		&AformSignFailedExceptionTest,
		&AformExecuteNotSignedFailedExceptionTest,
		&AformExecuteFailedExceptionTest,
		NULL
	};

	for (int i = 0; funcArr[i] != NULL; i++)
	{
		std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;
		funcArr[i]();
	}
	std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;
}

void bureaucratGradeTooLowExceptionTest()
{
	std::cout << " -> construt with too low value " << std::endl;

	try
	{
		printFakeComment("160 Grade value is considered low in Bureaucrat");
		Bureaucrat bu1("Steve", 160);
		std::cout << "Bureaucrat bu1(\"Steve\", 160);" << std::endl;

	}
	catch (const std::exception &e)
	{
		std::cout << "Exception Catch!:: " << e.what() << std::endl;
	}
}

void bureaucratGradeTooHighExceptionTest()
{
	std::cout << " -> construt with too high value " << std::endl;

	try
	{
		printFakeComment("0 Grade value is considered high in Bureaucrat");
		Bureaucrat bu1("Steve", 0);
		std::cout << "Bureaucrat bu1(\"Steve\", 160);" << std::endl;

	}
	catch (const std::exception &e)
	{
		std::cout << "Exception Catch!:: " << e.what() << std::endl;
	}
}

void bureaucratExceptionTest()
{
	std::cout << "	Bureaucrat Exception Test" << std::endl;

	void (*funcArr[])() = {
		&bureaucratGradeTooLowExceptionTest,
		&bureaucratGradeTooHighExceptionTest,
		NULL
	};

	for (int i = 0; funcArr[i] != NULL; i++)
	{
		std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;
		funcArr[i]();
	}
	std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;
}

void throwExceptionTest()
{
	std::cout << "	ExceptionTest" << std::endl;

	void (*funcArr[])() = {
		&AFormExceptionTest,
		&bureaucratExceptionTest,
		NULL
	};

	for (int i = 0; funcArr[i] != NULL; i++)
	{
		std::cout << "*******************************************************" << std::endl;
		funcArr[i]();
		std::cout << "*******************************************************\n\n\n";
	}
}

void allocationTest()
{
	std::cout << "	allocation test" << std::endl;
	
	std::vector<AForm *> formArray;

	formArray.push_back(new PresidentialPardonForm("Anutin"));
	formArray.push_back(new ShrubberyCreationForm("Bob Ross"));
	formArray.push_back(new RobotomyRequestForm("Wall-E"));

	std::cout <<
	"formArray.push_back(new PresidentialPardonForm(\"Anutin\"));\n"
	"formArray.push_back(new ShrubberyCreationForm(\"Bob Ross\"));\n"
	"formArray.push_back(new RobotomyRequestForm(\"Wall-E\"));"
	<< std::endl << std::endl;

	printFakeComment("Iterate the array ");
	for (size_t i = 0; i < formArray.size(); i++)
		std::cout << "array[" << i << "]: " << *formArray[i] << std::endl;

	std::cout << "	sign and execute the whole array " << std::endl;

	Bureaucrat pm("Trump", 1);

	for (size_t i = 0; i < formArray.size(); i++)
	{
		std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
		pm.signForm(*formArray[i]);
		printTest(formArray[i]);
		pm.executeForm(*formArray[i]);
	}
	std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;

	printFakeComment("Cleaning the AForm array");
	for (size_t i = 0; i < formArray.size(); i++)
		delete formArray[i];
}
