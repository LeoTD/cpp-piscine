#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

# include <string>
# include <Zombie.hpp>

class ZombieEvent {
public:
	ZombieEvent();
	~ZombieEvent();

	void			setZombieType(std::string);
	Zombie *		newZombie(std::string);
	void			randomChump();

private:
	std::string		_zombieType;
};

#endif