#include "Human.hpp"
#include <iostream>

void		Human::meleeAttack(std::string const & tar) {
	std::cout << "Melee Attack targetting " << tar << "!" << std::endl;
}

void		Human::rangedAttack(std::string const & tar) {
	std::cout << "Ranged Attack targetting " << tar << "!" << std::endl;
}

void		Human::intimidatingShout(std::string const & tar) {
	std::cout << "Intimidating Shout targetting " << tar << "!" << std::endl;
}

void		Human::action(std::string const & name, std::string const & tar) {
	std::string const		actionNames[] = {
		"meleeAttack",
		"rangedAttack",
		"intimidatingShout"
	};

	typedef void (Human::*fptr)(std::string const &);
	fptr actions[] = {
		&Human::meleeAttack,
		&Human::rangedAttack,
		&Human::intimidatingShout
	};

	for (unsigned int i = 0; i < (sizeof(actionNames) / sizeof(actionNames[0])); i++) {
		if (name == actionNames[i]) {
			(this->*(actions[i]))(tar);
		}
	}
}