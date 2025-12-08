#include "../include/Cat.hpp"

Cat::Cat(){
	std::cout << "Cat Default Constructor" << std::endl;
	type = "Cat";
}
Cat::Cat(const Cat& obj) : Animal(obj){
	std::cout << "Cat Copy Constructor" << std::endl;
	operator=(obj);
}
Cat& Cat::operator=(const Cat& obj){
	std::cout << "Cat Copy Assignment Operator" << std::endl;
	type = obj.type;
	return (*this);
}
Cat::~Cat(){
	std::cout << "Cat Destructor" << std::endl;
}

void Cat::makeSound() const {
	std::cout << type << ": Meow Meow!" << std::endl;
}
