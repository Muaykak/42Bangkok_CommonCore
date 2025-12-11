#include "../include/Animal.hpp"

Animal::Animal() : type("noType"){
	std::cout << "Animal Default Constructor"  << std::endl;
}
Animal::Animal(const Animal& obj) : type(obj.type){
	std::cout << "Animal Copy Constructor" << std::endl;
}
Animal& Animal::operator=(const Animal& obj){
	std::cout << "Animal Copy Assignment Operator" << std::endl;
	if (this != &obj){
		type = obj.type;
	}
	return (*this);
}
Animal::~Animal(){
	std::cout << "Animal Destructor" << std::endl;
}

void	Animal::makeSound() const {
	std::cout << type << " makes generic animal sounds" << std::endl;
}

const std::string& Animal::getType() const {
	return (type);
}