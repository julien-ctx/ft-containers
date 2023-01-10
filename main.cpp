#include "vector.hpp"

#include "tools.hpp"

#include "utils/reverse_iterator.hpp"

#define TESTED_TYPE int
#define TESTED_NAMESPACE ft

int trash()
{
    TESTED_NAMESPACE::vector<int> v;
  
    try
    {
        v.pop_back();
        PRINT(v.capacity());
        PRINT(v.size());
        NL();
        for (size_t i = 0; i < v.size(); i++)
            std::cout << v[i] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return false;

}

int main(void)
{
    return trash();
}
