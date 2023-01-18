#pragma once

#include "vector.hpp"

namespace ft
{

template <class T, class Container = ft::vector<T> > class stack
{

public:
	typedef T value_type;
	typedef Container container_type;
	typedef std::size_t size_type;


protected:
	container_type c;

public:
	/* ----- Constructors ----- */
	// Default constructor
	explicit stack(const Container &cont = Container()) {}
	/* -------------------------*/

};

}

