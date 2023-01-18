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
/*
single element (1)
        iterator insert (iterator position, const value_type& val);

fill (2)
    void insert (iterator position, size_type n, const value_type& val);

range (3)
        template <class InputIterator>
                void insert (iterator position, InputIterator first, InputIterator last);
*/

int             main(void)
{
        // TESTED_NAMESPACE::vector<TESTED_TYPE> vct(10);
        // TESTED_NAMESPACE::vector<TESTED_TYPE> vct2;
        TESTED_NAMESPACE::vector<TESTED_TYPE> vct3;

        // for (unsigned long int i = 0; i < vct.size(); ++i)
        //         vct[i] = (vct.size() - i) * 3;
        // printSize(vct);

        // vct2.insert(vct2.end(), 42);
        // vct2.insert(vct2.begin(), 2, 21);
        // printSize(vct2);

        // vct2.insert(vct2.end() - 2, 42);
        // printSize(vct2);

        // vct2.insert(vct2.end(), 2, 84);
        // printSize(vct2);

        // vct2.resize(4);
        // printSize(vct2);

        // vct2.insert(vct2.begin() + 2, vct.begin(), vct.end());
        // vct.clear();
        // printSize(vct2);

        // printSize(vct);

        for (int i = 0; i < 5; ++i)
        {
                vct3.insert(vct3.end(), i);
        }
        vct3.insert(vct3.begin() + 1, 2, 111);
        printSize(vct3);

        std::cout << "----------------------------------------" << std::endl;
        // std::cout << vct.size() << " " << vct.capacity() << std::endl;
        // std::cout << vct2.size() << " " << vct2.capacity() << std::endl;
        std::cout << vct3.size() << " " << vct3.capacity() << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        return (0);
}

// int main()
// {
//         std::vector<int> v(5, 20);
//         std::vector<int> v2(3, 10);
//         v.swap(v2);
//         for (size_t i = 0; i < v.size(); i++)
//             std::cout << v[i] << " ";
//         std::cout << std::endl;
// 		std::cout << v.size() << std::endl;
// 		std::cout << v2.size() << std::endl;
// 		for (size_t i = 0; i < v2.size(); i++)
//             std::cout << v2[i] << " ";
//         std::cout << std::endl;
// }

// int main ()
// {
//         TESTED_NAMESPACE::vector<TESTED_TYPE> foo(3, 15);
//         TESTED_NAMESPACE::vector<TESTED_TYPE> bar(5, 42);
//         TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator it_foo = foo.begin();
//         TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator it_bar = bar.begin();
//         foo.swap(bar);

//         std::cout << "AFTER SWAP" << std::endl;

//         std::cout << "foo contains:" << std::endl;
//         printSize(foo);
//         std::cout << "bar contains:" << std::endl;
//         printSize(bar);

//         std::cout << "Iterator validity:" << std::endl;
//         std::cout << (it_foo == bar.begin()) << std::endl;
//         std::cout << (it_bar == foo.begin()) << std::endl;

//         return (0);
// }

// #include <list>
// int             main(void)
// {
//         std::list<TESTED_TYPE> lst;
//         std::list<TESTED_TYPE>::iterator lst_it;
//         for (int i = 1; i < 5; ++i)
//                 lst.push_back(i * 3);

//         TESTED_NAMESPACE::vector<TESTED_TYPE> vct(lst.begin(), lst.end());
//         printSize(vct);
//         lst_it = lst.begin();
//         for (int i = 1; lst_it != lst.end(); ++i)
//                 *lst_it++ = i * 5;
//         vct.assign(lst.begin(), lst.end());
//         std::cout << "test\n";
//         printSize(vct);

//         vct.insert(vct.end(), lst.rbegin(), lst.rend());
//         printSize(vct);
//         return (0);
// }

// int main()
// {
// 	vectorTest();
// 	return 0;
// }
