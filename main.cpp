/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:02:51 by jcauchet          #+#    #+#             */
/*   Updated: 2022/11/19 19:57:57 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"
#include <vector>

int *trash()
{
    ft::Vector<int> Test(1, -1);
    std::cout << Test.max_size() << std::endl;
    return NULL;
}

int main()
{
    trash();
    exit(1);
    std::vector<int> Test(5, 42);
    for (std::vector<int>::iterator it = Test.begin(); it != Test.end(); it++)
    {
        *it = 44;
        std::cout << *it << std::endl;
    }
}
