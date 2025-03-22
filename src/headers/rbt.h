#ifndef RBT_H
#define RBT_H

#include "stl_declarations.h"

namespace s21 {
template <class T>
class rbt {
 public:
  struct node;
  using iterator = typename node::iterator;
  using const_iterator = typename node::const_iterator;
  using Color = typename node::Color;

  rbt();
  rbt(node* n);
  rbt(const rbt<T>& other);
  rbt(rbt<T>&& other);
  ~rbt();
  rbt<T>& operator=(const rbt<T>& other);
  rbt<T>& operator=(rbt<T>&& other);

  iterator begin();
  iterator end();
  const_iterator cbegin() const;
  const_iterator cend() const;

  void rotate_left(node* n);
  void rotate_right(node* n);
  void insert(const T& value);
  bool empty();
  void fix_insertion(node* t);
  void remove(const T& value);
  void fix_removing(node* p);
  void clear();
  iterator search(
      const T& value,
      bool (*equal)(const T& lhs, const T& rhs) =
          [](const T& lhs, const T& rhs) { return lhs == rhs; });
  void swap(rbt& other);
  node* get_root();
  friend bool operator==(const rbt& lhs, const rbt& rhs) {
    bool result = true;
    for (auto iter_l = lhs.cbegin(), iter_r = rhs.cbegin();
         result && iter_l != lhs.cend() && iter_r != rhs.cend();
         ++iter_l, ++iter_r) {
      if (*iter_l != *iter_r) result = false;
    }
    return result;
  }
  friend bool operator!=(const rbt& lhs, const rbt& rhs) {
    return !(lhs == rhs);
  }
  void _print_tree();

 private:
  node* root_;

