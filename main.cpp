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

TEST::map<std::string, int>  trash()
{
	TEST::map<std::string, int> mymap;
	mymap.insert(TEST::make_pair("test", 1));
	mymap.insert(TEST::make_pair("tenjhmst2", 1));
	mymap.insert(TEST::make_pair("tvfdest2", 1));
	mymap.insert(TEST::make_pair("vfdtest2", 1));
	mymap.insert(TEST::make_pair("tsdvdfest2", 1));
	mymap.insert(TEST::make_pair("teswt2", 1));
	mymap.insert(TEST::make_pair("tacest2", 1));
	mymap.insert(TEST::make_pair("teedest2", 1));
	mymap.insert(TEST::make_pair("tesbfgbfgbt2", 1));
	mymap.insert(TEST::make_pair("tebgbfb", 1));
	return mymap;
}

int main()
{
	TEST::map<std::string, int>  t = trash();
	t.clear();
	std::cout << t.size() << std::endl;
	system("leaks ft_containers");
	return 0;
}
