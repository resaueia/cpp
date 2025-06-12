/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:01:45 by rsaueia           #+#    #+#             */
/*   Updated: 2025/06/12 16:38:10 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp" // Include Brain class to use its pointer in Animal class

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		//Animal(std::string name);
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual ~Animal();
		
		virtual void makeSound() const;
		virtual std::string getType() const;
		virtual Brain* getBrain() const = 0; // Pure virtual function to enforce derived classes to implement it - works as a placeholder for Brain pointer
};

#endif