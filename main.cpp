#include "vector.hpp"
#include "stack.hpp"

#include "tools.hpp"

#include <iostream>
#include <vector>


#include "utils/reverse_iterator.hpp"
#include "utils/lexicographical_compare.hpp"


template <typename T_STACK>
void    printSize(T_STACK &stck, bool print_content = 1)
{
        std::cout << "size: " << stck.size() << std::endl;
        if (print_content)
        {
                std::cout << std::endl << "Content was:" << std::endl;
                while (stck.size() != 0) {
                        std::cout << "- " << stck.top() << std::endl;
                        stck.pop();
                }
        }
        std::cout << "###############################################" << std::endl;
}


template <class T_STACK>
void    cmp(const T_STACK &lhs, const T_STACK &rhs)
{
        static int i = 0;

        std::cout << "############### [" << i++ << "] ###############"  << std::endl;
        std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
        std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
        std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}

int             main(void)
{
        ft::vector<int>  ctnr;

        ctnr.push_back(21);
        ctnr.push_back(42);
        ctnr.push_back(1337);
        ctnr.push_back(19);
        ctnr.push_back(0);
        ctnr.push_back(183792);

       ft::stack<int>        stck(ctnr);
        ft::stack<int>          stck2(ctnr);

        cmp(stck, stck);  // 0
        cmp(stck, stck2); // 1

        stck2.push(60);
        stck2.push(61);
        stck2.push(62);

        cmp(stck, stck2); // 2
        cmp(stck2, stck); // 3

        stck.push(42);

        cmp(stck, stck2); // 4
        cmp(stck2, stck); // 5

        stck.push(100);

        cmp(stck, stck2); // 6
        cmp(stck2, stck); // 7
        return (0);
}
