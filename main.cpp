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


// #define T1 int
// #define T2 std::string
// typedef TESTED_NAMESPACE::map<T1, T2>::value_type T3;
// typedef TESTED_NAMESPACE::map<T1, T2>::iterator iterator;

// static int iter = 0;

// template <typename MAP, typename U>
// void    ft_insert(MAP &mp, U param)
// {
//         _pair<iterator, bool> tmp;

//         std::cout << "\t-- [" << iter++ << "] --" << std::endl;
//         tmp = mp.insert(param);
//         std::cout << "insert return: " << printPair(tmp.first);
//         std::cout << "Created new node: " << tmp.second << std::endl;
//         printSize(mp);
// }

// template <typename MAP, typename U, typename V>
// void    ft_insert(MAP &mp, U param, V param2)
// {
//         iterator tmp;

//         std::cout << "\t-- [" << iter++ << "] --" << std::endl;
//         tmp = mp.insert(param, param2);
//         std::cout << "insert return: " << printPair(tmp);
//         printSize(mp);
// }

// int             main(void)
// {
//         TESTED_NAMESPACE::map<T1, T2> mp, mp2;

//         ft_insert(mp, T3(42, "lol"));
//         ft_insert(mp, T3(42, "mdr"));

//         ft_insert(mp, T3(50, "mdr"));
//         ft_insert(mp, T3(35, "funny"));

//         ft_insert(mp, T3(45, "bunny"));
//         ft_insert(mp, T3(21, "fizz"));
//         ft_insert(mp, T3(38, "buzz"));

//         ft_insert(mp, mp.begin(), T3(55, "fuzzy"));

//         ft_insert(mp2, mp2.begin(), T3(1337, "beauty"));
//         ft_insert(mp2, mp2.end(), T3(1000, "Hello"));
//         ft_insert(mp2, mp2.end(), T3(1500, "World"));

//         return (0);
// }



#define T1 float
#define T2 foo<int>
typedef _pair<const T1, T2> T3;

// template <typename T>
// std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
// {
// 	o << "key: " << iterator->first << " | value: " << iterator->second;
// 	if (nl)
// 		o << std::endl;
// 	return ("");
// }

int             main(void)
{
        std::list<T3> lst;
        unsigned int lst_size = 5;
        for (unsigned int i = 0; i < lst_size; ++i)
                lst.push_back(T3(2.5 - i, (i + 1) * 7));
        TESTED_NAMESPACE::map<T1, T2> mp(lst.begin(), lst.end());
        TESTED_NAMESPACE::map<T1, T2>::const_iterator ite(mp.begin());
		std::cout << ite->first << std::endl;
        // printPair(++ite);
        // printPair(ite++);
        // printPair(ite++);
        // printPair(++ite);

        // it->second.m();
        // ite->second.m();

        // printPair(++it);
        // printPair(it++);
        // printPair(it++);
        // printPair(++it);

        // printPair(--ite);
        // printPair(ite--);
        // printPair(--ite);
        // printPair(ite--);

        // (*it).second.m();
        // (*ite).second.m();

        // printPair(--it);
        // printPair(it--);
        // printPair(it--);
        // printPair(--it);

        return (0);
}
