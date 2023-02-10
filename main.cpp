#include "includes/vector.hpp"
#include "includes/map.hpp"
#include "includes/stack.hpp"

#include "includes/tools.hpp"

#include <iostream>
#include <vector>
#include <list>
#include <map>

#include "includes/reverse_iterator.hpp"
#include "includes/lexicographical_compare.hpp"
#include "containers_test/srcs/map/common.hpp"
#include <iostream>
#include <string>
#include <deque>

#define TEST ft

int main()
{
	TEST::map<int, int> mp;
	mp.insert(TEST::make_pair(34, 3));
	mp.insert(TEST::make_pair(22, 3));
	mp.insert(TEST::make_pair(10, 3));
	mp.insert(TEST::make_pair(9, 3));
	mp.insert(TEST::make_pair(1, 3));
	mp.insert(TEST::make_pair(4, 3));
	mp.insert(TEST::make_pair(30, 3));
	mp.insert(TEST::make_pair(8, 3));
	mp.insert(TEST::make_pair(32, 3));
	mp.insert(TEST::make_pair(3, 3));
	for (TEST::map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
	{
		if (it.getCurr()->color == RED)
			std::cout << it->first << ": RED"<< std::endl;
		else
			std::cout << it->first << ": BLACK"<< std::endl;
	}
		
	std::cout << "------------\n";
	std::cout << mp.size() << std::endl;
}
