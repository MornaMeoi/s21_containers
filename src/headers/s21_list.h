#ifndef S21_LIST_H
#define S21_LIST_H

#include "stl_declarations.h"

namespace s21 {
template <class T>
class list {
 public:
  struct node;

  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using iterator = typename list<T>::node::iterator;
  using const_iterator = typename list<T>::node::const_iterator;
  using size_type = size_t;

  list();
  list(size_type size);
  list(const list& other);
  list(list&& other);
  list(const std::initializer_list<value_type>& ilist);
  ~list();
  list& operator=(const list& other);
  list& operator=(list&& other) noexcept;
  list& operator=(const std::initializer_list<value_type>& ilist);

  const_reference front() const;
  const_reference back() const;

  iterator begin() noexcept;
  iterator end() noexcept;
  const_iterator cbegin() const noexcept;
  const_iterator cend() const noexcept;

  bool empty() const;
  size_type size() const;
  size_type max_size() const;

  void clear();
  iterator insert(iterator pos, const_reference element);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void swap(list& other);
  void merge(list& other);
  void splice(const_iterator pos, list& other);
  void reverse();
  void unique();
  void sort();
  template <class... Args>
  iterator insert_many(const_iterator pos, Args&&... args);
  template <class... Args>
  void insert_many_back(Args&&... args);
  template <class... Args>
  void insert_many_front(Args&&... args);

  friend bool operator==(const list& lhs, const list& rhs) {
    bool result = lhs.size() == rhs.size();
    for (typename list<T>::const_iterator lhs_iter = lhs.cbegin(),
                                          rhs_iter = rhs.cbegin();
         result && lhs_iter != lhs.cend(); ++lhs_iter, ++rhs_iter)
      if (*lhs_iter != *rhs_iter) result = false;
    return result;
  }
  friend bool operator!=(const list& lhs, const list& rhs) {
    return !(lhs == rhs);
  }

