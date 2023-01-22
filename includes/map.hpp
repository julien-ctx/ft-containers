#pragma once

#include "tools.hpp"
#include "reverse_iterator.hpp"
#include "iterator_traits.hpp"
#include "enable_if.hpp"
#include "bidirectional_iterator.hpp"
#include "is_integral.hpp"
#include "lexicographical_compare.hpp"
#include "pair.hpp"

#define RED_NODE 42
#define BLACK_NODE 43

namespace ft
{

template< class Key, class T, class Compare = std::less<Key>, 
class Allocator = std::allocator< ft::pair<const Key, T> > >
class map
{
public:
	typedef ft::pair<const Key, T> value_type;
	typedef Key key_type;
	typedef T mapped_type;
	typedef Compare key_compare;
	// typedef value_compare ???
	typedef Allocator allocator_type;
	typedef typename allocator_type::reference reference;
	typedef typename allocator_type::const_reference const_reference;
	typedef typename allocator_type::pointer pointer;
	typedef typename allocator_type::const_pointer const_pointer;
	typedef typename ft::bidirectional_iterator<value_type> iterator;
	typedef typename ft::bidirectional_iterator<const value_type> const_iterator;
	typedef typename ft::reverse_iterator<iterator> reverse_iterator;
	typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
	typedef std::ptrdiff_t difference_type;
	typedef std::size_t size_type;

private:
	struct Node
	{
		value_type pair;
		Node *root;
		Node *left;
		Node *right;
		bool color;
	};

	Node *_root;
	Node *_sentinel;
	size_type _size;
	Compare _comp;
	Allocator _alloc;

public:
	/* ----- Constructors ----- */
	// Default constructor
	explicit map(const key_compare &comp = key_compare(),
	const allocator_type &alloc = allocator_type()) :
	_root(NULL), _sentinel(NULL), _size(0), _comp(comp), _alloc(alloc) {}

	// Range constructor
	template <class InputIterator>
	map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), 
	const allocator_type &alloc = allocator_type()) : _comp(comp), _alloc(alloc)
	{
		(void)first;
		(void)last;
		// Need to use insert in a loop
	}

	// Copy constructor
	map(const map &x) {*this = x;}
	/* -------------------------*/

	/* ------ Members Overloads ------- */
	map &operator=(const map &x)
	{
		_root = x._root;
		_sentinel = x._sentinel;
		_size = x._size;
		_comp = x._comp;
		return *this;
	}

	/* ---------------------------------*/
};

}
