#include <gtest/gtest.h>

#include <set>

#include "../s21_containers.h"

TEST(Templates, test_default_contstruction_from_int_type) {
  s21::multiset<int> s21_multiset_int;
  std::multiset<int> std_multiset_int;
  ASSERT_EQ(s21_multiset_int.size(), std_multiset_int.size());
}

TEST(Templates, test_default_contstruction_from_double_type) {
  s21::multiset<double> s21_multiset_double;
  std::multiset<double> std_multiset_double;
  ASSERT_EQ(s21_multiset_double.size(), std_multiset_double.size());
}

TEST(Templates, test_default_contstruction_from_complex_type) {
  s21::multiset<s21::multiset<char>> s21_multiset_complex;
  std::multiset<std::multiset<char>> std_multiset_complex;
  ASSERT_EQ(s21_multiset_complex.size(), std_multiset_complex.size());
}

TEST(Constructors, test_default_constructor) {
  s21::multiset<double> s21_multiset;
  std::multiset<double> std_multiset;
  ASSERT_EQ(s21_multiset.size(), std_multiset.size());
}

TEST(Constructors, test_initializer_list_constructor) {
  std::initializer_list<double> data = {1., 2., 2., 2., 3., 4., 5.6};
  s21::multiset<double> s21_multiset(data);
  ASSERT_EQ(s21_multiset.size(), data.size());
  auto ini_iter = data.begin();
  for (auto iter = s21_multiset.begin(); iter != s21_multiset.end();
       ++iter, ++ini_iter)
    ASSERT_EQ(*iter, *ini_iter);
}

TEST(Constructors, test_copy_constructor) {
  s21::multiset<double> initial = {1., 2., 2., 2., 3., 4., 5.6}, dest(initial);
  ASSERT_EQ(initial.size(), dest.size());
  for (auto initial_iter = initial.begin(), dest_iter = dest.begin();
       initial_iter != initial.end(); ++initial_iter, ++dest_iter)
    ASSERT_EQ(*initial_iter, *dest_iter);
}

TEST(Constructors, test_move_constructor) {
  std::initializer_list<double> data = {1., 2., 2., 2., 3., 4., 5.6};
  s21::multiset<double> initial = data, dest(std::move(initial));
  const long unsigned int a = 0;
  const long unsigned int b = 7;
  ASSERT_EQ(initial.size(), a);
  ASSERT_EQ(dest.size(), b);
  auto ini_iter = data.begin();
  for (auto iter = dest.begin(); iter != dest.end(); ++iter, ++ini_iter)
    ASSERT_EQ(*iter, *ini_iter);
}

TEST(Operators, test_copy_assignment) {
  s21::multiset<double> initial = {1., 2., 2., 2., 3., 4., 5.6}, dest = initial;
  ASSERT_EQ(initial.size(), dest.size());
  for (auto initial_iter = initial.begin(), dest_iter = dest.begin();
       initial_iter != initial.end(); ++initial_iter, ++dest_iter)
    ASSERT_EQ(*initial_iter, *dest_iter);
}

TEST(Operators, test_move_assignment) {
  std::initializer_list<double> data = {1., 2., 2., 2., 3., 4., 5.6};
  s21::multiset<double> initial = data, dest = std::move(initial);
  const long unsigned int a = 0;
  const long unsigned int b = 7;
  ASSERT_EQ(initial.size(), a);
  ASSERT_EQ(dest.size(), b);
  auto ini_iter = data.begin();
  for (auto iter = dest.begin(); iter != dest.end(); ++iter, ++ini_iter)
    ASSERT_EQ(*iter, *ini_iter);
}

TEST(Operators, test_initializer_list_assignment) {
  std::initializer_list<double> data = {1., 2., 2., 2., 3., 4., 5.6};
  s21::multiset<double> s21_multiset = data;
  ASSERT_EQ(s21_multiset.size(), data.size());
  auto ini_iter = data.begin();
  for (auto iter = s21_multiset.begin(); iter != s21_multiset.end();
       ++iter, ++ini_iter)
    ASSERT_EQ(*iter, *ini_iter);
}

TEST(Operators, test_equal) {
  s21::multiset<double> initial = {1., 2., 2., 2., 3., 4., 5.6}, dest(initial);
  ASSERT_TRUE(initial == dest);
}

TEST(Operators, test_not_equal) {
  s21::multiset<double> initial = {1., 2., 2., 2., 3., 4., 5.6}, dest(initial);
  initial.insert(5.);
  ASSERT_TRUE(initial != dest);
}

TEST(Iterators, test_begin) {
  std::initializer_list<double> data = {1., 2., 2., 2., 3., 4., 5.6};
  s21::multiset<double> s21_multiset = data;
  std::multiset<double> std_map = data;
  ASSERT_EQ(*s21_multiset.begin(), *std_map.begin());
}

TEST(Iterators, test_end) {
  std::initializer_list<double> data = {1., 2., 2., 2., 3., 4., 5.6};
  s21::multiset<double> s21_multiset = data;
  std::multiset<double> std_map = data;
  auto std_iter = data.begin();
  for (auto s21_iter = s21_multiset.begin(); s21_iter != s21_multiset.end();
       ++s21_iter, ++std_iter)
    ASSERT_EQ(*s21_iter, *std_iter);
}

TEST(Capacity, test_size) {
  std::initializer_list<double> data = {1., 2., 2., 2., 3., 4., 5.6};
  s21::multiset<double> s21_multiset = data;
  std::multiset<double> std_map = data;
  ASSERT_EQ(s21_multiset.size(), std_map.size());
}

