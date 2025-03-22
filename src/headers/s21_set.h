#ifndef S21_SET_H
#define S21_SET_H

#include "stl_declarations.h"

namespace s21 {
template <class T>
class set {
 public:
  using key_type = T;
  using value_type = T;
  using reference = value_type&;
  using const_reference = const reference;
  using iterator = typename rbt<value_type>::node::iterator;
  using const_iterator = typename rbt<value_type>::node::const_iterator;
  using size_type = size_t;

  //-------------------------------------------------------------
  // MemberFunctions

  set();
  set(std::initializer_list<value_type> const& items);
  set(const set& s);
  set(set&& s);
  ~set();
  rbt<T>& GetTree() { return tree_; };
  set& operator=(set&& s);
  set& operator=(const std::initializer_list<value_type>& items);
  bool operator==(set& s);
  bool operator!=(set& s);

  //------------------------------------------------------------- Iterators

  iterator begin() noexcept;
  iterator end() noexcept;
  const_iterator cbegin() const noexcept;
  const_iterator cend() const noexcept;

  //------------------------------------------------------------- Capacity

  bool empty();
  size_type size();
  size_type max_size();

  //------------------------------------------------------------- Modifiers

  void clear();
  std::pair<iterator, bool> insert(const value_type& value);
  void erase(iterator pos);
  void swap(set& other);
  void merge(set& other);

  //------------------------------------------------------------- Lookup

  iterator find(const T& key);
  bool contains(const T& key);

  //-------------------------------------------------------------

  template <class... Args>
  vector<std::pair<iterator, bool>> insert_many(Args&&... args);

 private:
  rbt<T> tree_;
  size_t size_;
};

//------------------------------------------------------------- MemberFunctions

template <class T>
set<T>::set() : tree_(), size_(0) {}

template <class T>
set<T>::set(const std::initializer_list<value_type>& items) : size_(0) {
  *this = items;
}

template <class T>
set<T>::set(const set<value_type>& s) {
  // if(*this != s) {
  this->size_ = s.size_;
  this->tree_ = s.tree_;
  // }
}

template <class T>
set<T>::set(set<value_type>&& s) {
  // *this = s;
  tree_ = std::move(s.tree_);
  std::swap(size_, s.size_);
}

template <class T>
set<T>::~set() {
  clear();
}

template <class T>
bool set<T>::operator==(set& s) {
  return this->begin() == s.begin();
}

template <class T>
bool set<T>::operator!=(set& s) {
  return !(*this == s);
}

template <class T>
set<T>& set<T>::operator=(const std::initializer_list<value_type>& items) {
  if (!this->empty()) clear();
  for (auto iter = items.begin(); iter != items.end(); ++iter) insert(*iter);
  return *this;
}

template <class T>
set<T>& set<T>::operator=(set&& s) {
  if (*this != s) {
    tree_ = s.tree_;
    size_ = s.size_;
  }
  return *this;
}

//------------------------------------------------------------- Iterators

template <class T>
typename set<T>::iterator set<T>::begin() noexcept {
  return tree_.begin();
}

template <class T>
typename set<T>::iterator set<T>::end() noexcept {
  return tree_.end();
}

template <class T>
typename set<T>::const_iterator set<T>::cbegin() const noexcept {
  return tree_.cbegin();
}

template <class T>
typename set<T>::const_iterator set<T>::cend() const noexcept {
  return tree_.cend();
}

//------------------------------------------------------------- Capacity

template <class T>
bool set<T>::empty() {
  return size_ == 0;
}

template <class T>
typename set<T>::size_type set<T>::size() {
  return size_;
}

template <class T>
typename set<T>::size_type set<T>::max_size() {
  return ((powl(2, __WORDSIZE) / 10) / sizeof(void*));
}
//------------------------------------------------------------- Modifiers

template <class T>
void set<T>::clear() {
  tree_.clear();
  size_ = 0;
}

template <class T>
std::pair<typename set<T>::iterator, bool> set<T>::insert(
    const value_type& value) {
  iterator result = tree_.search(value);
  bool was_inserted = false;
  if (result.get_node_pointer() == nullptr) {
    tree_.insert(value);
    result = tree_.search(value);
    was_inserted = true;
    ++size_;
  }
  return {result, was_inserted};
}

template <class T>
void set<T>::erase(iterator pos) {
  tree_.remove(*pos);
  --size_;
}

template <class T>
void set<T>::swap(set& other) {
  tree_.swap(other.tree_);
  std::swap(size_, other.size_);
}

template <class T>
void set<T>::merge(set& other) {
  for (iterator iter = other.begin(); iter != other.end();) {
    if (!contains(*iter)) {
      insert(*iter);
      other.erase(iter);
      iter = other.begin();
    } else {
      ++iter;
    }
  }
}

//------------------------------------------------------------- Lookup

template <class T>
typename set<T>::iterator set<T>::find(const T& key) {
  return tree_.search(key);
}

template <class T>
bool set<T>::contains(const T& key) {
  return tree_.search(key) != end();
}

//-------------------------------------------------------------

template <class T>
template <class... Args>
vector<std::pair<typename set<T>::iterator, bool>> set<T>::insert_many(
    Args&&... args) {
  vector<std::pair<iterator, bool>> result;
  for (const auto& element : {args...}) result.push_back(insert(element));
  return result;
}

}  // namespace s21

#endif