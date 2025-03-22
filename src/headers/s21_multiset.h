#ifndef S21_MULTISET_H
#define S21_MULTISET_H

#include "../s21_containers.h"

namespace s21 {
template <class T>
class multiset {
 public:
  using key_type = T;
  using value_type = key_type;
  using reference = value_type&;
  using const_reference = const reference&;
  using iterator = typename rbt<value_type>::node::iterator;
  using const_iterator = typename rbt<value_type>::node::const_iterator;
  using size_type = size_t;

  multiset();
  multiset(const std::initializer_list<value_type>& items);
  multiset(const multiset& ms);
  multiset(multiset&& ms);
  ~multiset();
  multiset& operator=(const std::initializer_list<value_type>& items);
  multiset& operator=(const multiset& ms);
  multiset& operator=(multiset&& ms);

  iterator begin() noexcept;
  iterator end() noexcept;
  const_iterator cbegin() const noexcept;
  const_iterator cend() const noexcept;

  bool empty() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;

  void clear();
  iterator insert(const value_type& value);
  void erase(iterator pos);
  void swap(multiset& other);
  void merge(multiset& other);
  template <class... Args>
  vector<iterator> insert_many(Args&&... args);

  size_type count(const key_type& key);
  iterator find(const key_type& key);
  bool contains(const key_type& key);
  std::pair<iterator, iterator> equal_range(const key_type& key);
  iterator lower_bound(const key_type& key);
  iterator upper_bound(const key_type& key);

  friend bool operator==(const multiset& lhs, const multiset& rhs) {
    return lhs.size() == rhs.size() && lhs.tree_ == rhs.tree_;
  }
  friend bool operator!=(const multiset& lhs, const multiset& rhs) {
    return !(lhs == rhs);
  }

 private:
  rbt<value_type> tree_;
  size_t size_;
};

template <class T>
multiset<T>::multiset() : tree_(), size_(0) {}

template <class T>
multiset<T>::multiset(const std::initializer_list<value_type>& items)
    : multiset() {
  *this = items;
}

template <class T>
multiset<T>::multiset(const multiset& ms) : multiset() {
  tree_ = ms.tree_;
  size_ = ms.size_;
}

template <class T>
multiset<T>::multiset(multiset&& ms) : multiset() {
  tree_ = std::move(ms.tree_);
  std::swap(size_, ms.size_);
}

template <class T>
multiset<T>::~multiset() {
  clear();
}

template <class T>
multiset<T>& multiset<T>::operator=(
    const std::initializer_list<value_type>& items) {
  clear();
  for (auto iter = items.begin(); iter != items.end(); ++iter) insert(*iter);
  return *this;
}

template <class T>
multiset<T>& multiset<T>::operator=(multiset&& ms) {
  if (*this != ms) {
    tree_ = std::move(ms.tree_);
    std::swap(size_, ms.size_);
  }
  return *this;
}

template <class T>
multiset<T>& multiset<T>::operator=(const multiset& ms) {
  if (*this != ms) {
    clear();
    tree_ = ms.tree_;
    size_ = ms.size_;
  }
  return *this;
}

template <class T>
typename multiset<T>::iterator multiset<T>::begin() noexcept {
  return tree_.begin();
}

template <class T>
typename multiset<T>::iterator multiset<T>::end() noexcept {
  return tree_.end();
}

template <class T>
typename multiset<T>::const_iterator multiset<T>::cbegin() const noexcept {
  return tree_.cbegin();
}

template <class T>
typename multiset<T>::const_iterator multiset<T>::cend() const noexcept {
  return tree_.cend();
}

template <class T>
bool multiset<T>::empty() const noexcept {
  return size_ == 0;
}

template <class T>
typename multiset<T>::size_type multiset<T>::size() const noexcept {
  return size_;
}

template <class T>
typename multiset<T>::size_type multiset<T>::max_size() const noexcept {
  return (std::numeric_limits<size_type>::max() - sizeof(size_type) -
          sizeof(void*)) /
         (sizeof(value_type) + sizeof(void*) * 3 +
          sizeof(typename rbt<value_type>::node::Color));
}

template <class T>
void multiset<T>::clear() {
  tree_.clear();
  size_ = 0;
}

template <class T>
typename multiset<T>::iterator multiset<T>::insert(const value_type& value) {
  tree_.insert(value);
  ++size_;
  return tree_.search(value);
}

template <class T>
void multiset<T>::erase(iterator pos) {
  tree_.remove(*pos);
  --size_;
}

template <class T>
void multiset<T>::swap(multiset& other) {
  tree_.swap(other.tree_);
  std::swap(size_, other.size_);
}

template <class T>
void multiset<T>::merge(multiset& other) {
  for (iterator iter = other.begin(); iter != other.end(); ++iter)
    insert(*iter);
  other.clear();
}

template <class T>
template <class... Args>
vector<typename multiset<T>::iterator> multiset<T>::insert_many(
    Args&&... args) {
  vector<iterator> result;
  for (const auto& element : {args...}) result.push_back(insert(element));
  return result;
}

template <class T>
typename multiset<T>::size_type multiset<T>::count(const key_type& key) {
  size_type amount = 0;
  for (auto iter = find(key); iter != end() && *iter == key; ++iter) ++amount;
  return amount;
}

template <class T>
typename multiset<T>::iterator multiset<T>::find(const key_type& key) {
  return tree_.search(key);
}

template <class T>
bool multiset<T>::contains(const key_type& key) {
  return find(key) != end();
}

template <class T>
std::pair<typename multiset<T>::iterator, typename multiset<T>::iterator>
multiset<T>::equal_range(const key_type& key) {
  return {lower_bound(key), upper_bound(key)};
}

template <class T>
typename multiset<T>::iterator multiset<T>::lower_bound(const key_type& key) {
  return find(key);
}
template <class T>
typename multiset<T>::iterator multiset<T>::upper_bound(const key_type& key) {
  auto upper = lower_bound(key);
  while (upper != end() && *upper == key) ++upper;
  return upper;
}

}  // namespace s21
#endif