#pragma once

#include <iostream>
#include <string>
#include <type_traits>
#include <sstream>
#include <limits>
#include <ctime>

// My containers implementation includes
#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"
#include "pair.hpp"

// STL containers includes
#include <vector>
#include <map>
#include <stack>

#define RESET   "\033[0m"
#define GREEN   "\033[1m\033[32m"      /* Bold Green */
#define YELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BLUE    "\033[1m\033[34m"      /* Bold Blue */
#define MAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define CYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLD    "\033[1m\033[37m"      /* Bold White */

#define BLACK 0
#define RED 1

#define PRINT(x) std::cout << BOLD << x << std::endl << RESET; 
#define NL() std::cout << std::endl;

void timeDiff(clock_t &ft_diff, clock_t &std_diff);

void vectorTest();
void stackTest();
void mapTest();

namespace ft
{
	typedef std::ptrdiff_t difference_type;
	typedef std::size_t size_type;

	template<class T>
	struct Node
	{
		T pair;
		Node *left;
		Node *right;
		Node *parent;
		bool color;
	};

	template<class It>
	difference_type distance(It first, It last)
	{
		// Check here if the iterator is a random access iterator and return last - first.
		difference_type i = 0;
		for (i = 0; first != last; i++)
			first++;
		return i;
	}

	template<class T>
	void swapData(T &first, T &second)
	{
		T tmp = first;
		first = second;
		second = tmp;
	}

}
