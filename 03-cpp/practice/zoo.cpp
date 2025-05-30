#include <iostream>
#include <string>

class Animal
{
	public:
	Animal() { std::cout << "Animal created" << std::endl; }
	virtual ~Animal() { std::cout << "Animal destroyed" << std::endl; }
	virtual void makeSound() const
	{
		std::cout << "Animal sound" << std::endl;
	}
};

class Dog : public Animal
{
	public:
	Dog() { std::cout << "Dog created" << std::endl; }
	~Dog() { std::cout << "Dog destroyed" << std::endl; }
	void makeSound() const override
	{
		std::cout << "Woof!" << std::endl;
	}
};

class Cat : public Animal {
	public:
	Cat() { std::cout << "Cat created" << std::endl; }
	~Cat() { std::cout << "Cat destroyed" << std::endl; }
	void makeSound() const override
	{
		std::cout << "Meow!" << std::endl;
	}
};

int main()
{
	Animal* zoo[2];

	zoo[0] = new Dog(); // creates a dog, but accesses it through the Animal pointer
	zoo[1] = new Cat(); // creates a cat, but accesses it through the Animal pointer

	std::cout << "----- Zoo Sounds -----" << std::endl;
	for (int i = 0; i < 2; i++)
		zoo[i]->makeSound(); // Calls the overridden makeSound method

	std::cout << "----- Cleaning up -----" << std::endl;
	for (int i = 0; i < 2; i++)
	{
		delete zoo[i]; // Deletes the animals, calling their destructors
	}
	std::cout << "----- Zoo cleaned up -----" << std::endl;
	return (0);
}