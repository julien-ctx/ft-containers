#include "../tools.hpp"
#include "../vector.hpp"

void vectorTest()
{
	NL();
	std::cout << BLUE << "*************** VECTOR TESTS ***************\n" << RESET;
	NL();

	std::cout << CYAN << "--------------- CONSTRUCTORS ---------------\n" << RESET;
	std::cout << BOLD << "              ⇊ std::vector ⇊               \n" << RESET;
	{
		std::vector<int> v;
		std::vector<int> v2(10, 42);
		std::vector<int> v3(v2.begin() + 2, v2.begin() + 5);
		std::vector<int> v4(v3);
		std::cout << v.capacity() << " " << v.size() << std::endl;
		std::cout << v2.capacity() << " " << v2.size() << std::endl;
		std::cout << v3.capacity() << " " << v3.size() << std::endl;
		std::cout << v4.capacity() << " " << v4.size() << std::endl;
		for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << " ";
		NL();
		for (std::vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
			std::cout << *it << " ";
		NL();
		for (std::vector<int>::iterator it = v3.begin(); it != v3.end(); it++)
			std::cout << *it << " ";
		NL();
		for (std::vector<int>::iterator it = v4.begin(); it != v4.end(); it++)
			std::cout << *it << " ";
		NL();
		NL();
	}
	std::cout << BOLD << "              ⇊ ft::vector ⇊                \n" << RESET;
	{
		ft::vector<int> v;
		ft::vector<int> v2(10, 42);
		ft::vector<int> v3(v2.begin() + 2, v2.begin() + 5);
		ft::vector<int> v4(v3);
		std::cout << v.capacity() << " " << v.size() << std::endl;
		std::cout << v2.capacity() << " " << v2.size() << std::endl;
		std::cout << v3.capacity() << " " << v3.size() << std::endl;
		std::cout << v4.capacity() << " " << v4.size() << std::endl;
		for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << " ";
		NL();
		for (ft::vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
			std::cout << *it << " ";
		NL();
		for (ft::vector<int>::iterator it = v3.begin(); it != v3.end(); it++)
			std::cout << *it << " ";
		NL();
		for (ft::vector<int>::iterator it = v4.begin(); it != v4.end(); it++)
			std::cout << *it << " ";
		NL();
	}
	std::cout << CYAN << "--------------------------------------------\n\n" << RESET;
	std::cout << CYAN << "------------------- SIZE -------------------\n" << RESET;
	std::cout << BOLD << "              ⇊ std::vector ⇊               \n" << RESET;
	{
		std::vector<int> v;
		try
		{
			v.push_back(42);
			v.push_back(84);
			std::cout << v.capacity() << " " << v.size() << std::endl;	
			v.resize(0);
			std::cout << v.capacity() << " " << v.size() << std::endl;	
			v.resize(10);
			std::cout << v.capacity() << " " << v.size() << std::endl;	
			for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
				std::cout << *it << " ";
			NL();	
			std::cout << v.max_size() << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << BOLD << "              ⇊ ft::vector ⇊                \n" << RESET;
	{
		ft::vector<int> v;
		try
		{
			v.push_back(42);
			v.push_back(84);
			std::cout << v.capacity() << " " << v.size() << std::endl;	
			v.resize(0);
			std::cout << v.capacity() << " " << v.size() << std::endl;	
			v.resize(10);
			std::cout << v.capacity() << " " << v.size() << std::endl;	
			for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
				std::cout << *it << " ";
			NL();	
			std::cout << v.max_size() << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << CYAN << "--------------------------------------------\n\n" << RESET;
	std::cout << CYAN << "------------------- ACCESS ------------------\n" << RESET;
	std::cout << BOLD << "              ⇊ std::vector ⇊               \n" << RESET;
	{
		std::vector<int> v;
		try
		{
			v.push_back(24);
			v.push_back(42);
			v.push_back(84);
			std::cout << v.at(1) << std::endl;
			std::cout << v[1] << std::endl;
			std::cout << v.front() << std::endl;
			std::cout << v.back() << std::endl;
			std::cout << *v.data() << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << BOLD << "              ⇊ ft::vector ⇊                \n" << RESET;
	{
		ft::vector<int> v;
		try
		{
			v.push_back(24);
			v.push_back(42);
			v.push_back(84);
			std::cout << v.at(1) << std::endl;
			std::cout << v[1] << std::endl;
			std::cout << v.front() << std::endl;
			std::cout << v.back() << std::endl;
			std::cout << *v.data() << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << CYAN << "--------------------------------------------\n\n" << RESET;
	std::cout << CYAN << "------------------- MODIFIERS ------------------\n" << RESET;
	std::cout << BOLD << "              ⇊ std::vector ⇊               \n" << RESET;
	{
		std::vector<int> v;
		try
		{
			v.push_back(24);
			for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
				std::cout << *it << " ";
			NL();
			v.push_back(42);
			for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
				std::cout << *it << " ";
			NL();
			v.pop_back();
			for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
				std::cout << *it << " ";
			NL();
			v.push_back(84);
			std::cout << *v.erase(v.begin()) << std::endl;
			for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
				std::cout << *it << " ";
			NL();
			v.clear();
			std::cout << v.empty() << std::endl;
			v.push_back(84);
			v.push_back(84);
			v.erase(v.begin(), v.end());
			std::cout << v.empty() << std::endl;
			NL();
			// Swap test:
			std::vector<std::string> v2(5, "v2");
			std::vector<std::string> v3(2, "v3");
			for (std::vector<std::string>::iterator it = v2.begin(); it != v2.end(); it++)
				std::cout << *it << " ";
			NL();	
			for (std::vector<std::string>::iterator it = v3.begin(); it != v3.end(); it++)
				std::cout << *it << " ";
			NL();
			v2.swap(v3);
			for (std::vector<std::string>::iterator it = v2.begin(); it != v2.end(); it++)
				std::cout << *it << " ";
			NL();	
			for (std::vector<std::string>::iterator it = v3.begin(); it != v3.end(); it++)
				std::cout << *it << " ";
			NL();
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << BOLD << "              ⇊ ft::vector ⇊                \n" << RESET;
	{
		ft::vector<int> v;
		try
		{
			v.push_back(24);
			for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
				std::cout << *it << " ";
			NL();
			v.push_back(42);
			for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
				std::cout << *it << " ";
			NL();
			v.pop_back();
			for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
				std::cout << *it << " ";
			NL();
			v.push_back(84);
			std::cout << *v.erase(v.begin()) << std::endl;
			for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
				std::cout << *it << " ";
			NL();
			v.clear();
			std::cout << v.empty() << std::endl;
			v.push_back(84);
			v.push_back(84);
			v.erase(v.begin(), v.end());
			std::cout << v.empty() << std::endl;
			NL();	
			// Swap test:
			ft::vector<std::string> v2(5, "v2");
			ft::vector<std::string> v3(2, "v3");
			for (ft::vector<std::string>::iterator it = v2.begin(); it != v2.end(); it++)
				std::cout << *it << " ";
			NL();	
			for (ft::vector<std::string>::iterator it = v3.begin(); it != v3.end(); it++)
				std::cout << *it << " ";
			NL();
			v2.swap(v3);
			for (ft::vector<std::string>::iterator it = v2.begin(); it != v2.end(); it++)
				std::cout << *it << " ";
			NL();	
			for (ft::vector<std::string>::iterator it = v3.begin(); it != v3.end(); it++)
				std::cout << *it << " ";
			NL();
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}
