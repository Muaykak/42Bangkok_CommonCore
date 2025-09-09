
#include "HumanB.hpp"

HumanB::HumanB(){
	this->_weapon = NULL;
	this->_name = "HumanB_defaultName";
}

HumanB::HumanB( const Weapon &weapon_type ){
	this->_weapon = new Weapon(weapon_type.getType());
	this->_name = "HumanB_defaultName";
}

HumanB::HumanB( const std::string &human_name, const Weapon &weapon_type ){
	this->_name = human_name;
	this->_weapon = new Weapon(weapon_type.getType());
}

HumanB::HumanB( const std::string &human_name)
{
	this->_name = human_name;
	this->_weapon = NULL;
}


HumanB::~HumanB(){
	delete this->_weapon;
}

void	HumanB::attack( void ){
	if (this->_weapon == NULL)
		std::cout << this->_name << " attack with their bare hands(no weapon)" << std::endl;
	else
		std::cout << this->_name << " attack with their " << this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon( const Weapon &new_weapon ){
	if (this->_weapon == NULL)
		this->_weapon = new Weapon;
	this->_weapon->setType(new_weapon.getType());
}