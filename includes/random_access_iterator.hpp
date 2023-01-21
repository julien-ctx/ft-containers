#pragma once

#include <cstdlib>
#include "iterator_traits.hpp"

namespace ft
{

template <class T>
class random_access_iterator
{

private:
	T *_curr;

public:
	
	typedef T value_type;
	typedef T& reference;
	typedef T* pointer;
	typedef std::ptrdiff_t difference_type;
	typedef ft::random_access_iterator_tag iterator_category;

	/* ----- Constructors ----- */
	random_access_iterator() {}

	random_access_iterator(T *ptr) : _curr(ptr) {}

	random_access_iterator (const random_access_iterator &it) : _curr(it.operator->()) {}

	template<class U>
	random_access_iterator (const random_access_iterator<U> &it) : _curr(it.operator->()) {}

	~random_access_iterator() {}
	/* -------------------------*/

	/* ------ Overloads ------- */

	template <class U>
	random_access_iterator &operator=(const random_access_iterator<U> &rhs)
	{
		_curr = rhs.operator->();
		return *this;
	}

	reference operator*() const {return *_curr;}

	pointer operator->() const {return &(operator*());}

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

	random_access_iterator &operator++()
	{
		++this->_curr;
		return *this;
	}
	// Suffix
	// Returns a copy of the value and increments it later
	random_access_iterator operator++(int)
	{
		random_access_iterator tmp = *this;
		this->_curr++;
		return tmp;
	}

	random_access_iterator &operator--()
	{
		--this->_curr;
		return *this;
	}
	// Suffix
	// Returns a copy of the value and decrements it later
	random_access_iterator operator--(int)
	{
		random_access_iterator tmp = *this;
		this->_curr--;
		return tmp;
	}

	random_access_iterator operator+(difference_type n) {return random_access_iterator(_curr + n);}
	
	random_access_iterator operator-(difference_type n) {return random_access_iterator(_curr - n);}

	// difference_type operator-(random_access_iterator &rhs) {return this->_curr - rhs.operator->();}

	reference operator[](difference_type n) const {return this->_curr[n];}

};	

typedef std::ptrdiff_t difference_type;

template<class Iterator1, class Iterator2>
bool operator==(const random_access_iterator<Iterator1> &lhs,
	const random_access_iterator<Iterator2> &rhs) {return lhs.operator->() == rhs.operator->();}

template<class Iterator1, class Iterator2>
bool operator!=(const random_access_iterator<Iterator1> &lhs,
	const random_access_iterator<Iterator2> &rhs) {return !operator==(lhs, rhs);}

template<class Iter>
random_access_iterator<Iter> operator+(difference_type n, const random_access_iterator<Iter> &rhs)
{return random_access_iterator<Iter>(rhs.operator->() + n);}

template<class Iter>
random_access_iterator<Iter> operator-(difference_type n, const random_access_iterator<Iter> &rhs)
{return random_access_iterator<Iter>(rhs.operator->() - n);}

template<class Iterator1, class Iterator2>
difference_type operator-(const random_access_iterator<Iterator1> &lhs, const random_access_iterator<Iterator2> &rhs)
{return lhs.operator->() - rhs.operator->();}

template<class Iterator1, class Iterator2>
bool operator>(const random_access_iterator<Iterator1> &lhs,
	const random_access_iterator<Iterator2> &rhs) {return lhs.operator->() > rhs.operator->();}

template<class Iterator1, class Iterator2>
bool operator<(const random_access_iterator<Iterator1> &lhs,
	const random_access_iterator<Iterator2> &rhs) {return lhs.operator->() < rhs.operator->();}

template<class Iterator1, class Iterator2>
bool operator>=(const random_access_iterator<Iterator1> &lhs,
	const random_access_iterator<Iterator2> &rhs) {return lhs.operator->() >= rhs.operator->();}

template<class Iterator1, class Iterator2>
bool operator<=(const random_access_iterator<Iterator1> &lhs,
	const random_access_iterator<Iterator2> &rhs) {return lhs.operator->() <= rhs.operator->();}

}
