#include "includes/vector.hpp"
#include "includes/map.hpp"
#include "includes/stack.hpp"

#include "includes/tools.hpp"

#include <iostream>
#include <vector>
#include <map>

#include "includes/reverse_iterator.hpp"
#include "includes/lexicographical_compare.hpp"

#define TEST std
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


void trash()
{
	TEST::map<int, int> mp;
	mp.insert(TEST::make_pair<int, int>(25, 5));
	mp.insert(TEST::make_pair<int, int>(211, 443));
	mp.insert(TEST::make_pair<int, int>(23, 345));

	TEST::map<int, int> mp2(mp);
	// mp2.insert(TEST::make_pair<int, int>(233, 345));

	std::cout << "---------------\n";
	TEST::map<int, int>::iterator it2 = mp2.begin();
	std::cout << "Size: " << mp2.size() << std::endl;
	mp2.end();
	mp = mp2;
	std::cout << "Size: " << mp.size() << std::endl;
	mp = mp2;
	for (; it2 != mp2.end(); it2++)
		std::cout << it2->first << std::endl;
}

int main()
{
	trash();
}
