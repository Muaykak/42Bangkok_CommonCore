#include "Bureaucrat.hpp"
#include "Form.hpp"

void testBureaucratAllFunctionNormally();
void testBureaucratExceptions();

void testFormNormal();
void testFormException();

int main()
{
	bool isTestBureauCratNormal = false;
	bool isTestBureauCratException = false;
	bool isTestFormNormal = true;
	bool isTestFormException = true; 

	if (isTestBureauCratNormal || isTestBureauCratException || isTestFormNormal || isTestFormException)
		std::cout << "############## CPP05 ex00 test ###############" << std::endl;

	if (isTestBureauCratNormal)
		testBureaucratAllFunctionNormally();
	if (isTestBureauCratException)
		testBureaucratExceptions();
	if (isTestFormNormal)
		testFormNormal();
	if (isTestFormException)
		testFormException();
}

void testFormException()
{
	{
		std::string testName = "Wrong since Object's creation";
		std::cout << "======= " << testName << " =======" << std::endl;
		try {
			std::string varName = "a";
			std::string formname1 = "abc";
			int signGrade = 46;
			int executeGrade = 0;

			std::cout << varName << "(\"" << formname1 << "\", " << signGrade << ", " << executeGrade << ")" << std::endl;
			Form a(formname1, signGrade, executeGrade);

			std::cout << "---------- Print test -----------" << std::endl;
			std::cout << a << std::endl;
			std::cout << "-----------------------------" << std::endl;

		}
		catch (std::exception &e)
		{
			std::cout << "Exception catch!::" << e.what() << std::endl;
		}
		

		std::cout << "======================================" << std::endl << std::endl << std::endl;
	}

	{
		std::string testName = "Wrong since Object's creation";
		std::cout << "======= " << testName << " =======" << std::endl;
		try {
			std::string varName = "a";
			std::string formname1 = "abc";
			int signGrade = 46;
			int executeGrade = 151;

			std::cout << varName << "(\"" << formname1 << "\", " << signGrade << ", " << executeGrade << ")" << std::endl;
			Form a(formname1, signGrade, executeGrade);

			std::cout << "---------- Print test -----------" << std::endl;
			std::cout << a << std::endl;
			std::cout << "-----------------------------" << std::endl;

		}
		catch (std::exception &e)
		{
			std::cout << "Exception catch!::" << e.what() << std::endl;
		}
		

		std::cout << "======================================" << std::endl << std::endl << std::endl;
	}

	{
		std::string testName = "Form beSign() throw ";
		std::cout << "======= " << testName << " =======" << std::endl;
		try {
			std::string varName = "a";
			std::string formname1 = "abc";
			int signGrade = 46;
			int executeGrade = 23;

			std::cout << varName << "(\"" << formname1 << "\", " << signGrade << ", " << executeGrade << ")" << std::endl;
			Form a(formname1, signGrade, executeGrade);

			std::string buVarName1 = "bureaucrat1";
			std::string buName1 = "Kessy";
			int buGrade = 47;
			std::cout << buVarName1 << "(\"" << buName1 << "\", " << buGrade << ")" << std::endl;
			Bureaucrat bureaucrat1(buName1, buGrade);

			std::cout << "Before beSigned()" << std::endl;
			a.beSigned(bureaucrat1);
			std::cout << "After beSigned()" << std::endl;

			std::cout << "---------- Print test -----------" << std::endl;
			std::cout << a << std::endl;
			std::cout << "-----------------------------" << std::endl;

		}
		catch (std::exception &e)
		{
			std::cout << "Exception catch!::" << e.what() << std::endl;
		}
		
		std::cout << "======================================" << std::endl << std::endl << std::endl;
	}

	{
		std::string testName = "Bureaucrat signForm() ";
		std::cout << "======= " << testName << " =======" << std::endl;

			std::string varName = "a";
			std::string formname1 = "abc";
			int signGrade = 46;
			int executeGrade = 23;

			std::cout << varName << "(\"" << formname1 << "\", " << signGrade << ", " << executeGrade << ")" << std::endl;
			Form a(formname1, signGrade, executeGrade);

			std::string buVarName1 = "bureaucrat1";
			std::string buName1 = "Kessy";
			int buGrade = 47;
			std::cout << buVarName1 << "(\"" << buName1 << "\", " << buGrade << ")" << std::endl;
			Bureaucrat bureaucrat1(buName1, buGrade);

			std::cout << "Before signForm()" << std::endl;
			std::cout << a << std::endl;
			bureaucrat1.signForm(a);
			std::cout << "After signForm()" << std::endl;
			std::cout << a << std::endl;

		std::cout << "======================================" << std::endl << std::endl << std::endl;
	}
}

