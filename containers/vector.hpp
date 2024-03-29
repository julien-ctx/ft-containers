#pragma once

#include "../utils/tools.hpp"
#include "../utils/reverse_iterator.hpp"
#include "../utils/iterator_traits.hpp"
#include "../utils/enable_if.hpp"
#include "../utils/random_access_iterator.hpp"
#include "../utils/is_integral.hpp"
#include "../utils/lexicographical_compare.hpp"

#define VEC_DATA() std::cout << _size << " <- size | capacity -> " << _capacity << std::endl;

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

	void destroyAndFree(size_type size, size_type capacity)
	{
		for (size_type i = 0; i < size; i++)
			_alloc.destroy(&_array[i]);
		_alloc.deallocate(_array, capacity);
	}

public:

	/* ----- Constructors ----- */
	// Default constructor
	explicit vector(const allocator_type &alloc = allocator_type()) :
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
	vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(),
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
	vector(const vector &x) : _alloc(Allocator()), _size(x.size()), _capacity(x.capacity())
	{
		_array = _alloc.allocate(_capacity);
		for (size_type i = 0; i < _size; i++)
			_alloc.construct(&_array[i], x[i]);
	}

	// Destructor
	virtual ~vector()
	{
		for (size_type i = 0; i < _size; i++)
			_alloc.destroy(&_array[i]);
		_alloc.deallocate(_array, _capacity);
	}
	/* -------------------------*/

	/* ------ Members Overloads ------- */
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
	/* ---------------------------------*/

	reference at(size_type n)
	{
		if (n >= _size)
			throw std::out_of_range("vector: index out of range");
		else
			return operator[](n);
	}
	
	const_reference at(size_type n) const
	{
		if (n >= _size)
			throw std::out_of_range("vector: index out of range");
		else
			return operator[](n);
	}

	T* data() {return _array;}

	const T* data() const {return _array;}

	reference front() {return operator[](0);}

	const_reference front() const {return operator[](0);}

	reference back() {return operator[](_size - 1);}

	const_reference back() const {return operator[](_size - 1);}
	

	iterator end() {return iterator(&_array[_size]);}
	
	const_iterator end() const {return const_iterator(&_array[_size]);}

	iterator begin() {return iterator(_array);}
	
	const_iterator begin() const {return const_iterator(_array);}

	reverse_iterator rbegin() {return reverse_iterator(iterator(&_array[_size]));}

	reverse_iterator rend() {return reverse_iterator(iterator(_array));}

	const_reverse_iterator rbegin() const {return reverse_iterator(iterator(&_array[_size]));}
	
	const_reverse_iterator rend() const {return reverse_iterator(iterator(_array));}

	allocator_type get_allocator() const {return _alloc;}


	size_type size() const {return _size;}

	size_type max_size() const {return _alloc.max_size();}

	bool empty() const {return !_size;}

	size_type capacity() const {return _capacity;}

	void reserve(size_type new_cap)
	{
		if (new_cap > max_size())
			throw std::length_error("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size");
		if (new_cap > _capacity)
		{
			T *new_array = _alloc.allocate(new_cap);
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(&new_array[i], _array[i]);
			destroyAndFree(_size, _capacity);
			_capacity = new_cap;
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
			while (_size != count)
				_alloc.destroy(&_array[--_size]);
	}

	void push_back(const value_type &val)
	{
		size_type cx2 = _capacity * 2;
		if (_size == _capacity)
		{
			if (_capacity)
				reserve(cx2 <= max_size() ? cx2 : max_size());
			else
				reserve(1);
		}
		_alloc.construct(&_array[_size++], val);
	}

	void pop_back() {_alloc.destroy(&_array[_size-- - 1]);}

	void assign(size_type count, const T &value)
	{
		resize(count);
		for (size_type i = 0; i < count; i++)
			_alloc.construct(&_array[i], value);
	}

	template <class InputIterator> 
	void assign(InputIterator first, InputIterator last,
	typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = false)
	{
		size_type count = ft::distance(first, last);
		resize(count);
		for (size_type i = 0; i < count; i++, first++)
			_alloc.construct(&_array[i], *first);
	}

	iterator insert(iterator position, const value_type &val)
	{
		// Save old capacity to deallocate and destroy the previous array
		size_type old_capacity = _capacity;
		if (_size == _capacity)
			if ((_capacity * 2) > max_size())
				throw std::bad_alloc();
		// If the position is end() and there is enough space, we don't reallocate
		if (position == end())
		{
			push_back(val);
			return end() - 1;
		}
		_capacity *= 2;
		T *new_array = _alloc.allocate(_capacity);
		T *ptr = NULL; size_type i = 0;
		for (iterator it = begin(); it != end(); i++)
		{
			if (it == position && !ptr)
			{
				_alloc.construct(&new_array[i], val);
				ptr = &new_array[i];
			}
			else
				_alloc.construct(&new_array[i], *it++);
		}
		destroyAndFree(_size, old_capacity);
		_array = new_array; _size++;
		return iterator(ptr);
	}

	void insert(iterator position, size_type n, const value_type &val)
	{
		if (position == end())
			for (size_type i = 0; i < n; i++)
				push_back(val);
		else
		{
			size_type old_capacity = _capacity;
			if (_size + n > _capacity)
				if ((_capacity = _size + n) > max_size())
					throw std::bad_alloc();
			T *new_array = _alloc.allocate(_capacity);
			bool found = false; size_type i = 0;
			for (iterator it = begin(); it != end(); i++)
			{
				if (it == position && !found)
				{
					for (size_type j = 0; j < n; j++, i++)
						_alloc.construct(&new_array[i], val);
					found = true; --i;
				}
				else
					_alloc.construct(&new_array[i], *it++);
			}
			destroyAndFree(_size, old_capacity);
			_array = new_array; _size += n;
		}
	}

	template <class InputIterator>
	void insert(iterator position, InputIterator first, InputIterator last,
	typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = false)
	{
		if (position == end())
			for (; first != last; first++)
				push_back(*first);
		else
		{
			size_type old_capacity = _capacity;
			size_type n = ft::distance(first, last);
			if (_size + n > _capacity)
				if ((_capacity = _size + n) > max_size())
					throw std::bad_alloc();
			T *new_array = _alloc.allocate(_capacity);
			bool found = false; size_type i = 0; ;
			for (iterator it = begin(); it != end(); i++)
			{
				if (it == position && !found)
				{
					for (; first != last; first++)
						_alloc.construct(&new_array[i++], *first);
					found = true; i--;
				}
				else
					_alloc.construct(&new_array[i], *it++);
			}
			destroyAndFree(_size, old_capacity);
			_array = new_array; _size += n;
		}
	}

	iterator erase(iterator position)
	{
		for (size_type i = 0; i < _size; i++)
		{
			if (position.operator->() == &_array[i])
			{
				for (; i + 1 < _size; i++)
					_array[i] = _array[i + 1];
				_alloc.destroy(&_array[--_size]);
				return position;
			}
		}
		return position;
	}
	
	iterator erase(iterator first, iterator last)
	{
		for (size_type i = 0; i < _size; i++)
		{
			if (first.operator->() == &_array[i])
			{
				size_type count = ft::distance(first, last);
				for (; i + count < _size; i++)
					_array[i] = _array[i + count];
				for (i = 1; i < count; i++)
					_alloc.destroy(&_array[_size - i]);	
				_size -= count;
				return first;
			}
		}
		return first;	
	}

	void swap(vector &x)
	{
	    ft::swapData(_array, x._array);
    	ft::swapData(_size, x._size);
    	ft::swapData(_capacity, x._capacity);
	}
};

/* ---- Non Members Overloads ----- */
template<class Type, class Alloc>
bool operator==(const vector<Type, Alloc> &lhs,
	const ft::vector<Type, Alloc> &rhs)
{
	if (lhs.size() != rhs.size())
		return false;
	size_type lhs_size = lhs.size();
	for (size_type i = 0; i < lhs_size; i++)
		if (lhs[i] != rhs[i])
			return false;
	return true;
}

template<class Type, class Alloc>
bool operator!=(const vector<Type, Alloc> &lhs,
	const vector<Type, Alloc> &rhs) {return !(lhs == rhs);}

template<class T, class Alloc>
bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
{return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());}

template<class T, class Alloc>
bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
{return rhs < lhs;}

template<class T, class Alloc>
bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
{return !(lhs > rhs);}

template<class T, class Alloc>
bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
{return !(lhs < rhs);}
/* ---------------------------------*/

}
