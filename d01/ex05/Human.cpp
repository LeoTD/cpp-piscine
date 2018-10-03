#include <Human.hpp>

Human::Human(): _brain() {}

Human::~Human() {}

std::string		Human::identify() const {
	return _brain.identify();
}

Brain const &	Human::getBrain() const {
	return _brain;
}