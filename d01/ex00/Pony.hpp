#ifndef PONY_CLASS_HPP
# define PONY_CLASS_HPP

# include <string>

class Pony {
	
public:
	Pony();
	Pony(std::string name, std::string owner, int stats[6]);
	~Pony();

	int				_height;
	int				_weight;
	std::string		_name;
	std::string		_owner;

	int				_CR;
	int				_MAX_HP;
	int				_MAX_MP;
	int				_HP;
	int				_MP;

	int				_MAX_SPEED;
	int				_SPEED;

	int				dexterity;
	int				strength;
	int				constitution;
	int				charisma;
	int				wisdom;
	int				intelligence;

	int				stompAtk(void);
	void			emote(void);
	void			gallop(void);

	void			displayStatus(void);
};

#endif