TEST(Capacity, test_empty) {
  std::initializer_list<double> data = {1., 2., 2., 2., 3., 4., 5.6};
  s21::multiset<double> s21_multiset = data;
  std::multiset<double> std_map = data;
  ASSERT_EQ(s21_multiset.empty(), std_map.empty());
}

TEST(Capacity, test_max_size) {
  s21::multiset<double> s21_multiset;
  std::multiset<double> std_map;
  ASSERT_NE(s21_multiset.max_size(), std_map.max_size());
}

TEST(Modifiers, test_clear) {
  s21::multiset<double> s21_multiset = {1., 2., 2., 2., 3., 4., 5.6};
  s21_multiset.clear();
  const long unsigned int a = 0;
  ASSERT_EQ(s21_multiset.size(), a);
  ASSERT_EQ(s21_multiset.begin(), s21_multiset.end());
  ASSERT_EQ(s21_multiset.begin(), nullptr);
}

TEST(Modifiers, test_insert) {
  s21::multiset<double> s21_multiset = {1., 2., 2., 2., 3., 4., 5.6};
  double data = 6.;
  auto result = s21_multiset.insert(data);
  ASSERT_EQ(*result, data);
}

TEST(Modifiers, test_erase) {
  s21::multiset<double> s21_multiset = {1., 2., 2., 2., 3., 4., 5.6};
  s21_multiset.erase(s21_multiset.find(3.));
  double test = 4.;
  ASSERT_EQ(*(s21_multiset.upper_bound(2.)), test);
}

TEST(Modifiers, test_swap) {
  std::initializer_list<double> left_data = {1.2, 3.4, 5.6},
                                right_data = {7.8, 9.1};
  s21::multiset<double> left = left_data, right = right_data;
  left.swap(right);
  const long unsigned int a = 2;
  const long unsigned int b = 3;
  ASSERT_EQ(left.size(), a);
  ASSERT_EQ(right.size(), b);
  auto iter = left.begin();
  for (auto data_iter = right_data.begin(); data_iter != right_data.end();
       ++data_iter, ++iter)
    ASSERT_EQ(*data_iter, *iter);
  iter = right.begin();
  for (auto data_iter = left_data.begin(); data_iter != left_data.end();
       ++data_iter, ++iter)
    ASSERT_EQ(*data_iter, *iter);
}

TEST(Modifiers, test_merge) {
  std::initializer_list<double> dest_data = {1.2, 3.4, 5.6},
                                source_data = {7.8, 1.2, 3.4, 3.4, 9.1};
  s21::multiset<double> dest = dest_data, source = source_data;
  dest.merge(source);
  const long unsigned int a = 8;
  const long unsigned int b = 0;
  ASSERT_EQ(dest.size(), a);
  ASSERT_EQ(source.size(), b);
  std::initializer_list<double> result = {1.2, 1.2, 3.4, 3.4,
                                          3.4, 5.6, 7.8, 9.1};
  auto iter = dest.begin();
  for (auto data_iter = result.begin(); data_iter != result.end();
       ++data_iter, ++iter)
    ASSERT_EQ(*data_iter, *iter);
}

TEST(Modifiers, test_multiset_insert_many) {
  s21::multiset<double> s21_multiset = {1., 2., 2., 2., 3., 4., 5.6};
  auto result = s21_multiset.insert_many(2., 3., 5.);
  double test[] = {2., 3., 5.};
  for (size_t i = 0; i < 3; ++i) ASSERT_EQ(*result[i], test[i]);
}

TEST(Lookup, test_count) {
  s21::multiset<double> s21_multiset = {1., 2., 2., 2., 3., 4., 5.6};
  const long unsigned int b = 3;
  ASSERT_EQ(s21_multiset.count(2.), b);
}

TEST(Lookup, test_find) {
  s21::multiset<double> s21_multiset = {1., 2., 2., 2., 3., 4., 5.6};
  double test = 4.;
  auto iter = s21_multiset.begin();
  while (iter != s21_multiset.end() && *iter != test) ++iter;
  ASSERT_EQ(*iter, test);
  ASSERT_EQ(iter, s21_multiset.find(test));
}

TEST(Lookup, test_contains) {
  s21::multiset<double> s21_multiset = {1., 2., 2., 2., 3., 4., 5.6};
  ASSERT_TRUE(s21_multiset.contains(5.6));
  ASSERT_FALSE(s21_multiset.contains(-1.));
}

TEST(Lookup, test_equal_range) {
  s21::multiset<double> s21_multiset = {1., 2., 2., 2., 3., 4., 5.6};
  double test = 2.;
  auto left = ++s21_multiset.begin(), right = left;
  while (right != s21_multiset.end() && *right == test) ++right;
  ASSERT_EQ(s21_multiset.equal_range(test), std::make_pair(left, right));
}

TEST(Lookup, test_lower_bound) {
  s21::multiset<double> s21_multiset = {1., 2., 2., 2., 3., 4., 5.6};
  double test = 2.;
  auto left = ++s21_multiset.begin();
  ASSERT_EQ(s21_multiset.lower_bound(test), left);
}

TEST(Lookup, test_upper_bound) {
  s21::multiset<double> s21_multiset = {1., 2., 2., 2., 3., 4., 5.6};
  double test = 2.;
  auto right = ++s21_multiset.begin();
  while (right != s21_multiset.end() && *right == test) ++right;
  ASSERT_EQ(s21_multiset.upper_bound(test), right);
}