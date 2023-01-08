#include "Vector.hpp"

#include "tools.hpp"

#include "utils/reverse_iterator.hpp"

void trash()
{
    std::vector<int> v1;
    v1.push_back(5);
    v1.push_back(452);
    v1.push_back(453);
    v1.push_back(2);
    v1.push_back(545);


    ft::vector<int> v2(v1.begin(), v1.end());
    int size = v2.size();
    for (int i = 0; i < size; i++)
        PRINT(v2[i]);
    PRINT(v2.capacity());
}

int main()
{
    trash();
    system("leaks ft_containers");
}
