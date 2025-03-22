#ifndef S21_cont_st_H_
#define S21_cont_st_H_

#include "stl_declarations.h"

namespace s21 {

template <class T, class container>
class stack {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  stack();
  stack(std::initializer_list<value_type> const &items);
  stack(const stack &s);
  stack(stack &&s);
  stack &operator=(stack &&s);
  stack &operator=(const stack &s);
  ~stack() {};

  const_reference top();

  bool empty();
  size_type size();

  void push(const_reference value);
  void pop();
  void swap(stack &other);
  template <typename... Args>
  void insert_many_back(Args &&...args);

 private:
  container cont_st_;
};

template <typename T, typename container>
stack<T, container>::stack() : cont_st_(){};

template <typename T, typename container>
stack<T, container>::stack(std::initializer_list<value_type> const &items)
    : cont_st_(items){};

template <typename T, typename container>
stack<T, container>::stack(const stack &s) : cont_st_(s.cont_st_){};

template <typename T, typename container>
stack<T, container>::stack(stack &&s) : cont_st_(std::move(s.cont_st_)){};

template <typename T, typename container>
stack<T, container> &stack<T, container>::operator=(stack &&s) {
  cont_st_ = std::move(s.cont_st_);
  return *this;
};

template <typename T, typename container>
stack<T, container> &stack<T, container>::operator=(const stack &s) {
  cont_st_ = (s.cont_st_);
  return *this;
};

template <typename T, typename container>
typename stack<T, container>::const_reference stack<T, container>::top() {
  return cont_st_.back();
};

template <typename T, typename container>
bool stack<T, container>::empty() {
  return cont_st_.empty();
};

template <typename T, typename container>
typename stack<T, container>::size_type stack<T, container>::size() {
  return cont_st_.size();
};

template <typename T, typename container>
void stack<T, container>::push(const_reference value) {
  cont_st_.push_back(value);
};

template <typename T, typename container>
void stack<T, container>::pop() {
  cont_st_.pop_back();
};

template <typename T, typename container>
void stack<T, container>::swap(stack &other) {
  cont_st_.swap(other.cont_st_);
};

template <typename T, typename container>
template <typename... Args>
void stack<T, container>::insert_many_back(Args &&...args) {
  cont_st_.insert_many_back(args...);
};
}  // namespace s21

#endif
