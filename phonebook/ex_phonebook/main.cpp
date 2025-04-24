#include "phonebook.hpp"

int	main(void)
{
	Phonebook phonebook;
	std::string command;

	std::cout << "-*-*-*-*-*- Welcome to your Little Black Book! -*-*-*-*-*-" << std::endl;
	while (true)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		if (command == "ADD" || command == "add")
			phonebook.add_contact();
		else if (command == "SEARCH" || command == "search")
		{
			phonebook.show_table();
			phonebook.show_contact();
		}
		else if (command == "EXIT" || command == "exit")
		{
			std::cout << "Auf Wiedersehen!\n";
			break ;
		}
		else
			std::cout << "Invalid command. Please try again.\n";
	}
	return (0);
}