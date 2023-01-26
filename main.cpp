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
	mymap.insert(TEST::make_pair(34, 2));
	mymap.insert(TEST::make_pair(65, 4));
	mymap.insert(TEST::make_pair(23, 1));
	mymap.insert(TEST::make_pair(2, 7));
	mymap.insert(TEST::make_pair(657, 1));
	mymap.insert(TEST::make_pair(76, 1));
	mymap.insert(TEST::make_pair(4, 1));
	mymap.insert(TEST::make_pair(1, 1));
	mymap.insert(TEST::make_pair(345, 1));
	mymap.insert(TEST::make_pair(5, 1));
	mymap.insert(TEST::make_pair(30, 1));
	return mymap;
}

int main()
{
	TEST::map<int, int>  t = trash();
	TEST::map<int, int>::reverse_iterator it = t.rbegin();
	for (int i = 0; it != t.rend(); it++, i++)
	{
		std::cout << it->first << std::endl;
	}
	std::cout << "END\n";
	// system("leaks ft_containers");
}
