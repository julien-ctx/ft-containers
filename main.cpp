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
    std::reverse_iterator<std::vector<int>::iterator> rit = v.rbegin();
    
    // Use the -> operator to access the value of the last element
    std::cout << rit->value << std::endl;
    NL();
}
