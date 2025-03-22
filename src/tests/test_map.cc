#include <gtest/gtest.h>

#include <map>

#include "../s21_containers.h"

TEST(MapTemplates, test_map_default_contstruction_from_int_int_types) {
  s21::map<int, int> s21_map_int_int;
  std::map<int, int> std_map_int_int;
  ASSERT_EQ(s21_map_int_int.size(), std_map_int_int.size());
}

TEST(MapTemplates, test_map_default_contstruction_from_char_double_types) {
  s21::map<char, double> s21_map_char_double;
  std::map<char, double> std_map_char_double;
  ASSERT_EQ(s21_map_char_double.size(), std_map_char_double.size());
}

TEST(MapTemplates, test_map_default_contstruction_from_complex_types) {
  s21::map<char, s21::map<int, int>> s21_map_complex;
  std::map<char, s21::map<int, int>> std_map_complex;
  ASSERT_EQ(s21_map_complex.size(), std_map_complex.size());
}

TEST(MapConstructors, test_map_default_constructor) {
  s21::map<int, double> s21_map;
  std::map<int, double> std_map;
  ASSERT_EQ(s21_map.size(), std_map.size());
}

TEST(MapConstructors, test_map_initializer_list_constructor) {
  std::initializer_list<std::pair<const int, double>> data = {
      {0, 1.}, {1, 2.}, {2, 3.}, {3, 4.}, {4, 5.6}};
  s21::map<int, double> s21_map(data);
  ASSERT_EQ(s21_map.size(), data.size());
  auto ini_iter = data.begin();
  for (auto iter = s21_map.begin(); iter != s21_map.end(); ++iter, ++ini_iter)
    ASSERT_EQ(*iter, *ini_iter);
}

TEST(MapConstructors, test_map_copy_constructor) {
  s21::map<int, double> initial = {{0, 1.},
                                   {1, 2.},
                                   {2, 3.},
                                   {3, 4.},
                                   {4, 5.6}},
                        dest(initial);
  ASSERT_EQ(initial.size(), dest.size());
  for (auto initial_iter = initial.begin(), dest_iter = dest.begin();
       initial_iter != initial.end(); ++initial_iter, ++dest_iter)
    ASSERT_EQ(*initial_iter, *dest_iter);
}

TEST(MapConstructors, test_map_move_constructor) {
  std::initializer_list<std::pair<const int, double>> data = {
      {0, 1.}, {1, 2.}, {2, 3.}, {3, 4.}, {4, 5.6}};
  s21::map<int, double> initial = data, dest(std::move(initial));
  const long unsigned int a = 0;
  const long unsigned int b = 5;
  ASSERT_EQ(initial.size(), a);
  ASSERT_EQ(dest.size(), b);
  auto ini_iter = data.begin();
  for (auto iter = dest.begin(); iter != dest.end(); ++iter, ++ini_iter)
    ASSERT_EQ(*iter, *ini_iter);
}

TEST(MapOperators, test_map_copy_assignment) {
  s21::map<int, double> initial = {{0, 1.},
                                   {1, 2.},
                                   {2, 3.},
                                   {3, 4.},
                                   {4, 5.6}},
                        dest = initial;
  ASSERT_EQ(initial.size(), dest.size());
  for (auto initial_iter = initial.begin(), dest_iter = dest.begin();
       initial_iter != initial.end(); ++initial_iter, ++dest_iter)
    ASSERT_EQ(*initial_iter, *dest_iter);
}

TEST(MapOperators, test_map_move_assignment) {
  std::initializer_list<std::pair<const int, double>> data = {
      {0, 1.}, {1, 2.}, {2, 3.}, {3, 4.}, {4, 5.6}};
  s21::map<int, double> initial = data, dest = std::move(initial);
  const long unsigned int a = 0;
  const long unsigned int b = 5;
  ASSERT_EQ(initial.size(), a);
  ASSERT_EQ(dest.size(), b);
  auto ini_iter = data.begin();
  for (auto iter = dest.begin(); iter != dest.end(); ++iter, ++ini_iter)
    ASSERT_EQ(*iter, *ini_iter);
}

