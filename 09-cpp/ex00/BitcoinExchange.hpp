/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 12:36:36 by rsaueia           #+#    #+#             */
/*   Updated: 2025/11/08 12:37:42 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

#include <map>
#include <string>
#include <stdexcept>

/**
 * @brief Holds a date->price database and evaluates input lines of "date | value".
 * 
 * Design:
 *  - Store historical BTC prices in a sorted std::map<YYYY-MM-DD, price>.
 *  - For each query date, find the same date or the previous existing date
 *    using lower_bound and a one-step back when needed.
 *  - Validate input line format, date, and value constraints.
 */
class BitcoinExchange {
public:
    // Loads DB and prepares evaluator.
    explicit BitcoinExchange(const std::string& csvPath);

    // Non-copyable (but could be implemented if desired).
    BitcoinExchange(const BitcoinExchange&);
    BitcoinExchange& operator=(const BitcoinExchange&);
    ~BitcoinExchange();

    /**
     * @brief Process one input line "YYYY-MM-DD | value" and return formatted output
     *        (or throws to indicate an error that caller should print).
     * 
     * @param line Raw input line.
     * @return std::string Output like "YYYY-MM-DD => x = y" (no trailing newline).
     * @throws std::runtime_error with specific message for error cases.
     */
    std::string processLine(const std::string& line) const;

private:
    std::map<std::string, double> _db;

    // --- Helpers (parsing/validation) ---
    static std::string trim(const std::string& s);
    static bool isValidDate(const std::string& d); // YYYY-MM-DD + calendar checks
    static bool parseValue(const std::string& s, double& out);

    // Finds rate for date d (exact or closest lower date). Throws if none available.
    double rateForDateOrPrev(const std::string& d) const;

    // Loads CSV "date,rate" (first line is header).
    void loadCsv(const std::string& csvPath);
};

