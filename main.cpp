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
int main ()
{
  TEST::map<char,int> mymap;

  mymap.insert(TEST::make_pair('a', 10));
  mymap.insert(TEST::make_pair('b', 20));
  mymap.insert(TEST::make_pair('c', 30));

  TEST::pair<TEST::map<char,int>::iterator,TEST::map<char,int>::iterator> ret;
  ret = mymap.equal_range('b');

  std::cout << "lower bound points to: ";
  std::cout << ret.first->first << " => " << ret.first->second << '\n';

  std::cout << "upper bound points to: ";
  std::cout << ret.second->first << " => " << ret.second->second << '\n';

  return 0;
}
