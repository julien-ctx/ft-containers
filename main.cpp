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



#include <list>

#define T1 char
#define T2 int
typedef _pair<const T1, T2> T3;

int             main(void)
{
        std::list<T3> lst;
        unsigned int lst_size = 5;
        for (unsigned int i = 0; i < lst_size; ++i)
                lst.push_back(T3('a' + i, (i + 1) * 7));

        TESTED_NAMESPACE::map<T1, T2> mp(lst.begin(), lst.end());
        TESTED_NAMESPACE::map<T1, T2>::iterator it_ = mp.begin();
        TESTED_NAMESPACE::map<T1, T2>::reverse_iterator it(it_), ite;
        printSize(mp);

        std::cout << (it_ == it.base()) << std::endl;
        std::cout << (it_ == dec(it, 3).base()) << std::endl;

        printPair(it.base());
        printPair(inc(it.base(), 1));

        std::cout << "TEST OFFSET" << std::endl;
        --it;
        printPair(it);
        printPair(it.base());

        it = mp.rbegin();
		ite = mp.rend();
        while (it != ite)
                std::cout << "[rev] " << printPair(it++, false) << std::endl;
        printReverse(mp);

        return (0);
}