void testFormNormal()
{
	{
		std::string testName = "Normal default Contructor";
		std::cout << "======= " << testName << " =======" << std::endl;
		
		std::string varName = "a";
		std::cout << varName << ": default constructor" << std::endl;
		Form a;
		std::cout << "---------- Print test -----------" << std::endl;
		std::cout << a << std::endl;
		std::cout << "-----------------------------" << std::endl;

		std::cout << "======================================" << std::endl << std::endl << std::endl;
	}

	{
		std::string testName = "Parameter Contructor #1";
		std::cout << "======= " << testName << " =======" << std::endl;
		
		std::string varName = "a";

		std::string formname1 = "abc";

		std::cout << varName << "(\"" << formname1 << "\")" << std::endl;
		Form a(formname1);

		std::cout << "---------- Print test -----------" << std::endl;
		std::cout << a << std::endl;
		std::cout << "-----------------------------" << std::endl;

		std::cout << "======================================" << std::endl << std::endl << std::endl;
	}

	{
		std::string testName = "Parameter Contructor #2";
		std::cout << "======= " << testName << " =======" << std::endl;
		
		std::string varName = "a";

		int grade = 43;

		std::cout << varName << "(" << grade << ")" << std::endl;
		Form a(grade);

		std::cout << "---------- Print test -----------" << std::endl;
		std::cout << a << std::endl;
		std::cout << "-----------------------------" << std::endl;

		std::cout << "======================================" << std::endl << std::endl << std::endl;
	}

	{
		std::string testName = "Parameter Contructor #3";
		std::cout << "======= " << testName << " =======" << std::endl;
		
		std::string varName = "a";

		std::string formname1 = "abc";
		int grade = 67;

		std::cout << varName << "(\"" << formname1 << "\", " << grade << ")" << std::endl;
		Form a(formname1, grade);

		std::cout << "---------- Print test -----------" << std::endl;
		std::cout << a << std::endl;
		std::cout << "-----------------------------" << std::endl;

		std::cout << "======================================" << std::endl << std::endl << std::endl;
	}

	{
		std::string testName = "Parameter Contructor #4";
		std::cout << "======= " << testName << " =======" << std::endl;
		
		std::string varName = "a";
		std::string formname1 = "abc";
		int signGrade = 46;
		int executeGrade = 32;

		std::cout << varName << "(\"" << formname1 << "\", " << signGrade << ", " << executeGrade << ")" << std::endl;
		Form a(formname1, signGrade, executeGrade);

		std::cout << "---------- Print test -----------" << std::endl;
		std::cout << a << std::endl;
		std::cout << "-----------------------------" << std::endl;

		std::cout << "======================================" << std::endl << std::endl << std::endl;
	}

	{
		std::string testName = "Copy Constructor";
		std::cout << "======= " << testName << " =======" << std::endl;
		
		std::string varName1 = "a";
		std::string formname1 = "abc";
		int signGrade1 = 46;
		int executeGrade1 = 32;

		std::string varname2 = "b";


		std::cout << varName1 << "(\"" << formname1 << "\", " << signGrade1 << ", " << executeGrade1 << ")" << std::endl;
		Form a(formname1, signGrade1, executeGrade1);

		std::cout << varName1 << " = " << varname2 << "   " << testName << std::endl;
		Form b = a;

		std::cout << "---------- Print test b -----------" << std::endl;
		std::cout << b << std::endl;
		std::cout << "-----------------------------" << std::endl;

		std::cout << "======================================" << std::endl << std::endl << std::endl;
	}

	{
		std::string testName = "Copy Assignment Operator";
		std::cout << "======= " << testName << " =======" << std::endl;
		
		std::string varName1 = "a";
		std::string formname1 = "abc";
		int signGrade1 = 46;
		int executeGrade1 = 32;

		std::cout << varName1 << "(\"" << formname1 << "\", " << signGrade1 << ", " << executeGrade1 << ")" << std::endl;
		Form a(formname1, signGrade1, executeGrade1);

		std::string varName2 = "b";
		std::string formname2 = "Seka";
		int signGrade2 = 54;
		int executeGrade2 = 23;

		std::cout << varName2 << "(\"" << formname2 << "\", " << signGrade2 << ", " << executeGrade2 << ")" << std::endl;
		Form b(formname2, signGrade2, executeGrade2);

		std::cout << "Signing A to make it true" << std::endl;
		Bureaucrat admin("admin", 1);
		admin.signForm(a);

		std::cout << varName2 << " = " << varName1 << "   " << testName << std::endl;
		b = a;

		std::cout << "---------- Print test b -----------" << std::endl;
		std::cout << b << std::endl;
		std::cout << "-----------------------------" << std::endl;

		std::cout << "======================================" << std::endl << std::endl << std::endl;
	}

	{
		std::string testName = "beSigned() test ";
		std::cout << "======= " << testName << " =======" << std::endl;
		
		std::string varName1 = "a";
		std::string formname1 = "abc";
		int signGrade1 = 46;
		int executeGrade1 = 32;

		std::cout << varName1 << "(\"" << formname1 << "\", " << signGrade1 << ", " << executeGrade1 << ")" << std::endl;
		Form a(formname1, signGrade1, executeGrade1);

		std::string buVarName1 = "bureaucrat1";
		std::string buName1 = "Heehe";
		int buGrade = 4;
		std::cout << buVarName1 << "(\"" << buName1 << "\", " << buGrade << ") create Bureaucrat object" << std::endl;
		Bureaucrat bureaucrat1(buName1, buGrade);

		std::cout << "Before beSigned()" << std::endl;
		std::cout << a << std::endl;

		try
		{
			a.beSigned(bureaucrat1);
		}
		catch (std::exception &e)
		{
			std::cout << "Error Form::" << e.what() << std::endl;
		}

		std::cout << "After beSigned()" << std::endl;
		std::cout << a << std::endl;

		std::cout << "======================================" << std::endl << std::endl << std::endl;
	}
}

