/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:06:09 by rsaueia-          #+#    #+#             */
/*   Updated: 2025/06/03 17:14:40 by rsaueia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap(); // default constructor
        FragTrap(std::string name); // construcor with parameter
        FragTrap(const FragTrap& other); // copy constructor
        FragTrap& operator=(const FragTrap& other); // assignment operator
        ~FragTrap(); // destructor
        
        void attack(const std::string& target); // override the base method
        void highFivesGuys(); // FragTrap specific method
};

#endif
