#include <iostream>

int main() {
    int* numeros = new int[5];

    // Atribuindo valores
    for (int i = 0; i < 5; i++) {
        numeros[i] = i * 10;
    }

    // Imprimindo valores
    std::cout << "Valores no array:\n";
    for (int i = 0; i < 5; i++) {
        std::cout << "numeros[" << i << "] = " << numeros[i] << std::endl;
    }

    // Liberando memória -> you don't need to iterate over the array to delete it (like in C!)
    delete[] numeros;

    return 0;
}
