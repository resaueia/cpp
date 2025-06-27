/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:28:11 by rsaueia           #+#    #+#             */
/*   Updated: 2025/06/27 18:38:52 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure: public AMateria
{
	public:
		Cure();
		Cure(const Cure &other);
		Cure& operator=(const Cure &other);
		~Cure();

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif