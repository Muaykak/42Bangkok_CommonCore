#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{

}

Base * generate(void)
{
	std::srand(clock());

	int randomNum = std::rand();
	switch (randomNum % 3)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		default:
			return (new C());
	}
}

void identify(Base* p)
{
	std::cout << "identify by ptr: ";
	if (dynamic_cast<A *>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B *>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C *>(p))
		std::cout << "C\n";
	else
		std::cout << "UNKNOWN\n";
}

void identify(Base& p)
{
	std::cout << "identify by reference: ";
	try
	{
		A& tmp = dynamic_cast<A&>(p);
		(void)tmp;
		std::cout << "A\n";
		return ;
	}
	catch (const std::exception& e)
	{
	}

	try
	{
		B& tmp = dynamic_cast<B&>(p);
		(void)tmp;
		std::cout << "B\n";
		return ;
	}
	catch (const std::exception& e)
	{
	}

	try
	{
		C& tmp = dynamic_cast<C&>(p);
		(void)tmp;
		std::cout << "C\n";
		return ;
	}
	catch (const std::exception& e)
	{
		std::cout << "UNKNOWN\n";
	}
	return ;
}
