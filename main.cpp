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

#define TESTED_NAMESPACE std

#define T1 int
#define T2 int

typedef ft::pair<const T1, T2> T3;


// template <typename T_MAP>
// void    printSize(T_MAP const &mp, bool print_content = 1)
// {
//         std::cout << "size: " << mp.size() << std::endl;
//         std::cout << "max_size: " << mp.max_size() << std::endl;
//         if (print_content)
//         {
//                 typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
//                 std::cout << std::endl << "Content is:" << std::endl;
//                 for (; it != ite; ++it)
//                         std::cout << "- " << printPair(it, false) << std::endl;
//         }
//         std::cout << "###############################################" << std::endl;
// }


// void trash()
// {
//  	std::list<T3> lst;
//         unsigned int lst_size = 7;
//         for (unsigned int i = 0; i < lst_size; ++i)
//                 lst.push_back(T3(lst_size - i, i));

//         TESTED_NAMESPACE::map<T1, T2> mp(lst.begin(), lst.end());
//         TESTED_NAMESPACE::map<T1, T2>::iterator it = mp.begin(), ite = mp.end();

//         TESTED_NAMESPACE::map<T1, T2> mp_range(it, --(--ite));
//         for (int i = 0; it != ite; ++it)
//                 it->second = ++i * 5;

//         it = mp.begin(); ite = --(--mp.end());
//         TESTED_NAMESPACE::map<T1, T2> mp_copy(mp);
//         for (int i = 0; it != ite; ++it)
//                 it->second = ++i * 7;

//         std::cout << "\t-- PART ONE --" << std::endl;
//         printSize(mp);
// }

// int main()
// {
// 	trash();
// }
#define TEST std
int main()
{
    TEST::map<int, int> m;
	m.insert(TEST::make_pair(10, 20));
	m.insert(TEST::make_pair(30, 10));
	m.insert(TEST::make_pair(1, 4));
	m.insert(TEST::make_pair(143, 44));

	for (TEST::map<int, int>::iterator it = m.begin(); it != m.end(); it++)
		std::cout << (*it).first << std::endl;
	// for (TEST::map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	// 	std::cout << (*it).first << std::endl;
	TEST::map<int, int>::iterator test2 = ++m.begin();	
	test2++;
	 m.insert(test2, TEST::make_pair(2, 42));
	 std::cout << "after insertion\n";
	for (TEST::map<int, int>::iterator it = m.begin(); it != m.end(); it++)
		std::cout << (*it).first << std::endl;
	std::cout << "lower bound\n";
	std::cout << (*m.upper_bound(30)).first << std::endl;
}
