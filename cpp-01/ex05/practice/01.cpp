#include <iostream>
#include <string>

class Harl {
public:
	void debug()   { std::cout << "Debug message\n"; }
	void info()    { std::cout << "Info message\n"; }
};

int main() {
	Harl harl;

	// Definindo o tipo de ponteiro para função-membro de Harl
	typedef void (Harl::*HarlMethod)();

	// Atribuindo
	HarlMethod func = &Harl::debug;

	// Chamando com instância
	(harl.*func)();  // output: Debug message

	// Trocando o ponteiro para outro método
	func = &Harl::info;
	(harl.*func)();  // output: Info message

	return 0;
}
