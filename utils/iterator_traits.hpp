/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:40:01 by jcauchet          #+#    #+#             */
/*   Updated: 2022/11/19 18:42:36 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

template <class T>
struct iterator_traits
{
	typedef typename T::value_type value_type;
	typedef typename T::difference_type difference_type;
	typedef typename T::iterator_category iterator_category;
	typedef typename T::pointer pointer;
	typedef typename T::reference reference;
};
