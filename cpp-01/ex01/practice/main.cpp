#include "Zombie.hpp"

int main() {
	int n = 5;
	Zombie* horda = zombieHorde(n, "Zumbi");

	if (!horda)
        return (1);
    for (int i = 0; i < n; i++)
        horda[i].announce();

	delete[] horda;

	return 0;
}
