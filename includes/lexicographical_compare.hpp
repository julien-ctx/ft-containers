#pragma once

namespace ft
{

/*
Lexicographical comparison is used in vector to allow operators of comparison
to work correctly. It compares two vectors in the given range of iterators.
*/

template<class InputIt1, class InputIt2>
bool lexicographical_compare(InputIt1 first1, InputIt1 last1, 
	InputIt2 first2, InputIt2 last2)
{
	for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
    {
        if (*first1 < *first2)
            return true;
        if (*first2 < *first1)
            return false;
    }
    return first1 == last1 && first2 != last2;
}

/*
This version of lexicographical_compare uses comp function to determine the
return value. It can be a self-implemented function.
*/

template<class InputIt1, class InputIt2, class Compare>
bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
	InputIt2 first2, InputIt2 last2, Compare comp)
{
	for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
    {
        if (comp (*first1, *first2))
            return true;
        if (comp (*first2, *first1))
            return false;
    }
    return first1 == last1 && first2 != last2;
}

}
