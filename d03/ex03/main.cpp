#include "FragTrap.class.hpp"
#include "ScavTrap.class.hpp"
#include "NinjaTrap.class.hpp"
#include <iostream>
#include <cmath>

int			main(void) {
	FragTrap		frag("ClapTrap");
	ScavTrap		scav("Stan");
	NinjaTrap		ninja("Genji");

	for (int i = 0; i < 15; i++) {
		ninja.ninjaShoebox(frag);
		ninja.ninjaShoebox(scav);
		ninja.ninjaShoebox(ninja);
		frag.vaulthunter_dot_exe("Stan");
		scav.challengeNewcomer("ClapTrap");
		frag.takeDamage(arc4random() % 50);
		scav.takeDamage(arc4random() % 50);
		ninja.takeDamage(arc4random() % 50);
		frag.beRepaired(arc4random() % 5);
		scav.beRepaired(arc4random() % 5);
		ninja.beRepaired(arc4random() % 5);
	}
	return 0;
}