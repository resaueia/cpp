/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:13:14 by rsaueia           #+#    #+#             */
/*   Updated: 2025/06/04 18:14:57 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
	public:
		Dog();
		//Dog(std::string name);
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		~Dog();
		virtual void makeSound() const;
		std::string getType() const;
};

#endif