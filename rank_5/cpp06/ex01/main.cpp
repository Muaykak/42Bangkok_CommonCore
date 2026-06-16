#include "Serializer.hpp"
#include <limits>

int main()
{
	Data b("Hello", 23);

	std::cout << "b addr: " << &b << '\n';

	uintptr_t serial1 = Serializer::serialize(&b);

	std::cout << "serial1: " << serial1 << '\n';
	std::cout <<  std::hex <<"serial1 hex: " << serial1 << '\n';

	Data *ptr = Serializer::deserialize(serial1);

	if (ptr)
		std::cout << "ptr addr: " << std::dec << ptr << " => " << *ptr << "\n";
	else
		std::cout << "ptr is NULL\n";

	std::cout << "UINTPTR_MAX: " << UINTPTR_MAX << '\n';
	std::cout << "UINTPTR_WIDTH: " << UINTPTR_WIDTH << '\n';
	std::cout << "uintptr_t MAX using std::numeric_limits: " << std::numeric_limits<uintptr_t>::max() << '\n';

	//try to access some wrong place 
	//{
	//	Data *c = Serializer::deserialize(103);
	//	std::cout << "c addr: " << c << '\n';
	//	if (c)
	//		std::cout << "c => " << *c << "\n";
	//	else
	//		std::cout << "ptr is NULL\n";
	//}
}