 private:
  node *head_, *tail_;
  size_type size_;
};

template <class T>
list<T>::list() : head_(nullptr), tail_(nullptr), size_(0) {}

template <class T>
list<T>::list(size_type size) : head_(new node()), tail_(head_), size_(size) {
  for (size_type i = 1; i < size; ++i, tail_ = tail_->next_) {
    tail_->next_ = new node();
    tail_->next_->prev_ = tail_;
  }
}

template <class T>
list<T>::list(const list& other) : list() {
  for (const_iterator iter = other.cbegin(); iter != other.cend(); ++iter)
    push_back(*iter);
}

template <class T>
list<T>::list(list&& other) : list() {
  std::swap(head_, other.head_);
  std::swap(tail_, other.tail_);
  std::swap(size_, other.size_);
}

template <class T>
list<T>::list(const std::initializer_list<value_type>& ilist) : list() {
  *this = ilist;
}

template <class T>
list<T>::~list() {
  clear();
}

template <class T>
list<T>& list<T>::operator=(const list& other) {
  if (*this != other) {
    clear();
    *this = std::move(list<T>(other));
  }
  return *this;
}

template <class T>
list<T>& list<T>::operator=(list&& other) noexcept {
  if (*this != other) {
    std::swap(head_, other.head_);
    std::swap(tail_, other.tail_);
    std::swap(size_, other.size_);
  }
  return *this;
}

template <class T>
list<T>& list<T>::operator=(const std::initializer_list<value_type>& ilist) {
  clear();
  for (const T& element : ilist) push_back(element);
  return *this;
}

template <class T>
typename list<T>::const_reference list<T>::front() const {
  return head_->value_;
}

template <class T>
typename list<T>::const_reference list<T>::back() const {
  return tail_->value_;
}

template <class T>
typename list<T>::iterator list<T>::begin() noexcept {
  return iterator(head_);
}

template <class T>
typename list<T>::iterator list<T>::end() noexcept {
  return empty() ? iterator(tail_) : iterator(tail_->next_);
}

template <class T>
typename list<T>::const_iterator list<T>::cbegin() const noexcept {
  return const_iterator(head_);
}

template <class T>
typename list<T>::const_iterator list<T>::cend() const noexcept {
  return empty() ? const_iterator(tail_) : const_iterator(tail_->next_);
}

template <class T>
typename list<T>::size_type list<T>::size() const {
  return size_;
}

template <class T>
bool list<T>::empty() const {
  return size_ == 0;
}

template <class T>
typename list<T>::size_type list<T>::max_size() const {
  return (std::numeric_limits<size_type>::max() - sizeof(size_type) -
          sizeof(void*) * 2) /
         (sizeof(value_type) + sizeof(void*) * 2);
}

template <class T>
void list<T>::clear() {
  while (!empty()) pop_back();
}

template <class T>
typename list<T>::iterator list<T>::insert(iterator pos,
                                           const_reference element) {
  ++size_;
  node* new_node = new node(element, pos.get_node_pointer());
  if (new_node->next_ != nullptr) {
    if (new_node->next_->prev_ != nullptr) {
      new_node->prev_ = new_node->next_->prev_;
      new_node->prev_->next_ = new_node;
    }
    new_node->next_->prev_ = new_node;
  }
  if (pos.get_node_pointer() == head_) head_ = new_node;
  return new_node;
}

template <class T>
void list<T>::erase(iterator pos) {
  if (pos.get_node_pointer()) {
    if (pos->next_ != nullptr) pos->next_->prev_ = pos->prev_;
    if (pos->prev_ != nullptr) pos->prev_->next_ = pos->next_;
    if (pos.get_node_pointer() == head_) head_ = pos->next_;
    if (pos.get_node_pointer() == tail_) tail_ = pos->prev_;
    --size_;
    delete pos.get_node_pointer();
  }
}

template <class T>
void list<T>::push_back(const_reference element) {
  ++size_;
  node* new_node = new node(element, nullptr, tail_);
  if (tail_ != nullptr)
    tail_->next_ = new_node;
  else
    head_ = new_node;
  tail_ = new_node;
}

template <class T>
void list<T>::pop_back() {
  erase(tail_);
}

template <class T>
void list<T>::push_front(const_reference element) {
  insert(begin(), element);
}

template <class T>
void list<T>::pop_front() {
  erase(begin());
}

template <class T>
void list<T>::swap(list& other) {
  std::swap(tail_, other.tail_);
  std::swap(head_, other.head_);
  std::swap(size_, other.size_);
}

template <class T>
void list<T>::merge(list& other) {
  if (*this != other) {
    iterator left_iter = begin(), right_iter = other.begin();
    while (right_iter != other.end() && left_iter != end()) {
      if (*left_iter < *right_iter)
        ++left_iter;
      else {
        insert(left_iter, *right_iter);
        ++right_iter;
      }
    }
    while (right_iter != other.end()) {
      push_back(*right_iter);
      ++right_iter;
    }
    other.clear();
  }
}

template <class T>
void list<T>::splice(const_iterator pos, list& other) {
  iterator p = const_cast<node*>(pos.get_node_pointer());
  for (iterator iter = other.begin(); iter != end(); ++iter) insert(p, *iter);
  other.clear();
}

template <class T>
void list<T>::reverse() {
  size_type i = 0;
  for (iterator left = begin(), right = tail_; i != size() / 2;
       ++left, --right, ++i)
    left.get_node_pointer()->swap(right.get_node_pointer());
}

template <class T>
void list<T>::unique() {
  for (iterator left = begin(); left != end(); ++left)
    for (iterator right = left.get_node_pointer()->next_; right != end();
         ++right)
      if (*left == *right) {
        iterator temp = right;
        --right;
        erase(temp);
      }
}

template <class T>
void list<T>::sort() {
  for (iterator left = begin(); left != end(); ++left)
    for (iterator right = left.get_node_pointer()->next_; right != end();
         ++right)
      if (*left > *right)
        left.get_node_pointer()->swap(right.get_node_pointer());
}

template <class T>
template <class... Args>
typename list<T>::iterator list<T>::insert_many(const_iterator pos,
                                                Args&&... args) {
  iterator result = nullptr;
  for (const auto& element : {args...})
    result = insert(const_cast<node*>(pos.get_node_pointer()), element);
  return result;
}

template <class T>
template <class... Args>
void list<T>::insert_many_back(Args&&... args) {
  for (const auto& element : {args...}) push_back(element);
}

template <class T>
template <class... Args>
void list<T>::insert_many_front(Args&&... args) {
  for (const auto& element : {args...}) push_front(element);
}

template <class T>
bool operator==(const list<T>& lhs, const list<T>& rhs) {
  bool result = true;
  for (typename list<T>::iterator lhs_iter = lhs.begin(),
                                  rhs_iter = rhs.begin();
       lhs_iter != lhs.end() && rhs_iter != rhs.end && result;
       ++lhs_iter, ++rhs_iter)
    if (*lhs_iter != *rhs_iter) result = false;
  return result;
}

template <class T>
bool operator!=(const list<T>& lhs, const list<T>& rhs) {
  return !(lhs == rhs);
}

template <class T>
struct list<T>::node {
 public:
  class iterator;
  class const_iterator;
  friend class list;

