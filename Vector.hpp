#pragma once

// https://en.cppreference.com/w/cpp/memory/allocator#:~:text=The%20default%20allocator%20is%20stateless,of%20the%20same%20allocator%20type.
// To check the type

// https://medium.com/@terselich/1-a-guide-to-implement-a-simple-c-stl-allocator-705ede6b60e4

// https://channgo2203.github.io/allocator/

#include <string>
#include <iostream>
#include <limits.h>
#include <stdexcept>

namespace ft
{
	
template < class T, class Allocator = std::allocator<T> >
class Vector
{
public:
	typedef typename Allocator::size_type size_t;

	/* ----- Constructors ----- */

	explicit Vector() : _array(NULL) {}
	
	explicit Vector (size_t n, const T &val = Allocator::value_type()) : _size(n), _capacity(n)
	{
		_array = _alloc.allocate(n);
		for (size_t i = 0; i < n; i++)
			_array[i] = val;
	}

	/* ----- Accessors ----- */

	T	*getArray() const {return _array;}
	size_t size() const {return _size;}
	size_t capacity() const {return _capacity;}
	size_t max_size() const {return _alloc.max_size();}

	/* ----- Destructors ----- */
	
	~Vector()
	{
		_alloc.deallocate(_array, _size);
	}

private:
	T *_array;
	size_t _size;
	size_t _capacity;

	Allocator _alloc;
};

}
