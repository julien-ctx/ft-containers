#pragma once

#include <string>
#include <iostream>
#include <limits.h>
#include <stdexcept>

#include "utils/reverse_iterator.hpp"

namespace ft
{
	
template < class T, class Allocator = std::allocator<T> >
class vector
{

private:
	T* _array;
	Allocator _alloc;
	size_t _size;
	size_t _capacity;

public:
	typedef T value_type;
	typedef Allocator allocator_type;
	typedef typename Allocator::reference reference;
	typedef typename Allocator::const_reference const_reference;
	typedef typename Allocator::pointer pointer;
	typedef typename Allocator::const_pointer const_pointer;
	// The following two typedefs need to be edited are replaced by my implementation
	typedef typename std::iterator<std::random_access_iterator_tag, value_type> iterator;
	typedef typename std::iterator<std::random_access_iterator_tag, const value_type> const_iterator;
	typedef typename ft::reverse_iterator<iterator> reverse_iterator;
	typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;

	/* ----- Constructors ----- */
	// Default constructor
	explicit vector (const allocator_type &alloc = allocator_type())
	{
		_array = NULL;
		_alloc = alloc;
		_size = 0;
		_capacity = 0;
	}

	// Fill constructor
	explicit vector (size_type n, const value_type &val = value_type(),
		const allocator_type &alloc = allocator_type())
	{
		_alloc = alloc;
		_array = _alloc.allocate(n);
		for (size_t i = 0; i < n; i++)
			_alloc.construct(&_array[i], val);
	}

	// Range constructor
	template <class InputIterator>
	vector (InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type()) {}

	// Copy constructor
	vector (const vector &x) {}

	// Destructor
	~vector()
	{

	}
	/* -------------------------*/

	/* ------ Accessors ------- */

	reference operator[](size_t n) const {return _array[n];}

	/* -------------------------*/

	/* ------ Overloads ------- */	

	/* -------------------------*/

};

}
