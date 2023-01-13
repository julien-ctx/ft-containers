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

private:
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

	bidirectional_iterator (const bidirectional_iterator &it) : _curr(it._curr) {}

	template<class U>
	bidirectional_iterator (const bidirectional_iterator<U> &it) : _curr(it.operator->()) {}

	~bidirectional_iterator() {}
	/* -------------------------*/

	/* ------ Overloads ------- */

	template <class U>
	bidirectional_iterator &operator=(const bidirectional_iterator<U> &rhs)
	{
		_curr = rhs.operator->();
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

	/* -------------------------*/

};

template<class Iterator1, class Iterator2>
bool operator==(const bidirectional_iterator<Iterator1> &lhs,
	const bidirectional_iterator<Iterator2> &rhs) {return lhs.operator->() == rhs.operator->();}

template<class Iterator1, class Iterator2>
bool operator!=(const bidirectional_iterator<Iterator1> &lhs,
	const bidirectional_iterator<Iterator2> &rhs) {return !operator==(lhs, rhs);}

}
