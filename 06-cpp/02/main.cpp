/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:32:35 by rsaueia           #+#    #+#             */
/*   Updated: 2025/10/10 16:32:38 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main()
{
    Base* ptr = generate();  // cria A, B ou C aleatoriamente

    identify(ptr);           // identifica pelo ponteiro
    identify(*ptr);          // identifica pela referência

    delete ptr;              // limpa a memória
    return 0;
}
