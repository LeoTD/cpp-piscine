#include "NinjaTrap.class.hpp"

// --------------------------------------------------------- //
// ---- Constructors and Init							---- //
// --------------------------------------------------------- //

void		NinjaTrap::init(void) {
	_set_hp(60);
	_set_MAX_HP(60);
	_set_energy(120);
	_set_MAX_ENERGY(120);
	_set_level(1);
	_set_melee_dmg(60);
	_set_ranged_dmg(5);
	_set_armor(0);
	_set_type("\033[95mSHHH-TP\033[m");

	_meleeMessage[0] = "Hiyah!";
	_meleeMessage[1] = "* slice *";
	_meleeMessage[2] = "...";

	_rangedMessage[0] = "* thunk *";
	_rangedMessage[1] = "* thwack *";
	_rangedMessage[2] = "...";

	_damageMessage[0] = "* angry dead robot noises *";
	_damageMessage[1] = "...";
	_damageMessage[2] = "Aah...";

	_repairMessage[0] = "..." ;
	_repairMessage[1] = "* Windows Startup Noise *";
	_repairMessage[2] = "...";
}

NinjaTrap::NinjaTrap()
{
	init();
	_set_name("NinjaTrap");
	return ;
}

NinjaTrap::NinjaTrap(std::string name)
{
	init();
	_set_name(name);
	return ;
}

NinjaTrap::NinjaTrap(NinjaTrap const & that) {
	*this = that;
	return ;
}

NinjaTrap::~NinjaTrap() {

	return ;
}

// --------------------------------------------------------- //
// ---- Operators										---- //
// --------------------------------------------------------- //

NinjaTrap &	NinjaTrap::operator=(NinjaTrap const & that) {
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

std::ostream &	operator<<(std::ostream & os, NinjaTrap const & that) {
	os << that._get_name();
	return os;
}

// --------------------------------------------------------- //
// ---- Functions										---- //
// --------------------------------------------------------- //

void			NinjaTrap::ninjaShoebox(FragTrap const & tar) {
	std::cout << "<" << _get_type() << "; " << _get_name() << "> ";
	std::cout << "You dishonor your family " << tar._get_type() << " " << tar._get_name() << std::endl;
}
void			NinjaTrap::ninjaShoebox(ScavTrap const & tar) {
	std::cout << "<" << _get_type() << "; " << _get_name() << "> ";
	std::cout << "You dishonor your family " << tar._get_type() << " " << tar._get_name() << std::endl;
}
void			NinjaTrap::ninjaShoebox(NinjaTrap const & tar) {
	std::cout << "<" << _get_type() << "; " << _get_name() << "> ";
	std::cout << "You honor your family " << tar._get_type() << " " << tar._get_name() << std::endl;
}
