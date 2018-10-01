#include "testClass.hpp"

testClass::testClass(std::string leos_song): _leos_song(leos_song) {
	std::cout << "Calling the constructor" << std::endl;
	std::cout << "new string is :" << _leos_song  << std::endl;
}

testClass::~testClass() {
	std::cout << "Calling the destructor" << std::endl;
};


void	testClass::get_leos_song(void) const
{
	std::cout << _leos_song << std::endl;
}

void	testClass::leo_is_the_best(int alex, int barry)
{
	a = alex;
	c = barry;
	
	std::cout << "value of a is " << a << "second value is " << c << std::endl;
}

