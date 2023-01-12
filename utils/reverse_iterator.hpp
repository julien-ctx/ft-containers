#pragma once

#include "iterator_traits.hpp"
#include "bidirectional_iterator.hpp"
#include "random_access_iterator.hpp"

namespace ft
{

template<class Iter>
class reverse_iterator
{

private:
	Iter _curr;

public:
	typedef Iter iterator_type;
	typedef typename ft::iterator_traits<Iter>::iterator_category iterator_category;
	typedef typename ft::iterator_traits<Iter>::value_type value_type;
	typedef typename ft::iterator_traits<Iter>::difference_type difference_type;
	typedef typename ft::iterator_traits<Iter>::pointer pointer;
	typedef typename ft::iterator_traits<Iter>::reference reference;

	/* ----- Constructors ----- */
	// Default constructor
	reverse_iterator() {}

	// Initialization constructor from a normal iterator with Iter type.
	// x iterator should point to the element we want the reverse_iterator to start with.
	explicit reverse_iterator(Iter x) : _curr(x) {}

	// Copy constructor from an already existing reverse iterator.
	reverse_iterator (const reverse_iterator &rev_it) : _curr(rev_it.base()) {}

	// Copy constructor from an already existing reverse iterator, but another type. This is useful for const types.
	template<class U>
	reverse_iterator (const reverse_iterator<U> &rev_it) : _curr(rev_it.base()) {}

	// Destructor
	~reverse_iterator() {}
	/* -------------------------*/

	/* ------ Overloads ------- */	
	
	reverse_iterator &operator=(const reverse_iterator &rhs)
	{
		if (this != &rhs)
			_curr = rhs._curr;
		return *this;
	}

	reference operator*() const
	{
		Iter tmp = base() - 1;
		return *tmp;
	}

	pointer operator->() const {return &(operator*());}

	reference operator[](difference_type n) const {return *(base() - n - 1);}

	// Prefix
	reverse_iterator &operator++()
	{
		--_curr;
		return *this;
	}
	// Suffix
	// Returns a copy of the value and increments it later
	reverse_iterator operator++(int)
	{
		reverse_iterator tmp = *this;
		_curr--;
		return tmp;
	}
	// Prefix
	reverse_iterator &operator--()
	{
		++_curr;
		return *this;
	}
	// Suffix
	// Returns a copy of the value and decrements it later
	reverse_iterator operator--(int)
	{
		reverse_iterator tmp = *this;
		_curr++;
		return tmp;
	}

	reverse_iterator operator+(difference_type n) const {return reverse_iterator(base() - n);}

	reverse_iterator operator-(difference_type n) const {return reverse_iterator(base() + n);}

	template<class U>
	friend reverse_iterator<U> operator+(difference_type n, const reverse_iterator<U> &it) {return it + n;}

	template<class U>
	friend reverse_iterator<U> operator-(difference_type n, const reverse_iterator<U> &it) {return it - n;}

	reverse_iterator &operator+=(difference_type n)
	{
		_curr -= n;
		return *this;
	}

	reverse_iterator &operator-=(difference_type n)
	{
		_curr += n;
		return *this;
	}

	template<class Iterator1, class Iterator2>
	friend bool operator==(const reverse_iterator<Iterator1> &lhs,
		const reverse_iterator<Iterator2> &rhs) {return (rhs.base() == lhs.base());}

	template<class Iterator1, class Iterator2>
	friend bool operator!=(const reverse_iterator<Iterator1> &lhs,
		const reverse_iterator<Iterator2> &rhs) {return !operator==(lhs, rhs);}

	template<class Iterator1, class Iterator2>
	friend bool operator>(const reverse_iterator<Iterator1> &lhs,
		const reverse_iterator<Iterator2> &rhs) {return rhs.base() > lhs.base();}
	
	template<class Iterator1, class Iterator2>
	friend bool operator<(const reverse_iterator<Iterator1> &lhs,
		const reverse_iterator<Iterator2> &rhs) {return rhs.base() < lhs.base();}

	template<class Iterator1, class Iterator2>
	friend bool operator>=(const reverse_iterator<Iterator1> &lhs,
		const reverse_iterator<Iterator2> &rhs) {return rhs.base() >= lhs.base();}

	template<class Iterator1, class Iterator2>
	friend bool operator<=(const reverse_iterator<Iterator1> &lhs,
		const reverse_iterator<Iterator2> &rhs) {return rhs.base() <= lhs.base();}

	/* -------------------------*/

	iterator_type base() const {return _curr;}

};

}
