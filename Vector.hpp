#pragma once

#include <string>
#include <iostream>
#include <limits.h>
#include <stdexcept>
#include <type_traits>
#include <unistd.h>

#include "tools.hpp"
#include "utils/reverse_iterator.hpp"
#include "utils/iterator_traits.hpp"
#include "utils/enable_if.hpp"

namespace ft
{
	
template < class T, class Allocator = std::allocator<T> >
class vector
{

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
	typedef std::size_t size_type;
	typedef std::ptrdiff_t difference_type;

private:
	T* _array;
	Allocator _alloc;
	size_type _size;
	size_type _capacity;

public:

	/* ----- Constructors ----- */
	// Default constructor
	explicit vector (const allocator_type &alloc = allocator_type()) :
		_array(NULL), _alloc(alloc), _size(0), _capacity(0) {}

	// Fill constructor
	explicit vector (size_type n, const value_type &val = value_type(),
		const allocator_type &alloc = allocator_type()) : _alloc(alloc), _size(n), _capacity(n)
	{
		_array = _alloc.allocate(n);
		for (size_type i = 0; i < n; i++)
			_alloc.construct(&_array[i], val);
	}

	// Range constructor
	template<class InputIterator>
	vector (InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type()) : _alloc(alloc)
	{
		size_type dist = ft::distance<InputIterator>(first, last);
		_array = _alloc.allocate(dist);
		for (size_type i = 0; i < dist; first++, i++)
			_alloc.construct(&_array[i], *first);
		_size = dist;
		_capacity = dist;
	}

	// Copy constructor
	vector (const vector &x) : _alloc(Allocator()), _size(x.size()), _capacity(_size)
	{
		_array = _alloc.allocate(_size);
		for (size_type i = 0; i < _size; i++)
			_alloc.construct(&_array[i], x[i]);
	}

	// Destructor
	~vector()
	{
		for (size_type i = 0; i < _size; i++)
			_alloc.destroy(&_array[i]);
		_alloc.deallocate(_array, _capacity);
	}
	/* -------------------------*/

	/* ------ Overloads ------- */

	reference operator[](size_type n) const {return _array[n];}

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

	reference front() {return operator[](0);}

	const_reference front() const {return operator[](0);}

	reference back() {return operator[](_size - 1);}

	const_reference back() const {return operator[](_size - 1);}

	size_type size() const {return _size;}

	size_type max_size() const {return _alloc.max_size();}

	size_type capacity() const {return _capacity;}

};

}

