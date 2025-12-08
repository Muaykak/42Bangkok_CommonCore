#include "../include/Animal.hpp"

Animal::Animal(){
	std::cout << "Animal Default Constructor"  << std::endl;
	type = "noType";
}
Animal::Animal(const Animal& obj){
	std::cout << "Animal Copy Constructor" << std::endl;
	operator=(obj);
}
Animal& Animal::operator=(const Animal& obj){
	std::cout << "Animal Copy Assignment Operator" << std::endl;
	type = obj.type;
	return (*this);
}
Animal::~Animal(){
	std::cout << "Animal Destructor" << std::endl;
}

const std::string& Animal::getType() const {
	return (type);
}