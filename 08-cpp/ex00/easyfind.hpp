/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 17:31:35 by rsaueia           #+#    #+#             */
/*   Updated: 2025/10/18 17:41:16 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

#include <algorithm>
#include <iterator>
#include <exception>
#include <iostream>
#include <vector>

template <typename T>

typename T::iterator easyfind(T &container, int value)
{
	// std::find returns an iterator to the element if found,
    // or container.end() if not found.
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::runtime_error("Value not found!");
	return it;
}