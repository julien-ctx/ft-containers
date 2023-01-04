/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:40:01 by jcauchet          #+#    #+#             */
/*   Updated: 2023/01/04 19:43:05 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

// This structure is used to provide a generic way of accessing iterator traits,
// depending on their attributes.

template <class Iter>
struct iterator_traits
{
	typedef typename Iter::value_type value_type;
	typedef typename Iter::difference_type difference_type;
	typedef typename Iter::iterator_category iterator_category;
	typedef typename Iter::pointer pointer;
	typedef typename Iter::reference reference;
};
