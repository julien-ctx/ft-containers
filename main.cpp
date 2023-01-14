#include "vector.hpp"

#include "tools.hpp"

#include "utils/reverse_iterator.hpp"
#include "utils/lexicographical_compare.hpp"

#define TESTED_NAMESPACE ft

#define T_SIZE_TYPE typename TESTED_NAMESPACE::vector<T>::size_type

template <typename T>
void    printSize(TESTED_NAMESPACE::vector<T> const &vct, bool print_content = true)
{
        const T_SIZE_TYPE size = vct.size();
        const T_SIZE_TYPE capacity = vct.capacity();
        const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
        // Cannot limit capacity's max value because it's implementation dependent

        std::cout << "size: " << size << std::endl;
        std::cout << "capacity: " << isCapacityOk << std::endl;
        std::cout << "max_size: " << vct.max_size() << std::endl;
        if (print_content)
        {
                typename TESTED_NAMESPACE::vector<T>::const_iterator it = vct.begin();
                typename TESTED_NAMESPACE::vector<T>::const_iterator ite = vct.end();
                std::cout << std::endl << "Content is:" << std::endl;
                for (; it != ite; ++it)
                        std::cout << "- " << *it << std::endl;
        }
        std::cout << "###############################################" << std::endl;
}


#define TESTED_TYPE int

template <class T, class Alloc>
void    cmp(const TESTED_NAMESPACE::vector<T, Alloc> &lhs, const TESTED_NAMESPACE::vector<T, Alloc> &rhs)
{
        static int i = 0;

        std::cout << "############### [" << i++ << "] ###############"  << std::endl;
        std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
        // std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
        // std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}


#include <algorithm>
#include <string>

struct MyComparator {
    bool operator()(const char& a, const char& b) const {
        return tolower(a) < tolower(b);
    }
};

int main()
{
    std::string s1 = "Hell";
    std::string s2 = "Hello";

    bool result = std::lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end(), MyComparator());
    std::cout << result << std::endl;
    result = ft::lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end(), MyComparator());
    std::cout << result << std::endl;
    return 0;
}

