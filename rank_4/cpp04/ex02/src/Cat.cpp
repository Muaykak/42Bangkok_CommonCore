#include "../include/Cat.hpp"

Cat::Cat(){
	std::cout << "Cat Default Constructor" << std::endl;
	type = "Cat";
	brain = new Brain();
	if (!brain){
		std::cout << "Cat::Cat() brain allocation failed" << std::endl;
	}
}
Cat::Cat(const Cat& obj) : Animal(obj){
	std::cout << "Cat Copy Constructor" << std::endl;
	brain = new Brain(*obj.brain);
	if (!brain){
		std::cout << "Cat::Cat(const Cat& obj) failed:: brain allocation failed" << std::endl;
		return ;
	}
	if (!obj.brain){
		std::cout << "Cat::Cat(const Cat& obj) failed:: obj.brain is not allocated" << std::endl;
		return ;
	}
	operator=(obj);
}
Cat& Cat::operator=(const Cat& obj){
	std::cout << "Cat Copy Assignment Operator" << std::endl;
	type = obj.type;
	*brain = *obj.brain;
	return (*this);
}
Cat::~Cat(){
	std::cout << "Cat Destructor" << std::endl;
	delete brain;
}

void Cat::makeSound() const {
	std::cout << type << ": Meow Meow!" << std::endl;
}

Brain* Cat::getBrain() {
	return (brain);
}
