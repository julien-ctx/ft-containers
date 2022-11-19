/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 09:56:11 by jcauchet          #+#    #+#             */
/*   Updated: 2022/11/19 15:34:17 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// https://en.cppreference.com/w/cpp/memory/allocator#:~:text=The%20default%20allocator%20is%20stateless,of%20the%20same%20allocator%20type.
// To check the type

// https://medium.com/@terselich/1-a-guide-to-implement-a-simple-c-stl-allocator-705ede6b60e4

// https://channgo2203.github.io/allocator/

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
	explicit Vector() : _array(NULL) {}
	
	explicit Vector (size_t n, const T &val = Allocator::value_type()) : _size(n)
	{
		this->_array = this->_alloc.allocate(n);
		for (size_t i = 0; i < n; i++)
			this->_array[i] = val;
	}

	/* ----- Accessors ----- */

	T	*getArray() const
	{
		return this->_array;
	}

	/* ----- Destructors ----- */
	
	~Vector()
	{
		this->_alloc.deallocate(this->_array, this->_size);
	}

private:
	T *_array;
	size_t _size;

	Allocator _alloc;
};

}
