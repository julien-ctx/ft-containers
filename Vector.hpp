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

public:
	typedef T value_type;
	typedef Allocator allocator_type;
	typedef typename Allocator::reference reference;
	typedef typename Allocator::const_reference const_reference;
	typedef typename Allocator::pointer pointer;
	typedef typename Allocator::const_pointer const_pointer;
	// The following two typedefs need to be edited are replaced by my implementation
	typedef typename std::random_access_iterator<value_type> iterator;
	typedef typename std::random_access_iterator<const value_type> const_iterator;
	typedef typename ft::reverse_iterator<iterator> reverse_iterator;
	typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;

	/* ----- Constructors ----- */
	// Default constructor
	explicit vector (const allocator_type &alloc = allocator_type()) {}

	// Fill constructor
	explicit vector (size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) {}

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

	/* ------ Overloads ------- */	

	/* -------------------------*/

};

}
