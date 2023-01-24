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

// https://brilliant.org/wiki/red-black-tree/

/*
Properties:
 * The black height of the red-black tree is the number of black nodes on a path
 from the root node to a leaf node. Leaf nodes are also counted as black nodes.
 So, a red-black tree of height h has black height >= h/2.
 * Height of a red-black tree with n nodes is h<= 2 log2(n + 1).
 * All leaves (NIL) are black.
 * The black depth of a node is defined as the number of black nodes from the
 root to that node i.e the number of black ancestors.
 * Every red-black tree is a special case of a binary tree.
 * If a node is red, then its parent is black. A red node cannot have a red parent or red child)
 * An inserted node is always red
*/

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
	typedef struct Node
	{
		value_type pair;
		Node *root;
		Node *left;
		Node *right;
		bool color;
	} Node;

	// Template rebind allows to use the given allocator with another type
	// Allocator::template is necessary because rebind is a template inside std::allocator class
	typedef typename Allocator::template rebind<Node>::other NodeAllocator;

	Node *_root;
	Node *_sentinel;
	size_type _size;
	Compare _comp;
	NodeAllocator _alloc;

public:
	/* ----- Constructors ----- */
	// Default constructor
	explicit map(const key_compare &comp = key_compare(),
	const allocator_type &alloc = allocator_type()) :
	_root(NULL), _sentinel(NULL), _size(0), _comp(comp), _alloc(alloc)
	{

	}

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

	T &at(const Key &key)
	{
		(void)key;
		return _root->pair.second;
	}

	const T &at(const Key &key) const
	{
		(void)key;
		return _root->pair.second;
	}

	void /* ft::pair<iterator, bool> */ insert(const value_type &value)
	{
		Node *node = _alloc.allocate(1);
		// bool inserted = false;
		if (!_root)
		{
			_alloc.construct(node, (Node){value, NULL, NULL, NULL, BLACK_NODE});	
			_root = node;
		}
	}

	iterator find(const Key &key)
	{
		Node *curr = _root;
		for (Node *curr = _root; curr && key != curr->pair;)
			curr = key < curr->pair.first ? curr->left : curr->right;
		return curr;
	}

	const_iterator find(const Key &key) const
	{
		Node *curr = _root;
		for (Node *curr = _root; curr && key != curr->pair;)
			curr = key < curr->pair.first ? curr->left : curr->right;
		return curr;
	}

};

}
