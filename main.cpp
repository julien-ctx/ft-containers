/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:02:51 by jcauchet          #+#    #+#             */
/*   Updated: 2022/11/19 12:08:17 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"
#include <vector>

int main()
{
    int val = 1;
    unsigned int n = 5;
 
    // fill constructor
    std::vector<int> vec(n, val);
 
    for (int i= 0; (unsigned int)i < n; i++) {
        std::cout << i << ' ';
    }
 
    return 0;
}
