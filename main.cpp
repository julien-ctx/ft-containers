#include "vector.hpp"

#include "tools.hpp"

#include "utils/reverse_iterator.hpp"

#define TESTED_TYPE int
#define TESTED_NAMESPACE ft

int main()
{
  
    std::vector<int> v(5, 5);
    try
    {
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

