# Containers: An Implementation Of C++ Containers | 42

## Overview
In this project I recreated **3 containers** of the STL in C++98 : **vector, stack and map**, from scratch. Each of them works the same way as the official versions, and even better in some cases.

### Vector

Vector is a **contiguous array** in memory that allows variables of any type to be stored and accessed via **indexes or iterators**.

In my implementation, the memory was allocated with **std::allocator**. This allowed me to correctly manage the capacity of the vector, as well as all the functions that modify it.

The vector has **random access iterators**. So I decided to create a class with the same functionality, and this was certainly the most difficult part of the vector implementation.

### Stack

The stack is a contiguous array of elements of any type which has the particularity of respecting the **Last In, First Out (LIFO) principle**.

In fact, to create this container, I made a vector inheritance, and I simply **reversed the direction of navigation** by inverting the values returned by accessors like `top()` and modifiers like `pop()`.

### Map

Map is a binary tree allowing to store **pairs (key/value)**. I first coded my own `std::pair` and then started the implementation of map.

Unlike vector and stack, the memory is no longer contiguous but organized according to the keys. This allows to increase the performances when it comes to find an element in the array with `find()`, or to delete it with `erase()`.

So I implemented not a simple binary tree but a **Red-Black Tree**! Red-Black trees are very similar to a standard BST; however, they contain a few extra lines of code that describe a red and black node, as well as a few more operations.

The coloured nodes allow for the data structure to be **self-balanced**. Here are the main advantages to use a Red-Black Tree over a simple BST:

- Binary Search Tree time complexity in worst-case: O(n). 
- Red-Black Tree time complexity in worst-case: O(log n).

## Getting Started
All my containers are coded inside a namespace called `std`. To use them, you just have to include the correct `.hpp` file and call my implementation `std::vector` and so forth...

You can check the **performance tests** and the comparison between my **implementation of STL containers** and the real one by using the following command:

```
make && ./ft_containers
```
