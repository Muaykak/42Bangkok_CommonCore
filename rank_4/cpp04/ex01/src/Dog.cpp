#include "../include/Dog.hpp"

Dog::Dog(){
	std::cout << "Dog Default Constructor" << std::endl;
	type = "Dog";
	brain = new Brain();
	if (!brain){
		std::cout << "Dog::Dog() brain allocation failed" << std::endl;
	}
}
Dog::Dog(const Dog& obj) : Animal(obj){
	std::cout << "Dog Copy Constructor" << std::endl;
	brain = new Brain(*obj.brain);
	if (!brain){
		std::cout << "Dog::Dog(const Dog& obj) failed:: brain allocation failed" << std::endl;
		return ;
	}
	if (!obj.brain){
		std::cout << "Dog::Dog(const Dog& obj) failed:: obj.brain is not allocated" << std::endl;
		return ;
	}
	operator=(obj);
}
Dog& Dog::operator=(const Dog& obj){
	std::cout << "Dog Copy Assignment Operator" << std::endl;
	type = obj.type;
	*brain = *obj.brain;
	return (*this);
}
Dog::~Dog(){
	std::cout << "Dog Destructor" << std::endl;
	delete brain;
}

void Dog::makeSound() const {
	std::cout << type << ": Wuf wuf!" << std::endl;
}

Brain* Dog::getBrain() {
	return (brain);
}
