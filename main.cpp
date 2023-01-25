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
	TEST::pair<std::string, int> mypair("Test", 42);
	TEST::pair<std::string, int> mypair2("Test2", 43);
	TEST::map<std::string, int>::iterator it = mymap.insert(mypair).first;
	TEST::map<std::string, int>::iterator it2 = mymap.insert(mypair2).first;

std::cout <<  mymap.value_comp()(*it, *it2) << std::endl;
  return 0;
}
