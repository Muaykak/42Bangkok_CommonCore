#include "Bureaucrat.hpp"

void testAllFunctionNormally();
void testExceptions();

int main()
{
	bool isTestNormal = false;
	bool isTestException = true;

	if (isTestNormal || isTestException)
		std::cout << "############## CPP05 ex00 test ###############" << std::endl;

	if (isTestNormal)
		testAllFunctionNormally();
	if (isTestException)
		testExceptions();
}

void testExceptions()
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

void testAllFunctionNormally()
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

