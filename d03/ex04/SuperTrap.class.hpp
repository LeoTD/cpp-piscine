#ifndef SUPERTRAP_CLASS_HPP
# define SUPERTRAP_CLASS_HPP

# include "ClapTrap.class.hpp"
# include "FragTrap.class.hpp"
# include "NinjaTrap.class.hpp"

class SuperTrap : public NinjaTrap, public FragTrap {
public:
	SuperTrap();
	SuperTrap(std::string);
	SuperTrap(SuperTrap const &);
	SuperTrap &operator=(SuperTrap const &);
	~SuperTrap();

	void			init(void);

private:
	
};

std::ostream &		operator<<(std::ostream &, SuperTrap const &);

#endif
