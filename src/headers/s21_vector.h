#ifndef S21_VECTOR_H
#define S21_VECTOR_H

#include "stl_declarations.h"
namespace s21 {

template <class T>
class vector {
 public:
  //--------------------------------------------------- Vector Member type
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using iterator = T*;
  using const_iterator = const T*;
  using size_type = size_t;

  vector();
  vector(size_type n);
  vector(std::initializer_list<value_type> const& items);
  vector(const vector& v);
  vector(vector&& v);
  ~vector();
  vector& operator=(vector&& v);

  vector& operator=(vector& v);
  vector& operator=(std::initializer_list<value_type> const& items);

  //--------------------------------------------------- Vector Element access

  reference at(size_type pos);
  reference operator[](size_type pos);
  const_reference front();
  const_reference back();
  iterator data();

  //--------------------------------------------------- Vector Iterators

  iterator begin();
  iterator end();

  //--------------------------------------------------- Vector Capacity

  bool empty();
  size_type size();
  size_type max_size();
  void reserve(size_type size);
  size_type capacity();
  void shrink_to_fit();

  //--------------------------------------------------- Vector Modifiers

  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void swap(vector& other);

  //----------------------------------------------------- add

  iterator rend();
  iterator rbegin();
  void resize(size_type size);
  void erase(iterator pos1, iterator pos2);
  void insert(iterator pos, size_type size, const_reference value);

  //-----------------------------------------------------

  template <class... Args>
  iterator insert_many(const_iterator pos, Args&&... args);
  template <class... Args>
  void insert_many_back(Args&&... args);

