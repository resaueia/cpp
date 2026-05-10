/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 17:14:45 by rsaueia           #+#    #+#             */
/*   Updated: 2025/10/06 16:37:09 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <iomanip>
#include <cmath>
#include <limits>

enum Literal_Type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	UNKNOWN
};

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter&);
		ScalarConverter& operator=(const ScalarConverter&);
		~ScalarConverter();

		static Literal_Type get_type(const std::string& literal);
	public:
		static void convert(const std::string& literal);
};