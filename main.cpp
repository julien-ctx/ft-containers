#include "vector.hpp"

#include "tools.hpp"

#include "utils/reverse_iterator.hpp"

#define TESTED_TYPE int
#define TESTED_NAMESPACE ft

void trash()
{
    ft::vector<int> v(5, 5);
  
    try
    {
        v.clear();
        PRINT(v.size());
        PRINT(v.capacity());
        PRINT(v[0]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    



}

int main(void)
{
    trash();
}
