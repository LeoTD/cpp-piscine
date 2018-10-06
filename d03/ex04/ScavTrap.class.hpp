#ifndef SCAVTRAP_CLASS_HPP
# define SCAVTRAP_CLASS_HPP

# include "ClapTrap.class.hpp"

class ScavTrap : public ClapTrap {
public:
	ScavTrap();
	ScavTrap(std::string);
	ScavTrap(ScavTrap const &);
	ScavTrap &operator=(ScavTrap const &);
	~ScavTrap();

	void			init(void);
	void			challengeNewcomer(std::string const &);

private:
	
};

std::ostream &		operator<<(std::ostream &, ScavTrap const &);

#endif
