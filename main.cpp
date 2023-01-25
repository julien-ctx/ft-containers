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

int main()
{
	TEST::map<std::string, int> mymap;
	std::string test = "Test";
	TEST::pair<std::string, int> mypair(test, 42);
	std::map<std::string, int>::iterator it = mymap.insert(mypair).first;
	std::cout << it->second << std::endl;	
}
