#include "vector.hpp"

#include "tools.hpp"

#include "utils/reverse_iterator.hpp"


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

int main(void)
{
        const int size = 5;
        TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size);
        TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it_ = vct.begin();
        TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it(it_);

        for (int i = 0; i < size; ++i)
                vct[i] = (i + 1) * 5;
        printSize(vct);

        std::cout << (it_ == it.base()) << std::endl;
        std::cout << (it_ == (it + 3).base()) << std::endl;

        std::cout << *(it.base() + 1) << std::endl;
        std::cout << *(it - 3) << std::endl;
        std::cout << *(it - 3).base() << std::endl;
        it -= 3;
        std::cout << *it.base() << std::endl;

        std::cout << "TEST OFFSET" << std::endl;
        std::cout << *(it) << std::endl;
        std::cout << *(it).base() << std::endl;
        std::cout << *(it - 0) << std::endl;
        std::cout << *(it - 0).base() << std::endl;
        std::cout << *(it - 1).base() << std::endl;

        return (0);
}
