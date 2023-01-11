#pragma once

#include <iostream>

namespace ft
{

template<class T>
struct is_integral
{
	static const bool value = std::is_convertible<T, bool>::value ||
							std::is_convertible<T, char>::value ||
							std::is_convertible<T, signed char>::value ||
							std::is_convertible<T, unsigned char>::value ||
							std::is_convertible<T, short>::value ||
							std::is_convertible<T, unsigned short>::value ||
							std::is_convertible<T, int>::value ||
							std::is_convertible<T, unsigned int>::value ||
							std::is_convertible<T, long>::value ||
							std::is_convertible<T, unsigned long>::value ||
							std::is_convertible<T, long long>::value ||
							std::is_convertible<T, unsigned long long>::value;
};

}
