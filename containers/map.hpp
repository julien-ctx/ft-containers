
#pragma once

#include "../utils/tools.hpp"
#include "../utils/reverse_iterator.hpp"
#include "../utils/iterator_traits.hpp"
#include "../utils/enable_if.hpp"
#include "../utils/bidirectional_iterator.hpp"
#include "../utils/is_integral.hpp"
#include "../utils/lexicographical_compare.hpp"
#include "../utils/pair.hpp"

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
		bool operator() (const value_type &x, const value_type &y) const {return comp(x.first, y.first);}
	};

private:
 
	// Template rebind allows to use the given allocator with another type
	// Allocator::template is necessary because rebind is a template inside std::allocator class
	typedef typename Allocator::template rebind<Node>::other NodeAllocator;

	Node *_root;
	size_type _size;
	Compare _comp;
	NodeAllocator _alloc;	

	Node *_min;
	Node *_max;
	
	/* ----- Red Black Tree ----- */	
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
	
	void setMinMax(key_type key, Node *node)
	{
		if (!_min || _comp(key, _min->pair.first))
			_min = node;
		if (!_max || _comp(_max->pair.first, key))
			_max = node;
	}
	Node *getSubtreeMin(Node *node)
	{
		while (node->left)
			node = node->left;
		return node;
	}

	/*			   Rotate X-Y
	*		  Z					 Z
	*		 /					/
	*		X	    ---->	   Y     
	*		 \				  /
	*		  Y     	     X    
	*/
	void leftRotate(Node *x)
	{
		Node *y = x->right;
		x->right = y->left;
		if (y->left)
			y->left->parent = x;
		y->parent = x->parent;
		if (!x->parent)
			_root = y;
		else if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
		y->left = x;
		x->parent = y;
  	}

	/*			   Rotate Z-X
	*		  Z					 X
	*		 /					/ \
	*		X	    ---->	   /   \
	*	   /				  /     \
	*	  Y     	         Y       Z
	*/
	void rightRotate(Node *x)
	{
		Node *y = x->left;
		x->left = y->right;
		if (y->right)
			y->right->parent = x;
		y->parent = x->parent;
		if (!x->parent)
			_root = y;
		else if (x == x->parent->right)
			x->parent->right = y;
		else
			x->parent->left = y;
		y->right = x;
		x->parent = y;
	}

	// This function looks for the insertion position of value, in the range start to end.
	iterator insertionCheck(iterator start, iterator end, const value_type &value)
	{
		iterator it = start;
		iterator it2 = it == end ? end : ++start;
		for (; it2 != end; it++, it2++)
		{
			if (it->first == value.first)
				return it;
			if (it->first < value.first && it2->first > value.first)
			{
				Node *node = _alloc.allocate(1);
				Node *parent = it.getCurr();
				_alloc.construct(node, (Node){value, NULL, NULL, parent, RED});
				if (_comp(value.first, parent->pair.first))
					parent->left = node;
				else
					parent->right = node;
				setMinMax(value.first, node);
				_size++;
				if (!node->parent) 
				{
					_root = node;
					node->color = BLACK;
					return iterator(node, _min, _max);
				}
				if (node->parent && !node->parent->parent)
					return iterator(node, _min, _max);
				insertRebalance(node);
				return iterator(node, _min, _max);
			}
		}
		return (insert(value)).first;
	}

	/*
	After inserting an element, this function is used to adjust
	the tree so that it keeps its properties:
	- Node colors are modified when they need to be.
	- Right Rotate and Left Rotate reorder the tree correctly.
	*/
	void insertRebalance(Node *node)
	{
		Node *u;
    	while (node->parent->color == RED)
		{
      		if (node->parent == node->parent->parent->right)
			{
       			u = node->parent->parent->left;
        		if (u && u->color == RED)
				{
					u->color = BLACK;
					node->parent->color = BLACK;
					node->parent->parent->color = RED;
					node = node->parent->parent;
        		} 
				else
				{
					if (node == node->parent->left)
					{
						node = node->parent;
						rightRotate(node);
					}
					node->parent->color = BLACK;
					node->parent->parent->color = RED;
					leftRotate(node->parent->parent);
				}
      		}
			else
			{
				u = node->parent->parent->right;
				if (u && u->color == RED)
				{
					u->color = BLACK;
					node->parent->color = BLACK;
					node->parent->parent->color = RED;
					node = node->parent->parent;
				} 
				else
				{
					if (node == node->parent->right)
					{
						node = node->parent;
						leftRotate(node);
					}
					node->parent->color = BLACK;
					node->parent->parent->color = RED;
					rightRotate(node->parent->parent);
				}
			}
			if (node == _root)
				break;
    	}
    	_root->color = BLACK;
  	}

	void eraseReorder(Node *node, key_type key)
	{
		Node *z = NULL; Node *x = NULL; Node *y = NULL;
		while (node)
		{
			if (node->pair.first == key)
				z = node;
			if (node->pair.first <= key)
				node = node->right;
			else
				node = node->left;
		}
		if (!z)
			return;
		y = z;
		bool saved_y_color = y->color;
		if (!z->left)
		{
			x = z->right;
			transplant(z, z->right);
		} 
		else if (!z->right)
		{
			x = z->left;
			transplant(z, z->left);
		}
		else
		{
			y = getSubtreeMin(z->right);
			saved_y_color = y->color;
			x = y->right;
			if (x && y->parent == z)
				x->parent = y;
			else
			{
				transplant(y, y->right);
				y->right = z->right;
				if (y->right)
					y->right->parent = y;
			}
			transplant(z, y);
			y->left = z->left;
			y->left->parent = y;
			y->color = z->color;
		}
		_alloc.destroy(z);
		_alloc.deallocate(z, 1);
		if (saved_y_color == BLACK)
			eraseRebalance(x);
	}

	void transplant(Node *u, Node *v)
	{
		if (!u->parent)
			_root = v;
		else if (u == u->parent->left)
			u->parent->left = v;
		else
			u->parent->right = v;
		if (v)
			v->parent = u->parent;
	}

	void eraseRebalance(Node *x)
	{
		Node *s = NULL;
		while (x && x != _root && x->color == BLACK)
		{
			if (x == x->parent->left)
			{
				s = x->parent->right;
				if (s->color == RED)
				{
					s->color = BLACK;
					x->parent->color = RED;
					leftRotate(x->parent);
					s = x->parent->right;
				}
				if (s->left->color == BLACK && s->right->color == BLACK)
				{
					s->color = RED;
					x = x->parent;
				} 
				else
				{
					if (s->right->color == BLACK)
					{
						s->left->color = BLACK;
						s->color = RED;
						rightRotate(s);
						s = x->parent->right;
					} 
					s->color = x->parent->color;
					x->parent->color = BLACK;
					s->right->color = BLACK;
					leftRotate(x->parent);
					x = _root;
				}
			} 
			else
			{
				s = x->parent->left;
				if (s->color == RED)
				{
					s->color = BLACK;
					x->parent->color = RED;
					rightRotate(x->parent);
					s = x->parent->left;
				}
				if (s->left->color == BLACK && s->right->color == BLACK)
				{
					s->color = RED;
					x = x->parent;
				}
				else 
				{
					if (s->left->color == BLACK)
					{
						s->right->color = BLACK;
						s->color = RED;
						leftRotate(s);
						s = x->parent->left;
					} 
					s->color = x->parent->color;
					x->parent->color = BLACK;
					s->left->color = BLACK;
					rightRotate(x->parent);
					x = _root;
				}
			} 
		}
		if (x)
			x->color = BLACK;
	}
	/* -------------------------- */

