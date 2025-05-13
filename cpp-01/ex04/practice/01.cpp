#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
// This is a simple program that reads a file and prints its content to the console
// It uses the fstream library to handle file input/output
// The program opens a file called "test.txt" and reads its content
// line by line, printing each line to the console

/*int	main(void)
{
	std::ifstream file("test.txt");
	if (!file.is_open())
	{
		std::cerr << "Error opening file" << std::endl;
		return (1);
	}
	std::string line;
	while (std::getline(file, line))
	{
		std::cout << line << std::endl;
	}
	file.close();
}*/
// This next approach transfers the entire file content into a string using a stringstream
// instead of reading it line by line
// This is useful for smaller files

int	main(void)
{
	std::ifstream file("test.txt");

	if (!file.is_open())
	{
		std::cerr << "Erro ao abrir o arquivo!" << std::endl;
		return (1);
	}

	std::stringstream buffer;
	buffer << file.rdbuf(); // transfere todo conteúdo do arquivo para o buffer

	std::string conteudo = buffer.str(); // extrai tudo como uma string
	std::cout << "Conteúdo do arquivo:\n";
	std::cout << conteudo << std::endl;

	file.close();
	return (0);
}