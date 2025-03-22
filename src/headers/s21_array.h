#ifndef S21_ARRAY_H
#define S21_ARRAY_H

#include "stl_declarations.h"

namespace s21 {
template <class T, size_t S>
class array {
 public:
  //--------------------------------- Array Member Type
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;
  //--------------------------------- Array Member Functions
  array();
  array(std::initializer_list<value_type> const &items);
  array(const array &a);
  array(array &&a);
  ~array();
  array &operator=(array &a);
  array &operator=(array &&a);
  //--------------------------------- Array Element access
  reference at(size_type pos);
  reference operator[](size_type pos) noexcept;
  const_reference front() noexcept;
  const_reference back() noexcept;
  iterator data();
  //--------------------------------- Array Iterators
  iterator begin();
  iterator end();
  //--------------------------------- Array Capacity
  bool empty();
  size_type size();
  size_type max_size();
  //--------------------------------- Array Modifiers
  void swap(array &other);
  void fill(const_reference value);
  //---------------------------------
 private:
  const size_type _size = S;
  T _data[S];
};

//--------------------------------- Array Member Functions

template <class T, size_t S>
array<T, S>::array() {
  for (size_type i = 0; i < _size; ++i) _data[i] = T();
};

template <class T, size_t S>
array<T, S>::array(std::initializer_list<value_type> const &items) {
  size_type i = 0;
  for (auto &item : items) {
    if (i < _size) _data[i++] = item;
  }
  while (i < _size) {
    _data[i++] = T();
  }
};

template <class T, size_t S>
array<T, S>::~array(){};

template <class T, size_t S>
array<T, S>::array(const array &a) {
  for (size_type i = 0; i < a._size; ++i) {
    _data[i] = a._data[i];
  }
};

template <class T, size_t S>
array<T, S>::array(array &&a) {
  if (this != &a) {
    for (size_type i = 0; i < _size; ++i) {
      _data[i] = std::move(a._data[i]);
    }
  }
};

template <class T, size_t S>
array<T, S> &array<T, S>::operator=(array &a) {
  if (this != &a) {
    for (size_type i = 0; i < _size; ++i) {
      _data[i] = a._data[i];
    }
  }
  return *this;
}

template <class T, size_t S>
array<T, S> &array<T, S>::operator=(array &&a) {
  if (this != &a) {
    for (size_type i = 0; i < _size; ++i) {
      _data[i] = a._data[i];
    }
  }
  return *this;
}

//--------------------------------- Array Element access

template <class T, size_t S>
typename array<T, S>::reference array<T, S>::at(size_type pos) {
  if (pos >= _size)
    throw std::out_of_range("Out Of Range");
  else
    return _data[pos];
}

template <class T, size_t S>
typename array<T, S>::reference array<T, S>::operator[](
    size_type pos) noexcept {
  return _data[pos];
}

template <class T, size_t S>
typename array<T, S>::const_reference array<T, S>::front() noexcept {
  return _data[0];
}

template <class T, size_t S>
typename array<T, S>::const_reference array<T, S>::back() noexcept {
  return _data[_size - 1];
}

template <class T, size_t S>
typename array<T, S>::iterator array<T, S>::data() {
  return _data;
}

//--------------------------------- Array Iterators

template <class T, size_t S>
typename array<T, S>::iterator array<T, S>::begin() {
  return _data;
};

template <class T, size_t S>
typename array<T, S>::iterator array<T, S>::end() {
  return _data + _size;
};

//--------------------------------- Array Capacity

template <class T, size_t S>
bool array<T, S>::empty() {
  return _size > 0 ? false : true;
};

template <class T, size_t S>
typename array<T, S>::size_type array<T, S>::size() {
  return _size;
}

template <class T, size_t S>
typename array<T, S>::size_type array<T, S>::max_size() {
  return _size;
}

//--------------------------------- Array Modifiers

template <class T, size_t S>
void array<T, S>::swap(array &other) {
  for (size_type i = 0; i < _size; ++i) {
    T tmp = _data[i];
    _data[i] = other[i];
    other[i] = tmp;
  }
}

template <class T, size_t S>
void array<T, S>::fill(const_reference value) {
  for (size_type i = 0; i < _size; ++i) {
    _data[i] = value;
  }
}
}  // namespace s21

#endif
