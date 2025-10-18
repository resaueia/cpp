/*
Containers STL são estruturas de dados prontas para armazenar elementos
genéricos. Elas facilitam a manipulação de dados, oferecendo funcionalidades
como inserção, remoção e iteração. Exemplos comuns incluem:
- std::vector: Um array dinâmico que pode redimensionar conforme necessário.
- std::list: Uma lista duplamente ligada que permite inserções e remoções eficientes.
- std::map: Um contêiner associativo que armazena pares chave-valor ordenados.
*/

/*
A STL é um dos pilares do C++. Ela é uma coleção de templates genéricos 
que já implementam as estruturas e operações mais usadas em programação 
— filas, pilhas, listas, vetores, buscas, ordenações, etc.

Um container é uma estrutura que guarda elementos (de qualquer tipo) 
e permite manipulá-los de forma organizada.
*/

#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers; // cria um vetor vazio
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    std::cout << "Size: " << numbers.size() << std::endl;
    std::cout << "Element at index 1: " << numbers[1] << std::endl;

    return 0;
}
// Este trecho de código demonstra o uso do método `push_back` da classe `std::vector` em C++. 
// O método adiciona elementos ao final do vetor, aumentando seu tamanho dinamicamente. 
// Após adicionar os valores 10, 20 e 30, o vetor contém três elementos, com índices 0, 1 e 2. 
// A saída "Size: 3" indica que o vetor possui três elementos, e "Element at index 1: 20" 
// confirma que o valor no índice 1 é 20, conforme a ordem de inserção.



#include <iostream>
#include <vector>

int main() {
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    std::cout << "Using iterators:\n";
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << std::endl;
    }
}
// v.begin() → retorna um iterador para o primeiro elemento
// v.end() → retorna um iterador “um passo depois” do último
// *it → acessa o valor apontado pelo iterador
// ++it → move o iterador para o próximo elemento



#include <iostream>
#include <vector>
#include <algorithm> // contém std::find

int main() {
    std::vector<int> v = {3, 6, 9, 12};

    std::vector<int>::iterator it = std::find(v.begin(), v.end(), 9);

    if (it != v.end())
        std::cout << "Found: " << *it << std::endl;
    else
        std::cout << "Not found" << std::endl;
}
// std::find → busca um valor em um intervalo definido por dois iteradores
// Se encontrar, retorna um iterador para o elemento; caso contrário, 
//retorna o iterador de fim (v.end())
