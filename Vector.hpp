#pragma once

#include <string>
#include <iostream>
#include <limits.h>
#include <stdexcept>
#include <type_traits>

#include "utils/reverse_iterator.hpp"
#include "utils/iterator_traits.hpp"
#include "tools.hpp"

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
		_capacity = n;
		_size = n;
	}

	// Range constructor
	template<class InputIterator>
	vector (InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type())
	{
		_alloc = alloc;
		size_t dist = ft::distance<InputIterator>(first, last);
		_array = _alloc.allocate(dist);
		for (size_t i = 0; i < dist; first++, i++)
			_alloc.construct(&_array[i], *first);
		_size = dist;
		_capacity = dist;
	}

	// Copy constructor
	vector (const vector &x)
	{

	}

	// Destructor
	~vector()
	{
		for (size_t i = 0; i < _size; i++)
			_alloc.destroy(&_array[i]);
		_alloc.deallocate(_array, _capacity);
	}
	/* -------------------------*/

	/* ------ Overloads ------- */

	reference operator[](size_t n) const {return _array[n];}

	/* -------------------------*/

	reference at(size_type n)
	{
		if (n >= _size)
			throw std::out_of_range("Index out of range");
		else
			return operator[](n);
	}
	
	const_reference at(size_type n) const
	{
		if (n >= _size)
			throw std::out_of_range("Index out of range");
		else
			return operator[](n);
	}

	size_type size() const {return _size;}

	size_type capacity() const {return _capacity;}


};

}
