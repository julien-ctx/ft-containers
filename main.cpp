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


#define T1 int
#define T2 std::string
typedef TESTED_NAMESPACE::map<T1, T2>::value_type T3;
typedef TESTED_NAMESPACE::map<T1, T2>::iterator iterator;

static int iter = 0;

template <typename MAP, typename U>
void    ft_insert(MAP &mp, U param)
{
        _pair<iterator, bool> tmp;

        std::cout << "\t-- [" << iter++ << "] --" << std::endl;
        tmp = mp.insert(param);
        std::cout << "insert return: " << printPair(tmp.first);
        std::cout << "Created new node: " << tmp.second << std::endl;
        printSize(mp);
}

template <typename MAP, typename U, typename V>
void    ft_insert(MAP &mp, U param, V param2)
{
        iterator tmp;

        std::cout << "\t-- [" << iter++ << "] --" << std::endl;
        tmp = mp.insert(param, param2);
        std::cout << "insert return: " << printPair(tmp);
        printSize(mp);
}

int             main(void)
{
        TESTED_NAMESPACE::map<T1, T2> mp, mp2;
        ft_insert(mp2, mp2.end(), T3(1000, "Hello"));
		std::cout << "test------------------\n";
        ft_insert(mp2, mp2.end(), T3(1500, "World"));

        return (0);
}
