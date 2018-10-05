#ifndef FRAGTRAP_CLASS_HPP
# define FRAGTRAP_CLASS_HPP

# include "ClapTrap.class.hpp"

class FragTrap : public ClapTrap {
public:
	FragTrap();
	FragTrap(std::string);
	FragTrap(FragTrap const &);
	FragTrap &operator=(FragTrap const &);
	~FragTrap();

	void			init(void);
	void			vaulthunter_dot_exe(std::string const &);

private:
	
};

std::ostream &		operator<<(std::ostream &, FragTrap const &);

#endif
