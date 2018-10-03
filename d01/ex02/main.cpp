#include "ZombieEvent.hpp"
#include <Zombie.hpp>
#include <iostream>

int main(void) {
	ZombieEvent		apoc;

	apoc.setZombieType("Spooky");
	Zombie *		z = apoc.newZombie("Josh");
	z->announce();
	apoc.randomChump();
	delete z;
	return (0);
}