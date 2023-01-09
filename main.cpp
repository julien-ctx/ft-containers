#include "vector.hpp"

#include "tools.hpp"

#include "utils/reverse_iterator.hpp"

#define TESTED_TYPE int
#define TESTED_NAMESPACE std

int trash()
{
    TESTED_NAMESPACE::vector<int> v(5, 5);
  
    try
    {
        TESTED_NAMESPACE::vector<int> v2(5, 5);
        v2[4] = 53;
        return (v == v2) ? 1 : 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    



}

int main(void)
{
    return trash();
}
