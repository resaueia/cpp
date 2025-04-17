#include <iostream>
#include <string>
#include <iomanip>

std::string format_name(std:: string text)
{
	if (text.length() > 10)
	{
		return text.substr(0, 9) + ".";
	}
	else
	{
		return text;
	}
}

int main()
{
	std::string names[3] = {"Yinlin", "Zhezhi", "Cantarella"};
	std::string surnames[3] = {"Cunt", "Novotny", "Fubanguissima"};
	std::string nicknames[3] = {"boobies", "bubbles", "lil hoe"};

	std::cout << "|" << std::setw(10) << "Id"
		<< "|" << std::setw(10) << "First Name"
		<< "|" << std::setw(10) << "Surname"
		<< "|" << std::setw(10) << "Nickname" << "|" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		std::cout << "|" << std::setw(10) << i
			<< "|" << std::setw(10) << format_name(names[i])
			<< "|" << std::setw(10) << format_name(surnames[i])
			<< "|" << std::setw(10) << format_name(nicknames[i]) << "|" << std::endl;
	}
	return 0;
}