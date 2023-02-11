#include "../utils/tools.hpp"
#include "../containers/vector.hpp"

void timeDiff(clock_t &ft_diff, clock_t &std_diff)
{
	if (ft_diff > std_diff)
	{
		std::cout << "My implementation is " << ft_diff - std_diff << " ms slower."<< std::endl;
		std::cout << (ft_diff - std_diff) * 100 / std_diff << "\% slower" << std::endl;
	}
	else
	{
		std::cout << "STL implementation is " << std_diff - ft_diff << " ms slower."<< std::endl;
		std::cout << (std_diff - ft_diff) * 100 / ft_diff << "\% slower" << std::endl;
	}
}

void vectorTest()
{
	NL();
	std::cout << BLUE << "*************** VECTOR TESTS ***************\n" << RESET;
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
		std::cout.rdbuf(cout_buf);
		std_diff = begin_time - clock();
	}
	{
		begin_time = clock();
		std::cout.rdbuf(ft_ss.rdbuf());
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
		std::cout.rdbuf(cout_buf);
		std_diff = begin_time - clock();
	}
	{
		begin_time = clock();
		std::cout.rdbuf(ft_ss.rdbuf());
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

	std::cout << CYAN << "----------------- CAPACITY -----------------\n" << RESET;
	{
		begin_time = clock();
		std::cout.rdbuf(std_ss.rdbuf());
		std::vector<int> v;
		try
		{
			v.push_back(42);
			v.push_back(84);
			std::cout << v.capacity() << " " << v.size() << std::endl;	
			for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
				std::cout << *it << " ";
			v.reserve(10);
			for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
				std::cout << *it << " ";
			std::cout << v.capacity() << " " << v.size() << std::endl;	
			v.reserve(1);
			std::cout << v.capacity() << " " << v.size() << std::endl;	
			for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
				std::cout << *it << " ";
			NL();	
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout.rdbuf(cout_buf);
		std_diff = begin_time - clock();
	}
	{
		begin_time = clock();
		std::cout.rdbuf(ft_ss.rdbuf());
		ft::vector<int> v;
		try
		{
			v.push_back(42);
			v.push_back(84);
			std::cout << v.capacity() << " " << v.size() << std::endl;	
			for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
				std::cout << *it << " ";
			v.reserve(10);
			for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
				std::cout << *it << " ";
			std::cout << v.capacity() << " " << v.size() << std::endl;	
			v.reserve(1);
			std::cout << v.capacity() << " " << v.size() << std::endl;	
			for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
				std::cout << *it << " ";
			NL();	
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
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
		std::cout.rdbuf(cout_buf);
		std_diff = begin_time - clock();
	}
	{
		begin_time = clock();
		std::cout.rdbuf(ft_ss.rdbuf());
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
		std::cout.rdbuf(cout_buf);
		std_diff = begin_time - clock();
	}
	{
		begin_time = clock();
		std::cout.rdbuf(ft_ss.rdbuf());
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
		std::vector<unsigned int> v;
		for (unsigned int i = 0; i < 10; i++)
			v.push_back(i);
		try
		{
			std::cout << ft::distance(v.begin(), v.end()) << std::endl;
			std::cout << *(v.begin() + 2) << std::endl;
			std::cout << *(v.end() - 1) << std::endl;
			std::cout << v.back() << std::endl;
			std::cout << *++v.begin() << std::endl;
			std::cout << (v.begin() < (v.begin() + 1)) << std::endl;

			std::vector<unsigned int>::iterator it = v.begin();

			std::cout << (it == v.begin()) << std::endl;

			std::vector<unsigned int>::reverse_iterator it2 = v.rbegin();	

			std::cout << (it2 == std::vector<unsigned int>::reverse_iterator((v.end() - 1))) << std::endl;	
			it++;
			std::vector<unsigned int>::const_iterator const_it = v.begin();
			std::cout << (it - const_it) << std::endl;
			for (; it2 != v.rend(); it2++)
				std::cout << *it2 << " ";
			NL();
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout.rdbuf(cout_buf);
		std_diff = begin_time - clock();
	}
	{
		begin_time = clock();
		std::cout.rdbuf(ft_ss.rdbuf());
		ft::vector<unsigned int> v;
		for (unsigned int i = 0; i < 10; i++)
			v.push_back(i);
		try
		{
			std::cout << ft::distance(v.begin(), v.end()) << std::endl;
			std::cout << *(v.begin() + 2) << std::endl;
			std::cout << *(v.end() - 1) << std::endl;
			std::cout << v.back() << std::endl;
			std::cout << *++v.begin() << std::endl;
			std::cout << (v.begin() < (v.begin() + 1)) << std::endl;

			ft::vector<unsigned int>::iterator it = v.begin();

			std::cout << (it == v.begin()) << std::endl;

			ft::vector<unsigned int>::reverse_iterator it2 = v.rbegin();	

			std::cout << (it2 == ft::vector<unsigned int>::reverse_iterator((v.end() - 1))) << std::endl;	
			it++;
			ft::vector<unsigned int>::const_iterator const_it = v.begin();
			std::cout << (it - const_it) << std::endl;
			for (; it2 != v.rend(); it2++)
				std::cout << *it2 << " ";
			NL();
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
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
		std::vector<int> v;
		for (int i = 0; i < 10; i++)
			v.push_back(i);
		std::vector<int> v2;
		for (int i = 0; i < 10; i++)
			v2.push_back(i);
		try
		{
			std::cout << (v == v2) << std::endl;
			v2.insert(v2.begin() + 1, -1);
			std::cout << (v != v2) << std::endl;
			std::cout << (v <= v2) << std::endl;	
			std::cout << (v > v2) << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout.rdbuf(cout_buf);
		std_diff = begin_time - clock();
	}
	{
		begin_time = clock();
		std::cout.rdbuf(ft_ss.rdbuf());
		ft::vector<int> v;
		for (int i = 0; i < 10; i++)
			v.push_back(i);
		ft::vector<int> v2;
		for (int i = 0; i < 10; i++)
			v2.push_back(i);
		try
		{
			std::cout << (v == v2) << std::endl;
			v2.insert(v2.begin() + 1, -1);
			std::cout << (v != v2) << std::endl;
			std::cout << (v <= v2) << std::endl;	
			std::cout << (v > v2) << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
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
