#include "vector.hpp"

#include "tools.hpp"

#include "utils/reverse_iterator.hpp"

#define TESTED_TYPE int
#define TESTED_NAMESPACE std

int main()
{
  
    std::vector<int> v(5, 5);
    try
    {
        TESTED_NAMESPACE::vector<int>::iterator it = v.begin();
        it += 1;
        std::cout << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

