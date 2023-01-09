#include "vector.hpp"

#include "tools.hpp"

#include "utils/reverse_iterator.hpp"

#define TESTED_TYPE int
#define TESTED_NAMESPACE ft

void trash()
{
    // std::vector<int> v(5, 5);
  
    // v.reserve(4);
    // PRINT(v.capacity());
    // PRINT(v.size());

    std::vector<int> v1(5, 5);
    std::vector<int> v2;

    v2 = v1;

    PRINT(v2.size());
    PRINT(v2.capacity());

}

int main(void)
{
    trash();
}
