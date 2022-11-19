/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:02:51 by jcauchet          #+#    #+#             */
/*   Updated: 2022/11/19 15:35:49 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"
#include <vector>
#include <limits.h>

int *trash()
{
    ft::Vector<int> Test(5, 42);
    return Test.getArray();
}

int main()
{
    int *array = trash();
    for (int i = 0; i < 5; i++)
        std::cout << array[i] << std::endl;
    system("leaks ft_containers");
}
