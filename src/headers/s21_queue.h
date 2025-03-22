
#ifndef S21_QUEUE_H_
#define S21_QUEUE_H_

#include "stl_declarations.h"

namespace s21 {

template <class T, class container>
class queue {
 public:
  using value_type = T;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = size_t;

 private:
  list<value_type> list_;

 public:
  queue() : list_() {};
  queue(std::initializer_list<value_type> const &items) : list_(items) {};
  queue(const queue &other) : list_(other.list_) {};
  queue(queue &&other) noexcept : list_(std::move(other.list_)) {};

  queue &operator=(queue &&other) noexcept {
    if (this != &other) {
      list_ = std::move(other.list_);
    }
    return *this;
  }

  const_reference front() { return list_.front(); }

  const_reference back() { return list_.back(); }

  void push(const_reference value) { list_.push_back(value); }

  void pop() { list_.pop_front(); }

  bool empty() { return size() == 0; }

  size_type size() const { return list_.size(); }

  void swap(queue &other) { list_.swap(other.list_); }

  template <typename... Args>
  void insert_many_back(Args &&...args) {
    list_.insert_many_back(args...);
  };
};

}  // namespace s21

#endif