public:
	/* ----- Constructors ----- */
	// Default constructor
	explicit map(const key_compare &comp = key_compare(),
	const allocator_type &alloc = allocator_type()) :
	_root(NULL), _size(0), _comp(comp), _alloc(alloc), _min(NULL), _max(NULL) {}

	// Range constructor
	template <class InputIterator>
	map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), 
	const allocator_type &alloc = allocator_type()) :
	_root(NULL), _size(0), _comp(comp), _alloc(alloc), _min(NULL), _max(NULL)
	{
		for (; first != last; first++)
			insert(*first);
	}

	// Copy constructor
	map(const map &x) :
	_root(NULL), _size(0), _comp(x._comp), _alloc(x.get_allocator()), _min(NULL),
	_max(NULL)
	{*this = x;}

	~map() {deleteAll(_root);}
	/* -------------------------*/

	/* ------ Members Overloads ------- */
	map &operator=(const map &x)
	{
		clear();
		insert(x.begin(), x.end());
		return *this;
	}

	T &operator[](const key_type &key)
	{
		iterator it = find(key);
		if (it != end())
			return it->second;
		ft::pair<key_type, mapped_type> pair = ft::make_pair(key, mapped_type());
		return ((*(insert(pair)).first).second);
	}

	/* ---------------------------------*/

	T &at(const Key &key)
	{
		Node *curr = _root;
		while (curr && key != curr->pair.first)
			curr = _comp(key, curr->pair.first) ? curr->left : curr->right;
		if (!curr)
			throw std::out_of_range("map::at: key not found");
		return curr->pair.second;
	}

	const T &at(const Key &key) const
	{
		Node *curr = _root;
		while (curr && key != curr->pair.first)
			curr = _comp(key, curr->pair.first) ? curr->left : curr->right;
		if (!curr)
			throw std::out_of_range("map::at: key not found");
		return curr->pair.second;
	}

	ft::pair<iterator, bool> insert(const value_type &value)
	{
		// Find insertion position
		Node *curr = _root; Node *parent = NULL;
		while (curr)
		{
			parent = curr;
			if (_comp(curr->pair.first, value.first))
				curr = curr->right;
			else if (_comp(value.first, curr->pair.first))
            	curr = curr->left;
			else
				return ft::make_pair(iterator(curr, _min, _max), false);
		}
		// Set correct parent
		Node *node = _alloc.allocate(1);
		_alloc.construct(node, (Node){value, NULL, NULL, parent, RED});
		if (!_root)
			_root = node;
		else if (_comp(value.first, parent->pair.first))
			parent->left = node;
		else
			parent->right = node;
		setMinMax(value.first, node);
		if (!node->parent)
		{
			// No need to rebalance if there is only one element in the tree
			node->color = BLACK;
			return ft::make_pair(iterator(node, _min, _max), ++_size);
		}
		if (!node->parent->parent)
			return ft::make_pair(iterator(node, _min, _max), ++_size);
		insertRebalance(node);
		return ft::make_pair(iterator(node, _min, _max), ++_size);
	}

	iterator insert(iterator position, const value_type &value)
	{
		iterator it = insertionCheck(position, end(), value);
		return it.getCurr() ? it : insertionCheck(begin(), position, value);
	}

	template <class InputIterator> 
	void insert(InputIterator first, InputIterator last)
	{
		for (; first != last; first++)
			insert(*first);
	}

	void erase(iterator pos)
	{
		if (pos == end() || !find(pos->first).getCurr())
			return;
		_size--;
		if (pos.getCurr() == _max)
		{
			iterator tmp(_max, _min, _max);
			tmp--;
			_max = tmp.getCurr();
		}
		if (pos.getCurr() == _min)
		{
			iterator tmp(_min, _min, _max);
			tmp++;
			_min = tmp.getCurr();
		}
		eraseReorder(_root, pos->first);
	}

	void erase(iterator first, iterator last)
	{
		while (first != last)
		{
			iterator tmp = first;
			++first;
			erase(tmp);
		}
	}

	size_type erase(const Key &key)
	{
		for (iterator it = begin(); it != end(); it++)
		{
			if (it->first == key)
			{
				erase(it);
				return 1;
			}
		}
		return 0;
	}

	iterator find(const Key &key)
	{
		Node *curr = _root;
		while (curr && key != curr->pair.first)
			curr = _comp(key, curr->pair.first) ? curr->left : curr->right;
		return iterator(curr, _min, _max);
	}

	const_iterator find(const Key &key) const
	{
		Node *curr = _root;
		while (curr && key != curr->pair.first)
			curr = _comp(key, curr->pair.first) ? curr->left : curr->right;
		return const_iterator(curr, _min, _max);
	}

	iterator lower_bound(const Key &key)
	{
		for (iterator it = begin(); it != end(); it++)
			if (it->first >= key)
				return it;
		return end();
	}

	const_iterator lower_bound(const Key &key) const
	{
		for (const_iterator it = begin(); it != end(); it++)
			if (it->first >= key)
				return it;
		return end();
	}

	iterator upper_bound(const Key &key)
	{
		for (iterator it = begin(); it != end(); it++)
			if (it->first > key)
				return it;
		return end();
	}

	const_iterator upper_bound(const Key &key) const
	{
		for (const_iterator it = begin(); it != end(); it++)
			if (it->first > key)
				return it;
		return end();
	}

	ft::pair<iterator, iterator> equal_range(const Key &key)
	{return make_pair(lower_bound(key), upper_bound(key));}

	ft::pair<const_iterator,const_iterator> equal_range(const Key &key) const
	{return make_pair(lower_bound(key), upper_bound(key));}

	size_type count(const Key &key) const
	{
		Node *curr = _root;
		while (curr && key != curr->pair.first)
			curr = _comp(key, curr->pair.first) ? curr->left : curr->right;
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
		_min = NULL;
		_max = NULL;
		_root = NULL;
	}

	void swap(map &x)
	{
		ft::swapData(_root, x._root);
		ft::swapData(_size, x._size);
		ft::swapData(_comp, x._comp);
		ft::swapData(_min, x._min);
		ft::swapData(_max, x._max);
	}

	iterator begin()
	{
		Node *curr = _root;
		if (!curr)
			return iterator(curr, _min, _max);
		while (curr->left)
			curr = curr->left;
		return iterator(curr, _min, _max);	
	}

	const_iterator begin() const
	{
		Node *curr = _root;
		if (!curr)
			return const_iterator(curr, _min, _max);
		while (curr->left)
			curr = curr->left;
		return const_iterator(curr, _min, _max);	
	}

	iterator end()
	{return iterator(NULL, _min, _max);}

	const_iterator end() const
	{return const_iterator(NULL, _min, _max);}

	reverse_iterator rbegin()
	{
		if (!_size)
			return (reverse_iterator(iterator(_root, _min, _max)));
		return reverse_iterator(iterator(NULL, _min, _max));
	}

	const_reverse_iterator rbegin() const
	{
		if (!_size)
			return (const_reverse_iterator(iterator(_root, _min, _max)));
		return const_reverse_iterator(iterator(NULL, _min, _max));	
	}

	reverse_iterator rend()
	{
		if (!_size)
			return (reverse_iterator(iterator(_root, _min, _max)));
		return reverse_iterator(begin());
	}

	const_reverse_iterator rend() const
	{
		if (!_size)
			return (const_reverse_iterator(iterator(_root, _min, _max)));
		return const_reverse_iterator(begin());	
	}

};

