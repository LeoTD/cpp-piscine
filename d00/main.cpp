#include "testClass.hpp"

int main(void)
{
	testClass		leo("Harrison_is_cooll");
	testClass		*harrison = new testClass("random");
	
	leo.leo_is_the_best(15, 20);
	delete harrison;
}