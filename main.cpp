#include "tools.hpp"

int main()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    std::vector<int>::reverse_iterator it = v.rbegin();
    for (; it != v.rend(); it++)
        PRINT(*it);
    NL();
    
}
