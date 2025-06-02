/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:56:45 by rsaueia           #+#    #+#             */
/*   Updated: 2025/06/02 19:17:16 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(); // Default constructor
		ScavTrap(std::string name); // Constructor with name parameter
		ScavTrap(const ScavTrap &other); // Copy constructor
		ScavTrap &operator=(const ScavTrap &other); // Assignment operator
		~ScavTrap(); // Destructor
		
		void attack(const std::string &target); // Override attack method
		void guardGate(); // New method specific to ScavTrap
};

#endif