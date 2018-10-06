#include "FragTrap.class.hpp"
#include "ScavTrap.class.hpp"
#include <iostream>
#include <cmath>

int			main(void) {
	FragTrap		frag("ClapTrap");
	ScavTrap		scav("Stan");

	for (int i = 0; i < 15; i++) {
		frag.vaulthunter_dot_exe("Stan");
		frag.takeDamage(arc4random() % 50);
		scav.takeDamage(arc4random() % 50);
		scav.challengeNewcomer("ClapTrap");
		frag.beRepaired(arc4random() % 5);
		scav.beRepaired(arc4random() % 5);
	}
	return 0;
}
