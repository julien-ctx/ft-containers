#pragma once

// https://h-deb.clg.qc.ca/Sujets/TrucsScouts/Comprendre_enable_if.html

namespace ft
{

template<bool, class T>
struct enable_if {};

template <class T>
struct enable_if<true, T>
{
    typedef T value;
};

}
