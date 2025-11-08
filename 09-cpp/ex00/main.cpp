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
    //    The subject says a CSV of historical bitcoin prices is provided.
    //    We'll assume it's named "data.csv" and placed next to the executable.
    //    (If your repo uses a different path, adjust here.)
    BitcoinExchange bex("data.csv");

    std::string line;
    // Optionally skip header lines starting with "date"
    if (std::getline(fin, line)) {
        if (line.size() < 4 || line.substr(0,4) != "date")
            ; // first line is real data, process it after by handling below
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
