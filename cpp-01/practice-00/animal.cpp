#include "animal.hpp"
#include <iostream>

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
	Animal a_stack;
	a_stack.set_name("Carminha");
	a_stack.talk();

	Animal *a_heap = new Animal();
	a_heap->set_name("Billy");
	a_heap->talk();
	delete a_heap;
	return (0);
}