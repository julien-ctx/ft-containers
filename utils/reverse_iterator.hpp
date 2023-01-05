#pragma once

#include "iterator_traits.hpp"

// Reverse iterator is used a type alias, for example std::vector<int>::reverse_iterator vec

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
	reverse_iterator() {}

	explicit reverse_iterator(Iter x) {}

	template <class Iter>
	reverse_iterator (const reverse_iterator<Iter> &rev_it) {}

};

}
