#include <HumanA.hpp>
#include <iostream>

HumanA::HumanA(std::string name, Weapon& w): _weapon(w) {
	_name = name;
}

HumanA::~HumanA() {}

void			HumanA::attack() const {
	std::cout << _name << " attacks with his " << _weapon.getType() << std::endl;
}

void			HumanA::setWeapon(Weapon w) {
	_weapon = w;
}