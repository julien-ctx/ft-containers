#include "../includes/tools.hpp"
#include "../includes/stack.hpp"

void stackTest()
{
	NL();
	std::cout << BLUE << "*************** STACK TESTS ****************\n" << RESET;
	NL();

	std::stringstream ft_ss;
	std::stringstream std_ss;
	std::streambuf* cout_buf = std::cout.rdbuf();

	std::cout << CYAN << "--------------- CONSTRUCTORS ---------------\n" << RESET;
	{
		std::cout.rdbuf(std_ss.rdbuf());
		std::stack<std::string> s;
		std::cout << s.empty() << std::endl;
		std::cout.rdbuf(cout_buf);
	}
	{
		std::cout.rdbuf(ft_ss.rdbuf());
		ft::stack<std::string> s;
		std::cout << s.empty() << std::endl;	
		std::cout.rdbuf(cout_buf);
	}
	std::cout << BOLD;
	std_ss.str() == ft_ss.str() ? std::cout << "DIFF OK ✅\n" : std::cout << "DIFF KO ❌\n";
	std::cout << RESET;
	ft_ss.clear();
	std_ss.clear();

	std::cout << CYAN << "---------------- MODIFIERS -----------------\n" << RESET;
	{
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
	}
	{
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
	}
	std::cout << BOLD;
	std_ss.str() == ft_ss.str() ? std::cout << "DIFF OK ✅\n" : std::cout << "DIFF KO ❌\n";
	std::cout << RESET;
	ft_ss.clear();
	std_ss.clear();

	std::cout << CYAN << "----------- RELATIONAL OPERATORS -----------\n" << RESET;
	{
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
	}
	{
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
	}
	std::cout << BOLD;
	std_ss.str() == ft_ss.str() ? std::cout << "DIFF OK ✅\n" : std::cout << "DIFF KO ❌\n";
	std::cout << RESET;
	ft_ss.clear();
	std_ss.clear();
}
