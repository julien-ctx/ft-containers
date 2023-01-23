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
	mymap.insert(mypair);
	try
	{
		std::cout << mymap.at("Test") << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
