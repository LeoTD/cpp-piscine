#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

# include <string>
# include <Zombie.hpp>

class ZombieHorde {
public:
	ZombieHorde();
	ZombieHorde(int);
	~ZombieHorde();

	void			setZombieType(std::string);
	Zombie *		newZombie(std::string);
	std::string		_getRandomName();

private:
	std::string		_zombieType;
	Zombie *		_z;
};

#endif