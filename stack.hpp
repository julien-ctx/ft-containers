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
	explicit stack(const Container &cont = Container()) : c(cont) {}
	/* -------------------------*/

	bool empty() const {return c.empty();}
	
	size_type size() const {return c.size();}

	value_type &top() {return c.back();}
	
	const value_type &top() const {return c.back();}

	void push (const value_type &val) {return c.push_back(val);}

	void pop() {return c.pop_back();}


	/* ------ Members Overloads ------- */
	stack &operator=(const stack &other) {return c.operator=(other);}
	/* ---------------------------------*/
	
	/* ---- Non Members Overloads ----- */
	friend bool operator==(const stack<T,Container> &lhs, const stack<T,Container> &rhs)
	{return lhs.c == rhs.c;}

	friend bool operator!=(const stack<T,Container> &lhs, const stack<T,Container> &rhs)
	{return lhs.c != rhs.c;}

	friend bool operator<(const stack<T,Container> &lhs, const stack<T,Container> &rhs)
	{return lhs.c < rhs.c;}

	friend bool operator>(const stack<T,Container> &lhs, const stack<T,Container> &rhs)
	{return lhs.c > rhs.c;}

	friend bool operator<=(const stack<T,Container> &lhs, const stack<T,Container> &rhs)
	{return lhs.c <= rhs.c;}

	friend bool operator>=(const stack<T,Container> &lhs, const stack<T,Container> &rhs)
	{return lhs.c >= rhs.c;}
	/* ---------------------------------*/
};

}
