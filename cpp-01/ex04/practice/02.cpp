#include <fstream>
#include <iostream>
#include <string>

int main()
{
	std::ofstream output("out.txt");
	if (!output.is_open())
	{
		std::cerr << "Error opening file" << std::endl;
		return (1);
	}
	output << "Line 1: Hello, World!" << std::endl;
	output << "Line 2: This is a test." << std::endl;
	output << "Line 3: Writing to a file." << std::endl;
	output << "Line 4: Hope it works!" << std::endl;
	output << "Line 4: Goodbye!" << std::endl;
	output.close();
	std::cout << "File created and written successfully!" << std::endl;
	return 0;
}