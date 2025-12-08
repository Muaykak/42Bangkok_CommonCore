#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongCat.hpp"
#include "../include/WrongDog.hpp"

#include <iomanip>

int main()
{
	{
		std::cout << "Derived From Animal Class" <<std::endl;
		std::cout << std::left << std::setw(40) << std::setfill('-')
			<< "-----Animal *meta = new Animal()" << std::endl;
		const Animal* meta = new Animal();
		std::cout << std::left << std::setw(40) << std::setfill('-')
			<< "-----Animal *j = new Dog()" << std::endl;
		const Animal* j = new Dog();
		std::cout << std::left << std::setw(40) << std::setfill('-')
			<< "-----Animal *i = new Cat()" << std::endl;
		const Animal* i = new Cat();
		std::cout << std::left << std::setw(40) << std::setfill('-')
			<< "----" << std::endl;

		/* ------------------------------------------ */
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		/* ------------------------------------------ */

		std::cout << std::left << std::setw(40) << std::setfill('-')
			<< "----delete meta*" << std::endl;
		delete meta;
		std::cout << std::left << std::setw(40) << std::setfill('-')
			<< "----delete j*" << std::endl;
		delete	j;
		std::cout << std::left << std::setw(40) << std::setfill('-')
			<< "----delete i*" << std::endl;
		delete	i;
		std::cout << std::left << std::setw(40) << std::setfill('-')
			<< "----" << std::endl;
	}
	std::cout << std::endl << std::endl;

	{
		std::cout << "Derived From WrongAnimal Class" <<std::endl;
		std::cout << std::left << std::setw(40) << std::setfill('-')
			<< "-----WrongAnimal *meta = new WrongAnimal()" << std::endl;
		const WrongAnimal* meta = new WrongAnimal();
		std::cout << std::left << std::setw(40) << std::setfill('-')
			<< "-----WrongAnimal *j = new WrongDog()" << std::endl;
		const WrongAnimal* j = new WrongDog();
		std::cout << std::left << std::setw(40) << std::setfill('-')
			<< "-----WrongAnimal *i = new WrongCat()" << std::endl;
		const WrongAnimal* i = new WrongCat();
		std::cout << std::left << std::setw(40) << std::setfill('-')
			<< "----" << std::endl;

		/* ------------------------------------------ */
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		/* ------------------------------------------ */

		std::cout << std::left << std::setw(40) << std::setfill('-')
			<< "----delete meta*" << std::endl;
		delete meta;
		std::cout << std::left << std::setw(40) << std::setfill('-')
			<< "----delete j*" << std::endl;
		delete	j;
		std::cout << std::left << std::setw(40) << std::setfill('-')
			<< "----delete i*" << std::endl;
		delete	i;
		std::cout << std::left << std::setw(40) << std::setfill('-')
			<< "----" << std::endl;
	}
	std::cout << std::endl << std::endl;
}
