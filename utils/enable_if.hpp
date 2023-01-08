#pragma once

// https://h-deb.clg.qc.ca/Sujets/TrucsScouts/Comprendre_enable_if.html

/*
Substitution Failure Is Not An Error (SFINAE) is a C++ language feature that allows the compiler to ignore
certain function template overloads or specializations when they are invalid.
This allows the compiler to continue looking for a valid function template overload or specialization,
rather than generating a compile-time error.
*/

namespace ft
{

template<bool, class T>
struct enable_if {};

template <class T>
struct enable_if<true, T>
{
    typedef T type;
};

}