  void _destruction_traversal(node* n);
  void _copying_traversal(node* parent, node** dest, const node* src);
};

template <class T>
rbt<T>::rbt() : rbt(nullptr) {}

template <class T>
rbt<T>::rbt(node* n) : root_(n) {}

template <class T>
void rbt<T>::_copying_traversal(node* parent, node** dest, const node* src) {
  *dest = new node(*src);
  (*dest)->parent_ = parent;
  if (src->left_ != nullptr)
    _copying_traversal(*dest, &((*dest)->left_), src->left_);
  if (src->right_ != nullptr)
    _copying_traversal(*dest, &((*dest)->right_), src->right_);
}

template <class T>
rbt<T>::rbt(const rbt<T>& other) : rbt() {
  _copying_traversal(nullptr, &root_, other.root_);
}

template <class T>
rbt<T>::rbt(rbt<T>&& other) : rbt() {
  *this = other;
}

template <class T>
rbt<T>::~rbt() {
  clear();
}

template <class T>
rbt<T>& rbt<T>::operator=(const rbt<T>& other) {
  clear();
  _copying_traversal(nullptr, &root_, other.root_);
  return *this;
}

template <class T>
rbt<T>& rbt<T>::operator=(rbt<T>&& other) {
  std::swap(root_, other.root_);
  return *this;
}

template <class T>
void rbt<T>::_destruction_traversal(node* n) {
  if (n != nullptr) {
    if (n->left_ != nullptr) _destruction_traversal(n->left_);
    if (n->right_ != nullptr) _destruction_traversal(n->right_);
    delete n;
  }
}

template <class T>
typename rbt<T>::iterator rbt<T>::begin() {
  iterator result(root_);
  result._push_all_left(result.iter_);
  return ++result;
}

template <class T>
typename rbt<T>::iterator rbt<T>::end() {
  return iterator(nullptr);
}

template <class T>
typename rbt<T>::const_iterator rbt<T>::cbegin() const {
  const_iterator result(root_);
  result._push_all_left(result.iter_);
  return ++result;
}

template <class T>
typename rbt<T>::const_iterator rbt<T>::cend() const {
  return const_iterator(nullptr);
}

template <class T>
void rbt<T>::rotate_left(node* n) {
  if (n == root_) root_ = n->right_;
  node* pivot = n->right_;
  pivot->parent_ = n->parent_;
  if (n->parent_ != nullptr) {
    if (n->parent_->left_ == n)
      n->parent_->left_ = pivot;
    else
      n->parent_->right_ = pivot;
  }
  n->right_ = pivot->left_;
  if (pivot->left_ != nullptr) pivot->left_->parent_ = n;
  n->parent_ = pivot;
  pivot->left_ = n;
}

template <class T>
void rbt<T>::rotate_right(node* n) {
  if (n == root_) root_ = n->left_;
  node* pivot = n->left_;
  pivot->parent_ = n->parent_;
  if (n->parent_ != nullptr) {
    if (n->parent_->left_ == n)
      n->parent_->left_ = pivot;
    else
      n->parent_->right_ = pivot;
  }
  n->left_ = pivot->right_;
  if (pivot->right_ != nullptr) pivot->right_->parent_ = n;
  n->parent_ = pivot;
  pivot->right_ = n;
}

template <class T>
void rbt<T>::insert(const T& value) {
  node* t = new node(value, node::Color::RED, nullptr, nullptr);
  if (empty()) {
    root_ = t;
    t->parent_ = nullptr;
  } else {
    node *p = root_, *q = nullptr;
    while (p != nullptr) {
      q = p;
      if (p->value_ < t->value_)
        p = p->right_;
      else
        p = p->left_;
    }
    t->parent_ = q;
    if (q->value_ < t->value_)
      q->right_ = t;
    else
      q->left_ = t;
  }
  fix_insertion(t);
}

template <class T>
bool rbt<T>::empty() {
  return root_ == nullptr;
}

template <class T>
void rbt<T>::fix_insertion(node* t) {
  if (t == root_)
    t->color_ = node::Color::BLACK;
  else {
    while (t->parent_ != nullptr && t->parent_->color_ == node::Color::RED) {
      if (t->get_grandparent() != nullptr &&
          t->parent_ == t->get_grandparent()->left_) {
        if (t->get_uncle() != nullptr &&
            t->get_uncle()->color_ == node::Color::RED) {
          t->parent_->color_ = node::Color::BLACK;
          t->get_uncle()->color_ = node::Color::BLACK;
          t->get_grandparent()->color_ = node::Color::RED;
          t = t->get_grandparent();
        } else {
          if (t == t->parent_->left_) {
            t = t->parent_;
            rotate_left(t);
          }
          t->parent_->color_ = node::Color::BLACK;
          t->get_grandparent()->color_ = node::Color::RED;
          rotate_right(t->get_grandparent());
        }
      } else {
        if (t->get_uncle() != nullptr &&
            t->get_uncle()->color_ == node::Color::RED) {
          t->parent_->color_ = node::Color::BLACK;
          t->get_uncle()->color_ = node::Color::BLACK;
          t->get_grandparent()->color_ = node::Color::RED;
          t = t->get_grandparent();
        } else {
          if (t == t->parent_->left_) {
            t = t->parent_;
            rotate_right(t);
          }
          t->parent_->color_ = node::Color::BLACK;
          t->get_grandparent()->color_ = node::Color::RED;
          rotate_left(t->get_grandparent());
        }
      }
    }
    root_->color_ = node::Color::BLACK;
  }
}

template <class T>
void rbt<T>::remove(const T& value) {
  node* p = root_;
  while (p->value_ != value)
    if (p->value_ < value)
      p = p->right_;
    else
      p = p->left_;
  if (p->left_ == nullptr && p->right_ == nullptr) {
    if (p == root_)
      root_ = nullptr;
    else {
      if (p == p->parent_->left_)
        p->parent_->left_ = nullptr;
      else
        p->parent_->right_ = nullptr;
    }
    delete p;
    return;
  }
  node* y = nullptr;
  if ((p->left_ != nullptr && p->right_ == nullptr) ||
      (p->left_ == nullptr && p->right_ != nullptr))
    y = p->left_ == nullptr ? p->right_ : p->left_;
  else {
    y = p->right_;
    while (y->left_ != nullptr) y = y->left_;
    if (y->right_ != nullptr) y->right_->parent_ = y->parent_;
    if (y == y->parent_->left_)
      y->parent_->left_ = y->right_;
    else
      y->parent_->right_ = y->right_;
    y->left_ = p->left_;
    if (y != p->right_) y->right_ = p->right_;
    if (p->left_ != nullptr) p->left_->parent_ = y;
    if (p->right_ != nullptr) p->right_->parent_ = y;
  }
  if (p != root_) {
    if (p == p->parent_->left_)
      p->parent_->left_ = y;
    else
      p->parent_->right_ = y;
  } else
    root_ = y;
  y->parent_ = p->parent_;
  if (p->color_ == node::Color::BLACK) fix_removing(y);
  delete p;
}

template <class T>
void rbt<T>::fix_removing(node* p) {
  while (p->color_ == node::Color::BLACK && p != root_) {
    if (p == p->parent_->left_) {
      node* brother = p->parent_->right_;
      if (brother->color_ == node::Color::RED) {
        brother->color_ = node::Color::BLACK;
        p->parent_->color_ = node::Color::RED;
        rotate_left(p->parent_);
      }
      if (brother->left_ != nullptr &&
          brother->left_->color_ == node::Color::BLACK &&
          brother->left_ != nullptr &&
          brother->left_->color_ == node::Color::BLACK)
        brother->color_ = node::Color::RED;
      else {
        if (brother->right_ != nullptr &&
            brother->right_->color_ == node::Color::BLACK &&
            brother->left_ != nullptr) {
          brother->left_->color_ = node::Color::BLACK;
          brother->color_ = node::Color::RED;
          rotate_right(brother);
        }
        brother->color_ = p->parent_->color_;
        p->parent_->color_ = node::Color::BLACK;
        brother->right_->color_ = node::Color::BLACK;
        rotate_left(p->parent_);
        p = root_;
      }
    } else {
      node* brother = p->parent_->left_;
      if (brother->color_ == node::Color::RED) {
        brother->color_ = node::Color::BLACK;
        p->parent_->color_ = node::Color::RED;
        rotate_right(p->parent_);
      }
      if (brother->left_ != nullptr &&
          brother->left_->color_ == node::Color::BLACK &&
          brother->left_ != nullptr &&
          brother->left_->color_ == node::Color::BLACK)
        brother->color_ = node::Color::RED;
      else {
        if (brother->left_ != nullptr &&
            brother->left_->color_ == node::Color::BLACK &&
            brother->right_ != nullptr) {
          brother->right_->color_ = node::Color::BLACK;
          brother->color_ = node::Color::RED;
          rotate_left(brother);
        }
        brother = p->parent_;
        p->parent_->color_ = node::Color::BLACK;
        brother->left_->color_ = node::Color::BLACK;
        rotate_right(p->parent_);
        p = root_;
      }
    }
  }
  p->color_ = node::Color::BLACK;
  root_->color_ = node::Color::BLACK;
}

template <class T>
void rbt<T>::clear() {
  _destruction_traversal(root_);
  root_ = nullptr;
}

template <class T>
typename rbt<T>::iterator rbt<T>::search(const T& value,
                                         bool (*equal)(const T& lhs,
                                                       const T& rhs)) {
  iterator result = begin();
  while (result != end() && !equal(*result, value)) ++result;
  return result;
}

template <class T>
void rbt<T>::swap(rbt& other) {
  std::swap(root_, other.root_);
}

template <class T>
void rbt<T>::_print_tree() {
  for (const_iterator iter = cbegin(); iter != nullptr; ++iter)
    std::cout << *iter << ' ';
}

template <class T>
typename rbt<T>::node* rbt<T>::get_root() {
  return root_;
}

template <class T>
struct rbt<T>::node {
 public:
  friend rbt;
  class iterator;
  class const_iterator;
  enum class Color { RED, BLACK };
  node(const T& value, Color color, node* left, node* right);
  node(const node& other);
  ~node();
  node& operator=(const node& other);
  Color get_node_color() { return color_; }

