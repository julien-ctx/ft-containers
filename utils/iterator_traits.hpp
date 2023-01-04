#pragma once

#include <iostream>
#include <string>

// This structure is used to provide a generic way of accessing iterator traits,
// depending on their attributes.

template<class Iter>
struct iterator_traits
{
	typedef typename Iter::value_type value_type;
	typedef typename Iter::difference_type difference_type;
	typedef typename Iter::iterator_category iterator_category;
	typedef typename Iter::pointer pointer;
	typedef typename Iter::reference reference;
};
