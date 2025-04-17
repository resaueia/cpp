#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <string>

class Person{
	private:
	std::string name;
	public:
	void set_name(std::string n);
	void say_name();
};

#endif