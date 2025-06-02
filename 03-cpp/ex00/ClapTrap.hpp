/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:47:32 by rsaueia           #+#    #+#             */
/*   Updated: 2025/06/02 17:19:43 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
  private:
	std::string name;
	int hitPoints;
	int energyPoints;
	int attackDamage;

  public:
	ClapTrap(); // Default constructor
	ClapTrap(std::string name);
	// Constructor with name parameter
	ClapTrap(const ClapTrap &other);            // Copy constructor
	ClapTrap &operator=(const ClapTrap &other); // Assignment operator
	~ClapTrap();

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	std::string getName() const;
	int getHitPoints() const;
};

#endif