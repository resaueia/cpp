#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {
	std::cout << "Zombie (nameless) was born!" << std::endl;
}

Zombie::Zombie(std::string name) {
	this->name = name;
	std::cout << "Zombie " << name << " was born!" << std::endl;
}

Zombie::~Zombie() {
	std::cout << "Zombie " << name << " has perished!" << std::endl;
}

void Zombie::announce() {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
	this->name = name;
}
