#ifndef STL_DECL_H
#define STL_DECL_H

// #include <stack>
#include <cmath>
#include <initializer_list>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <typeinfo>
#include <utility>

namespace s21 {
template <class T>
class vector;
template <class T>
class list;
template <class T>
class set;
template <class T1, class T2>
class map;
template <class T, class container = s21::list<T>>
class stack;
template <class T, class container = s21::list<T>>
class queue;
template <class T, size_t S>
class array;
template <class T>
class multiset;
}  // namespace s21

#endif