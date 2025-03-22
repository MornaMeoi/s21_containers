#include <gtest/gtest.h>

#include <list>

#include "../s21_containers.h"

TEST(Templates_list, test_list_default_contstruction_from_int_type) {
  s21::list<int> s21_list_int;
  std::list<int> std_list_int;
  ASSERT_EQ(s21_list_int.size(), std_list_int.size());
}

TEST(Templates_list, test_list_parametrized_contstruction_from_char_type) {
  s21::list<double> s21_list_double(5);
  std::list<double> std_list_double(5);
  ASSERT_EQ(s21_list_double.size(), std_list_double.size());
}

TEST(Templates_list, test_list_default_contstruction_from_complex_type) {
  s21::list<s21::list<double>> s21_list_complex;
  std::list<std::list<double>> std_list_complex;
  ASSERT_EQ(s21_list_complex.size(), std_list_complex.size());
}

TEST(Constructors_list, test_list_default_constructor) {
  s21::list<double> s21_list;
  std::list<double> std_list;
  ASSERT_EQ(s21_list.size(), std_list.size());
}

TEST(Constructors_list, test_list_parametrized_constructor) {
  s21::list<double> s21_list(5);
  std::list<double> std_list(5);
  ASSERT_EQ(s21_list.size(), std_list.size());
  auto s21_iter = s21_list.begin();
  for (auto std_iter = std_list.begin(); std_iter != std_list.end();
       ++s21_iter, ++std_iter)
    ASSERT_EQ(*s21_iter, *std_iter);
}

TEST(Constructors_list, test_list_copy_constructor) {
  s21::list<double> initial = {1.2, 3.4, 5.6}, dest(initial);
  ASSERT_EQ(initial.size(), dest.size());
  for (auto initial_iter = initial.begin(), dest_iter = dest.begin();
       initial_iter != initial.end(); ++initial_iter, ++dest_iter)
    ASSERT_EQ(*initial_iter, *dest_iter);
}

TEST(Constructors_list, test_list_move_constructor) {
  std::initializer_list<double> data = {1., 2., 3., 4., 5.6};
  s21::list<double> initial = data, dest(std::move(initial));
  const long unsigned int a = 0;
  const long unsigned int b = 5;
  ASSERT_EQ(initial.size(), a);
  ASSERT_EQ(dest.size(), b);
  auto ini_iter = data.begin();
  for (auto iter = dest.begin(); iter != dest.end(); ++iter, ++ini_iter)
    ASSERT_EQ(*iter, *ini_iter);
}

TEST(Constructors_list, test_list_initializer_list_constructor) {
  std::initializer_list<double> data = {1., 2., 3., 4., 5.6};
  s21::list<double> s21_list(data);
  ASSERT_EQ(s21_list.size(), data.size());
  auto ini_iter = data.begin();
  for (auto iter = s21_list.begin(); iter != s21_list.end(); ++iter, ++ini_iter)
    ASSERT_EQ(*iter, *ini_iter);
}

TEST(Operators_list, test_list_copy_assignment) {
  s21::list<double> initial = {1.2, 3.4, 5.6}, dest = initial;
  ASSERT_EQ(initial.size(), dest.size());
  for (auto initial_iter = initial.begin(), dest_iter = dest.begin();
       initial_iter != initial.end(); ++initial_iter, ++dest_iter)
    ASSERT_EQ(*initial_iter, *dest_iter);
}

TEST(Operators_list, test_list_move_assignment) {
  std::initializer_list<double> data = {1., 2., 3., 4., 5.6};
  s21::list<double> initial = data, dest = std::move(initial);
  const long unsigned int a = 0;
  const long unsigned int b = 5;
  ASSERT_EQ(initial.size(), a);
  ASSERT_EQ(dest.size(), b);
  auto ini_iter = data.begin();
  for (auto iter = dest.begin(); iter != dest.end(); ++iter, ++ini_iter)
    ASSERT_EQ(*iter, *ini_iter);
}

TEST(Operators_list, test_list_initializer_list_assignment) {
  std::initializer_list<double> data = {1., 2., 3., 4., 5.6};
  s21::list<double> s21_list = data;
  ASSERT_EQ(s21_list.size(), data.size());
  auto ini_iter = data.begin();
  for (auto iter = s21_list.begin(); iter != s21_list.end(); ++iter, ++ini_iter)
    ASSERT_EQ(*iter, *ini_iter);
}

