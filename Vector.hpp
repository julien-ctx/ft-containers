/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 09:56:11 by jcauchet          #+#    #+#             */
/*   Updated: 2022/11/19 12:34:13 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

namespace ft
{
	
template < class T, class Allocator = std::allocator<T> >
class Vector
{
public:
	/* ----- Constructors ----- */

	// Default
	explicit Vector() {}
	
	explicit Vector (size_t n, const T &val = value_type()) {}

private:
};

}

