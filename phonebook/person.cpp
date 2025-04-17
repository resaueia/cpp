#include "Person.hpp"

void Person::set_name(std::string n)
{
	name = n;
}

void Person::say_name()
{
	std::cout << "My name is: " << name << std::endl;
}

int main()
{
	Person p;
	p.set_name ("Cantarella");
	p.say_name();
	Person list[3];
	list[0].set_name("Yinlin");
	list[1].set_name("Zhezhi");
	list[2].set_name("Shorekeeper");
	for (int i = 0; i < 3; i++)
	{
		list[i].say_name();
	}
	return 0;
}