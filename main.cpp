#include "includes/vector.hpp"
#include "includes/map.hpp"
#include "includes/stack.hpp"

#include "includes/tools.hpp"

#include <iostream>
#include <vector>
#include <map>

#include "includes/reverse_iterator.hpp"
#include "includes/lexicographical_compare.hpp"

#define TEST ft

TEST::map<int, int>  trash()
{
	TEST::map<int, int> mymap;
	mymap.insert(TEST::make_pair(34, 1));
	// mymap.insert(TEST::make_pair(65, 1));
	// mymap.insert(TEST::make_pair(23, 1));
	// mymap.insert(TEST::make_pair(2, 1));
	// mymap.insert(TEST::make_pair(657, 1));
	// mymap.insert(TEST::make_pair(76, 1));
	// mymap.insert(TEST::make_pair(4, 1));
	// mymap.insert(TEST::make_pair(1, 1));
	// mymap.insert(TEST::make_pair(345, 1));
	return mymap;
}

int main()
{
	TEST::map<int, int>  t = trash();
	TEST::map<int, int>::iterator it = t.begin();
		// std::cout << it->first << std::endl;
		// it++;
		// std::cout << it->first << std::endl;
		// it--;
		// std::cout << it->first << std::endl;
	for (; it != t.end(); it++)
		std::cout << it->first << std::endl;
	// system("leaks ft_containers");
}
