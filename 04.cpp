#include <iostream>
#include <string>

int main()
{
	char letter;
	char uppercase;
	std::cout << "Enter a letter: ";
	std::cin >> letter;
	uppercase = toupper(letter);
	std::cout << "The uppercase letter is: " << uppercase << std::endl;
	return 0;
}