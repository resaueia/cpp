/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:54:45 by rsaueia           #+#    #+#             */
/*   Updated: 2025/10/08 18:59:25 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


//ScalarConverter::ScalarConverter() {}

//ScalarConverter::~ScalarConverter() {}

Literal_Type ScalarConverter::get_type(const std::string& literal)
{
	// we can check if the string has only one character and if that character is not a digit
	if (literal.length() == 1 && !isdigit(literal[0]))
		return CHAR;

	// we can check for special float and double values (subject requirements)
	
	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
		return FLOAT;
	if (literal == "nan" || literal == "+inf" || literal == "-inf")
		return DOUBLE;

	//we have to check if its an integer

	bool isInt = true;
    size_t i = 0;

	if (literal[i] == '+' || literal[i] == '-')
		i++;

    if (i >= literal.length()) // check if there's at least one digit
        return UNKNOWN;

    while (i < literal.length())
	{
		if (!isdigit(literal[i])) {
			isInt = false;
			break;
		}
        i++;
	}
	if (isInt)
		return INT;

	// we have to check if its a float (one dot + ends with f + characters before and after dot are digits)

	bool isFloat = false;

    if (literal.find('.') != std::string::npos && literal[literal.length() - 1] == 'f')
		isFloat = true;

	if (isFloat)
		return FLOAT;

	// we have to check if its a double (one dot + characters before and after dot are digits)

	bool isDouble = false;

	if (literal.find('.') != std::string::npos && literal[literal.length() - 1] != 'f')
		isDouble = true;

	if (isDouble)
		return DOUBLE;

	return UNKNOWN;
}

void ScalarConverter::convert(const std::string& literal)
{
	Literal_Type type = get_type(literal);

    double value = 0.0;

    // Convert string to a numeric base value (double)
    switch (type)
    {
        case CHAR:
            value = static_cast<double>(literal[0]);
            break;
        case INT:
            value = static_cast<double>(atoi(literal.c_str()));
            break;
        case FLOAT:
            value = static_cast<double>(atof(literal.c_str()));
            break;
        case DOUBLE:
            value = strtod(literal.c_str(), NULL);
            break;
        default:
            std::cout << "Invalid literal!" << std::endl;
            return;
    }


    // ---------- CHAR ----------
    std::cout << "char: ";
    if (std::isnan(value) || std::isinf(value))
        std::cout << "impossible" << std::endl;
    else if (value < std::numeric_limits<char>::min() ||
             value > std::numeric_limits<char>::max())
        std::cout << "impossible" << std::endl;
    else if (value < 32 || value > 126)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;

    // ---------- INT ----------
    std::cout << "int: ";
    if (std::isnan(value) || std::isinf(value))
        std::cout << "impossible" << std::endl;
    else if (value < std::numeric_limits<int>::min() ||
             value > std::numeric_limits<int>::max())
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(value) << std::endl;

    // ---------- FLOAT ----------
    std::cout << "float: ";
    if (std::isnan(value))
        std::cout << "nanf" << std::endl;
    else if (std::isinf(value))
        std::cout << (value < 0 ? "-inff" : "+inff") << std::endl;
    else
    {
        float f = static_cast<float>(value);
        std::cout << std::fixed << std::setprecision((f == static_cast<int>(f)) ? 1 : 6);
        std::cout << f << "f" << std::endl;
    }

    // ---------- DOUBLE ----------
    std::cout << "double: ";
    if (std::isnan(value))
        std::cout << "nan" << std::endl;
    else if (std::isinf(value))
        std::cout << (value < 0 ? "-inf" : "+inf") << std::endl;
    else
    {
        std::cout << std::fixed << std::setprecision((value == static_cast<int>(value)) ? 1 : 6);
        std::cout << value << std::endl;
    }
}