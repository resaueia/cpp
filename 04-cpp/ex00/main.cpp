/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:50:25 by rsaueia           #+#    #+#             */
/*   Updated: 2025/06/09 16:35:04 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const Animal* k = i;

	std::cout << "------------------------" << std::endl;
	std::cout << meta->getType() << std::endl;
	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	std::cout << k->getType() << std::endl; // This will also print "Cat" since k points to a Cat object
	std::cout << "------------------------" << std::endl;
	
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << "------------------------" << std::endl;

	const Animal* another = j;
	another->makeSound(); // This will call Dog's makeSound() because i now points to a Dog object

	delete i;
	delete j;
	delete meta;
	return (0);
}
/*
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	const WrongAnimal* wrong = new WrongCat();

	std::cout << wrong->getType() << std::endl;
	wrong->makeSound(); // Vai chamar o método da WrongAnimal

	delete wrong;
	return 0;
}*/
