#include "vector.hpp"

#include "tools.hpp"

#include "utils/reverse_iterator.hpp"


#define TESTED_NAMESPACE std

int main()
{
    TESTED_NAMESPACE::vector<int> v(5, 5);
    TESTED_NAMESPACE::vector<int>::iterator it1 = v.begin();
    TESTED_NAMESPACE::vector<int>::iterator it2 = v.begin();
    if (it1 != it2)
        std::cout << "equal\n";
    else
        std::cout << "not\n";
}
