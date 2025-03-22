#ifndef S21_MAP_H
#define S21_MAP_H

#include "stl_declarations.h"

namespace s21 {
template <class T1, class T2>
class map {
 public:
  using key_type = T1;
  using mapped_type = T2;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type&;
  using const_reference = const reference;
  using iterator = typename rbt<value_type>::node::iterator;
  using const_iterator = typename rbt<value_type>::node::const_iterator;
  using size_type = size_t;

  map();
  map(const std::initializer_list<value_type>& items);
  map(const map<key_type, mapped_type>& m);
  map(map<key_type, mapped_type>&& m);
  ~map();
  map<key_type, mapped_type>& operator=(
      const std::initializer_list<value_type>& items);
  map<key_type, mapped_type>& operator=(const map<key_type, mapped_type>& m);
  map<key_type, mapped_type>& operator=(map<key_type, mapped_type>&& m);

  mapped_type& at(const key_type& key);
  mapped_type& operator[](const key_type& key);

  iterator begin() noexcept;
  iterator end() noexcept;
  const_iterator cbegin() const noexcept;
  const_iterator cend() const noexcept;

  bool empty() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;

  void clear();
  std::pair<iterator, bool> insert(const value_type& value);
  std::pair<iterator, bool> insert(const key_type& key, const mapped_type& obj);
  std::pair<iterator, bool> insert_or_assign(const key_type& key,
                                             const mapped_type& obj);
  void erase(iterator pos);
  void swap(map& other);
  void merge(map& other);
  template <class... Args>
  vector<std::pair<iterator, bool>> insert_many(Args&&... args);

  bool contains(const key_type& key);
  friend bool operator==(const map& lhs, const map& rhs) {
    return lhs.size() == rhs.size() && lhs.tree_ == rhs.tree_;
  }
  friend bool operator!=(const map& lhs, const map& rhs) {
    return !(lhs == rhs);
  }

 private:
  rbt<value_type> tree_;
  size_t size_;
};

template <class T1, class T2>
map<T1, T2>::map() : tree_(), size_(0) {}

template <class T1, class T2>
map<T1, T2>::map(const std::initializer_list<value_type>& items) : map() {
  *this = items;
}

template <class T1, class T2>
map<T1, T2>::map(const map<key_type, mapped_type>& m) : map() {
  tree_ = m.tree_;
  size_ = m.size_;
}

template <class T1, class T2>
map<T1, T2>::map(map<key_type, mapped_type>&& m) : map() {
  tree_ = std::move(m.tree_);
  std::swap(size_, m.size_);
}

template <class T1, class T2>
map<T1, T2>::~map() {
  clear();
}

template <class T1, class T2>
map<T1, T2>& map<T1, T2>::operator=(
    const std::initializer_list<value_type>& items) {
  clear();
  for (auto iter = items.begin(); iter != items.end(); ++iter) insert(*iter);
  return *this;
}

template <class T1, class T2>
map<T1, T2>& map<T1, T2>::operator=(map<key_type, mapped_type>&& m) {
  if (*this != m) {
    tree_ = std::move(m.tree_);
    std::swap(size_, m.size_);
  }
  return *this;
}

template <class T1, class T2>
map<T1, T2>& map<T1, T2>::operator=(const map<key_type, mapped_type>& m) {
  if (*this != m) {
    clear();
    tree_ = m.tree_;
    size_ = m.size_;
  }
  return *this;
}

template <class T1, class T2>
typename map<T1, T2>::mapped_type& map<T1, T2>::at(const key_type& key) {
  iterator result =
      tree_.search(value_type(key, mapped_type()),
                   [](const value_type& lhs, const value_type& rhs) {
                     return lhs.first == rhs.first;
                   });
  if (result.get_node_pointer() == nullptr) throw std::out_of_range("");
  return result->second;
}

template <class T1, class T2>
typename map<T1, T2>::mapped_type& map<T1, T2>::operator[](
    const key_type& key) {
  return (*(insert(key, mapped_type()).first)).second;
}

template <class T1, class T2>
typename map<T1, T2>::iterator map<T1, T2>::begin() noexcept {
  return tree_.begin();
}

template <class T1, class T2>
typename map<T1, T2>::iterator map<T1, T2>::end() noexcept {
  return tree_.end();
}

template <class T1, class T2>
typename map<T1, T2>::const_iterator map<T1, T2>::cbegin() const noexcept {
  return tree_.cbegin();
}

template <class T1, class T2>
typename map<T1, T2>::const_iterator map<T1, T2>::cend() const noexcept {
  return tree_.cend();
}

template <class T1, class T2>
void map<T1, T2>::clear() {
  tree_.clear();
  size_ = 0;
}

template <class T1, class T2>
bool map<T1, T2>::empty() const noexcept {
  return size_ == 0;
}

template <class T1, class T2>
typename map<T1, T2>::size_type map<T1, T2>::size() const noexcept {
  return size_;
}

template <class T1, class T2>
typename map<T1, T2>::size_type map<T1, T2>::max_size() const noexcept {
  return (std::numeric_limits<size_type>::max() - sizeof(size_type) -
          sizeof(void*)) /
         (sizeof(value_type) + sizeof(void*) * 3 +
          sizeof(typename rbt<value_type>::node::Color));
}

template <class T1, class T2>
std::pair<typename map<T1, T2>::iterator, bool> map<T1, T2>::insert(
    const value_type& value) {
  iterator result =
      tree_.search(value, [](const value_type& lhs, const value_type& rhs) {
        return lhs.first == rhs.first;
      });
  bool was_inserted = false;
  if (result == end()) {
    tree_.insert(value);
    result =
        tree_.search(value, [](const value_type& lhs, const value_type& rhs) {
          return lhs.first == rhs.first;
        });
    was_inserted = true;
    ++size_;
  }
  return {result, was_inserted};
}

template <class T1, class T2>
std::pair<typename map<T1, T2>::iterator, bool> map<T1, T2>::insert(
    const key_type& key, const mapped_type& obj) {
  return insert({key, obj});
}

template <class T1, class T2>
std::pair<typename map<T1, T2>::iterator, bool> map<T1, T2>::insert_or_assign(
    const key_type& key, const mapped_type& obj) {
  auto result = insert(key, obj);
  result.second = !result.second;
  if (result.second == false) result.first->second = obj;
  return result;
}

template <class T1, class T2>
void map<T1, T2>::erase(iterator pos) {
  tree_.remove(*pos);
  --size_;
}

template <class T1, class T2>
void map<T1, T2>::swap(map& other) {
  tree_.swap(other.tree_);
  std::swap(size_, other.size_);
}

template <class T1, class T2>
void map<T1, T2>::merge(map& other) {
  for (iterator iter = other.begin(); iter != other.end();)
    if (!contains(iter->first)) {
      insert(*iter);
      other.erase(iter);
      iter = other.begin();
    } else
      ++iter;
}

template <class T1, class T2>
template <class... Args>
vector<std::pair<typename map<T1, T2>::iterator, bool>>
map<T1, T2>::insert_many(Args&&... args) {
  vector<std::pair<iterator, bool>> result;
  for (const auto& element : {args...}) result.push_back(insert(element));
  return result;
}

template <class T1, class T2>
bool map<T1, T2>::contains(const key_type& key) {
  return tree_.search(value_type(key, mapped_type()),
                      [](const value_type& lhs, const value_type& rhs) {
                        return lhs.first == rhs.first;
                      }) != end();
}

}  // namespace s21
#endif