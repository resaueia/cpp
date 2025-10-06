/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifier.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 11:27:09 by rsaueia           #+#    #+#             */
/*   Updated: 2025/10/06 11:36:48 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// figure out a way to identify the type of data stored

#include <iostream>
#include <string>

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
int i = 0;

if (literal[i] == '+' || literal[i] == '-')
    i++;

for (; i < literal.length(); ++i)
{
    if (!isdigit(literal[i])) {
        isInt = false;
        break;
    }
}
if (isInt)
    return INT;

// we have to check if its a float (one dot + ends with f + characters before and after dot are digits)

bool isFloat = false;

if (literal.find('.') != string::npos && literal.back() == 'f')
    isFloat = true;

if (isFloat)
    return FLOAT;

// we have to check if its a double (one dot + characters before and after dot are digits)

bool isDouble = false;

if (literal.find('.') != string::npos && literal.back() != 'f')
    isDouble = true;

if (isDouble)
    return DOUBLE;

//lastly, if none of the above, we return UNKNOWN
	
return UNKNOWN;