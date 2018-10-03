#include <ZombieEvent.hpp>
#include <iostream>
#include <fstream>
#include <cstdlib>

ZombieEvent::ZombieEvent() {
	std::cout << "The apocalypse begins!" << std::endl;
}

ZombieEvent::~ZombieEvent() {
	std::cout << "Humanity is saved!" << std::endl;
}

void		ZombieEvent::setZombieType(std::string type) {
	_zombieType = type;
}

Zombie *	ZombieEvent::newZombie(std::string name) {
	Zombie *	z = new Zombie(name, _zombieType);
	return z;
}

void		ZombieEvent::randomChump() {
	std::string const	types[] = {"Shambler", "Runner", "Spitter", "Spawner", "Cannibal"};

	std::ifstream		ifs("/dev/random");
	char	name_buf[11];
	ifs.read(name_buf, 10);

	for (int i = 1; i < 10; i++) {
		name_buf[i] = abs(name_buf[i] % 26) + 'a';
	}
	name_buf[0] = abs(name_buf[0] % 26) + 'A';
	name_buf[10] = '\0';

	Zombie				z(name_buf, types[rand() % 5]);
	z.announce();
	ifs.close();
}