#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {
	std::cout << "Zombie (sem nome) nasceu!" << std::endl;
}

Zombie::Zombie(std::string name) {
	this->name = name;
	std::cout << "Zombie " << name << " nasceu!" << std::endl;
}

Zombie::~Zombie() {
	std::cout << "Zombie " << name << " morreu!" << std::endl;
}

void Zombie::announce() {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
	this->name = name;
}

Zombie* zombieHorde(int N, std::string name)
{
    if (N <= 0)
    {
        std::cout << "Número inválido de zumbis!" << std::endl;
        return NULL;
    }
    Zombie *horde = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        horde[i].setName(name + "_" + std::to_string(i));
    }
    return horde;
}