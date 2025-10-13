/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:29:55 by rsaueia           #+#    #+#             */
/*   Updated: 2025/10/13 16:51:50 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
#include <iostream>

template <typename T>
void swap(T &value, T &value2) {
	T temp = value;
	value = value2;
	value2 = temp;
}

template <typename T>
T min(T const &a, T const &b) {
	return (a <= b ? a : b);
}

template <typename T>
T max(T const &a, T const &b) {
	return (a >= b ? a : b);
}

/*
the comparison operator uses the lexicographical order for strings
which is basically a comparison based on the ASCII values of the characters.
*/
