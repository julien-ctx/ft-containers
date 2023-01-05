#pragma once

#include <cstddef>
#include <iostream>
#include <string>

// This structure is used to provide a generic way of accessing iterator traits,
// depending on their attributes.

namespace ft
{

// A simple implementation to explain the inheritance of iterators.
// For example forward_iterator is also an input_iterator.
struct input_iterator_tag  {};
struct output_iterator_tag {};
struct forward_iterator_tag       : public input_iterator_tag         {};
struct bidirectional_iterator_tag : public forward_iterator_tag       {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};

template<class Iter>
struct iterator_traits
{
	typedef typename Iter::value_type value_type;
	typedef typename Iter::difference_type difference_type;
	typedef typename Iter::iterator_category iterator_category;
	typedef typename Iter::pointer pointer;
	typedef typename Iter::reference reference;
};

template<class T>
struct iterator_traits<T*>
{
	typedef T value_type;
	typedef ptrdiff_t difference_type;
	typedef ft::random_access_iterator_tag iterator_category;
	typedef T* pointer;
	typedef T& reference;
};

template<class T>
struct iterator_traits<const T*>
{
	typedef T value_type;
	typedef ptrdiff_t difference_type;
	typedef ft::random_access_iterator_tag iterator_category;
	typedef const T* pointer;
	typedef const T& reference;
};

}
