#include <HumanB.hpp>
#include <iostream>

HumanB::HumanB(std::string name) {
	_name = name;
}

HumanB::~HumanB() {}

void			HumanB::attack() const {
	std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
}

void			HumanB::setWeapon(Weapon w) {
	_weapon = &w;
}