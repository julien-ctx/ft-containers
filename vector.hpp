#pragma once

#include <string>
#include <iostream>
#include <limits.h>
#include <stdexcept>
#include <type_traits>
#include <unistd.h>

#include "tools.hpp"
#include "utils/reverse_iterator.hpp"
#include "utils/iterator_traits.hpp"
#include "utils/enable_if.hpp"
#include "utils/random_access_iterator.hpp"
#include "utils/is_integral.hpp"

namespace ft
{
	
template < class T, class Allocator = std::allocator<T> >
class vector
{

public:
	typedef T value_type;
	typedef Allocator allocator_type;
	typedef typename Allocator::reference reference;
	typedef typename Allocator::const_reference const_reference;
	typedef typename Allocator::pointer pointer;
	typedef typename Allocator::const_pointer const_pointer;
	typedef typename ft::random_access_iterator<T> iterator;
	typedef typename ft::random_access_iterator<const T> const_iterator;
	typedef typename ft::reverse_iterator<iterator> reverse_iterator;
	typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
	typedef std::size_t size_type;
	typedef std::ptrdiff_t difference_type;

private:
	T* _array;
	Allocator _alloc;
	size_type _size;
	size_type _capacity;

public:

	/* ----- Constructors ----- */
	// Default constructor
	explicit vector (const allocator_type &alloc = allocator_type()) :
		_array(NULL), _alloc(alloc), _size(0), _capacity(0) {}

	// Fill constructor
	explicit vector (size_type n, const value_type &val = value_type(),
		const allocator_type &alloc = allocator_type()) : _alloc(alloc), _size(n), _capacity(n)
	{
		_array = _alloc.allocate(n);
		for (size_type i = 0; i < n; i++)
			_alloc.construct(&_array[i], val);
	}

	// Range constructor
	template<class InputIterator>
	vector (InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(),
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = false) : _alloc(alloc)
	{
		size_type dist = ft::distance<InputIterator>(first, last);
		_array = _alloc.allocate(dist);
		for (size_type i = 0; i < dist; first++, i++)
			_alloc.construct(&_array[i], *first);
		_size = dist;
		_capacity = dist;
	}

	// Copy constructor
	vector (const vector &x) : _alloc(Allocator()), _size(x.size()), _capacity(x.capacity())
	{
		_array = _alloc.allocate(_capacity);
		for (size_type i = 0; i < _size; i++)
			_alloc.construct(&_array[i], x[i]);
	}

	// Destructor
	~vector()
	{
		for (size_type i = 0; i < _size; i++)
			_alloc.destroy(&_array[i]);
		_alloc.deallocate(_array, _capacity);
	}
	/* -------------------------*/

	/* ------ Overloads ------- */

	reference operator[](size_type n) const {return _array[n];}

	vector &operator=(const vector &other)
	{
		// Destroys and deallocates the previous data
		for (size_type i = 0; i < _size; i++)
			_alloc.destroy(&_array[i]);
		_alloc.deallocate(_array, _capacity);

		_capacity = other.capacity();
		_size = other.size();

		_array = _alloc.allocate(_capacity);
		for (size_type i = 0; i < _size; i++)
			_alloc.construct(&_array[i], other[i]);
		return *this;
	}

	/* 
	friend keyword allows the function to become non-member of the class.
	Thanks to this, the function becomes friend with ft::vector class.
	Therefore it can access the private data of the class and compare the vectors.
	It is needed by operator[] which access the underlying array directly.
	*/
	template<class Type, class Alloc>
	friend bool operator==(const vector<Type, Alloc> &lhs,
    	const vector<Type, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		size_type lhs_size = lhs.size();
		for (size_type i = 0; i < lhs_size; i++)
			if (lhs[i] != rhs[i])
				return false;
		return true;
	}

	template< class Type, class Alloc >
	friend bool operator!=(const std::vector<Type, Alloc> &lhs,
    	const std::vector<Type, Alloc> &rhs) {return !operator==(lhs, rhs);}

	// template< class Type, class Alloc >
	// friend bool operator<(const std::vector<Type, Alloc> &lhs,
    // 	const std::vector<Type, Alloc> &rhs)
	// {

	// }

	/* -------------------------*/

	reference at(size_type n)
	{
		if (n >= _size)
			throw std::out_of_range("Index out of range");
		else
			return operator[](n);
	}
	
	const_reference at(size_type n) const
	{
		if (n >= _size)
			throw std::out_of_range("Index out of range");
		else
			return operator[](n);
	}

	reference front() {return operator[](0);}

	const_reference front() const {return operator[](0);}

	reference back() {return operator[](_size - 1);}

	const_reference back() const {return operator[](_size - 1);}

	iterator end() {return iterator(&_array[_size]);}
	
	const_iterator end() const {return const_iterator(&_array[_size]);}

	iterator begin() {return iterator(_array);}
	
	const_iterator begin() const {return const_iterator(_array);}

	size_type size() const {return _size;}

	size_type max_size() const {return _alloc.max_size();}

	bool empty() const {return !_size;}

	size_type capacity() const {return _capacity;}

	void reserve(size_type new_cap)
	{
		if (new_cap > max_size())
			throw std::bad_alloc();
		if (new_cap > _capacity)
		{
			T* new_array = _alloc.allocate(new_cap);
			_capacity = new_cap;
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(&new_array[i], _array[i]);
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(&_array[i]);
			_alloc.deallocate(_array, _capacity);
			_array = new_array;	
		}
	}

	void clear() {while (--_size) _alloc.destroy(&_array[_size]);}

	// Maybe I could have used erase...
	void resize(size_type count, T value = T())
	{
		if (count > _size)
		{
			reserve(count);
			for (size_t i = _size; i < _capacity; i++)
				_alloc.construct(&_array[i], value);
			_size = count;
		}
		else
			while (--_size != count)
				_alloc.destroy(&_array[_size]);
	}

	void push_back(const value_type &val)
	{
		size_type cx2 = _capacity * 2;
		if (_size == _capacity)
			_capacity ? (reserve(cx2 <= max_size() ? cx2 : max_size())) : reserve(1);
		_alloc.construct(&_array[_size++], val);
	}

	reverse_iterator rbegin() {return reverse_iterator(&_array[_size - 1]);}

	reverse_iterator rend() {return reverse_iterator(_array);}

	const_reverse_iterator rbegin() const {return reverse_iterator(&_array[_size - 1]);}
	
	const_reverse_iterator rend() const {return reverse_iterator(_array);}

	void pop_back() {_alloc.destroy(&_array[_size-- - 1]);}

};

}
