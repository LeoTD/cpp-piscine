#include <ZombieHorde.hpp>
#include <iostream>
#include <fstream>
#include <cstdlib>

ZombieHorde::ZombieHorde() {
	std::cout << "The apocalypse begins!" << std::endl;
}

ZombieHorde::ZombieHorde(int n) {
	std::string const	types[] = {"Shambler", "Runner", "Spitter", "Spawner", "Cannibal"};
	_z = new Zombie[n]();

	for (int i = 0; i < n; i++) {
		_z[i]._name = _getRandomName();
		_z[i]._type = types[rand() % 5];
		_z[i].announce();
	}
	std::cout << "The apocalypse begins!" << std::endl;
}

ZombieHorde::~ZombieHorde() {
	std::cout << "Humanity is saved!" << std::endl;
	delete[] _z;
}

void			ZombieHorde::setZombieType(std::string type) {
	_zombieType = type;
}

Zombie *		ZombieHorde::newZombie(std::string name) {
	Zombie *	z = new Zombie(name, _zombieType);
	return z;
}

std::string		ZombieHorde::_getRandomName() {
	std::ifstream		ifs("/dev/random");
	char	name_buf[11];
	ifs.read(name_buf, 10);
	for (int i = 1; i < 10; i++) {
		name_buf[i] = abs(name_buf[i] % 26) + 'a';
	}
	name_buf[0] = abs(name_buf[0] % 26) + 'A';
	name_buf[10] = '\0';
	ifs.close();
	return std::string(name_buf);
}