TEST(MapOperators, test_map_initializer_list_assignment) {
  std::initializer_list<std::pair<const int, double>> data = {
      {0, 1.}, {1, 2.}, {2, 3.}, {3, 4.}, {4, 5.6}};
  s21::map<int, double> s21_map = data;
  ASSERT_EQ(s21_map.size(), data.size());
  auto ini_iter = data.begin();
  for (auto iter = s21_map.begin(); iter != s21_map.end(); ++iter, ++ini_iter)
    ASSERT_EQ(*iter, *ini_iter);
}

TEST(MapOperators, test_map_equal) {
  s21::map<int, double> initial = {{0, 1.},
                                   {1, 2.},
                                   {2, 3.},
                                   {3, 4.},
                                   {4, 5.6}},
                        dest(initial);
  ASSERT_TRUE(initial == dest);
}

TEST(MapOperators, test_map_not_equal) {
  s21::map<int, double> initial = {{0, 1.},
                                   {1, 2.},
                                   {2, 3.},
                                   {3, 4.},
                                   {4, 5.6}},
                        dest(initial);
  initial[5] = 5.;
  ASSERT_TRUE(initial != dest);
}

// TEST(MapElement_access, test_map_at) {
//   s21::map<int, double> s21_map = {
//       {0, 1.}, {1, 2.}, {2, 3.}, {3, 4.}, {4, 5.6}};
//   ASSERT_EQ(s21_map.at(2), 3.);
//   ASSERT_ANY_THROW(s21_map.at(228));
// }

TEST(MapElement_access, test_map_branch_operator) {
  s21::map<int, double> s21_map = {
      {0, 1.}, {1, 2.}, {2, 3.}, {3, 4.}, {4, 5.6}};
  s21_map[5] = 7.8;
  const long unsigned int a = 6;
  ASSERT_EQ(s21_map.size(), a);
  ASSERT_EQ(s21_map.at(5), 7.8);
}

TEST(MapIterators, test_map_begin) {
  std::initializer_list<std::pair<const int, double>> data = {
      {0, 1.}, {1, 2.}, {2, 3.}, {3, 4.}, {4, 5.6}};
  s21::map<int, double> s21_map = data;
  std::map<int, double> std_map = data;
  ASSERT_EQ(*s21_map.begin(), *std_map.begin());
}

TEST(MapIterators, test_map_end) {
  std::initializer_list<std::pair<const int, double>> data = {
      {0, 1.}, {1, 2.}, {2, 3.}, {3, 4.}, {4, 5.6}};
  s21::map<int, double> s21_map = data;
  std::map<int, double> std_map = data;
  auto std_iter = data.begin();
  for (auto s21_iter = s21_map.begin(); s21_iter != s21_map.end();
       ++s21_iter, ++std_iter)
    ASSERT_EQ(*s21_iter, *std_iter);
}

TEST(MapCapacity, test_map_size) {
  std::initializer_list<std::pair<const int, double>> data = {
      {0, 1.}, {1, 2.}, {2, 3.}, {3, 4.}, {4, 5.6}};
  s21::map<int, double> s21_map = data;
  std::map<int, double> std_map = data;
  ASSERT_EQ(s21_map.size(), std_map.size());
}

TEST(MapCapacity, test_map_empty) {
  std::initializer_list<std::pair<const int, double>> data = {
      {0, 1.}, {1, 2.}, {2, 3.}, {3, 4.}, {4, 5.6}};
  s21::map<int, double> s21_map = data;
  std::map<int, double> std_map = data;
  ASSERT_EQ(s21_map.empty(), std_map.empty());
}

TEST(MapCapacity, test_map_max_size_1) {
  s21::map<int, double> s21_map;
  std::map<int, double> std_map;
  ASSERT_NE(s21_map.max_size(), std_map.max_size());
}

TEST(MapCapacity, test_map_max_size_2) {
  s21::map<char, bool> s21_map;
  std::map<char, bool> std_map;
  ASSERT_NE(s21_map.max_size(), std_map.max_size());
}

TEST(MapCapacity, test_map_max_size_3) {
  s21::map<int, s21::map<int, double>> s21_map;
  std::map<int, std::map<int, double>> std_map;
  ASSERT_NE(s21_map.max_size(), std_map.max_size());
}

TEST(MapModifiers, test_map_clear) {
  s21::map<int, double> s21_map = {
      {0, 1.}, {1, 2.}, {2, 3.}, {3, 4.}, {4, 5.6}};
  s21_map.clear();
  const long unsigned int a = 0;
  ASSERT_EQ(s21_map.size(), a);
  ASSERT_EQ(s21_map.cbegin(), s21_map.cend());
  ASSERT_EQ(s21_map.cbegin(), nullptr);
}

