#include "FragTrap.class.hpp"

// --------------------------------------------------------- //
// ---- Constructors and Init							---- //
// --------------------------------------------------------- //

void		FragTrap::init(void) {
	_set_hp(100);
	_set_MAX_HP(100);
	_set_energy(100);
	_set_MAX_ENERGY(100);
	_set_level(1);
	_set_melee_dmg(30);
	_set_ranged_dmg(20);
	_set_armor(5);
	_set_type("\033[94mFR4G-TP\033[m");

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

FragTrap::FragTrap()
{
	init();
	_set_name("FragTrap");
	return ;
}

FragTrap::FragTrap(std::string name)
{
	init();
	_set_name(name);
	return ;
}

FragTrap::FragTrap(FragTrap const & that) {
	*this = that;
	return ;
}

FragTrap::~FragTrap() {

	return ;
}

// --------------------------------------------------------- //
// ---- Operators										---- //
// --------------------------------------------------------- //

FragTrap &	FragTrap::operator=(FragTrap const & that) {
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
	}
	return *this;
}

std::ostream &	operator<<(std::ostream & os, FragTrap const & that) {
	os << that._get_name();
	return os;
}

// --------------------------------------------------------- //
// ---- Functions										---- //
// --------------------------------------------------------- //

void				FragTrap::vaulthunter_dot_exe(std::string const & tar) {
	if (arc4random() % 2) {
		meleeAttack(tar);
	} else {
		rangedAttack(tar);
	}
}
