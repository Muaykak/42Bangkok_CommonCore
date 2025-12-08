#include "../include/Brain.hpp"

Brain::Brain(){
	std::cout << "Brain Default Constructor" << std::endl;
}
Brain::Brain( const Brain& obj){
	std::cout << "Brain Copy Constructor" << std::endl;
	operator=(obj);
}
Brain& Brain::operator=(const Brain& obj){
	std::cout << "Brain Copy Assignment Operator" << std::endl;
	for (int i = 0; i < 100; i++){
		idea[i] = obj.idea[i];
	}
	return (*this);
}
Brain::~Brain(){
	std::cout << "Brain Destructor Called" << std::endl;
}

void Brain::setIdea(const std::string& newIdea, const int& index){
	if (index < 0 || index > 99){
		std::cout << "Error::Brain::setIdea() => index out of range!" << std::endl;
		return ;
	}
	idea[index] = newIdea;
}

std::string Brain::getIdea(const int& index) const {
	if (index < 0 || index > 99){
		std::cout << "Error::Brain::setIdea() => index out of range!" << std::endl;
		return ("Wrong Index");
	}
	return (idea[index]);
}