 private:
  T value_;
  Color color_;
  node *left_, *right_, *parent_;

  node* get_grandparent();
  node* get_uncle();
};

template <class T>
rbt<T>::node::node(const T& value, Color color, node* left, node* right)
    : value_(value),
      color_(color),
      left_(left),
      right_(right),
      parent_(nullptr) {}

template <class T>
rbt<T>::node::node(const node& other)
    : node(other.value_, other.color_, nullptr, nullptr) {}

template <class T>
rbt<T>::node::~node() {
  left_ = right_ = parent_ = nullptr;
}

template <class T>
typename rbt<T>::node& rbt<T>::node::operator=(const node& other) {
  if (*this != other) {
    value_ = other.value_;
    color_ = other.color_;
    left_ = right_ = parent_ = nullptr;
  }
  return *this;
}

template <class T>
typename rbt<T>::node* rbt<T>::node::get_grandparent() {
  node* result = nullptr;
  if (parent_ != nullptr) result = parent_->parent_;
  return result;
}

template <class T>
typename rbt<T>::node* rbt<T>::node::get_uncle() {
  node* result = get_grandparent();
  if (result != nullptr) {
    if (parent_ == result->left_)
      result = result->right_;
    else
      result = result->left_;
  }
  return result;
}

template <class T>
class rbt<T>::node::iterator {
 public:
  friend rbt;
  iterator();
  iterator(const iterator& other);
  iterator(node* n);
  ~iterator();
  iterator& operator=(const iterator& other);
  iterator& operator=(node* n);
  iterator& operator++();
  T& operator*();
  T* operator->();
  friend bool operator==(const iterator& lhs, const iterator& rhs) {
    return lhs.iter_ == rhs.iter_;
  }
  friend bool operator!=(const iterator& lhs, const iterator& rhs) {
    return !(lhs == rhs);
  }
  node* get_node_pointer();

