#include "tools.hpp"
#include "utils/reverse_iterator.hpp"

int main()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    std::vector<int>::iterator it = v.end();
    ft::reverse_iterator<std::vector<int>::iterator> rit(it);
    PRINT(rit[0]);
    NL();
}
