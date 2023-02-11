#pragma once

#include <cstddef>
#include <iostream>
#include <string>

// https://h-deb.clg.qc.ca/Sujets/Divers--cplusplus/Traits.html

/* 
Traits are used to represent correctly data of an iterator.
Thanks to specialization, we can change variables according to the type of the iterator.
*/

namespace ft
{

// A simple implementation to explain the inheritance of iterators.
// For example forward_iterator is also an input_iterator, and so on...
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
	typedef std::ptrdiff_t difference_type;
	typedef ft::random_access_iterator_tag iterator_category;
	typedef T* pointer;
	typedef T& reference;
};

template<class T>
struct iterator_traits<const T*>
{
	typedef T value_type;
	typedef std::ptrdiff_t difference_type;
	typedef ft::random_access_iterator_tag iterator_category;
	typedef const T* pointer;
	typedef const T& reference;
};

}
