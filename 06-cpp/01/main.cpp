/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 15:26:58 by rsaueia           #+#    #+#             */
/*   Updated: 2025/10/10 15:43:39 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data data;
    data.number = 42;
    data.text = "Bonjour 42!";

    std::cout << "Original Data address: " << &data << std::endl;

    unsigned long raw = Serializer::serialize(&data);
    std::cout << "Serialized value (unsigned long): " << raw << std::endl;

    Data* deserialized = Serializer::deserialize(raw);
    std::cout << "Deserialized Data address: " << deserialized << std::endl;

    std::cout << "Data.number = " << deserialized->number << std::endl;
    std::cout << "Data.text   = " << deserialized->text << std::endl;

	//void* ptr = reinterpret_cast<void*>(0x7fff4b2ce5a0);
    //unsigned long raw2 = reinterpret_cast<unsigned long>(ptr);

    //std::cout << "Hex: 0x" << std::hex << raw2 << std::endl;
    //std::cout << "Dec: " << std::dec << raw2 << std::endl;
	
    return 0;
}
