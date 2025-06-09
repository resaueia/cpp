/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:00:53 by rsaueia           #+#    #+#             */
/*   Updated: 2025/06/09 17:15:33 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

/*int main() {
	std::cout << "=== Creating original Cat ===" << std::endl;
	Cat original;
	original.getBrain()->setIdea(0, "Chase laser pointer");

	std::cout << "\n=== Copy constructing Cat ===" << std::endl;
	Cat copyConstructed(original); // chama copy constructor

	std::cout << "\n=== Copy assigning Cat ===" << std::endl;
	Cat copyAssigned;
	copyAssigned = original; // chama operator=

	std::cout << "\n=== Modifying original's idea ===" << std::endl;
	original.getBrain()->setIdea(0, "Sleep all day");

	std::cout << "\n=== Verifying independence of copies ===" << std::endl;
	std::cout << "Original Cat idea:       " << original.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy constructed Cat:    " << copyConstructed.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy assigned Cat:       " << copyAssigned.getBrain()->getIdea(0) << std::endl;

	std::cout << "\n=== Destruction ===" << std::endl;
	return 0;
}*/


int main() {
	const int N = 4;
	Animal* animals[N];

	std::cout << "\n=== Creating animals ===" << std::endl;
	for (int i = 0; i < N; ++i) {
		if (i < N / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << "\n=== Making animals make sound ===" << std::endl;
	for (int i = 0; i < N; ++i)
		animals[i]->makeSound();

	std::cout << "\n=== Deleting animals ===" << std::endl;
	for (int i = 0; i < N; ++i)
		delete animals[i];

	std::cout << "\n=== Done ===" << std::endl;
	return 0;
}
