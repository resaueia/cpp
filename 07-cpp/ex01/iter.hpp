/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:16:05 by rsaueia           #+#    #+#             */
/*   Updated: 2025/10/14 17:23:03 by rsaueia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

#include <iostream>

template <typename T>
void iter(T *array, _size_t length, void (*func)(T const &)) {
	if (!array || length == 0 || !func)
		return;
	for (_size_t i = 0; i < length; i++)
		func(array[i]); // apply the function to each element of the array
}