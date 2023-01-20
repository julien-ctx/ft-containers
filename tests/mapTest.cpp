#include "../tools.hpp"
#include "../map.hpp"

void mapTest()
{

	NL();
	std::cout << BLUE << "******************* MAP ********************\n" << RESET;
	NL();

	std::stringstream ft_ss;
	std::stringstream std_ss;
	std::streambuf* cout_buf = std::cout.rdbuf();

	std::cout << CYAN << "------------------ PAIR --------------------\n" << RESET;
	{
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
		std::pair<std::string, int> pair2("test", 1);
		std::pair<std::string, int> pair = std::make_pair<std::string, int>("test", 1);
		std::cout << (p2 == p) << std::endl;
		std::cout.rdbuf(cout_buf);
	}
	{
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
		ft::pair<std::string, int> pair2("test", 1);
		ft::pair<std::string, int> pair = ft::make_pair<std::string, int>("test", 1);
		std::cout << (p2 == p) << std::endl;
		std::cout.rdbuf(cout_buf);
	}
	std::cout << BOLD;
	std_ss.str() == ft_ss.str() ? std::cout << "DIFF OK ✅\n" : std::cout << "DIFF KO ❌\n";
	std::cout << RESET;
	ft_ss.clear();
	std_ss.clear();
	
}
