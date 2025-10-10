/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia <rsaueia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 15:56:07 by rsaueia           #+#    #+#             */
/*   Updated: 2025/10/10 16:52:58 by rsaueia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

class Base {
	public:
		virtual ~Base();
};

/*
Since i have a public method, all the classes that inherit from Base
will have a virtual table, which will allow the dynamic_cast to
know the actual type of the object at runtime.
*/