#include "../include/Dog.hpp"

Dog::Dog(){
	std::cout << "Dog Default Constructor" << std::endl;
	type = "Dog";
}
Dog::Dog(const Dog& obj) : Animal(obj){
	std::cout << "Dog Copy Constructor" << std::endl;
	operator=(obj);
}
Dog& Dog::operator=(const Dog& obj){
	std::cout << "Dog Copy Assignment Operator" << std::endl;
	type = obj.type;
	return (*this);
}
Dog::~Dog(){
	std::cout << "Dog Destructor" << std::endl;
}

void Dog::makeSound() const {
	std::cout << type << ": Wuf Wuf!" << std::endl;
}
