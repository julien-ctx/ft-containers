
#pragma once

#include "tools.hpp"
#include "reverse_iterator.hpp"
#include "iterator_traits.hpp"
#include "enable_if.hpp"
#include "bidirectional_iterator.hpp"
#include "is_integral.hpp"
#include "lexicographical_compare.hpp"
#include "pair.hpp"

// https://brilliant.org/wiki/red-black-tree/
// https://www.cs.usfca.edu/~galles/visualization/RedBlack.html

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
	typedef Allocator allocator_type;
	typedef typename allocator_type::reference reference;
	typedef typename allocator_type::const_reference const_reference;
	typedef typename allocator_type::pointer pointer;
	typedef typename allocator_type::const_pointer const_pointer;
	typedef typename ft::bidirectional_iterator<value_type, false> iterator;
	typedef typename ft::bidirectional_iterator<value_type, true> const_iterator;
	typedef typename ft::reverse_iterator<iterator> reverse_iterator;
	typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
	typedef std::ptrdiff_t difference_type;
	typedef std::size_t size_type;
	typedef ft::Node<value_type> Node;
	
	class value_compare : public std::binary_function<value_type, value_type, bool>
	{
		friend class map;
	protected:
		Compare comp;
		value_compare (Compare c) : comp(c) {}
	public:
		typedef bool result_type;
		typedef value_type first_argument_type;
		typedef value_type second_argument_type;
		bool operator() (const value_type& x, const value_type& y) const {return comp(x.first, y.first);}
	};

private:
 
	// Template rebind allows to use the given allocator with another type
	// Allocator::template is necessary because rebind is a template inside std::allocator class
	typedef typename Allocator::template rebind<Node>::other NodeAllocator;

	Node *_root;
	Node *_sentinel;
	size_type _size;
	Compare _comp;
	NodeAllocator _alloc;	

	/* ----- Red Black Tree ----- */	
	// Rotation of elements to maintain the tree's order.
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
			_root = sibiling;
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

	// Change colors to maintain RBT properties.
	void rebalance(Node *node)
	{
		while (node != _root && node->parent->color == RED_NODE)
		{
			if (node->parent == node->parent->parent->right)
			{
				Node *uncle = node->parent->parent->left;
				if (uncle->color == RED_NODE)
				{
					uncle->color = BLACK_NODE;
					uncle->parent->color = RED_NODE;
					node->parent->color = BLACK_NODE;
					node = node->parent->parent;
				}
				else if (uncle->color == BLACK_NODE)
				{
					if (node == node->parent->left)
					{
						node = node->parent;
						rotate(node, RIGHT_ROT);
					}
					uncle->parent->color = RED_NODE;
					node->parent->color = BLACK_NODE;
					rotate(uncle->parent, LEFT_ROT);
				}
			}
			else
			{
				Node *uncle = node->parent->parent->right;
				if (uncle->color == RED_NODE)
				{
					uncle->color = BLACK_NODE;
					uncle->parent->color = RED_NODE;
					node->parent->color = BLACK_NODE;
					node = node->parent->parent;
				}
				else if (uncle->color == BLACK_NODE)
				{
					if (node == node->parent->right)
					{
						node = node->parent;
						rotate(node, LEFT_ROT);
					}
					uncle->parent->color = RED_NODE;
					node->parent->color = BLACK_NODE;
					rotate(uncle->parent, RIGHT_ROT);
				}
			}
		}
	}

	void deleteAll(Node *node)
	{
		if (node)
		{
			deleteAll(node->left);
			deleteAll(node->right);
			_alloc.destroy(node);
			_alloc.deallocate(node, 1);
		}
	}

	/* -------------------------- */	

