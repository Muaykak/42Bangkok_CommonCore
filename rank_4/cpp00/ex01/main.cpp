#include "Contact.hpp"

int	main(void)
{
	Contact	Me("hello", "test", "test1", "0123", "idontknow");

	std::cout << Me.getFirstName() << Me.getLastName() << std::endl;
	return (0);
}