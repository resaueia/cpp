#include <iostream>

class Counter
{
  public:
	// Default constructor
	Counter();
	// Copy constructor
	Counter(const Counter &other);
	// Copy assignment operator
	Counter &operator=(const Counter &other);
	// Destructor
	~Counter();

  private:
	int count_; // holds the counter value
};

// Definitions:

/*Counter::Counter()
	-> Isto é a assinatura do default constructor da classe Counter.
Ele não recebe parâmetros e é invocado sempre que você escreve Counter a;.

: count_(0) -> É a member initializer list (lista de inicialização de membros).
Antes do corpo da função ser executado,
	o membro count_ é inicializado com o valor 0.
Equivale a fazer, em C, f->rawBits = 0; dentro de um init,
	mas ocorre antes de entrar no {…}.
*/

Counter::Counter() : count_(0)
{
	std::cout << "default constructor" << std::endl;
}

/*Counter::Counter(const Counter &c) -> Assinatura do copy constructor.
Parâmetro const Counter &c é uma reference constante para outro objeto Counter.
É invocado quando você faz Counter b(a); ou Counter b = a;.

: count_(c.count_) -> Inicializa o membro count_ copiando o valor de c.count_.
Usamos a referência c para obter o valor interno do objeto existente.*/

Counter::Counter(const Counter &c) : count_(c.count_)
{
	std::cout << "copy constructor" << std::endl;
}

/*Counter & -> O operador retorna uma referência ao próprio objeto (*this),
permitindo encadeamento: a = b = c;  // (b = c) retorna b, então a = (resultado)

Counter::operator=(const Counter &c) -> Declaração do operator=, que trata o caso de você escrever c = b;.
Recebe também const Counter &c, referência ao objeto origem.

if (this != &c) -> Proteção contra auto-atribuição.
this é um ponteiro para o objeto à esquerda do =, e &c é o endereço do objeto à direita.
Se forem o mesmo objeto, não faz cópia (evita sobrescrever acidentalmente).

count_ = c.count_; -> Copia o valor interno de c.count_ para this->count_.

return (*this); -> Retorna, por referência, o objeto atual após a atribuição.*/

Counter &Counter::operator=(const Counter &c)
{
	std::cout << "copy assignment operator" << std::endl;
	if (this != &c)
	{
		count_ = c.count_;
	}
	return (*this);
}

Counter::~Counter()
{
	std::cout << "destructor" << std::endl;
}

int	main(void)
{
	Counter a;    // calls default constructor
	Counter b(a); // calls copy constructor
	Counter c;    // calls default constructor
	c = b;        // calls copy assignment operator
					// return (0);  // opcional em C++98
}
