#include "../includes/tools.hpp"
#include "../includes/map.hpp"

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
		std::pair<std::string, int> pair2("test", 1);
		std::pair<std::string, int> pair = std::make_pair<std::string, int>("test", 1);
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
		ft::pair<std::string, int> pair2("test", 1);
		ft::pair<std::string, int> pair = ft::make_pair<std::string, int>("test", 1);
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
}
