/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 15:19:06 by rsaueia           #+#    #+#             */
/*   Updated: 2025/10/10 15:31:20 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

#include "Data.hpp"
#include <stdint.h>
#include <iostream>
//#include <cstdint> // this is for the uintptr_t type (c++11)

class Serializer {
	private:
		Serializer();
		Serializer(const Serializer &other);
		Serializer &operator=(const Serializer &other);
		~Serializer();
	public:
		static unsigned long serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};