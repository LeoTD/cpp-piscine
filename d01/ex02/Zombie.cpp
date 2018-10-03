#include <Zombie.hpp>
#include <iostream>

Zombie::Zombie(std::string name, std::string type) {
	_name = name;
	_type = type;
}

Zombie::Zombie() {
	_name = "......";
	_type = "Shambler";
}

Zombie::~Zombie() {
	std::cout << _name << " has collapsed!" << std::endl;
}

void		Zombie::announce() {
	std::cout << "<" << _name << " (" << _type << ")> Braiiiiiiinnnssss..." << std::endl;
}