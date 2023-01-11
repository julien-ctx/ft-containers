#pragma once

#include "bidirectional_iterator.hpp"
#include "iterator_traits.hpp"

namespace ft
{

template <class T>
class random_access_iterator : public ft::bidirectional_iterator<T>
{

public:
	
	typedef typename ft::bidirectional_iterator<T>::value_type value_type;
	typedef typename ft::bidirectional_iterator<T>::reference reference;
	typedef typename ft::bidirectional_iterator<T>::pointer pointer;
	typedef typename ft::bidirectional_iterator<T>::difference_type difference_type;
	typedef ft::random_access_iterator_tag iterator_category;


	/* ----- Constructors ----- */
	random_access_iterator() {}

	random_access_iterator(T *ptr) {this->_curr = ptr;}

	random_access_iterator (const random_access_iterator<T> &it) {this->_curr = it._curr;}

	~random_access_iterator() {}
	/* -------------------------*/

	random_access_iterator operator+=(difference_type n)
	{
		this->_curr += n;
		return *this;
	}

	random_access_iterator operator-=(difference_type n)
	{
		this->_curr -= n;
		return *this;
	}

	reference operator[](difference_type n) const {return this->_curr[n];}

};	

}
