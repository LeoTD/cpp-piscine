#include <Pony.hpp>
#include <iostream>

bool	ponyOnTheStack() {
	Pony		p;

	p.emote();
	p.stompAtk();
	p.displayStatus();

	return true;
}

bool	ponyOnTheHeap() {
	int			stats[] = { 10, 11, 13, 16, 12, 9};
	Pony *		p = new Pony("Grog", "Pike", stats);

	p->emote();
	p->stompAtk();
	p->displayStatus();

	delete p;
	return true;
}

int		main(void) {
	std::cout << "Pony on the Heap:" << std::endl;
	ponyOnTheHeap();
	std::cout << std::endl << "Pony on the Stack:" << std::endl;
	ponyOnTheStack();
}