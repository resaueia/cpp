#include "Harl.hpp"

int main(int c, char **v)
{
	if (c != 2)
	{
		std::cout << "Usage: ./harl <complaint>" << std::endl;
		std::cout << "complaints are: DEBUG, INFO, WARNING or ERROR - in all CAPS!" << std::endl;
		return 1;
	}
	std::string level = v[1];
	Harl harl;
	if (level == "DEBUG")
		harl.complain("DEBUG");
	else if (level == "INFO")
		harl.complain("INFO");
	else if (level == "WARNING")
		harl.complain("WARNING");
	else if (level == "ERROR")
		harl.complain("ERROR");
	else
		std::cout << "[ Probably complaining about insignificant problems - Harl is such a Karen lol! ]" << std::endl;

	//harl.complain("DEBUG");
	//harl.complain("INFO");
	//harl.complain("WARNING");
	//harl.complain("ERROR");
	//harl.complain("UNKNOWN");

	return 0;
}