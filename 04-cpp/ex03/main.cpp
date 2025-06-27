/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 18:36:15 by rsaueia           #+#    #+#             */
/*   Updated: 2025/06/27 19:06:39 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main() {
	// Criando a fonte de matérias
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	// Criando um personagem
	ICharacter* me = new Character("me");

	// Criando e equipando matérias
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);

	tmp = src->createMateria("cure");
	me->equip(tmp);

	// Criando outro personagem
	ICharacter* bob = new Character("bob");

	// Usando as matérias
	me->use(0, *bob);
	me->use(1, *bob);

	// Limpeza
	delete bob;
	delete me;
	delete src;

	return 0;
}

/*int main() {
	MateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	Character* hero = new Character("Hero");

	// Equipando duas matérias
	hero->equip(src->createMateria("ice"));
	hero->equip(src->createMateria("cure"));

	std::cout << "\n--- Using before unequip ---" << std::endl;
	hero->use(0, *hero);
	hero->use(1, *hero);

	// Guardar referência manual ao ponteiro para não perder
	AMateria* orphaned = hero->getInventorySlot(0);

	std::cout << "\n--- Unequipping slot 0 ---" << std::endl;
	hero->unequip(0);

	std::cout << "\n--- Using after unequip ---" << std::endl;
	hero->use(0, *hero); // deve não fazer nada

	std::cout << "\n--- Reusing unequipped materia manually ---" << std::endl;
	orphaned->use(*hero); // ainda funciona!

	// Limpeza manual do ponteiro "orfão"
	delete orphaned;

	delete hero;
	delete src;
	return 0;
}*/

/*int main() {
	MateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	Character* rogue = new Character("Rogue");

	// Equipando 4 magias
	for (int i = 0; i < 4; ++i) {
		AMateria* m = src->createMateria((i % 2 == 0) ? "ice" : "cure");
		rogue->equip(m);
	}

	// Tentando equipar uma 5ª magia → leak se não for tratada!
	std::cout << "\n--- Trying to overfill inventory ---" << std::endl;
	AMateria* leak = src->createMateria("ice");
	rogue->equip(leak); // subject diz que deve ignorar (sem delete)

	std::cout << "\n--- Trying to use invalid index ---" << std::endl;
	rogue->use(-1, *rogue); // índice inválido
	rogue->use(10, *rogue); // índice inválido

	// Devemos deletar o ponteiro que não foi usado
	delete leak;

	delete rogue;
	delete src;
	return 0;
}*/