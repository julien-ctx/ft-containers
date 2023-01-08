#include "vector.hpp"

#include "tools.hpp"

#include "utils/reverse_iterator.hpp"

void trash()
{
    std::vector<int> v1(10, 42);
    std::cout << v1[3] << std::endl;
}

int main()
{
    trash();
    system("leaks ft_containers");
}
