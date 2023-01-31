#pragma once

#include "pair.hpp"

namespace ft
{

template <class T1, class T2>
struct pair
{
	typedef T1 first_type;
	typedef T2 second_type;

	first_type first;
	second_type second;

	/* ----- Constructors ----- */
	// Default constructor
	pair() {}

	// Copy constructor
	template<class U, class V>
	pair(const pair<U, V> &pr) : first(pr.first), second(pr.second) {}

	// Initialization constructor
	pair(const first_type &a, const second_type &b) : first(a), second(b) {}
	/* -------------------------*/

	/* ------ Members Overloads ------- */
	pair &operator=(const pair &pr)
	{
		first = pr.first;
		second = pr.second;
		return *this;
	}
	/* ---------------------------------*/

};

/* ---- Non Members Overloads ----- */
template<class T1, class T2>
bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
{return lhs.first == rhs.first && lhs.second == rhs.second;}

template<class T1, class T2>
bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
{return !(lhs == rhs);}

template<class T1, class T2>
bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
{return lhs.first == rhs.first ? lhs.second < rhs.second : lhs.first < rhs.first;}

template<class T1, class T2>
bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
{return rhs < lhs;}

template<class T1, class T2>
bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
{return !(lhs > rhs);}

template<class T1, class T2>
bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
{return !(lhs < rhs);}
/* ---------------------------------*/

template<class T1, class T2>
ft::pair<T1, T2> make_pair(T1 x, T2 y)
{return ft::pair<T1, T2>(x, y);}

}
