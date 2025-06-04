/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:11:37 by rsaueia           #+#    #+#             */
/*   Updated: 2025/06/04 18:14:36 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal{
	public:
		Cat();
		//Cat(std::string name);
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		~Cat();
		virtual void makeSound() const;
		std::string getType() const;
		
};

#endif