#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	std::cout << "WrongAnimal Default Constructor"  << std::endl;
	type = "noType";
}
WrongAnimal::WrongAnimal(const WrongAnimal& obj){
	std::cout << "WrongAnimal Copy Constructor" << std::endl;
	operator=(obj);
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj){
	std::cout << "WrongAnimal Copy Assignment Operator" << std::endl;
	type = obj.type;
	return (*this);
}
WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal Destructor" << std::endl;
}

void	WrongAnimal::makeSound() const {
	std::cout << type << " makes generic animal sounds" << std::endl;
}

const std::string& WrongAnimal::getType() const {
	return (type);
}