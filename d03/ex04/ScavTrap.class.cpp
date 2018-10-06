#include "ScavTrap.class.hpp"

// --------------------------------------------------------- //
// ---- Constructors and Init							---- //
// --------------------------------------------------------- //

void		ScavTrap::init(void) {
	_set_hp(100);
	_set_MAX_HP(100);
	_set_energy(50);
	_set_MAX_ENERGY(50);
	_set_level(1);
	_set_melee_dmg(20);
	_set_ranged_dmg(15);
	_set_armor(3);
	_set_type("\033[91mSC4V-TP\033[m");

	_meleeMessage[0] = "Take THAT!";
	_meleeMessage[1] = "There is no way this ends badly!";
	_meleeMessage[2] = "WOW! I hit 'em!";

	_rangedMessage[0] = "250 shots per second, ONE KILL!";
	_rangedMessage[1] = "Let's get this party started!";
	_rangedMessage[2] = "Flesh fireworks!";

	_damageMessage[0] = "* angry dead robot noises *";
	_damageMessage[1] = "Ouch! Watch it! This is a vintage chasis!";
	_damageMessage[2] = "AaAaHHH!!!111!1brrrzzzttt...";

	_repairMessage[0] = "I'm UNSTOPPABLE! HAhahaha!" ;
	_repairMessage[1] = "* Windows Startup Noise *";
	_repairMessage[2] = "Mmm. That's the STUFF!";
}

ScavTrap::ScavTrap()
{
	init();
	_set_name("ScavTrap");
	return ;
}

ScavTrap::ScavTrap(std::string name)
{
	init();
	_set_name(name);
	return ;
}

ScavTrap::ScavTrap(ScavTrap const & that) {
	*this = that;
	return ;
}

ScavTrap::~ScavTrap() {

	return ;
}

// --------------------------------------------------------- //
// ---- Operators										---- //
// --------------------------------------------------------- //

ScavTrap &	ScavTrap::operator=(ScavTrap const & that) {
	if (this != &that) {
		_set_hp(that._get_hp());
		_set_MAX_HP(that._get_MAX_HP());
		_set_energy(that._get_energy());
		_set_MAX_ENERGY(that._get_MAX_ENERGY());
		_set_level(that._get_level());
		_set_name(that._get_name());
		_set_melee_dmg(that._get_melee_dmg());
		_set_ranged_dmg(that._get_ranged_dmg());
		_set_armor(that._get_armor());
		_set_type(that._get_type());
	}
	return *this;
}

std::ostream &	operator<<(std::ostream & os, ScavTrap const & that) {
	os << that._get_name();
	return os;
}

// --------------------------------------------------------- //
// ---- Functions										---- //
// --------------------------------------------------------- //

void			ScavTrap::challengeNewcomer(std::string const & tar) {
	if (_get_energy() < 25) {
		std::cout << "<" << _get_type() << "; " << _get_name() << "> ";
		std::cout << "So, tired..." << std::endl;
		return ;
	}
	_set_energy(_get_energy() - 25);

	unsigned int	r = arc4random() % 5;

	std::cout << "<" << _get_type() << "; " << _get_name() << "> ";
	std::cout << "Hey " << tar << "! ";
	switch(r) {
		case 0:
			std::cout << "You versus me! Me versus you! Either way!" << std::endl;
			break ;
		case 1:
			std::cout << "I will prove to you my robotic superiority!" << std::endl;
			break ;
		case 2:
			std::cout << "Man versus machine! Very tiny streamlined machine!" << std::endl;
			break ;
		case 3:
			std::cout << "Care to have a friendly duel?" << std::endl;
			break ;
		case 4:
			std::cout << "Dance battle! Or, you know... regular battle." << std::endl;
			break ;
	}
}
