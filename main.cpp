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

#define TEST ft
int main()
{
        TEST::map<int, int> mp;
        mp.insert(ft::make_pair(44, 34));
        // mp.erase(mp.begin());
        std::cout << mp.size() << std::endl;
        for (TEST::map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
                std::cout << it->first << std::endl;
        
}
