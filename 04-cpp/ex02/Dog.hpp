/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:13:14 by rsaueia           #+#    #+#             */
/*   Updated: 2025/06/09 17:11:17 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain *brain; // Pointer to Brain object
	public:
		Dog();
		//Dog(std::string name);
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		~Dog();
		virtual void makeSound() const;
		std::string getType() const;
		Brain* getBrain() const;
};

#endif