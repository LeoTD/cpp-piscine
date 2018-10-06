#ifndef NINJATRAP_CLASS_HPP
# define NINJATRAP_CLASS_HPP

# include "ClapTrap.class.hpp"
# include "FragTrap.class.hpp"
# include "ScavTrap.class.hpp"

class NinjaTrap : public ClapTrap {
public:
	NinjaTrap();
	NinjaTrap(std::string);
	NinjaTrap(NinjaTrap const &);
	NinjaTrap &operator=(NinjaTrap const &);
	~NinjaTrap();

	void			init(void);
	void			ninjaShoebox(FragTrap const &);
	void			ninjaShoebox(ScavTrap const &);
	void			ninjaShoebox(NinjaTrap const &);

private:
	
};

std::ostream &		operator<<(std::ostream &, NinjaTrap const &);

#endif
