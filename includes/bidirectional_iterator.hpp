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

public:

	typedef T value_type;
	typedef T& reference;
	typedef T* pointer;
	typedef std::ptrdiff_t difference_type;
	typedef ft::bidirectional_iterator_tag iterator_category;
	typedef ft::Node<value_type> Node;

private:
	Node *_curr;

public:

	/* ----- Constructors ----- */
	bidirectional_iterator() {}

	bidirectional_iterator(Node *ptr) : _curr(ptr) {}
	
	bidirectional_iterator (const bidirectional_iterator &it) : _curr(it._curr) {}

	template<class U>
	bidirectional_iterator (const bidirectional_iterator &it) : _curr(it.getCurr()) {}

	~bidirectional_iterator() {}
	/* -------------------------*/

	/* ------ Overloads ------- */

	template <class U>
	bidirectional_iterator &operator=(const bidirectional_iterator<U> &rhs)
	{
		_curr = rhs.operator->();
		return *this;
	}

	reference operator*() const {return _curr->pair;}

	pointer operator->() const {return &(operator*());}

	// Prefix
	bidirectional_iterator &operator++()
	{
		if (_curr->right)
		{
			_curr = _curr->right;
			while (_curr->left)
				_curr = _curr->left;
		}
		else
		{
			while (_curr->parent && _curr == _curr->parent->right)
				_curr = _curr->parent;
			_curr = _curr->parent;
		}
		return *this;
	}
	// Suffix
	// Returns a copy of the value and increments it later
	bidirectional_iterator operator++(int)
	{
		bidirectional_iterator tmp = *this;
		if (_curr->right)
		{
			_curr = _curr->right;
			while (_curr->left)
				_curr = _curr->left;
		}
		else
		{
			while (_curr->parent && _curr == _curr->parent->right)
				_curr = _curr->parent;
			_curr = _curr->parent;
		}
		return tmp;
	}

	bidirectional_iterator &operator--()
	{
		if (_curr->left)
		{
			_curr = _curr->left;
			while (_curr->right)
				_curr = _curr->right;
		}
		else
		{
			while (_curr->parent && _curr == _curr->parent->left)
				_curr = _curr->parent;
			_curr = _curr->parent;
		}
		return *this;
	}
	// Suffix
	// Returns a copy of the value and decrements it later
	bidirectional_iterator operator--(int)
	{
		bidirectional_iterator tmp = *this;
		if (_curr->left)
		{
			_curr = _curr->left;
			while (_curr->right)
				_curr = _curr->right;
		}
		else
		{
			while (_curr->parent && _curr == _curr->parent->left)
				_curr = _curr->parent;
			_curr = _curr->parent;
		}
		return tmp;
	}

	Node *getCurr() const {return _curr;}

	/* -------------------------*/

};

template<class Iterator1, class Iterator2>
bool operator==(const bidirectional_iterator<Iterator1> &lhs,
	const bidirectional_iterator<Iterator2> &rhs) {return lhs.operator->() == rhs.operator->();}

template<class Iterator1, class Iterator2>
bool operator!=(const bidirectional_iterator<Iterator1> &lhs,
	const bidirectional_iterator<Iterator2> &rhs) {return !operator==(lhs, rhs);}

}
