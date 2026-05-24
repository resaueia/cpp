/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 15:22:30 by rsaueia           #+#    #+#             */
/*   Updated: 2025/10/10 15:40:15 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::~Serializer() {}

// static member functions can be called without an instance of the class
// here we use reinterpret_cast to convert the pointer to an integer (unsignbed)
// reinterpret_cast yields a value that has a different type, but the same bit pattern as the original value

uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}


// here we use reinterpret_cast to convert the integer back to a pointer

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}

/*
reint_cast does NOT alter the bits of the data. It simpky changes
the way the compiler interprets those bits. On serialize, the compiler
takes the address of the object and treats it as a number, with the
same binary value. 
On deserialize, the compiler takes that number and treats it as a 
memory address, again with the same binary value.
It's like saying: these bits represent an address. Regardless of the type,
just give me back this address as a number.
*/