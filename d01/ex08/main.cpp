#include "Human.hpp"
#include <iostream>

int		main(void) {
	Human		josh;

	josh.action("meleeAttack", "ezekiel");
	josh.action("rangedAttack", "rodrigo");
	josh.action("intimidatingShout", "gerardo");

	josh.action("meleeAttack", "jeff");
	josh.action("rangedAttack", "max");
	josh.action("intimidatingShout", "curtis");
}