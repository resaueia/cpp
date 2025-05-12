#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>
#include <sstream>

class Zombie {
private:
	std::string name;

public:
	Zombie();                      // construtor padrão
	Zombie(std::string name);      // construtor com parâmetro
	~Zombie();

	void announce();
	void setName(std::string name);  // setter simples para nome
};

Zombie *zombieHorde(int N, std::string name);

#endif
