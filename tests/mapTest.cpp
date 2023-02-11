#include "../utils/tools.hpp"
#include "../containers/map.hpp"

void mapTest()
{

	NL();
	std::cout << BLUE << "******************* MAP ********************\n" << RESET;
	NL();

	std::stringstream ft_ss;
	std::stringstream std_ss;
	std::streambuf* cout_buf = std::cout.rdbuf();
	clock_t begin_time;
	clock_t ft_diff;
	clock_t std_diff;

	std::cout << CYAN << "------------------ PAIR --------------------\n" << RESET;
	{
		begin_time = clock();
		std::cout.rdbuf(std_ss.rdbuf());
		std::pair<std::string, int> p("salut", 5);
		std::pair<std::string, int> p2("salut", 5);
		std::cout << (p == p2) << std::endl;
		std::cout << p.first << " " << p.second << std::endl;
		p.first = "bonjour";
		std::cout << (p != p2) << std::endl;
		std::cout << (p <= p2) << std::endl;
		std::cout << (p > p2) << std::endl;
		std::cout << (p >= p2) << std::endl;
		std::cout << (p < p2) << std::endl;
		std::pair<std::string, int> p3(p);	
		std::cout << (p3 == p) << std::endl;
		std::pair<std::string, int> pair2("std", 1);
		std::pair<std::string, int> pair = std::make_pair<std::string, int>("std", 1);
		std::cout << (p2 == p) << std::endl;
		std::cout.rdbuf(cout_buf);
		std_diff = begin_time - clock();
	}
	{
		begin_time = clock();
		std::cout.rdbuf(ft_ss.rdbuf());
		ft::pair<std::string, int> p("salut", 5);
		ft::pair<std::string, int> p2("salut", 5);
		std::cout << (p == p2) << std::endl;
		std::cout << p.first << " " << p.second << std::endl;
		p.first = "bonjour";
		std::cout << (p != p2) << std::endl;
		std::cout << (p <= p2) << std::endl;
		std::cout << (p > p2) << std::endl;
		std::cout << (p >= p2) << std::endl;
		std::cout << (p < p2) << std::endl;
		ft::pair<std::string, int> p3(p);	
		std::cout << (p3 == p) << std::endl;
		ft::pair<std::string, int> pair2("std", 1);
		ft::pair<std::string, int> pair = ft::make_pair<std::string, int>("std", 1);
		std::cout << (p2 == p) << std::endl;
		std::cout.rdbuf(cout_buf);
		ft_diff = begin_time - clock();
	}
	std::cout << BOLD;
	std_ss.str() == ft_ss.str() ? std::cout << "DIFF OK ✅\n" : std::cout << "DIFF KO ❌\n";
	std::cout << RESET;
	ft_ss.clear();
	std_ss.clear();
	std::cout << BOLD;
	timeDiff(ft_diff, std_diff);
	std::cout << RESET;	
	std::cout << CYAN << "------------------- SIZE -------------------\n" << RESET;
	{
		begin_time = clock();
		std::cout.rdbuf(std_ss.rdbuf());
		std::map<int, int> mp;
		std::cout << mp.size() << std::endl;
		for (int i = 0; i < 10; i++)
			mp.insert(std::make_pair(i, i));
		std::cout << mp.size() << std::endl;
		mp.erase(2);
		std::cout << mp.size() << std::endl;
		mp.clear();
		std::cout << mp.empty() << std::endl;
		std::cout << mp.size() << std::endl;
		mp[2];
		std::cout << mp.count(2) << std::endl;
		std::cout << mp.size() << std::endl;
		std::cout << mp.at(2) << std::endl;
		std::cout << mp.size() << std::endl;
		std::cout.rdbuf(cout_buf);
		std_diff = begin_time - clock();
	}
	{
		begin_time = clock();
		std::cout.rdbuf(ft_ss.rdbuf());
		ft::map<int, int> mp;
		std::cout << mp.size() << std::endl;
		for (int i = 0; i < 10; i++)
			mp.insert(ft::make_pair(i, i));
		std::cout << mp.size() << std::endl;
		mp.erase(2);
		std::cout << mp.size() << std::endl;
		mp.clear();
		std::cout << mp.empty() << std::endl;
		std::cout << mp.size() << std::endl;
		mp[2];
		std::cout << mp.count(2) << std::endl;
		std::cout << mp.size() << std::endl;
		std::cout << mp.at(2) << std::endl;
		std::cout << mp.size() << std::endl;
		std::cout.rdbuf(cout_buf);
		ft_diff = begin_time - clock();
	}
	std::cout << BOLD;
	std_ss.str() == ft_ss.str() ? std::cout << "DIFF OK ✅\n" : std::cout << "DIFF KO ❌\n";
	std::cout << RESET;
	ft_ss.clear();
	std_ss.clear();
	std::cout << BOLD;
	timeDiff(ft_diff, std_diff);
	std::cout << RESET;
	std::cout << CYAN << "------------------ ACCESS ------------------\n" << RESET;
	{
		begin_time = clock();
		std::cout.rdbuf(std_ss.rdbuf());
		std::map<int, std::string> mp;
		mp.insert(std::make_pair(1, "salut"));
		std::cout << mp.begin()->first << std::endl;
		for (int i = 0; i < 10; i++)
			mp.insert(std::make_pair(i, std::to_string(i)));
		std::cout << mp.lower_bound(7)->first << std::endl;
		std::cout << mp.at(4) << std::endl;
		for (std::size_t i = 0; i < mp.size(); i++)
			std::cout << mp[i] << std::endl;
		std::cout << mp.upper_bound(1)->second << std::endl;
		std::map<char, int> mp2;
		mp2.insert(std::make_pair('a', 10));
		mp2.insert(std::make_pair('b', 20));
		mp2.insert(std::make_pair('c', 30));
		std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
		ret = mp2.equal_range('b');
		std::cout << "lower bound points to: ";
		std::cout << ret.first->first << " => " << ret.first->second << '\n';
		std::cout << "upper bound points to: ";
		std::cout << ret.second->first << " => " << ret.second->second << '\n';
		std::cout.rdbuf(cout_buf);
		std_diff = begin_time - clock();
	}
	{
		begin_time = clock();
		std::cout.rdbuf(ft_ss.rdbuf());
		ft::map<int, std::string> mp;
		mp.insert(ft::make_pair(1, "salut"));
		std::cout << mp.begin()->first << std::endl;
		for (int i = 0; i < 10; i++)
			mp.insert(ft::make_pair(i, std::to_string(i)));
		std::cout << mp.lower_bound(7)->first << std::endl;
		std::cout << mp.at(4) << std::endl;
		for (std::size_t i = 0; i < mp.size(); i++)
			std::cout << mp[i] << std::endl;
		std::cout << mp.upper_bound(1)->second << std::endl;
		ft::map<char, int> mp2;
		mp2.insert(ft::make_pair('a', 10));
		mp2.insert(ft::make_pair('b', 20));
		mp2.insert(ft::make_pair('c', 30));
		ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
		ret = mp2.equal_range('b');
		std::cout << "lower bound points to: ";
		std::cout << ret.first->first << " => " << ret.first->second << '\n';
		std::cout << "upper bound points to: ";
		std::cout << ret.second->first << " => " << ret.second->second << '\n';	
		std::cout.rdbuf(cout_buf);
		ft_diff = begin_time - clock();
	}
	std::cout << BOLD;
	std_ss.str() == ft_ss.str() ? std::cout << "DIFF OK ✅\n" : std::cout << "DIFF KO ❌\n";
	std::cout << RESET;
	ft_ss.clear();
	std_ss.clear();
	std::cout << BOLD;
	timeDiff(ft_diff, std_diff);
	std::cout << RESET;

}
