#ifndef HUMAN_HPP
# define HUMAN_HPP

# include <Brain.hpp>
# include <string>

class Human {
public:
	Human();
	~Human();

	std::string		identify() const;
	Brain const &	getBrain() const;

private:
	Brain const		_brain;
};

#endif