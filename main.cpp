#include "vector.hpp"

#include "tools.hpp"

#include "utils/reverse_iterator.hpp"

#define TESTED_TYPE int
#define TESTED_NAMESPACE ft

int main(void)
{
    ft::vector<int> v(5, 55);
    PRINT(v[4]);
    // TESTED_NAMESPACE::vector<TESTED_TYPE> v(5, 5);
    // PRINT(v[2]);
    
        // TESTED_NAMESPACE::vector<TESTED_TYPE> vct(7);

        // for (unsigned long int i = 0; i < vct.size(); ++i)
        // {
        //         vct.at(i) = (vct.size() - i) * 3;
        //         std::cout << "vct.at(): " << vct.at(i) << " | ";
        //         std::cout << "vct[]: " << vct[i] << std::endl;
        // }

        // TESTED_NAMESPACE::vector<TESTED_TYPE> const vct_c(vct);

        // std::cout << "front(): " << vct.front() << " " << vct_c.front() << std::endl;
        // std::cout << "back(): " << vct.back() << " " <<  vct_c.back() << std::endl;

        // try {
        //         vct.at(10) = 42;
        // }
        // catch (std::out_of_range &e) {
        //         std::cout << "Catch out_of_range exception!" << std::endl;
        // }
        // catch (std::exception &e) {
        //         std::cout << "Catch exception: " << e.what() << std::endl;
        // }
        // return (0);
}
