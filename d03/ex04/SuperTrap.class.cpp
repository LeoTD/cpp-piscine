#include "SuperTrap.class.hpp"

// --------------------------------------------------------- //
// ---- Constructors and Init							---- //
// --------------------------------------------------------- //

void		SuperTrap::init(void) {
	_set_hp(100);
	_set_MAX_HP(100);
	_set_energy(120);
	_set_MAX_ENERGY(120);
	_set_level(1);
	_set_melee_dmg(60);
	_set_ranged_dmg(20);
	_set_armor(5);
	_set_type("\033[96mSUPA-TP\033[m");

	_meleeMessage[0] = "\033[96mHiyah!\033[m";
	_meleeMessage[1] = "\033[96m* slice *\033[m";
	_meleeMessage[2] = "\033[96m...\033[m";

	_rangedMessage[0] = "\033[96m* thunk *\033[m";
	_rangedMessage[1] = "\033[96m* thwack *\033[m";
	_rangedMessage[2] = "\033[96m...\033[m";

	_damageMessage[0] = "\033[96m* angry dead robot noises *\033[m";
	_damageMessage[1] = "\033[96m...\033[m";
	_damageMessage[2] = "\033[96mAah...\033[m";

	_repairMessage[0] = "\033[96m...\033[m" ;
	_repairMessage[1] = "\033[96m* Windows Startup Noise *\033[m";
	_repairMessage[2] = "\033[96m...\033[m";
}

SuperTrap::SuperTrap()
{
	init();
	_set_name("SuperTrap");
	return ;
}

SuperTrap::SuperTrap(std::string name)
{
	init();
	_set_name(name);
	return ;
}

SuperTrap::SuperTrap(SuperTrap const & that) {
	*this = that;
	return ;
}

SuperTrap::~SuperTrap() {

	return ;
}

// --------------------------------------------------------- //
// ---- Operators										---- //
// --------------------------------------------------------- //

SuperTrap &	SuperTrap::operator=(SuperTrap const & that) {
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

std::ostream &	operator<<(std::ostream & os, SuperTrap const & that) {
	os << that._get_name();
	return os;
}

// --------------------------------------------------------- //
// ---- Functions										---- //
// --------------------------------------------------------- //
