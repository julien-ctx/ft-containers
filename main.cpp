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
	mymap.insert(mypair);
	mymap.insert(TEST::make_pair("lol", 24));
	mymap.insert(TEST::make_pair("lsl", 55));
	try
	{
		std::cout << mymap.at("Test") << std::endl;
		std::cout << mymap.at("lol") << std::endl;
		// std::cout << mymap["a"] << std::endl;
		// std::cout << mymap["a"] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
