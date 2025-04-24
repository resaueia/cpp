#include "phonebook.hpp"

Phonebook::Phonebook()
{
	total_contacts = 0;
}

std::string format(std::string str)
{
	if (str.length() > 10)
		str = str.substr(0, 9) + ".";
	return (str);
}

void Phonebook::add_contact()
{
	Contact	new_contact;
	int		index;

	std::string input;
	std::cout << "Let's add a new contact!\n";
	std::cout << "Enter first name: ";
	std::getline(std::cin, input);
	while (input.empty())
	{
		std::cout << "Please enter a valid first name: ";
		std::getline(std::cin, input);
	}
	new_contact.set_first_name(input);
	std::cout << "Enter last name: ";
	std::getline(std::cin, input);
	while (input.empty())
	{
		std::cout << "Please enter a valid last name: ";
		std::getline(std::cin, input);
	}
	new_contact.set_last_name(input);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, input);
	while (input.empty())
	{
		std::cout << "Please enter a valid nickname: ";
		std::getline(std::cin, input);
	}
	new_contact.set_nickname(input);
	std::cout << "Enter phone number: ";
	std::getline(std::cin, input);
	while (input.empty() || !isdigit(input[0]))
	{
		std::cout << "Please enter a valid phone number: ";
		std::getline(std::cin, input);
	}
	new_contact.set_phone_number(input);
	std::cout << "Now tell me your darkest secret: ";
	std::getline(std::cin, input);
	while (input.empty())
	{
		std::cout << "It is imperative that you tell me your darkest secret: ";
		std::getline(std::cin, input);
	}
	new_contact.set_darkest_secret(input);
	index = total_contacts % 8;
	contacts[index] = new_contact;
	total_contacts++;
	std::cout << "Contact was succesfully added!\n";
}

void Phonebook::show_table()
{
	if (total_contacts == 0)
	{
		// std::cout << "No contacts to display.\n";
		return ;
	}
	std::cout << std::setw(10) << "Index"
				<< "|";
	std::cout << std::setw(10) << "First Name"
				<< "|";
	std::cout << std::setw(10) << "Last Name"
				<< "|";
	std::cout << std::setw(10) << "Nickname"
				<< "|" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (contacts[i].get_first_name().empty())
			break ;
		std::cout << std::setw(10) << i + 1 << "|";
		std::cout << std::setw(10) << format(contacts[i].get_first_name()) << "|";
		std::cout << std::setw(10) << format(contacts[i].get_last_name()) << "|";
		std::cout << std::setw(10) << format(contacts[i].get_nickname()) << "|" << std::endl;
	}
}

void Phonebook::show_contact()
{
	if (total_contacts == 0)
	{
		std::cout << "No contacts to display.\n";
		return ;
	}
	std::string input;
	int index;
	std::cout << "Enter the index of the contact you want to see: ";
	std::getline(std::cin, input);
	while (input.length() != 1 || !isdigit(input[0]))
	{
		std::cout << "Invalid input. Please enter a number between 1 and 8: ";
		std::getline(std::cin, input);
	}
	index = input[0] - '0';
	while (index < 1 || index > 8 || contacts[index
		- 1].get_first_name().empty())
	{
		std::cout << "Invalid index. Please enter a number between 1 and 8: ";
		std::getline(std::cin, input);
		if (input.length() != 1 || !isdigit(input[0]))
			continue ;

		index = input[0] - '0';
	}
	Contact contact = contacts[index - 1];
	std::cout << "First Name: " << contact.get_first_name() << std::endl;
	std::cout << "Last Name: " << contact.get_last_name() << std::endl;
	std::cout << "Nickname: " << contact.get_nickname() << std::endl;
	std::cout << "Phone Number: " << contact.get_phone_number() << std::endl;
	std::cout << "Darkest Secret: " << contact.get_darkest_secret() << std::endl;
}