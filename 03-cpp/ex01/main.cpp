#include "ScavTrap.hpp"

int main() {
	std::cout << "\n--- Creating ScavTraps ---" << std::endl;
	ScavTrap s1("Serena");
	ScavTrap s2("Guardian");

	std::cout << "\n--- Using guardGate() ---" << std::endl;
	s1.guardGate();

	std::cout << "\n--- Attacking enemy ---" << std::endl;
	s1.attack("enemy");

	std::cout << "\n--- Taking damage and repairing ---" << std::endl;
	s1.takeDamage(30);
	s1.beRepaired(20);

	std::cout << "\n--- Exhausting energy ---" << std::endl;
	for (int i = 0; i < 51; ++i) {
		s1.attack("training dummy");
	}

	std::cout << "\n--- Assignment and Copy Constructor Test ---" << std::endl;
	ScavTrap s3 = s1; // copy constructor
	ScavTrap s4("Temporary");
	s4 = s2;          // assignment operator

	std::cout << "\n--- All destructors will now be called ---" << std::endl;
	return 0;
}
