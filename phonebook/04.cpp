#include <iostream>
#include <string>

int main()
{
	std::string name;
	std::cout << "Type your full name: ";
	std::getline(std::cin, name);
	std::cout << "Your full name is: " << name << std::endl;
	return 0;
}