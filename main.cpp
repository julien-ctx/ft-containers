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
// TEST::map<int, int>  trash()
// {
// 	TEST::map<int, int> mymap;
// 	mymap.insert(TEST::make_pair(34, 2));
// 	mymap.insert(TEST::make_pair(65, 4));
// 	mymap.insert(TEST::make_pair(23, 1));
// 	mymap.insert(TEST::make_pair(2, 7));
// 	mymap.insert(TEST::make_pair(657, 1));
// 	mymap.insert(TEST::make_pair(76, 1));
// 	mymap.insert(TEST::make_pair(4, 1));
// 	mymap.insert(TEST::make_pair(1, 1));
// 	mymap.insert(TEST::make_pair(345, 1));
// 	mymap.insert(TEST::make_pair(5, 1));
// 	mymap.insert(TEST::make_pair(30, 1));
// 	return mymap;
// }

// int main()
// {
// 	TEST::map<int, int>  t = trash();
// 	TEST::map<int, int>::reverse_iterator it = t.rbegin();
// 	for (int i = 0; it != t.rend(); it++, i++)
// 	{
// 		std::cout << it->first << std::endl;
// 	}
// 	std::cout << "END\n";
// 	// system("leaks ft_containers");
// }

int main()
{
	// TEST::map<std::string, int> map1;
	// map1.insert(TEST::make_pair("test1", 4));
	// map1.insert(TEST::make_pair("test2", 5));
	// map1.insert(TEST::make_pair("test0", 5));

	// TEST::map<std::string, int> map2(map1.begin(), map1.end());
	// for (TEST::map<std::string, int>::iterator it = map2.begin(); it != map2.end(); it++)
	// 	std::cout << it->first << std::endl;
	TEST::map<int, int> mp;
	mp.insert(TEST::make_pair<int, int>(24, 5));
	mp.insert(TEST::make_pair<int, int>(211, 443));
	mp.insert(TEST::make_pair<int, int>(23, 345));

	TEST::map<int, int> mp2(mp);
	mp2.insert(TEST::make_pair<int, int>(233, 345));

	std::cout << (mp == mp2) << std::endl;
	// (void)it;
	std::cout << "i am here\n";
	// Maybe i need to make a deep copy?
	// TEST::map<int, int>::reverse_iterator it = mp.rbegin();//, ite = mp.rend();
}
