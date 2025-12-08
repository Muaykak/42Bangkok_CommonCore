#include "../include/WrongDog.hpp"

WrongDog::WrongDog(){
	std::cout << "WrongDog Default Constructor" << std::endl;
	type = "WrongDog";
}
WrongDog::WrongDog(const WrongDog& obj) : WrongAnimal(obj){
	std::cout << "WrongDog Copy Constructor" << std::endl;
	operator=(obj);
}
WrongDog& WrongDog::operator=(const WrongDog& obj){
	std::cout << "WrongDog Copy Assignment Operator" << std::endl;
	type = obj.type;
	return (*this);
}
WrongDog::~WrongDog(){
	std::cout << "WrongDog Destructor" << std::endl;
}

void WrongDog::makeSound() const {
	std::cout << type << ": Rawr Rawr!" << std::endl;
}