template<class Key, class T, class Compare, class Alloc>
bool operator==(const map<Key, T, Compare, Alloc> &lhs,
const map<Key, T, Compare, Alloc> &rhs)
{
	typedef typename ft::map<Key, T>::const_iterator const_iterator;

	if (lhs.size() != rhs.size())
		return false;
	const_iterator it_lhs = lhs.begin();
	const_iterator it_rhs = rhs.begin();
	for (; it_lhs != lhs.end(); it_lhs++, it_rhs++)
	{
		if (it_rhs == rhs.end())
			return false;
		if (it_lhs->first != it_rhs->first || it_lhs->second != it_rhs->second)
			return false;
	}
	return it_rhs != rhs.end() ? false : true;
}

template<class Key, class T, class Compare, class Alloc>
bool operator!=(const map<Key, T, Compare, Alloc> &lhs,
const map<Key, T, Compare, Alloc> &rhs)
{return !(lhs == rhs);}

template<class Key, class T, class Compare, class Alloc>
bool operator<(const map<Key, T, Compare, Alloc> &lhs,
const map<Key, T, Compare, Alloc> &rhs)
{return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());}

template<class Key, class T, class Compare, class Alloc>
bool operator>(const map<Key, T, Compare, Alloc> &lhs,
const map<Key, T, Compare, Alloc> &rhs)
{return rhs < lhs;}

template<class Key, class T, class Compare, class Alloc>
bool operator<=(const map<Key, T, Compare, Alloc> &lhs,
const map<Key, T, Compare, Alloc> &rhs)
{return !(lhs > rhs);}

template<class Key, class T, class Compare, class Alloc>
bool operator>=(const map<Key, T, Compare, Alloc> &lhs,
const map<Key, T, Compare, Alloc> &rhs)
{return !(lhs < rhs);}

}
