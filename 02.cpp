#include <iostream>
#include <string>

int main() {
	std::string name;
	std::string surname;
	std::cout << "Enter your name: ";
	std::cin >> name;
	std::cin.ignore(); // Ignore the newline character left in the buffer
	std::cout << "Now, enter your surname: ";
	getline(std::cin, surname);
	std::cout << "Hello, " << name << " " << surname << "! Welcome to the C++ world!" << std::endl;
	return 0;
}