void testBureaucratExceptions()
{
	std::cout << "$$$$$$$$$$$$ Exceptions test $$$$$$$$$$$$$$" << std::endl;

	{
		std::string testName = "Wrong since object creation";
		std::cout << "======= " << testName << " =======" << std::endl;
		try
		{
			std::string varName = "a";
			std::string buName = "Johnny";
			int wrongGrade = 0;
			std::cout << varName << "(\"" << buName << "\", " << wrongGrade << "): wrong constructor" << std::endl;
			Bureaucrat a(buName, wrongGrade);
			std::cout << "---------- Print test -----------" << std::endl;
			std::cout << a << std::endl;
			std::cout << "-----------------------------" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception:: std::exception catch!:: " << e.what() << std::endl;
		}

		std::cout << "======================================" << std::endl << std::endl << std::endl;
	}

	{
		std::string testName = "Wrong since object creation";
		std::cout << "======= " << testName << " =======" << std::endl;
		try
		{
			std::string varName = "a";
			std::string buName = "Jakey";
			int wrongGrade = 151;
			std::cout << varName << "(\"" << buName << "\", " << wrongGrade << "): wrong constructor" << std::endl;
			Bureaucrat a(buName, wrongGrade);
			std::cout << "---------- Print test -----------" << std::endl;
			std::cout << a << std::endl;
			std::cout << "-----------------------------" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception:: std::exception catch!:: " << e.what() << std::endl;
		}

		std::cout << "======================================" << std::endl << std::endl << std::endl;
	}

	{
		std::string testName = "upGrade() failed";
		std::cout << "======= " << testName << " =======" << std::endl;
		try
		{
			std::string varName = "a";
			std::string buName = "Peter";
			int wrongGrade = 1;
			std::cout << varName << "(\"" << buName << "\", " << wrongGrade << ")" << std::endl;
			Bureaucrat a(buName, wrongGrade);

			std::cout << "using upGrade()" << std::endl;

			a.upGrade();

			std::cout << "---------- Print test -----------" << std::endl;
			std::cout << a << std::endl;
			std::cout << "-----------------------------" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception:: std::exception catch!:: " << e.what() << std::endl;
		}

		std::cout << "======================================" << std::endl << std::endl << std::endl;
	}

	{
		std::string testName = "downGrade() failed";
		std::cout << "======= " << testName << " =======" << std::endl;
		try
		{
			std::string varName = "a";
			std::string buName = "Keth";
			int wrongGrade = 150;
			std::cout << varName << "(\"" << buName << "\", " << wrongGrade << ")" << std::endl;
			Bureaucrat a(buName, wrongGrade);

			std::cout << "using upGrade()" << std::endl;

			a.downGrade();

			std::cout << "---------- Print test -----------" << std::endl;
			std::cout << a << std::endl;
			std::cout << "-----------------------------" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception:: std::exception catch!:: " << e.what() << std::endl;
		}

		std::cout << "======================================" << std::endl << std::endl << std::endl;
	}

	std::cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << std::endl;
}

