#include "ClapTrap.hpp"

int	main(void)
{
	std::cout << "\n--- Creating ClapTraps ---" << std::endl;
	ClapTrap a("Alex");
	ClapTrap b("Beatrice");
	ClapTrap c("Charlotte");

	//std::cout << "\n--- Testing assignment: a = b = c ---" << std::endl;
	//a = b = c; // encadeamento

	std::cout << "\n--- Testing actions on ClapTrap a ---" << std::endl;
	a.attack("enemy");
	a.takeDamage(4);
	a.beRepaired(2);
	std::cout << "ClapTrap " << a.getName() << " has " << a.getHitPoints() << " hit points." << std::endl;

	std::cout << "\n--- Testing energy exhaustion ---" << std::endl;
	for (int i = 0; i < 12; ++i)
	{
		a.attack("enemy");
	}

	std::cout << "\n--- Testing damage until death ---" << std::endl;
	a.takeDamage(100); // should bring hitPoints to 0
	a.attack("enemy"); // should not work
	a.beRepaired(5);   // should not work

	std::cout << "\n--- End of program, destructors will be called ---" << std::endl;
	return (0);
}