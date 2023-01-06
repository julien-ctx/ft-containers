#pragma once

#include "iterator_traits.hpp"

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

	/* ----- Constructors ----- */
	// Default constructor
	reverse_iterator() {}

	// Initialization constructor from a normal iterator with Iter type.
	explicit reverse_iterator(Iter x) : _curr(x) {}

	// Copy constructor from an already existing reverse iterator.
	template <class Iter>
	reverse_iterator (const reverse_iterator<Iter> &rev_it) : _curr(rev_it._curr) {}

};

}