void testBureaucratAllFunctionNormally()
{
	std::cout << "$$$$$$$$$$$$   Test Functionality $$$$$$$$$$$$$" << std::endl << std::endl;

	{
		std::string testName = "Normal default Contructor";
		std::cout << "======= " << testName << " =======" << std::endl;
		
		std::string varName = "a";
		std::cout << varName << ": default constructor" << std::endl;
		Bureaucrat a;
		std::cout << "---------- Print test -----------" << std::endl;
		std::cout << a << std::endl;
		std::cout << "-----------------------------" << std::endl;

		std::cout << "======================================" << std::endl << std::endl << std::endl;
	}


	{
		std::string testName = "Parameter Contructor #1";
		std::cout << "======= " << testName << " =======" << std::endl;
		
		std::string buName = "Didda";
		int grade = 140;
		std::string varName = "a";
		std::cout << varName << "(\"" << buName << "\", " << grade << ")" << ": " << testName << std::endl;
		Bureaucrat a(buName, grade);
		std::cout << "---------- Print test -----------" << std::endl;
		std::cout << a << std::endl;
		std::cout << "-----------------------------" << std::endl;

		std::cout << "======================================" << std::endl << std::endl << std::endl;
	}

	{
		std::string testName = "Parameter Contructor #2";
		std::cout << "======= " << testName << " =======" << std::endl;
		
		std::string buName = "Didda";
		std::string varName = "a";
		std::cout << varName << "(\"" << buName << "\")" << ": " << testName << std::endl;
		Bureaucrat a(buName);
		std::cout << "---------- Print test -----------" << std::endl;
		std::cout << a << std::endl;
		std::cout << "-----------------------------" << std::endl;

		std::cout << "======================================" << std::endl << std::endl << std::endl;
	}

	{
		std::string testName = "Parameter Contructor #3";
		std::cout << "======= " << testName << " =======" << std::endl;
		
		int grade = 140;
		std::string varName = "a";
		std::cout << varName << "(" << grade << ")" << ": " << testName << std::endl;
		Bureaucrat a(grade);
		std::cout << "---------- Print test -----------" << std::endl;
		std::cout << a << std::endl;
		std::cout << "-----------------------------" << std::endl;

		std::cout << "======================================" << std::endl << std::endl << std::endl;
	}

	{
		std::string testName = "Copy Constructor";
		std::cout << "======= " << testName << " =======" << std::endl;
		
		std::string buName = "Pomni";
		int grade = 97;
		std::string varName = "a";
		std::cout << varName << "(\"" << buName << "\", " << grade << ")" << std::endl;
		Bureaucrat a(buName, grade);

		std::string varName2 = "b";
		std::cout << testName << "  " << varName << " to " << varName2 << std::endl;
		Bureaucrat b = a;

		std::cout << "---------- Print test " << varName2 << " -----------" << std::endl;
		std::cout << b << std::endl;
		std::cout << "-----------------------------" << std::endl;

		std::cout << "======================================" << std::endl << std::endl << std::endl;
	}

	{
		std::string testName = "Copy Assignment Operator";
		std::cout << "======= " << testName << " =======" << std::endl;
		
		std::string buName = "Pomni";
		int grade = 97;
		std::string varName = "a";
		std::cout << varName << "(\"" << buName << "\", " << grade << ")" << std::endl;
		Bureaucrat a(buName, grade);

		std::string varName2 = "b";
		std::string buName2 = "Chester";
		int grade2 = 22;
		std::cout << varName2 << "(\"" << buName2 << "\", " << grade2 << ")" << std::endl;
		Bureaucrat b(buName2, grade2);
		std::cout << testName << "  " << varName << " to " << varName2 << std::endl;
		b = a;

		std::cout << "---------- Print test " << varName2 << " -----------" << std::endl;
		std::cout << b << std::endl;
		std::cout << "-----------------------------" << std::endl;

		std::cout << "======================================" << std::endl << std::endl << std::endl;
	}

	{
		std::string testName = "test Bureaucrat::upGrade()";
		std::cout << "======= " << testName << " =======" << std::endl;
		
		std::string buName = "Pomni";
		int grade = 99;
		std::string varName = "a";
		std::cout << varName << "(\"" << buName << "\", " << grade << ")" << std::endl;
		Bureaucrat a(buName, grade);

		std::cout << "Before upGrade(): " << a << std::endl;

		a.upGrade();


		std::cout << "After upGrade(): " << a << std::endl;
		std::cout << "======================================" << std::endl << std::endl << std::endl;
	}

	{
		std::string testName = "test Bureaucrat::downGrade()";
		std::cout << "======= " << testName << " =======" << std::endl;
		
		std::string buName = "Pomni";
		int grade = 99;
		std::string varName = "a";
		std::cout << varName << "(\"" << buName << "\", " << grade << ")" << std::endl;
		Bureaucrat a(buName, grade);

		std::cout << "Before downGrade(): " << a << std::endl;

		a.downGrade();

		std::cout << "After downGrade(): " << a << std::endl;
		std::cout << "======================================" << std::endl << std::endl << std::endl;
	}

	std::cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << std::endl << std::endl;
}

