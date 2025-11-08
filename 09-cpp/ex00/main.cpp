#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <string>

/**
 * @brief Entry point: btc <input.txt>
 * 
 * Behavior:
 *  1) Load "data.csv" (provided with subject) into a std::map.
 *  2) Read lines from the given input file (skip header if present).
 *  3) For each "YYYY-MM-DD | value", print "YYYY-MM-DD => value = result".
 *  4) On errors, print the specific error message required by the subject.
 * 
 * Notes:
 *  - We DO NOT reuse std::map in later exercises (module rule).
 *  - All comments/documentation are kept in English per your preference.
 */
int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    const std::string inputPath = argv[1];
    std::ifstream fin(inputPath.c_str());
    if (!fin) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    // 1) Load DB (CSV shipped with subject)
    //    theres a CSV of historical bitcoin prices provided.
    BitcoinExchange bex("data.csv");

    std::string line;
    // Optionally skip header lines starting with "date"
    if (std::getline(fin, line)) {
        if (line.size() < 4 || line.substr(0,4) != "date"); // first line is real data, process it after by handling below
        else
            line.clear(); // header consumed
    }
    if (!line.empty()) {
        try {
            std::string out = bex.processLine(line);
            std::cout << out << std::endl;
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
    // Process remaining lines
    while (std::getline(fin, line)) {
        if (line.empty()) continue;
        try {
            std::string out = bex.processLine(line);
            std::cout << out << std::endl;
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }

    return 0;
}

/*
Nesse exercício o que precisei fazer foi ler um histórico de preços do Bitcoin (data.csv) e, 
com base nele, calcular o valor de entradas fornecidas pelo usuário (input.txt) no formato YYYY-MM-DD | value.
Pra isso, criei a classe BitcoinExchange, que usa um std::map<std::string, double> — o map foi escolhido 
porque mantém as datas ordenadas automaticamente e permite buscar facilmente a data exata ou a anterior com 
o método lower_bound() - e tb pq o azzevedo ja tinha me dado o insight.
A classe tem os principais métodos: loadCsv() → lê o arquivo data.csv e preenche o map com data → cotação.
isValidDate() e parseValue() → validam formato da data e valor numérico.
rateForDateOrPrev() → busca a taxa da data exata ou, se não existir, da data imediatamente anterior.
processLine() → recebe uma linha do arquivo de entrada, valida, busca a cotação e retorna a frase formatada com o cálculo.
pra usar, o input é ./btc input.txt, e o programa responde com algo como
2011-01-03 => 3 = 0.9, calculando automaticamente com base no histórico.
*/