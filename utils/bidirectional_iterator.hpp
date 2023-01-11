#pragma once

#include <iterator>
#include <iostream>
#include "iterator_traits.hpp"

// https://cplusplus.com/reference/iterator/BidirectionalIterator/

namespace ft
{

template <class T>
class bidirectional_iterator
{

protected:
	T *_curr;

public:

	typedef T value_type;
	typedef T& reference;
	typedef T* pointer;
	typedef std::ptrdiff_t difference_type;
	typedef ft::bidirectional_iterator_tag iterator_category;
	
	/* ----- Constructors ----- */
	bidirectional_iterator() {}

	bidirectional_iterator(T *ptr) : _curr(ptr) {}

	bidirectional_iterator (const bidirectional_iterator<T> &it) : _curr(it._curr) {}

	~bidirectional_iterator() {}
	/* -------------------------*/

	/* ------ Overloads ------- */


	bidirectional_iterator &operator=(const bidirectional_iterator<T> &rhs)
	{
		if (this != &rhs)
			_curr = rhs._curr;
		return *this;
	}

	reference operator*() const {return *_curr;}

	pointer operator->() const {return &(operator*());}

	// Prefix
	bidirectional_iterator &operator++()
	{
		++_curr;
		return *this;
	}
	// Suffix
	// Returns a copy of the value and increments it later
	bidirectional_iterator operator++(int)
	{
		bidirectional_iterator tmp = *this;
		_curr++;
		return tmp;
	}
	
	bidirectional_iterator &operator--()
	{
		--_curr;
		return *this;
	}
	// Suffix
	// Returns a copy of the value and decrements it later
	bidirectional_iterator operator--(int)
	{
		bidirectional_iterator tmp = *this;
		_curr--;
		return tmp;
	}

	friend bool operator==(const bidirectional_iterator<T> &lhs,
		const bidirectional_iterator<T> &rhs) {return lhs._curr == rhs._curr;}

	friend bool operator!=(const bidirectional_iterator<T> &lhs,
		const bidirectional_iterator<T> &rhs) {return !operator==(lhs, rhs);}
	
	/* -------------------------*/
};

}
