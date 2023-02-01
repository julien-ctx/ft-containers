#pragma once

#include <iterator>
#include <iostream>
#include "iterator_traits.hpp"

// https://cplusplus.com/reference/iterator/BidirectionalIterator/

namespace ft
{

template<bool B, class NoConst, class IsConst>
struct GetType {};

template <class NoConst, class IsConst>
struct GetType <false, NoConst, IsConst> {typedef NoConst type;};

template <class NoConst, class IsConst>
struct GetType <true, NoConst, IsConst> {typedef IsConst type;};

template <class T, bool cst>
class bidirectional_iterator
{

public:

	typedef T value_type;
	typedef typename GetType<cst, T*, const T*>::type pointer;
	typedef typename GetType<cst, T&, const T&>::type reference;
	typedef std::ptrdiff_t difference_type;
	typedef ft::bidirectional_iterator_tag iterator_category;
	typedef ft::Node<value_type> Node;

private:
	Node *_curr;
	Node *_min;
	Node *_max;

public:

	operator bidirectional_iterator<T, true>() {return bidirectional_iterator<T, true>(_curr, _min, _max);}
	
	/* ----- Constructors ----- */
	bidirectional_iterator() : _curr(NULL), _min(NULL), _max(NULL) {}

	bidirectional_iterator(Node *ptr, Node *min, Node *max) :
	_curr(ptr), _min(min), _max(max) {}
	
	bidirectional_iterator (const bidirectional_iterator &it) :
	_curr(it._curr), _min(it._min), _max(it._max) {}

	~bidirectional_iterator() {}
	/* -------------------------*/

	/* ------ Overloads ------- */

	template <class U>
	bidirectional_iterator &operator=(const bidirectional_iterator<U, false> &rhs)
	{
		_curr = rhs.operator->();
		return *this;
	}

	reference operator*() const
	{
		return _curr->pair;
	}

	pointer operator->() const {return &(operator*());}

	// Prefix
	bidirectional_iterator &operator++()
	{
		if (_curr == _max)
			_curr = NULL;
		else if (_curr->right)
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
		if (_curr == _max)
			_curr = NULL;
		else if (_curr->right)
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
		if (!_curr)
			_curr = _max;
		else if (_curr->left)
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
		if (!_curr)
			_curr = _max;
		else if (_curr->left)
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
	Node *getMin() const {return _min;}
	Node *getMax() const {return _max;}

	/* -------------------------*/

};

template<class Iterator1, class Iterator2>
bool operator==(const bidirectional_iterator<Iterator1, false> &lhs,
	const bidirectional_iterator<Iterator2, false> &rhs) {return lhs.operator->() == rhs.operator->();}

template<class Iterator1, class Iterator2>
bool operator==(const bidirectional_iterator<Iterator1, true> &lhs,
	const bidirectional_iterator<Iterator2, true> &rhs) {return lhs.operator->() == rhs.operator->();}

template<class Iterator1, class Iterator2>
bool operator!=(const bidirectional_iterator<Iterator1, false> &lhs,
	const bidirectional_iterator<Iterator2, false> &rhs) {return !operator==(lhs, rhs);}

template<class Iterator1, class Iterator2>
bool operator!=(const bidirectional_iterator<Iterator1, true> &lhs,
	const bidirectional_iterator<Iterator2, true> &rhs) {return !operator==(lhs, rhs);}

}
