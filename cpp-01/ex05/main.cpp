#include "Harl.hpp"

int main(int c, char **v)
{
	if (c != 2)
	{
		std::cout << "Usage: ./harl <complaint>" << std::endl;
		std::cout << "complaints are: DEBUG, INFO, WARNING or ERROR" << std::endl;
		return 1;
	}
	std::string level = v[1];
	Harl harl;
	if (level == "DEBUG" || level == "debug")
		harl.complain("DEBUG");
	else if (level == "INFO" || level == "info")
		harl.complain("INFO");
	else if (level == "WARNING" || level == "warning")
		harl.complain("WARNING");
	else if (level == "ERROR" || level == "error")
		harl.complain("ERROR");
	else
		std::cout << "[ Probably complaining about insignificant problems - Harl is such a Karen lol!]" << std::endl;

	//harl.complain("DEBUG");
	//harl.complain("INFO");
	//harl.complain("WARNING");
	//harl.complain("ERROR");
	//harl.complain("UNKNOWN");

	return 0;
}