// Basic inheritance syntax in C++
#include <iostream>

class Base
{
  public:
	void sayHello()
	{
		std::cout << "Hello from Base" << std::endl;
	}
};

class Derived : public Base
{
	// Inherits sayHello()
};

/*➡️ "public" define o tipo de herança :
public : mantém os membros públicos e protegidos da base com mesma visibilidade
private : torna todos os membros herdados privados
protected : mantém públicos e protegidos como protegidos.*/

class Animal
{
  public:
	Animal()
	{
		std::cout << "Animal created" << std::endl;
	}
	~Animal()
	{
		std::cout << "Animal destroyed" << std::endl;
	}
	std::string name;
	// Constructor with a parameter
	Animal(std::string name) : name(name)
	{
		std::cout << "Animal named " << name << " created" << std::endl;
	}
	void makeSound() const
	{
		std::cout << "Animal sound" << std::endl;
	}
};

class Dog : public Animal
{
  public:
	Dog()
	{
		std::cout << "Dog created" << std::endl;
	}
	// Construtor que repassa o nome para o construtor da base
	Dog(std::string name) : Animal(name)
	{
		std::cout << "Dog named " << name << " created" << std::endl;
	}
	~Dog()
	{
		std::cout << "Dog destroyed" << std::endl;
	}
	void makeSound() const
	{
		std::cout << "Woof!" << std::endl;
	}
};

int	main(void)
{
	Dog dog("Rex");
	dog.makeSound();         // Woof!
	dog.Animal::makeSound(); // Animal sound
	std::cout << "Dog's name is: " << dog.name << std::endl;
	return (0);
}
