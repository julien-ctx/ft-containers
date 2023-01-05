#pragma once

#include <iostream>
#include <string>

// Reverse iterator is used a type alias, for example std::vector<int>::reverse_iterator vec

template<class Iter>
class reverse_iterator
{
private:
	Iter iter;
public:
	typedef typename Iter iterator_type;

	/* ----- Constructors ----- */
	reverse_iterator() {}
};

