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

// #include "containers_test/srcs/map/common.hpp"
#define TEST std

#include <stdlib.h>

int main()
{
	TEST::map<int, int> mp;
	mp.insert(TEST::make_pair(42, 234));
	mp.insert(TEST::make_pair(5, 234));
	mp.insert(TEST::make_pair(65, 234));
	mp.insert(TEST::make_pair(43432, 234));
	mp.insert(TEST::make_pair(34, 234));
	mp.insert(TEST::make_pair(2, 234));
	mp.insert(TEST::make_pair(7, 234));
	TEST::map<int, int> mp2;
	
	for (TEST::map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
		std::cout << it->first << std::endl;
	TEST::map<int, int>::iterator it = mp.begin();
	// it++;it++;
	// it++;it++;

	std::cout << "erase ret: " << mp.erase(it)->first << std::endl;
	std::cout << "-----------\n";
	for (TEST::map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
		std::cout << it->first << std::endl;
}
