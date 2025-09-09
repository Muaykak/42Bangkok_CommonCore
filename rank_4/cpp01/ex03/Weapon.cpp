
#include "Weapon.hpp"

Weapon::Weapon(){

}

Weapon::Weapon( const std::string &weapon_name ){
	this->_type = weapon_name;
}

const std::string &Weapon::getType( void ) const{
	return (this->_type);
}

void	Weapon::setType( const std::string &new_type ){
	this->_type = new_type;
}