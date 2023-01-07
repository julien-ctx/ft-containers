#include "tools.hpp"
#include "utils/reverse_iterator.hpp"

int main()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    try
    {
        // Access the fourth element of the vector using at
        int x = v.at(3);
    }
    catch (const std::out_of_range &e)
    {
        // Print the error message
        std::cerr  << e.what() << std::endl;
    }

    return 0;
    

}
