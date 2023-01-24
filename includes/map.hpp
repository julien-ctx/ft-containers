
#pragma once

#include "tools.hpp"
#include "reverse_iterator.hpp"
#include "iterator_traits.hpp"
#include "enable_if.hpp"
#include "bidirectional_iterator.hpp"
#include "is_integral.hpp"
#include "lexicographical_compare.hpp"
#include "pair.hpp"

#define RED_NODE 0
#define BLACK_NODE 1
#define UNDEFINED_NODE 2
#define LEFT_ROT 0
#define RIGHT_ROT 1

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
		Node *parent;
		char color;
	} Node;

	// Template rebind allows to use the given allocator with another type
	// Allocator::template is necessary because rebind is a template inside std::allocator class
	typedef typename Allocator::template rebind<Node>::other NodeAllocator;

	Node *_origin;
	size_type _size;
	Compare _comp;
	NodeAllocator _alloc;

	void rotate(Node *node, bool rotate)
	{
		Node *sibiling = rotate == LEFT_ROT ? node->right : node->left;
		if (rotate == LEFT_ROT)
			node->right = sibiling->left;
		else
			node->left = sibiling->right;
		if (rotate == LEFT_ROT && sibiling->left)
			sibiling->left->parent = node;
		else if (rotate == RIGHT_ROT && sibiling->right)
			sibiling->right->parent = node;
		sibiling->parent = node->parent;
		if (!node->parent)
			_origin = sibiling;
		else
		{
			if (rotate == LEFT_ROT)
			{
				if (node == node->parent->left)
					node->parent->left = sibiling;
				else
					node->parent->right = sibiling;
			}
			else
			{
				if (node == node->parent->right)
					node->parent->right = sibiling;
				else
					node->parent->left = sibiling;
			}
		}
		if (rotate == LEFT_ROT)
			sibiling->left = node;
		else
			sibiling->right = node;
		node->parent = sibiling;
	}

	void rebalance(Node *node)
	{
		while (node != _origin && node->parent.color == RED_NODE)
		{
			if (node->parent == node->parent->parent.right)
			{
				Node *uncle = node->parent->parent.left;
				if (uncle->color == RED_NODE)
				{
					uncle->color = BLACK_NODE;
					uncle->parent.color = RED_NODE;
					node->parent.color = BLACK_NODE;
					node = node->parent->parent;
				}
				else if (uncle->color == BLACK_NODE)
				{
					if (node == node->parent.left)
					{
						node = node->parent;
						rotate(node, RIGHT_ROT);
					}
					uncle->parent.color = RED_NODE;
					node->parent.color = BLACK_NODE;
					rotate(uncle->parent, LEFT_ROT);
				}
			}
			else
			{
				Node *uncle = node->parent->parent.right;
				if (uncle->color == RED_NODE)
				{
					uncle->color = BLACK_NODE;
					uncle->parent.color = RED_NODE;
					node->parent.color = BLACK_NODE;
					node = node->parent->parent;
				}
				else if (uncle->color == BLACK_NODE)
				{
					if (node == node->parent.right)
					{
						node = node->parent;
						rotate(node, LEFT_ROT);
					}
					uncle->parent.color = RED_NODE;
					node->parent.color = BLACK_NODE;
					rotate(uncle->parent, RIGHT_ROT);
				}
			}
		}
	}

public:
	/* ----- Constructors ----- */
	// Default constructor
	explicit map(const key_compare &comp = key_compare(),
	const allocator_type &alloc = allocator_type()) :
	_origin(NULL), _size(0), _comp(comp), _alloc(alloc) {}

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
		_origin = x._origin;
		_size = x._size;
		_comp = x._comp;
		return *this;
	}

	T &operator[](const key_type &key)
	{
		Node *curr = _origin; Node *parent = _origin;
		while (curr && key != curr->pair.first)
		{
			parent = curr;
			curr = key < curr->pair.first ? curr->left : curr->right;
		}
		if (!curr)
		{
			_size++;
			Node *node = _alloc.allocate(1);
			_alloc.construct(node, (Node){ft::make_pair(key, mapped_type(),
				_origin, NULL, NULL, parent, UNDEFINED_NODE)});
			if (key < parent->pair.first)
				parent->left = node;
			else
				parent->right = node;
			rebalance(node);
			return node->pair.first;
		}
		return curr->pair.second;
	}
	/* ---------------------------------*/

	T &at(const Key &key)
	{
		Node *curr = _origin;
		while (curr && key != curr->pair.first)
			curr = key < curr->pair.first ? curr->left : curr->right;
		if (!curr)
			throw std::out_of_range("map::at: key not found");
		return curr->pair.second;
	}

	const T &at(const Key &key) const
	{
		Node *curr = _origin;
		while (curr && key != curr->pair.first)
			curr = key < curr->pair.first ? curr->left : curr->right;
		if (!curr)
			throw std::out_of_range("map::at: key not found");
		return curr->pair.second;
	}

	void /* ft::pair<iterator, bool> */ insert(const value_type &value)
	{
		Node *node = _alloc.allocate(1);
		bool inserted = false;
		if (!_origin)
		{
			_alloc.construct(node, (Node){value, node, NULL, NULL, node, BLACK_NODE});	
			_origin = node;
		}
		else
		{
			Node *curr = _origin; Node *parent = _origin;
			while (curr)
			{
				parent = curr;
				curr = value.first < curr->pair.first ? curr->left : curr->right;
			}
			_alloc.construct(node, (Node){value, _origin, NULL, NULL, parent, UNDEFINED_NODE});
			if (value.first < parent->pair.first)
				parent->left = node;
			else
				parent->right = node;
			rebalance(node);
		}
		if (!inserted)
		{
			_alloc.deallocate(node, 1);
			// Need to return correct boolean here
		}
		else
			_size++;
	}

	iterator find(const Key &key)
	{
		Node *curr = _origin;
		while (curr && key != curr->pair.first)
			curr = key < curr->pair.first ? curr->left : curr->right;
		return curr;
	}

	const_iterator find(const Key &key) const
	{
		Node *curr = _origin;
		while (curr && key != curr->pair.first)
			curr = key < curr->pair.first ? curr->left : curr->right;
		return curr;
	}

};

}
