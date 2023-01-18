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
}