 private:
  size_type capacity_;
  size_type size_;
  T* data_;
};

//--------------------------------------------------- Vector Member functions

// default constructor, creates empty vector
template <class T>
vector<T>::vector() : capacity_(0), size_(0), data_(nullptr){};

// parameterized constructor, creates the vector of size n
template <class T>
vector<T>::vector(size_type n) : capacity_(n), size_(n) {
  if (n > this->max_size()) {
    throw std::length_error("cannot create s21::vector larger than max_size()");
  }
  if (typeid(value_type) == typeid(bool&))
    capacity_ =
        n / __WORDSIZE * __WORDSIZE + ((n % __WORDSIZE) > 0 ? __WORDSIZE : 0);
  data_ = new value_type[capacity_]{};
};

// initializer list constructor, creates vector initizialized using
// std::initializer_list
template <class T>
vector<T>::vector(std::initializer_list<value_type> const& items)
    : capacity_(items.size()), size_(0), data_(new value_type[capacity_]{}) {
  for (auto it = items.begin(); it != items.end(); ++it, ++size_) {
    data_[size_] = value_type(*it);
  }
  if (typeid(value_type) == typeid(bool&))
    capacity_ = this->size_ / __WORDSIZE * __WORDSIZE +
                ((this->size_ % __WORDSIZE) > 0 ? __WORDSIZE : 0);
};

// copy constructor
template <class T>
vector<T>::vector(const vector& v)
    : capacity_{v.capacity_},
      size_{v.size_},
      data_{new value_type[capacity_]{}} {
  for (size_type i = 0; i < size_; ++i) {
    data_[i] = value_type(v.data_[i]);
  }
};

// move constructor
template <class T>
vector<T>::vector(vector&& v)
    : capacity_(v.capacity_), size_(v.size_), data_(v.data_) {
  v.capacity_ = 0;
  v.size_ = 0;
  v.data_ = nullptr;
};

// destructor
template <class T>
vector<T>::~vector() {
  delete[] data_;
};

// assignment operator overload for moving object
template <class T>
vector<T>& vector<T>::operator=(vector&& v) {
  if (this != &v) {
    delete[] data_;
    capacity_ = v.capacity_;
    size_ = v.size_;
    data_ = new value_type[capacity_]{};
    for (size_type i = 0; i < size_; ++i) {
      data_[i] = value_type(v.data_[i]);
    }
  }
  return *this;
};
// template <class T>
// vector<T> &vector<T>::operator=(vector &&v) {
//   if (&v != this) {
//     size_ = v.size_;
//     capacity_ = v.capacity_;
//     delete[] data_;
//     data_ = v.data_;

//     v.data_ = nullptr;
//     v.capacity_ = 0;
//     v.size_ = 0;
//   }
//   return *this;
// }

template <class T>
vector<T>& vector<T>::operator=(
    std::initializer_list<value_type> const& items) {
  size_ = items.size();
  if (capacity_ <= items.size()) {
    delete[] data_;
    capacity_ = items.size();
    data_ = new T[capacity_]{};
  }
  for (size_t i = 0; i < size_; i++) {
    data_[i] = items.begin()[i];
  }
  return *this;
};

template <class T>
vector<T>& vector<T>::operator=(vector& v) {
  if (&v != this) {
    delete[] data_;
    size_ = v.size();
    capacity_ = v.capacity();
    data_ = new T[capacity_]{};
    for (size_t i = 0; i < size_; i++) {
      data_[i] = v[i];
    }
  }
  return *this;
};

//--------------------------------------------------- Vector Element access

// access specified element with bounds checking
template <class T>
typename vector<T>::reference vector<T>::at(size_type pos) {
  if (pos > size_) throw std::out_of_range("Index out of range");
  return data_[pos];
};

// access specified element
template <class T>
typename vector<T>::reference vector<T>::operator[](size_type pos) {
  return data_[pos];
};

// access the first element
template <class T>
typename vector<T>::const_reference vector<T>::front() {
  return data_[0];
};

// access the last element
template <class T>
typename vector<T>::const_reference vector<T>::back() {
  return data_[size_ - 1];
};

// direct access to the underlying array
template <class T>
typename vector<T>::iterator vector<T>::data() {
  return data_;
};

//--------------------------------------------------- Vector Iterators

// returns an iterator to the beginning
template <class T>
typename vector<T>::iterator vector<T>::begin() {
  return iterator(data_);
};

// returns an iterator to the end
template <class T>
typename vector<T>::iterator vector<T>::end() {
  return iterator(data_ + size_);
};

//--------------------------------------------------- Vector Capacity

// checks whether the container is empty
template <class T>
bool vector<T>::empty() {
  return size_ ? false : true;
};

// returns the number of elements
template <class T>
typename vector<T>::size_type vector<T>::size() {
  return size_;
};

// returns the maximum possible number of elements
template <class T>
typename vector<T>::size_type vector<T>::max_size() {
  size_type reserve_size = 1;
  if (typeid(value_type) == typeid(bool&)) reserve_size = 64;
  return (((powl(2, __WORDSIZE) / sizeof(value_type)) / 2 - reserve_size));
};

// allocate storage of size elements and copies current array elements to a
// newely allocated array
template <class T>
void vector<T>::reserve(size_type size) {
  if (size > this->max_size()) throw std::length_error("vector::reserve");
  if (size_ <= size) {
    vector<value_type> temp(size);
    temp.size_ = 0;
    for (size_type i = 0; i < size_; ++i, ++temp.size_) {
      temp.data_[i] = value_type(data_[i]);
    }
    this->swap(temp);
  }
};

// returns the number of elements that can be held in currently allocated
// storage
template <class T>
typename vector<T>::size_type vector<T>::capacity() {
  return capacity_;
};

// memory usage by freeing unused memory
template <class T>
void vector<T>::shrink_to_fit() {
  vector<value_type> temp(size_);
  for (size_type i = 0; i < size_; ++i) {
    temp.data_[i] = value_type(data_[i]);
  }
  this->swap(temp);
};

//--------------------------------------------------- Vector Modifiers

// clears the contents
template <class T>
void vector<T>::clear() {
  if (typeid(value_type) == typeid(bool&))
    capacity_ = this->size_ / __WORDSIZE * __WORDSIZE +
                ((this->size_ % __WORDSIZE) > 0 ? __WORDSIZE : 0);
  size_ = 0;
};

// inserts elements into concrete pos and returns the iterator
// that points to the new element
template <class T>
typename vector<T>::iterator vector<T>::insert(iterator pos,
                                               const_reference value) {
  size_type idx = std::distance(begin(), pos);
  if (capacity_ == size_) reserve(capacity_ * 2);
  for (size_type i = size_; i > idx; --i) {
    data_[i] = data_[i - 1];
  }
  data_[idx] = value;
  ++size_;
  return (data_ + idx);
};

// erases element at pos
template <class T>
void vector<T>::erase(iterator pos) {
  size_type idx = std::distance(begin(), pos);
  for (size_type i = idx; i < size_ - 1; ++i) {
    data_[i] = data_[i + 1];
  }
  --size_;
  if (typeid(value_type) == typeid(bool&))
    capacity_ = this->size_ / __WORDSIZE * __WORDSIZE +
                ((this->size_ % __WORDSIZE) > 0 ? __WORDSIZE : 0);
};

// adds an element to the end
template <class T>
void vector<T>::push_back(const_reference value) {
  if (capacity_ == size_) reserve(capacity_ == 0 ? 1 : capacity_ * 2);
  data_[size_++] = value;
};

// removes the last element
template <class T>
void vector<T>::pop_back() {
  --size_;
};

// swaps the contents
template <class T>
void vector<T>::swap(vector& other) {
  vector<value_type> temp(*this);
  *this = std::move(other);
  other = std::move(temp);
};

//----------------------------------------------------- add

template <class T>
typename vector<T>::iterator vector<T>::rend() {
  return iterator(data_ + 1);
};
template <class T>
typename vector<T>::iterator vector<T>::rbegin() {
  return iterator(data_ + size_ - 1);
};
template <class T>
void vector<T>::resize(size_type size) {
  if (size_ < size) {
    vector<value_type> temp(size);
    for (size_type i = 0; i < size_; ++i) {
      temp.data_[i] = value_type(data_[i]);
    }
    this->swap(temp);
  } else {
    size_ = size;
  }
};
template <class T>
void vector<T>::erase(iterator pos1, iterator pos2) {
  size_type idx_1 = std::distance(begin(), pos1);
  size_type idx_2 = std::distance(pos1, pos2);
  for (size_type i = idx_1; i < size_ - idx_2; ++i) {
    data_[i] = data_[i + idx_2];
  }
  size_ -= idx_2;
  if (typeid(value_type) == typeid(bool&))
    capacity_ = this->size_ / __WORDSIZE * __WORDSIZE +
                ((this->size_ % __WORDSIZE) > 0 ? __WORDSIZE : 0);
};
template <class T>
void vector<T>::insert(iterator pos, size_type size, const_reference value) {
  size_type idx = std::distance(begin(), pos);
  if (capacity_ < (size_ + size)) reserve(capacity_ * 2);
  for (size_type i = (size_ + size); i >= (idx + size); --i) {
    data_[i] = data_[i - size];
  }
  for (size_type i = 0; i < size; i++) {
    data_[idx++] = value;
  }
  size_ += size;
};

//-----------------------------------------------------

template <class T>
template <class... Args>
typename vector<T>::iterator vector<T>::insert_many(const_iterator pos,
                                                    Args&&... args) {
  iterator result = nullptr;
  for (const auto& element : {args...})
    result = insert((pos.get_node_pointer()), element);
  return result;
}

template <class T>
template <class... Args>
void vector<T>::insert_many_back(Args&&... args) {
  for (const auto& element : {args...}) push_back(element);
}

}  // namespace s21

#endif
