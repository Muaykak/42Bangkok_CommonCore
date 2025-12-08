#include "../include/Dog.hpp"
#include "../include/Cat.hpp"

#include <iomanip>


void	arrayAnimals(){
	const unsigned int arraySize = 2;
	Animal** array = new Animal*[arraySize]();

	std::cout << "Array Animals test" << std::endl;
	for (unsigned int i = 0; i < arraySize; i++){
	std::cout << std::left << std::setw(40) << std::setfill('-')
		<< "--- Allocate Animal Cat/Dog" << std::endl;
		if (i < arraySize / 2)
			array[i] = new Cat();
		else
			array[i] = new Dog();
	}
	std::cout << std::left << std::setw(40) << std::setfill('-')
		<< "---" << std::endl;

	for (unsigned int i = 0; i < arraySize; i++){
		array[i]->makeSound();
	}

	for (unsigned int i = 0; i < arraySize; i++){
	std::cout << std::left << std::setw(40) << std::setfill('-')
		<< "--- Deallocate Animal Cat/Dog" << std::endl;
		delete array[i];
	}
	std::cout << std::left << std::setw(40) << std::setfill('-')
		<< "---" << std::endl;
	delete[] array;
	std::cout << std::endl << std::endl;
}

int main()
{
	arrayAnimals();
	{
		std::cout << "Cat Class test" << std::endl;
		std::cout << std::left << std::setw(40) << std::setfill('-')
			<< "--- Cat *a = new Cat();" << std::endl;
		Cat *a = new Cat();
		std::cout << std::left << std::setw(40) << std::setfill('-')
			<< "--" << std::endl;
		a->makeSound();
		std::cout << std::left << std::setw(40) << std::setfill('-')
			<< "--- delete a*" << std::endl;
		delete a;
		std::cout << std::left << std::setw(40) << std::setfill('-')
			<< "--" << std::endl;
	}
	std::cout << std::endl << std::endl;
	{
		std::cout << "Dog Class test" << std::endl;
		std::cout << std::left << std::setw(40) << std::setfill('-')
			<< "--- Dog *a = new Dog();" << std::endl;
		Dog *a = new Dog();
		std::cout << std::left << std::setw(40) << std::setfill('-')
			<< "--" << std::endl;
		a->makeSound();
		std::cout << std::left << std::setw(40) << std::setfill('-')
			<< "--- delete a*" << std::endl;
		delete a;
		std::cout << std::left << std::setw(40) << std::setfill('-')
			<< "--" << std::endl;
	}
	std::cout << std::endl << std::endl;
	{
		std::cout << "Copy Brain test" << std::endl;
		std::cout << std::left << std::setw(40) << std::setfill('-')
			<< "--- Cat a;" << std::endl;
		Cat a;
		std::cout << std::left << std::setw(40) << std::setfill('-')
			<< "---" << std::endl;
		a.getBrain()->setIdea("Hungry", 46);
		std::cout << std::left << std::setw(40) << std::setfill('-')
			<< "--- Cat b(a)" << std::endl;
		Cat b(a);
		a.getBrain()->setIdea("Satiated", 46);
		std::cout << std::left << std::setw(40) << std::setfill('-')
			<< "--- Check Cat b 's Brain content" << std::endl;
		std::cout << "Cat b::brain >> " << b.getBrain()->getIdea(46) << std::endl;
		std::cout << std::left << std::setw(40) << std::setfill('-')
			<< "--- Check Cat a 's Brain content" << std::endl;
		std::cout << "Cat a::brain >> " << a.getBrain()->getIdea(46) << std::endl;
		std::cout << std::left << std::setw(40) << std::setfill('-')
			<< "---" << std::endl;
	}
}
