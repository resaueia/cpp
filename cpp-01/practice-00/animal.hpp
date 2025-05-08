#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
private:
	std::string name;
public:
	Animal(std::string name);
	~Animal();
	void set_name(std::string new_name);
	void talk();
};

#endif