TEST(Operators_list, test_list_equal) {
  s21::list<double> initial = {1.2, 3.4, 5.6}, dest(initial);
  ASSERT_TRUE(initial == dest);
}

TEST(Operators_list, test_list_not_equal) {
  s21::list<double> initial = {1.2, 3.4, 5.6}, dest(initial);
  initial.push_back(5.);
  ASSERT_TRUE(initial != dest);
}

TEST(Element_access, test_list_front) {
  std::initializer_list<double> data = {1., 2., 3., 4., 5.6};
  s21::list<double> s21_list = data;
  std::list<double> std_list = data;
  ASSERT_EQ(s21_list.front(), std_list.front());
}

TEST(Element_access, test_list_back) {
  std::initializer_list<double> data = {1., 2., 3., 4., 5.6};
  s21::list<double> s21_list = data;
  std::list<double> std_list = data;
  ASSERT_EQ(s21_list.back(), std_list.back());
}

TEST(Iterators, test_list_begin) {
  std::initializer_list<double> data = {1., 2., 3., 4., 5.6};
  s21::list<double> s21_list = data;
  std::list<double> std_list = data;
  ASSERT_EQ(*s21_list.begin(), *std_list.begin());
}

TEST(Iterators, test_list_end) {
  std::initializer_list<double> data = {1., 2., 3., 4., 5.6};
  s21::list<double> s21_list = data;
  auto iter = s21_list.begin();
  while (*iter != s21_list.back()) ++iter;
  ++iter;
  ASSERT_EQ(s21_list.end(), iter);
}

TEST(Capacity_list, test_list_size) {
  std::initializer_list<double> data = {1., 2., 3., 4., 5.6};
  s21::list<double> s21_list = data;
  std::list<double> std_list = data;
  ASSERT_EQ(s21_list.size(), std_list.size());
}

TEST(Capacity_list, test_list_empty) {
  std::initializer_list<double> data = {1., 2., 3., 4., 5.6};
  s21::list<double> s21_list = data;
  std::list<double> std_list = data;
  ASSERT_EQ(s21_list.empty(), std_list.empty());
}

TEST(Capacity_list, test_list_max_size) {
  s21::list<double> s21_list;
  std::list<double> std_list;
  ASSERT_NE(s21_list.max_size(), std_list.max_size());
}

TEST(Modifiers_list, test_list_clear) {
  s21::list<double> s21_list = {1., 2., 3., 4., 5.6};
  s21_list.clear();
  const long unsigned int a = 0;
  ASSERT_EQ(s21_list.size(), a);
  ASSERT_EQ(s21_list.begin(), s21_list.end());
  ASSERT_EQ(s21_list.begin(), nullptr);
}

TEST(Modifiers_list, test_list_insert) {
  s21::list<double> s21_list = {1., 2., 3., 4., 5.6};
  auto iter = s21_list.begin();
  ++iter;
  double test = 2.5;
  s21_list.insert(iter, test);
  --iter;
  ASSERT_EQ(*iter, test);
}

TEST(Modifiers_list, test_list_erase) {
  s21::list<double> s21_list = {1., 2., 3., 4., 5.6};
  auto iter = s21_list.begin();
  ++iter;
  s21_list.erase(iter);
  iter = s21_list.begin();
  ++iter;
  ASSERT_EQ(*iter, 3.);
}

TEST(Modifiers_list, test_list_push_back_1) {
  s21::list<double> s21_list = {1., 2., 3., 4., 5.6};
  double test = 5.;
  s21_list.push_back(test);
  ASSERT_EQ(s21_list.back(), test);
}

TEST(Modifiers_list, test_list_push_back_2) {
  s21::list<double> s21_list;
  double test = 6.;
  s21_list.push_back(5.);
  s21_list.push_back(test);
  ASSERT_EQ(s21_list.back(), test);
}

TEST(Modifiers_list, test_list_pop_back) {
  s21::list<double> s21_list = {1., 2., 3., 4., 5.6};
  s21_list.pop_back();
  ASSERT_EQ(s21_list.back(), 4.);
}

TEST(Modifiers_list, test_list_push_front) {
  s21::list<double> s21_list = {1., 2., 3., 4., 5.6};
  double test = 5.;
  s21_list.push_front(test);
  ASSERT_EQ(s21_list.front(), test);
}

TEST(Modifiers_list, test_list_pop_front) {
  s21::list<double> s21_list = {1., 2., 3., 4., 5.6};
  s21_list.pop_back();
  ASSERT_EQ(s21_list.back(), 4.);
}