 private:
  node* iter_;
  stack<node*> st_;

  void _push_all_left(node* n);
};

template <class T>
rbt<T>::node::iterator::iterator() : iter_(), st_() {}

template <class T>
rbt<T>::node::iterator::iterator(node* n) : iter_(nullptr), st_() {
  *this = n;
}

template <class T>
typename rbt<T>::node::iterator& rbt<T>::node::iterator::operator=(node* n) {
  iter_ = n;
  return *this;
}

template <class T>
rbt<T>::node::iterator::iterator(const iterator& other) : iterator() {
  *this = other;
}

template <class T>
rbt<T>::node::iterator::~iterator() {
  iter_ = nullptr;
}

template <class T>
typename rbt<T>::node::iterator& rbt<T>::node::iterator::operator=(
    const iterator& other) {
  if (*this != other) {
    iter_ = other.iter_;
    st_ = other.st_;
  }
  return *this;
}

template <class T>
typename rbt<T>::node::iterator& rbt<T>::node::iterator::operator++() {
  if (!st_.empty()) {
    iter_ = st_.top();
    st_.pop();
    if (iter_->right_ != nullptr) _push_all_left(iter_->right_);
  } else
    iter_ = nullptr;
  return *this;
}

template <class T>
T& rbt<T>::node::iterator::operator*() {
  return iter_->value_;
}

template <class T>
T* rbt<T>::node::iterator::operator->() {
  return &(iter_->value_);
}

template <class T>
typename rbt<T>::node* rbt<T>::node::iterator::get_node_pointer() {
  return iter_;
}

template <class T>
void rbt<T>::node::iterator::_push_all_left(node* n) {
  while (n != nullptr) {
    st_.push(n);
    n = n->left_;
  }
}

template <class T>
class rbt<T>::node::const_iterator {
 public:
  friend rbt;
  const_iterator();
  const_iterator(const const_iterator& other);
  const_iterator(const node* n);
  ~const_iterator();
  const_iterator& operator=(const const_iterator& other);
  const_iterator& operator=(const node* n);
  const_iterator& operator++();
  const T& operator*();
  const T* operator->();
  friend bool operator==(const const_iterator& lhs, const const_iterator& rhs) {
    return lhs.iter_ == rhs.iter_;
  }
  friend bool operator!=(const const_iterator& lhs, const const_iterator& rhs) {
    return !(lhs == rhs);
  }
  const node* get_node_pointer();

 private:
  const node* iter_;
  stack<const node*> st_;

  void _push_all_left(const node* n);
};

template <class T>
rbt<T>::node::const_iterator::const_iterator() : iter_(), st_() {}

template <class T>
rbt<T>::node::const_iterator::const_iterator(const node* n)
    : iter_(nullptr), st_() {
  *this = n;
}

template <class T>
typename rbt<T>::node::const_iterator& rbt<T>::node::const_iterator::operator=(
    const node* n) {
  iter_ = n;
  return *this;
}

template <class T>
rbt<T>::node::const_iterator::const_iterator(const const_iterator& other)
    : const_iterator() {
  *this = other;
}

template <class T>
rbt<T>::node::const_iterator::~const_iterator() {
  iter_ = nullptr;
}

template <class T>
typename rbt<T>::node::const_iterator& rbt<T>::node::const_iterator::operator=(
    const const_iterator& other) {
  if (*this != other) {
    iter_ = other.iter_;
    st_ = other.st_;
  }
  return *this;
}

template <class T>
typename rbt<T>::node::const_iterator&
rbt<T>::node::const_iterator::operator++() {
  if (!st_.empty()) {
    iter_ = st_.top();
    st_.pop();
    if (iter_->right_ != nullptr) _push_all_left(iter_->right_);
  } else
    iter_ = nullptr;
  return *this;
}

template <class T>
const T& rbt<T>::node::const_iterator::operator*() {
  return iter_->value_;
}

template <class T>
const T* rbt<T>::node::const_iterator::operator->() {
  return &(iter_->value_);
}

template <class T>
const typename rbt<T>::node* rbt<T>::node::const_iterator::get_node_pointer() {
  return iter_;
}

template <class T>
void rbt<T>::node::const_iterator::_push_all_left(const node* n) {
  while (n != nullptr) {
    st_.push(n);
    n = n->left_;
  }
}

}  // namespace s21
#endif