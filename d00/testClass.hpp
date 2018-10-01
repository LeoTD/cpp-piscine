#ifndef TESTCLASS_HPP
# define TESTCLASS_HPP
# include <string>
# include <iostream>

class testClass {
	private:
		int	c;
		std::string		_leos_song;

	public:
		testClass(std::string leos_song);
		~testClass();

		void	get_leos_song(void) const;	
		void	leo_is_the_best(int e, int d);
		int a;
		
};

#endif