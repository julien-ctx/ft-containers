#pragma once

#include <iostream>
#include <string>

// My containers implementation includes
#include "Vector.hpp"

#include "utils/iterator_traits.hpp"
#include "utils/reverse_iterator.hpp"

// STL containers includes
#include <vector>
#include <map>

#define RESET   "\033[0m"
#define BLACK   "\033[1m\033[30m"      /* Bold Black */
#define RED     "\033[1m\033[31m"      /* Bold Red */
#define GREEN   "\033[1m\033[32m"      /* Bold Green */
#define YELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BLUE    "\033[1m\033[34m"      /* Bold Blue */
#define MAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define CYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLD    "\033[1m\033[37m"      /* Bold White */

#define PRINT(x) std::cout << BOLD << x << std::endl << RESET; 
#define NL() std::cout << std::endl;