TEST(MapModifiers, test_map_insert_1) {
  s21::map<int, double> s21_map = {
      {0, 1.}, {1, 2.}, {2, 3.}, {3, 4.}, {4, 5.6}};
  std::pair<const int, double> data = {5, 6.};
  auto result = s21_map.insert(data);
  ASSERT_EQ(s21_map.at(data.first), data.second);
  ASSERT_EQ(*(result.first), data);
  ASSERT_TRUE(result.second);
}

TEST(MapModifiers, test_map_insert_2) {
  s21::map<int, double> s21_map = {
      {0, 1.}, {1, 2.}, {2, 3.}, {3, 4.}, {4, 5.6}};
  std::pair<const int, double> data = {1, 2.};
  auto result = s21_map.insert(data.first, data.second);
  ASSERT_EQ(s21_map.at(data.first), data.second);
  ASSERT_EQ(*(result.first), data);
  ASSERT_FALSE(result.second);
}

TEST(MapModifiers, test_map_insert_or_assign) {
  s21::map<int, double> s21_map = {
      {0, 1.}, {1, 2.}, {2, 3.}, {3, 4.}, {4, 5.6}};
  std::pair<const int, double> data = {1, 2.};
  auto result = s21_map.insert_or_assign(data.first, data.second);
  ASSERT_EQ(s21_map.at(data.first), data.second);
  ASSERT_EQ(*(result.first), data);
  ASSERT_TRUE(result.second);
}

TEST(MapModifiers, test_map_erase) {
  s21::map<int, double> s21_map = {
      {0, 1.}, {1, 2.}, {2, 3.}, {3, 4.}, {4, 5.6}};
  s21_map.erase(++s21_map.begin());
  std::pair<const int, double> test = {2, 3.};
  ASSERT_EQ(*(++s21_map.begin()), test);
}

TEST(MapModifiers, test_map_swap) {
  std::initializer_list<std::pair<const int, double>> left_data = {{0, 1.2},
                                                                   {1, 3.4},
                                                                   {2, 5.6}},
                                                      right_data = {{3, 7.8},
                                                                    {4, 9.1}};
  s21::map<int, double> left = left_data, right = right_data;
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

TEST(MapModifiers, test_map_merge) {
  std::initializer_list<std::pair<const int, double>> dest_data = {{0, 1.2},
                                                                   {1, 3.4},
                                                                   {2, 5.6}},
                                                      source_data = {{0, 2.421},
                                                                     {3, 7.8},
                                                                     {4, 9.1}};
  s21::map<int, double> dest = dest_data, source = source_data;
  dest.merge(source);
  const long unsigned int a = 5;
  const long unsigned int b = 1;
  ASSERT_EQ(dest.size(), a);
  ASSERT_EQ(source.size(), b);
  std::initializer_list<std::pair<const int, double>> result = {
      {0, 1.2}, {1, 3.4}, {2, 5.6}, {3, 7.8}, {4, 9.1}};
  auto iter = dest.begin();
  for (auto data_iter = result.begin(); data_iter != result.end();
       ++data_iter, ++iter)
    ASSERT_EQ(*data_iter, *iter);
}

TEST(MapModifiers, test_map_insert_many) {
  s21::map<int, double> s21_map = {
      {0, 1.}, {1, 2.}, {2, 3.}, {3, 4.}, {4, 5.6}};
  auto result = s21_map.insert_many(std::pair<const int, double>(5, 1.1),
                                    std::pair<const int, double>(6, 1.3),
                                    std::pair<const int, double>(7, 1.4));
  std::pair<const int, double> test[] = {{5, 1.1}, {6, 1.3}, {7, 1.4}};
  for (size_t i = 0; i < 3; ++i) {
    ASSERT_EQ(result[i].first->first, test[i].first);
    ASSERT_EQ(result[i].first->second, test[i].second);
  }
}

TEST(MapLookup, test_map_contains) {
  s21::map<int, double> s21_map = {
      {0, 1.}, {1, 2.}, {2, 3.}, {3, 4.}, {4, 5.6}};
  ASSERT_TRUE(s21_map.contains(0));
  ASSERT_FALSE(s21_map.contains(-1));
}