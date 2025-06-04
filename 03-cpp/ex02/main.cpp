/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:06:41 by rsaueia           #+#    #+#             */
/*   Updated: 2025/06/04 16:20:45 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {
	std::cout << "\n--- Creating FragTraps ---" << std::endl;
	FragTrap f1("Fraggie");
	FragTrap f2("Trappie");

	std::cout << "\n--- Using highFivesGuys ---" << std::endl;
	f1.highFivesGuys();

	std::cout << "\n--- Attacking ---" << std::endl;
	f1.attack("enemy");

	std::cout << "\n--- Taking damage and repairing ---" << std::endl;
	f1.takeDamage(60);
	f1.beRepaired(40);
	
	std::cout << "\n--- Current energy points: " << f1.getEnergyPoints() << std::endl;

	std::cout << "\n--- Exhausting energy ---" << std::endl;
	for (int i = 0; i < 101; ++i)
		f1.attack("dummy");

	std::cout << "\n--- Copy and assignment ---" << std::endl;
	FragTrap f3 = f1; // Copy constructor
	FragTrap f4("Temp");
	f4 = f2;          // Assignment

	std::cout << "\n--- End of main ---" << std::endl;
	return 0;
}
