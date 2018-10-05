#include "FragTrap.class.hpp"
#include "ScavTrap.class.hpp"
#include <iostream>

int			main(void) {
	FragTrap		clap("ClapTrap");
	ScavTrap		scav("Stan");

	for (int i = 0; i < 15; i++) {
		clap.vaulthunter_dot_exe("Stan");
		scav.challengeNewcomer("ClapTrap");
	}
	return 0;
}
