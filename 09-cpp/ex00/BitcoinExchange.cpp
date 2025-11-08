/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 12:51:31 by rsaueia           #+#    #+#             */
/*   Updated: 2025/11/08 12:51:32 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <cctype>

// ---- Utility: trim ----
std::string BitcoinExchange::trim(const std::string& s) {
    size_t i = 0, j = s.size();
    while (i < j && std::isspace(static_cast<unsigned char>(s[i]))) ++i;
    while (j > i && std::isspace(static_cast<unsigned char>(s[j-1]))) --j;
    return s.substr(i, j - i);
}

// ---- Utility: date validation (YYYY-MM-DD) ----
static bool isLeap(int y) {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}
bool BitcoinExchange::isValidDate(const std::string& d) {
    // Basic format check: YYYY-MM-DD (10 chars)
    if (d.size() != 10 || d[4] != '-' || d[7] != '-') return false;
    for (size_t i = 0; i < d.size(); ++i) {
        if (i == 4 || i == 7) continue;
        if (!std::isdigit(static_cast<unsigned char>(d[i]))) return false;
    }
    int y = std::atoi(d.substr(0,4).c_str());
    int m = std::atoi(d.substr(5,2).c_str());
    int day = std::atoi(d.substr(8,2).c_str());
    if (m < 1 || m > 12) return false;
    int mdays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int maxd = mdays[m-1];
    if (m == 2 && isLeap(y)) maxd = 29;
    if (day < 1 || day > maxd) return false;
    return true;
}

// ---- Utility: parse value (float/int positive, 0..1000) ----
bool BitcoinExchange::parseValue(const std::string& s, double& out) {
    // Accept integer or float with optional leading/trailing spaces (already trimmed in caller).
    if (s.empty()) return false;
    std::istringstream iss(s);
    double val;
    iss >> val;
    if (!iss || !iss.eof()) return false;
    out = val;
    return true;
}

// ---- CSV loader ----
void BitcoinExchange::loadCsv(const std::string& csvPath) {
    std::ifstream fin(csvPath.c_str());
    if (!fin) throw std::runtime_error("Error: could not open file.");
    std::string line;
    // Expect header "date,exchange_rate"
    if (!std::getline(fin, line)) throw std::runtime_error("Error: empty database.");
    while (std::getline(fin, line)) {
        if (line.empty()) continue;
        std::string::size_type comma = line.find(',');
        if (comma == std::string::npos) continue;
        std::string d = line.substr(0, comma);
        std::string r = line.substr(comma + 1);
        d = trim(d);
        r = trim(r);
        if (!isValidDate(d)) continue;
        std::istringstream iss(r);
        double rate;
        if (!(iss >> rate)) continue;
        _db[d] = rate;
    }
    if (_db.empty()) throw std::runtime_error("Error: empty/invalid database.");
}

// ---- ctor/canonical ----
BitcoinExchange::BitcoinExchange(const std::string& csvPath) { loadCsv(csvPath); }
BitcoinExchange::BitcoinExchange(const BitcoinExchange& rhs) : _db(rhs._db) {}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs) {
    if (this != &rhs) _db = rhs._db;
    return *this;
}
BitcoinExchange::~BitcoinExchange() {}

// ---- Rate lookup: exact or previous date ----
double BitcoinExchange::rateForDateOrPrev(const std::string& d) const {
    // lower_bound: first element not less than d
    std::map<std::string, double>::const_iterator it = _db.lower_bound(d);
    if (it == _db.end()) {
        // All stored dates < d -> use the last one
        if (_db.empty()) throw std::runtime_error("Error: database is empty.");
        --it;
        return it->second;
    }
    if (it->first == d) return it->second;
    if (it == _db.begin()) {
        // There's a stored date >= d but none strictly smaller -> cannot use an earlier date
        throw std::runtime_error("Error: no earlier date available.");
    }
    // Step back to the previous (strictly lower) date
    --it;
    return it->second;
}

// ---- Main line processor ----
std::string BitcoinExchange::processLine(const std::string& raw) const {
    std::string line = trim(raw);
    if (line.empty()) throw std::runtime_error("Error: bad input => " + raw);

    // Expect format "date | value"
    std::string::size_type bar = line.find('|');
    if (bar == std::string::npos) throw std::runtime_error("Error: bad input => " + raw);

    std::string left = trim(line.substr(0, bar));
    std::string right = trim(line.substr(bar + 1));

    if (!isValidDate(left)) throw std::runtime_error("Error: bad input => " + left);

    double val;
    if (!parseValue(right, val)) throw std::runtime_error("Error: bad input => " + right);
    if (val < 0.0) throw std::runtime_error("Error: not a positive number.");
    if (val > 1000.0) throw std::runtime_error("Error: too large a number.");

    double rate = rateForDateOrPrev(left);
    std::ostringstream oss;
    // Output format matches subject's style.
    oss << left << " => " << right << " = " << (val * rate);
    return oss.str();
}
