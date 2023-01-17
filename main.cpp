#include "vector.hpp"

#include "tools.hpp"

#include <iostream>
#include <vector>


#include "utils/reverse_iterator.hpp"
#include "utils/lexicographical_compare.hpp"

#define TESTED_NAMESPACE ft

#define T_SIZE_TYPE typename TESTED_NAMESPACE::vector<T>::size_type

#define TESTED_TYPE int

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

#define TEST std 
int main()
{
    ft::vector<int> v(5, 42);
    for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;
    v.insert(v.begin(), 5, 24);
       for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;
    std::cout << v.capacity() << std::endl;
    std::cout << v.size() << std::endl;
}