public:
	/* ----- Constructors ----- */
	// Default constructor
	explicit map(const key_compare &comp = key_compare(),
	const allocator_type &alloc = allocator_type()) :
	_root(NULL), _size(0), _comp(comp), _alloc(alloc)
	{
		_sentinel = _alloc.allocate(1);
		_alloc.construct(_sentinel, (Node){ft::make_pair(key_type(),
		mapped_type()), NULL, NULL, NULL, UNDEFINED_NODE});
	}

	// Range constructor
	template <class InputIterator>
	map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), 
	const allocator_type &alloc = allocator_type()) : _comp(comp), _alloc(alloc)
	{
		_sentinel = _alloc.allocate(1);
		_alloc.construct(_sentinel, (Node){ft::make_pair(key_type(),
		mapped_type()), NULL, NULL, NULL, UNDEFINED_NODE});
		for (; first != last; first++)
			insert(*first);
	}

	// Copy constructor
	map(const map &x) {*this = x;}

	~map() {deleteAll(_root);}
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

	T &operator[](const key_type &key)
	{
		Node *curr = _root; Node *parent = _root;
		while (curr && key != curr->pair.first)
		{
			parent = curr;
			curr = key < curr->pair.first ? curr->left : curr->right;
		}
		if (!curr)
		{
			_size++;
			Node *node = _alloc.allocate(1);
			_alloc.construct(node, (Node){ft::make_pair(key, mapped_type()),
			NULL, NULL, parent, UNDEFINED_NODE});
			if (key < parent->pair.first)
				parent->left = node;
			else
				parent->right = node;
			rebalance(node);
			return node->pair.second;
		}
		return curr->pair.second;
	}
	/* ---------------------------------*/

	T &at(const Key &key)
	{
		Node *curr = _root;
		while (curr && key != curr->pair.first)
			curr = key < curr->pair.first ? curr->left : curr->right;
		if (!curr)
			throw std::out_of_range("map::at: key not found");
		return curr->pair.second;
	}

	const T &at(const Key &key) const
	{
		Node *curr = _root;
		while (curr && key != curr->pair.first)
			curr = key < curr->pair.first ? curr->left : curr->right;
		if (!curr)
			throw std::out_of_range("map::at: key not found");
		return curr->pair.second;
	}

	ft::pair<iterator, bool> insert(const value_type &value)
	{
		Node *node = NULL;
		if (!_root)
		{
			node = _alloc.allocate(1);
			_alloc.construct(node, (Node){value, NULL, NULL, node, BLACK_NODE});	
			_root = node;
			return ft::make_pair<iterator, bool>(iterator(node), ++_size);
		}
		else
		{
			Node *curr = _root; Node *parent = _root;
			while (curr)
			{
				if (curr->pair.first == value.first)
					return ft::make_pair<iterator, bool>(iterator(curr), false);
				parent = curr;
				curr = value.first < curr->pair.first ? curr->left : curr->right;
			}
			node = _alloc.allocate(1);
			_alloc.construct(node, (Node){value, NULL, NULL, parent, UNDEFINED_NODE});
			if (value.first < parent->pair.first)
				parent->left = node;
			else
				parent->right = node;
			rebalance(node);
		}
		return ft::make_pair<iterator, bool>(iterator(node), ++_size);
	}

	iterator find(const Key &key)
	{
		Node *curr = _root;
		while (curr && key != curr->pair.first)
			curr = key < curr->pair.first ? curr->left : curr->right;
		return curr;
	}

	const_iterator find(const Key &key) const
	{
		Node *curr = _root;
		while (curr && key != curr->pair.first)
			curr = key < curr->pair.first ? curr->left : curr->right;
		return curr;
	}
	
	size_type count(const Key &key) const
	{
		Node *curr = _root;
		while (curr && key != curr->pair.first)
			curr = key < curr->pair.first ? curr->left : curr->right;
		return curr ? 1 : 0;
	}

	allocator_type get_allocator() const {return _alloc;}

	key_compare key_comp() const {return _comp;}

	value_compare value_comp() const {return value_compare(_comp);}

	size_type max_size() const {return _alloc.max_size();}

	size_type size() const {return _size;}

	bool empty() const {return !_size;}

	void clear() 
	{
		deleteAll(_root);
		_size = 0;
		_root = NULL;
	}

	iterator begin()
	{
		Node *curr = _root;
		while (curr->left)
			curr = curr->left;
		return iterator(curr);	
	}

	const_iterator begin() const
	{
		Node *curr = _root;
		while (curr->left)
			curr = curr->left;
		return const_iterator(curr);	
	}

	iterator end()
	{
		Node *curr = _root;
		if (_sentinel->parent)
			return iterator(_sentinel);
		while (curr->right)
			curr = curr->right;
		curr->right = _sentinel;
		_sentinel->parent = curr;	
		return iterator(_sentinel);	
	}

	const_iterator end() const
	{
		Node *curr = _root;
		if (_sentinel->parent)
			return const_iterator(_sentinel);
		while (curr->right)
			curr = curr->right;
		curr->right = _sentinel;
		_sentinel->parent = curr;	
		return const_iterator(_sentinel);	
	}

	reverse_iterator rbegin()
	{
		return reverse_iterator(iterator(end().getCurr()->parent));
	}

	reverse_iterator rend()
	{
		return reverse_iterator(begin());
	}

};

}