  node();
  node(const_reference value, node* next_ = nullptr, node* prev_ = nullptr);
  ~node();
  friend bool operator==(const node& lhs, const node& rhs) {
    return lhs.value_ == rhs.value;
  }
  friend bool operator!=(const node& lhs, const node& rhs) {
    return !(lhs == rhs);
  }
  void swap(node* other);

 private:
  T value_;
  node* next_;
  node* prev_;
};

template <class T>
list<T>::node::node() : value_(value_type()), next_(nullptr), prev_(nullptr) {}

template <class T>
list<T>::node::node(const_reference value, node* next, node* prev)
    : value_(value), next_(next), prev_(prev) {}

template <class T>
list<T>::node::~node() {
  prev_ = next_ = nullptr;
}

template <class T>
void list<T>::node::swap(node* other) {
  std::swap(value_, other->value_);
}

template <class T>
class list<T>::node::iterator {
 public:
  iterator(const iterator& other);
  iterator(node* n);
  ~iterator();
  iterator& operator=(const iterator& other);
  iterator& operator=(node* n);
  iterator& operator++();
  iterator& operator--();
  reference operator*();
  node* operator->();
  friend bool operator==(const iterator& lhs, const iterator& rhs) {
    return lhs.iter_ == rhs.iter_;
  }
  friend bool operator!=(const iterator& lhs, const iterator& rhs) {
    return !(lhs == rhs);
  }
  node* get_node_pointer();

 private:
  node* iter_;
};

template <class T>
list<T>::node::iterator::iterator(const iterator& other) : iterator(nullptr) {
  *this = other;
}

template <class T>
list<T>::node::iterator::iterator(node* n) {
  *this = n;
}

template <class T>
list<T>::node::iterator::~iterator() {
  iter_ = nullptr;
}

template <class T>
typename list<T>::node::iterator& list<T>::node::iterator::operator=(
    const iterator& other) {
  if (*this != other) iter_ = other.iter_;
  return *this;
}

template <class T>
typename list<T>::node::iterator& list<T>::node::iterator::operator=(node* n) {
  iter_ = n;
  return *this;
}

template <class T>
typename list<T>::node::iterator& list<T>::node::iterator::operator++() {
  iter_ = iter_->next_;
  return *this;
}

template <class T>
typename list<T>::node::iterator& list<T>::node::iterator::operator--() {
  iter_ = iter_->prev_;
  return *this;
}

template <class T>
typename list<T>::reference list<T>::node::iterator::operator*() {
  return iter_->value_;
}

template <class T>
typename list<T>::node* list<T>::node::iterator::operator->() {
  return iter_;
}

template <class T>
typename list<T>::node* list<T>::node::iterator::get_node_pointer() {
  return iter_;
}

template <class T>
class list<T>::node::const_iterator {
 public:
  const_iterator(const const_iterator& other);
  const_iterator(node* n);
  ~const_iterator();
  const_iterator& operator=(const const_iterator& other);
  const_iterator& operator=(node* n);
  const_iterator& operator++();
  const_iterator& operator--();
  const_reference operator*();
  const node* operator->();
  friend bool operator==(const const_iterator& lhs, const const_iterator& rhs) {
    return lhs.iter_ == rhs.iter_;
  }
  friend bool operator!=(const const_iterator& lhs, const const_iterator& rhs) {
    return !(lhs == rhs);
  }
  const node* get_node_pointer();

 private:
  const node* iter_;
};

template <class T>
list<T>::node::const_iterator::const_iterator(const const_iterator& other)
    : const_iterator(nullptr) {
  *this = other;
}

template <class T>
list<T>::node::const_iterator::const_iterator(node* n) {
  *this = n;
}

template <class T>
list<T>::node::const_iterator::~const_iterator() {
  iter_ = nullptr;
}

template <class T>
typename list<T>::node::const_iterator&
list<T>::node::const_iterator::operator=(const const_iterator& other) {
  if (*this != other) iter_ = other.iter_;
  return *this;
}

template <class T>
typename list<T>::node::const_iterator&
list<T>::node::const_iterator::operator=(node* n) {
  iter_ = n;
  return *this;
}

template <class T>
typename list<T>::node::const_iterator&
list<T>::node::const_iterator::operator++() {
  iter_ = iter_->next_;
  return *this;
}

template <class T>
typename list<T>::node::const_iterator&
list<T>::node::const_iterator::operator--() {
  iter_ = iter_->prev_;
  return *this;
}

template <class T>
typename list<T>::const_reference list<T>::node::const_iterator::operator*() {
  return iter_->value_;
}

template <class T>
const typename list<T>::node* list<T>::node::const_iterator::operator->() {
  return iter_;
}

template <class T>
const typename list<T>::node*
list<T>::node::const_iterator::get_node_pointer() {
  return iter_;
}

}  // namespace s21
#endif