TEST(Modifiers_list, test_list_swap) {
  s21::list<double> left = {1.2, 3.4, 5.6}, right = {7.8, 9.1};
  left.swap(right);
  const long unsigned int a = 2;
  const long unsigned int b = 3;

  ASSERT_EQ(left.size(), a);
  ASSERT_EQ(right.size(), b);
  ASSERT_EQ(left.front(), 7.8);
  ASSERT_EQ(right.back(), 5.6);
}

TEST(Modifiers_list, test_list_merge) {
  s21::list<double> left = {1.2, 5.6}, right = {3.4, 7.8, 9.1};
  left.merge(right);
  const long unsigned int a = 0;
  const long unsigned int b = 5;
  ASSERT_EQ(left.size(), b);
  ASSERT_EQ(right.size(), a);
  double test[] = {1.2, 3.4, 5.6, 7.8, 9.1};
  int i = 0;
  for (auto iter = left.begin(); iter != left.end(); ++iter)
    ASSERT_EQ(*iter, test[i++]);
}

TEST(Modifiers_list, test_list_splice) {
  s21::list<double> dest = {1.2, 3.4}, src = {5.6, 7.8, 9.1};
  s21::list<double>::const_iterator it = dest.cbegin();
  ++it;
  dest.splice(it, src);
  double test[] = {1.2, 5.6, 7.8, 9.1, 3.4};
  int i = 0;
  for (auto iter = dest.begin(); iter != dest.end(); ++iter)
    ASSERT_EQ(*iter, test[i++]);
}

TEST(Modifiers_list, test_list_reverse) {
  s21::list<double> s21_list = {1.2, 3.4, 5.6, 7.8, 9.1};
  s21_list.reverse();
  double test[] = {9.1, 7.8, 5.6, 3.4, 1.2};
  int i = 0;
  for (auto iter = s21_list.begin(); iter != s21_list.end(); ++iter)
    ASSERT_EQ(*iter, test[i++]);
}

TEST(Modifiers_list, test_list_unique) {
  s21::list<double> s21_list = {1.2, 1.2, 1.2, 3.4, 5.6,
                                5.6, 7.8, 9.1, 9.1, 9.1};
  s21_list.unique();
  const long unsigned int b = 5;
  ASSERT_EQ(s21_list.size(), b);
  double test[] = {1.2, 3.4, 5.6, 7.8, 9.1};
  int i = 0;
  for (auto iter = s21_list.begin(); iter != s21_list.end(); ++iter)
    ASSERT_EQ(*iter, test[i++]);
}

TEST(Modifiers_list, test_list_sort) {
  s21::list<double> s21_list = {5.6, 1.2, 9.1, 3.4, 7.8};
  s21_list.sort();
  double test[] = {1.2, 3.4, 5.6, 7.8, 9.1};
  int i = 0;
  for (auto iter = s21_list.begin(); iter != s21_list.end(); ++iter)
    ASSERT_EQ(*iter, test[i++]);
}

TEST(Modifiers_list, test_list_insert_many) {
  s21::list<double> s21_list = {5.6, 1.2, 9.1, 3.4, 7.8};
  s21_list.insert_many(++s21_list.cbegin(), 1.1, 1.3, 1.4);
  double test[] = {1.1, 1.3, 1.4};
  size_t i = 0;
  for (auto iter = ++s21_list.begin(); i < 3; ++iter)
    ASSERT_EQ(*iter, test[i++]);
}

TEST(Modifiers_list, test_list_insert_many_back) {
  s21::list<double> s21_list = {5.6, 1.2, 9.1, 3.4, 7.8};
  auto prev_tail = s21_list.begin();
  while (*prev_tail != s21_list.back()) ++prev_tail;
  s21_list.insert_many_back(1.1, 1.3, 1.4);
  double test[] = {1.1, 1.3, 1.4};
  size_t i = 0;
  for (auto iter = ++prev_tail; iter != s21_list.end(); ++iter)
    ASSERT_EQ(*iter, test[i++]);
}

TEST(Modifiers_list, test_list_insert_many_front) {
  s21::list<double> s21_list = {5.6, 1.2, 9.1, 3.4, 7.8};
  s21_list.insert_many_front(1.1, 1.3, 1.4);
  double test[] = {1.1, 1.3, 1.4};
  size_t i = 0;
  for (auto iter = s21_list.begin(); i < 3; ++iter)
    ASSERT_EQ(*iter, test[2 - i++]);
}