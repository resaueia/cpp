#include "animal.hpp"
#include <iostream>

Animal::Animal(std::string name)
{
	this->name = name;
	std::cout << "Animal " << name << " created!" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal " << name << " destroyed!" << std::endl;
}

Animal *newnimal(std::string name) {
	Animal *a = new Animal(name);
	return (a);
}

void stack_animal(std::string name) {
	Animal a(name);
	a.talk();
}

void Animal::set_name(std::string new_name) {
	name = new_name;
}

void Animal::talk() {
	std::cout << "My name is " << name << "!" << std::endl;
}

/*int main() {
	Animal a;
	Animal b;
	a.set_name("Carminha");
	a.talk();
	b.set_name("Billy");
	b.talk();
	return (0);
}*/

int main(){
	Animal *pet = newnimal("Carminha");
	pet->talk();
	delete pet;
	return (0);
}