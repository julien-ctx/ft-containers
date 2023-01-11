#pragma once

#include "bidirectional_iterator.hpp"
#include "iterator_traits.hpp"

namespace ft
{

template <class T>
class random_access_iterator : public ft::bidirectional_iterator<T>
{

public:
	
	typedef ft::random_access_iterator_tag iterator_category;

};	

}
