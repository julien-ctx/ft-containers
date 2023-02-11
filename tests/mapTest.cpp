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
	std::cout << CYAN << "----------------- MODIFIERS ----------------\n" << RESET;
	{
		begin_time = clock();
		std::cout.rdbuf(std_ss.rdbuf());
		std::map<int, int> mp;
		for (std::size_t i = 0; i < 20; i++)
			std::cout << mp.insert(std::make_pair(i, i)).first->first << std::endl;
		for (std::size_t i = 0; i < mp.size(); i++)
			std::cout << mp[i] << std::endl;
		std::map<int, int> mp2 = mp;
		for (std::size_t i = 0; i < mp2.size(); i++)
			std::cout << mp2[i] << std::endl;
		mp2.clear();
		mp2.insert(++mp.begin(), mp.end());
		std::cout << mp2.size() << std::endl;
		for (std::size_t i = 0; i < mp2.size(); i++)
			std::cout << mp2[i] << std::endl;
		mp2.erase(mp2.begin(), mp2.end());
		std::cout << mp2.size() << std::endl;
		for (std::size_t i = 0; i < mp2.size(); i++)
			std::cout << mp2[i] << std::endl;
		mp.erase(14);
		for (std::size_t i = 0; i < mp.size(); i++)
			std::cout << mp[i] << std::endl;
		std::cout << mp.insert(std::make_pair(10, 10)).first->first << std::endl;
		mp.erase(--mp.end());
		for (std::size_t i = 0; i < mp.size(); i++)
			std::cout << mp[i] << std::endl;
		std::cout.rdbuf(cout_buf);
		std_diff = begin_time - clock();
	}
	{
		begin_time = clock();
		std::cout.rdbuf(ft_ss.rdbuf());
		ft::map<int, int> mp;
		for (std::size_t i = 0; i < 20; i++)
			std::cout << mp.insert(ft::make_pair(i, i)).first->first << std::endl;
		for (std::size_t i = 0; i < mp.size(); i++)
			std::cout << mp[i] << std::endl;
		ft::map<int, int> mp2 = mp;
		for (std::size_t i = 0; i < mp2.size(); i++)
			std::cout << mp2[i] << std::endl;
		mp2.clear();
		mp2.insert(++mp.begin(), mp.end());
		std::cout << mp2.size() << std::endl;
		for (std::size_t i = 0; i < mp2.size(); i++)
			std::cout << mp2[i] << std::endl;
		mp2.erase(mp2.begin(), mp2.end());
		std::cout << mp2.size() << std::endl;
		for (std::size_t i = 0; i < mp2.size(); i++)
			std::cout << mp2[i] << std::endl;
		mp.erase(14);
		for (std::size_t i = 0; i < mp.size(); i++)
			std::cout << mp[i] << std::endl;
		std::cout << mp.insert(ft::make_pair(10, 10)).first->first << std::endl;
		mp.erase(--mp.end());
		for (std::size_t i = 0; i < mp.size(); i++)
			std::cout << mp[i] << std::endl;
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
	std::cout << CYAN << "---------------- ITERATORS -----------------\n" << RESET;
	{
		begin_time = clock();
		std::cout.rdbuf(std_ss.rdbuf());
		std::map<int, unsigned int> mp;
		for (std::size_t i = 0; i < 20; i++)
			std::cout << mp.insert(std::make_pair(i, i + 42)).second << std::endl;	
		for (std::map<int, unsigned int>::iterator it = mp.begin(); it != mp.end(); it++)
			std::cout << it->first << " " << it->second << std::endl;
		std::map<int, unsigned int>::reverse_iterator rev = mp.rbegin();
		for (; rev != mp.rend(); rev++)
			std::cout << rev->first << " " << rev->second << std::endl;
		rev = mp.rbegin();
		std::map<int, unsigned int>::reverse_iterator rev2 = rev;
		std::cout << (++rev2)->first << std::endl;
		for (std::map<int, unsigned int>::const_iterator it = --mp.end(); it != mp.begin(); it--)
			std::cout << it->second << std::endl;
		std::cout << (++(++mp.begin()))->first << std::endl;
		std::cout << mp.find(10)->first << std::endl;	
		mp[10] = 0;
		std::cout << mp.find(10)->first << std::endl;	
		mp.erase(10);
		std::map<int, unsigned int>::iterator cit = mp.begin();
		std::map<int, unsigned int>::const_iterator it = cit;
		std::cout << it->first << std::endl;
		std::cout.rdbuf(cout_buf);
		std_diff = begin_time - clock();
	}
	{
		begin_time = clock();
		std::cout.rdbuf(ft_ss.rdbuf());
		ft::map<int, unsigned int> mp;
		for (std::size_t i = 0; i < 20; i++)
			std::cout << mp.insert(ft::make_pair(i, i + 42)).second << std::endl;	
		for (ft::map<int, unsigned int>::iterator it = mp.begin(); it != mp.end(); it++)
			std::cout << it->first << " " << it->second << std::endl;
		ft::map<int, unsigned int>::reverse_iterator rev = mp.rbegin();
		for (; rev != mp.rend(); rev++)
			std::cout << rev->first << " " << rev->second << std::endl;
		rev = mp.rbegin();
		ft::map<int, unsigned int>::reverse_iterator rev2 = rev;
		std::cout << (++rev2)->first << std::endl;
		for (ft::map<int, unsigned int>::const_iterator it = --mp.end(); it != mp.begin(); it--)
			std::cout << it->second << std::endl;
		std::cout << (++(++mp.begin()))->first << std::endl;
		std::cout << mp.find(10)->first << std::endl;	
		mp[10] = 0;
		std::cout << mp.find(10)->first << std::endl;	
		mp.erase(10);
		ft::map<int, unsigned int>::iterator cit = mp.begin();
		ft::map<int, unsigned int>::const_iterator it = cit;
		std::cout << it->first << std::endl;
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
	std::cout << CYAN << "----------- RELATIONAL OPERATORS -----------\n" << RESET;
	{
		begin_time = clock();
		std::cout.rdbuf(std_ss.rdbuf());
		std::map<int, int> mp;
		for (std::size_t i = 0; i < 42; i++)
			std::cout << mp.insert(std::make_pair(i, i + 42)).second << std::endl;
		std::map<int, int>::iterator it = mp.begin();
		std::map<int, int>::iterator it2 = mp.begin();
		std::map<int, int>::iterator it3 = mp.find(0);
		std::cout << (it == it2) << std::endl;
		std::cout << (it != it3) << std::endl;
		it2++;
		std::cout << (it == it2) << std::endl;
		it3 = it2;
		std::cout << (it3 == it2) << std::endl;
		std::cout << (it3 == it) << std::endl;
		std::map<int, int> mp2;
		for (std::size_t i = 0; i < 42; i++)
			std::cout << mp2.insert(std::make_pair(i, i)).first->first << std::endl;
		std::cout << (mp == mp2) << std::endl;
		std::cout << (mp < mp2) << std::endl;
		std::cout << (mp >= mp2) << std::endl;
		mp2 = mp;
		std::cout << (mp >= mp2) << std::endl;
		std::cout << (mp < mp2) << std::endl;
		std::cout.rdbuf(cout_buf);
		std_diff = begin_time - clock();
	}
	{
		begin_time = clock();
		std::cout.rdbuf(ft_ss.rdbuf());	
		ft::map<int, int> mp;
		for (std::size_t i = 0; i < 42; i++)
			std::cout << mp.insert(ft::make_pair(i, i + 42)).second << std::endl;
		ft::map<int, int>::iterator it = mp.begin();
		ft::map<int, int>::iterator it2 = mp.begin();
		ft::map<int, int>::iterator it3 = mp.find(0);
		std::cout << (it == it2) << std::endl;
		std::cout << (it != it3) << std::endl;
		it2++;
		std::cout << (it == it2) << std::endl;
		it3 = it2;
		std::cout << (it3 == it2) << std::endl;
		std::cout << (it3 == it) << std::endl;
		ft::map<int, int> mp2;
		for (std::size_t i = 0; i < 42; i++)
			std::cout << mp2.insert(ft::make_pair(i, i)).first->first << std::endl;
		std::cout << (mp == mp2) << std::endl;
		std::cout << (mp < mp2) << std::endl;
		std::cout << (mp >= mp2) << std::endl;
		mp2 = mp;
		std::cout << (mp >= mp2) << std::endl;
		std::cout << (mp < mp2) << std::endl;
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
