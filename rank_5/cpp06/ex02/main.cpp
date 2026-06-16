
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
	Base *ptr;
	const size_t max = 10;
	for (size_t i = 0; i < max; i++)
	{
		ptr = generate();
		identify(ptr);
		delete ptr;
	}
	std::cout << "=====================" << std::endl;
	for (size_t i = 0; i < max; i++)
	{
		ptr = generate();
		if (ptr)
			identify(*ptr);
		delete ptr;
	}
}
