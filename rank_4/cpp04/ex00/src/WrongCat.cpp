#include "../include/WrongCat.hpp"

WrongCat::WrongCat(){
	std::cout << "WrongCat Default Constructor" << std::endl;
	type = "WrongCat";
}
WrongCat::WrongCat(const WrongCat& obj) : WrongAnimal(obj){
	std::cout << "WrongCat Copy Constructor" << std::endl;
	operator=(obj);
}
WrongCat& WrongCat::operator=(const WrongCat& obj){
	std::cout << "WrongCat Copy Assignment Operator" << std::endl;
	type = obj.type;
	return (*this);
}
WrongCat::~WrongCat(){
	std::cout << "WrongCat Destructor" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << type << ": Quack Quack!" << std::endl;
}
