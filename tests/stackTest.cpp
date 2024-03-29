#include "../utils/tools.hpp"
#include "../containers/stack.hpp"

void stackTest()
{
	NL();
	std::cout << BLUE << "*************** STACK TESTS ****************\n" << RESET;
	NL();

	std::stringstream ft_ss;
	std::stringstream std_ss;
	std::streambuf* cout_buf = std::cout.rdbuf();
	clock_t begin_time;
	clock_t ft_diff;
	clock_t std_diff;

	std::cout << CYAN << "--------------- CONSTRUCTORS ---------------\n" << RESET;
	{
		begin_time = clock();
		std::cout.rdbuf(std_ss.rdbuf());
		std::stack<std::string> s;
		std::cout << s.empty() << std::endl;
		std::cout.rdbuf(cout_buf);
		std_diff = begin_time - clock();
	}
	{
		begin_time = clock();
		std::cout.rdbuf(ft_ss.rdbuf());
		ft::stack<std::string> s;
		std::cout << s.empty() << std::endl;	
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

	std::cout << CYAN << "---------------- MODIFIERS -----------------\n" << RESET;
	{
		begin_time = clock();
		std::cout.rdbuf(std_ss.rdbuf());
		std::stack<std::string> s;
		std::cout << s.empty() << std::endl;
		s.push("First push");
		s.push("Second push");
		std::cout << s.empty() << std::endl;
		std::cout << s.size() << std::endl;
		std::cout << s.top() << std::endl;
		s.pop();
		std::cout << s.size() << std::endl;
		std::cout.rdbuf(cout_buf);
		std_diff = begin_time - clock();
	}
	{
		begin_time = clock();
		std::cout.rdbuf(ft_ss.rdbuf());
		ft::stack<std::string> s;
		std::cout << s.empty() << std::endl;
		s.push("First push");
		s.push("Second push");
		std::cout << s.empty() << std::endl;
		std::cout << s.size() << std::endl;
		std::cout << s.top() << std::endl;
		s.pop();
		std::cout << s.size() << std::endl;
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
		std::stack<std::string> s;
		std::cout << s.empty() << std::endl;
		s.push("First push");
		s.push("Second push");
		std::stack<std::string> s2 = s;
		std::cout << (s == s2) << std::endl;
		std::cout << (s <= s2) << std::endl;
		s.pop();
		std::cout << (s >= s2) << std::endl;
		std::cout << (s > s2) << std::endl;
		std::stack<std::string> s3;
		std::stack<std::string> s4;
		std::cout << (s3 != s4) << std::endl;	
		s4.push("Test");
		std::cout << (s < s2) << std::endl;	
		std::cout.rdbuf(cout_buf);
		std_diff = begin_time - clock();
	}
	{
		begin_time = clock();
		std::cout.rdbuf(ft_ss.rdbuf());
		ft::stack<std::string> s;
		std::cout << s.empty() << std::endl;
		s.push("First push");
		s.push("Second push");
		ft::stack<std::string> s2 = s;
		std::cout << (s == s2) << std::endl;
		std::cout << (s <= s2) << std::endl;
		s.pop();
		std::cout << (s >= s2) << std::endl;
		std::cout << (s > s2) << std::endl;
		ft::stack<std::string> s3;
		ft::stack<std::string> s4;
		std::cout << (s3 != s4) << std::endl;	
		s4.push("Test");
		std::cout << (s < s2) << std::endl;	
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
