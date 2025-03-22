#include <gtest/gtest.h>

#include <set>
#include <string>

#include "../s21_containers.h"

// int
template <class T>
bool CompaireTree(s21::set<T>& s21, std::set<T>& std) {
  bool equal = false;
  // s21.GetTree()._print_tree();
  if (s21.size() == std.size()) {
    equal = true;
    auto iter_s21 = s21.begin();
    auto iter_std = std.begin();
    for (; iter_s21 != s21.end() && iter_std != std.end() && equal;
         ++iter_s21, ++iter_std) {
      if (*iter_s21 != *iter_std) equal = false;
    }
  }
  return equal;
}
//------------------------------------------------------------- MemberFunctions

TEST(MemberFunctions, test_int_set_0) {
  s21::set<int> s21_set;
  std::set<int> std_set;
  EXPECT_TRUE(s21_set.size() == std_set.size());
}

TEST(MemberFunctions, test_int_set_1) {
  s21::set<int> s21_set({1, 2, 3, 4, 5, 6, 7, 8, 9, 0});
  std::set<int> std_set({1, 2, 3, 4, 5, 6, 7, 8, 9, 0});
  EXPECT_TRUE(s21_set.size() == std_set.size());
}

TEST(MemberFunctions, test_int_set_2) {
  s21::set<int> s21_set({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
  std::set<int> std_set({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
  s21::set<int> s21_set_copy(s21_set);
  std::set<int> std_set_copy(std_set);
  EXPECT_TRUE(CompaireTree(s21_set, std_set));
  EXPECT_TRUE(CompaireTree(s21_set_copy, std_set_copy));
  EXPECT_TRUE(s21_set.size() == s21_set_copy.size());
  EXPECT_TRUE(std_set.size() == std_set_copy.size());
}

TEST(MemberFunctions, test_int_set_3) {
  s21::set<int> s21_set = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::set<int> std_set = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21::set<int> s21_set_copy(s21_set);
  std::set<int> std_set_copy(std_set);
  EXPECT_TRUE(CompaireTree(s21_set, std_set));
  EXPECT_TRUE(CompaireTree(s21_set_copy, std_set_copy));
  EXPECT_TRUE(s21_set.size() == s21_set_copy.size());
  EXPECT_TRUE(std_set.size() == std_set_copy.size());
}

TEST(MemberFunctions, test_int_set_4) {
  s21::set<int> s21_set = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::set<int> std_set = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  s21::set<int> s21_set_copy(s21_set);
  std::set<int> std_set_copy(std_set);
  EXPECT_TRUE(!CompaireTree(s21_set, std_set));
  EXPECT_TRUE(!CompaireTree(s21_set_copy, std_set_copy));
  EXPECT_TRUE(s21_set.size() == s21_set_copy.size());
  EXPECT_TRUE(std_set.size() == std_set_copy.size());
}

//------------------------------------------------------------- Iterators

TEST(Iterators, test_int_set_0) {
  std::initializer_list<int> data = {88, 1, 2, 3, 4, 5, 6, 7, 8, 99};
  s21::set<int> s21_set = data;
  std::set<int> std_set = data;
  EXPECT_TRUE(*s21_set.begin() == *std_set.begin());
}

TEST(Iterators, test_int_set_2) {
  s21::set<int> s21_set({88, 1, 2, 3, 4, 5, 6, 7, 8, 99});
  std::set<int> std_set({88, 1, 2, 3, 4, 5, 6, 7, 8, 99});
  EXPECT_TRUE(*s21_set.cbegin() == *std_set.cbegin());
}

//------------------------------------------------------------- Capacity

TEST(Capacity, test_int_set_0) {
  std::initializer_list<int> data = {88, 1, 2, 3, 4, 5, 6, 7, 8, 99};
  s21::set<int> s21_set = data;
  std::set<int> std_set = data;
  EXPECT_TRUE(s21_set.empty() == std_set.empty());
}

TEST(Capacity, test_int_set_1) {
  std::initializer_list<int> data = {88, 1, 2, 3, 4, 5, 6, 7, 8, 99};
  s21::set<int> s21_set = data;
  std::set<int> std_set = data;
  EXPECT_TRUE(s21_set.size() == std_set.size());
}

TEST(Capacity, test_int_set_2) {
  std::initializer_list<int> data = {88, 1, 2, 3, 4, 5, 6, 7, 8, 99};
  s21::set<int> s21_set = data;
  std::set<int> std_set = data;
  // std::cout << "s21 = " << s21_set.max_size() << std::endl;
  // std::cout << "std = " << std_set.max_size() << std::endl;
  EXPECT_TRUE(s21_set.max_size() == std_set.max_size());
}

TEST(Capacity, test_bool_set_2) {
  std::initializer_list<bool> data = {true, true, true, false};
  s21::set<bool> s21_set = data;
  std::set<bool> std_set = data;
  // std::cout << "s21 = " << s21_set.max_size() << std::endl;
  // std::cout << "std = " << std_set.max_size() << std::endl;
  EXPECT_TRUE(s21_set.max_size() == std_set.max_size());
}

TEST(Capacity, test_int_set_3) {
  s21::set<int> s21_set;
  std::set<int> std_set;
  EXPECT_TRUE(s21_set.empty() == std_set.empty());
  EXPECT_TRUE(true == std_set.empty());
  EXPECT_TRUE(s21_set.empty() == true);
}

//------------------------------------------------------------- Modifiers

TEST(Modifiers, test_int_set_0) {
  std::initializer_list<int> data = {88, 1, 2, 3, 4, 5, 6, 7, 8, 99};
  s21::set<int> s21_set = data;
  std::set<int> std_set = data;
  s21_set.clear();
  std_set.clear();
  EXPECT_TRUE(s21_set.empty() == std_set.empty());
  EXPECT_TRUE(s21_set.empty() == true);
  EXPECT_TRUE(true == std_set.empty());
}

TEST(Modifiers, test_int_set_1) {
  std::initializer_list<int> data = {88, 1, 2, 3, 4, 5, 6, 7, 8, 99};
  s21::set<int> s21_set = data;
  std::set<int> std_set = data;
  s21_set.insert(13);
  std_set.insert(13);
  EXPECT_TRUE(CompaireTree(s21_set, std_set));
  EXPECT_TRUE(s21_set.size() == std_set.size());
}

TEST(Modifiers, test_int_set_2) {
  std::initializer_list<int> data = {88, 1, 2, 3, 4, 5, 6, 7, 8, 99};
  s21::set<int> s21_set = data;
  std::set<int> std_set = data;
  auto iter_s21 = s21_set.begin();
  auto iter_std = std_set.begin();
  for (int i = 0; i < 5; i++) {
    ++iter_s21;
    ++iter_std;
  }
  s21_set.erase(iter_s21);
  std_set.erase(iter_std);
  // std::cout << "s21 = " << s21_set.size() << std::endl;
  // std::cout << "std = " << std_set.size() << std::endl;
  EXPECT_TRUE(CompaireTree(s21_set, std_set));
  EXPECT_TRUE(s21_set.size() == std_set.size());
}

TEST(Modifiers, test_int_set_3) {
  std::initializer_list<int> data_1 = {88, 1, 2, 3, 4, 5, 6, 7, 8, 99};
  std::initializer_list<int> data_2 = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
  s21::set<int> s21_set_1 = data_1;
  s21::set<int> s21_set_2 = data_2;
  std::set<int> std_set_1 = data_1;
  std::set<int> std_set_2 = data_2;
  s21_set_1.merge(s21_set_2);
  std_set_1.merge(std_set_2);
  // std::cout << "s21 = " << s21_set_1.size() << std::endl;
  // std::cout << "std = " << std_set_1.size() << std::endl;
  EXPECT_TRUE(CompaireTree(s21_set_1, std_set_1));
  EXPECT_TRUE(s21_set_1.size() == std_set_1.size());
}

//------------------------------------------------------------- Lookup

TEST(Lookup, test_int_set_0) {
  std::initializer_list<int> data = {88, 1, 2, 3, 4, 5, 6, 7, 8, 99};
  s21::set<int> s21_set = data;
  std::set<int> std_set = data;
  auto iter_s21 = s21_set.find(6);
  auto iter_std = std_set.find(6);
  EXPECT_TRUE(*iter_s21 == *iter_std);
}

//-------------------------------------------------------------

TEST(MapModifiers, test_int_set_insert_many) {
  s21::set<int> s21_set = {0, 1, 2, 3, 4, 5};
  auto result = s21_set.insert_many(5, 6, 7);
  std::set<int> std_set = {0, 1, 2, 3, 4, 5, 6, 7};
  EXPECT_TRUE(CompaireTree(s21_set, std_set));
}
// double
//------------------------------------------------------------- MemberFunctions

TEST(MemberFunctions, test_double_set_0) {
  s21::set<double> s21_set;
  std::set<double> std_set;
  EXPECT_TRUE(s21_set.size() == std_set.size());
}

TEST(MemberFunctions, test_double_set_1) {
  s21::set<double> s21_set({1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 0});
  std::set<double> std_set({1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 0});
  EXPECT_TRUE(s21_set.size() == std_set.size());
}

TEST(MemberFunctions, test_double_set_2) {
  s21::set<double> s21_set(
      {0.1, 1.5, 2.4, 3.2, 4.8, 5.3, 6.2, 7.1, 8.5, 9.9, 10});
  std::set<double> std_set(
      {0.1, 1.5, 2.4, 3.2, 4.8, 5.3, 6.2, 7.1, 8.5, 9.9, 10});
  s21::set<double> s21_set_copy(s21_set);
  std::set<double> std_set_copy(std_set);
  EXPECT_TRUE(CompaireTree(s21_set, std_set));
  EXPECT_TRUE(CompaireTree(s21_set_copy, std_set_copy));
  EXPECT_TRUE(s21_set.size() == s21_set_copy.size());
  EXPECT_TRUE(std_set.size() == std_set_copy.size());
}

TEST(MemberFunctions, test_double_set_3) {
  s21::set<double> s21_set = {0.1, 1.5, 2.4, 3.2, 4.8, 5.3,
                              6.2, 7.1, 8.5, 9.9, 10};
  std::set<double> std_set = {0.1, 1.5, 2.4, 3.2, 4.8, 5.3,
                              6.2, 7.1, 8.5, 9.9, 10};
  s21::set<double> s21_set_copy(s21_set);
  std::set<double> std_set_copy(std_set);
  EXPECT_TRUE(CompaireTree(s21_set, std_set));
  EXPECT_TRUE(CompaireTree(s21_set_copy, std_set_copy));
  EXPECT_TRUE(s21_set.size() == s21_set_copy.size());
  EXPECT_TRUE(std_set.size() == std_set_copy.size());
}

TEST(MemberFunctions, test_double_set_4) {
  s21::set<double> s21_set = {0.1, 1.5, 2.4, 3.2, 4.8, 5.3,
                              6.2, 7.1, 8.5, 9.9, 10};
  std::set<double> std_set = {0.1, 1.5, 2.4, 3.2, 4.8, 5.3,
                              6.2, 7.1, 8.5, 9.9, 0};
  s21::set<double> s21_set_copy(s21_set);
  std::set<double> std_set_copy(std_set);
  EXPECT_TRUE(!CompaireTree(s21_set, std_set));
  EXPECT_TRUE(!CompaireTree(s21_set_copy, std_set_copy));
  EXPECT_TRUE(s21_set.size() == s21_set_copy.size());
  EXPECT_TRUE(std_set.size() == std_set_copy.size());
}

//------------------------------------------------------------- Iterators

TEST(Iterators, test_double_set_0) {
  std::initializer_list<double> data = {88.0, 1.1, 2.2, 3.3, 4.4,
                                        5.5,  6.6, 7.7, 8.8, 99};
  s21::set<double> s21_set = data;
  std::set<double> std_set = data;
  EXPECT_TRUE(*s21_set.begin() == *std_set.begin());
}

TEST(Iterators, test_double_set_2) {
  s21::set<double> s21_set({88.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 99});
  std::set<double> std_set({88.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 99});
  EXPECT_TRUE(*s21_set.cbegin() == *std_set.cbegin());
}

//------------------------------------------------------------- Capacity

TEST(Capacity, test_double_set_0) {
  std::initializer_list<double> data = {88.0, 1.1, 2.2, 3.3, 4.4,
                                        5.5,  6.6, 7.7, 8.8, 99};
  s21::set<double> s21_set = data;
  std::set<double> std_set = data;
  EXPECT_TRUE(s21_set.empty() == std_set.empty());
}

TEST(Capacity, test_double_set_1) {
  std::initializer_list<double> data = {88.0, 1.1, 2.2, 3.3, 4.4,
                                        5.5,  6.6, 7.7, 8.8, 99};
  s21::set<double> s21_set = data;
  std::set<double> std_set = data;
  EXPECT_TRUE(s21_set.size() == std_set.size());
}

TEST(Capacity, test_double_set_2) {
  std::initializer_list<double> data = {88.0, 1.1, 2.2, 3.3, 4.4,
                                        5.5,  6.6, 7.7, 8.8, 99};
  s21::set<double> s21_set = data;
  std::set<double> std_set = data;
  // std::cout << "s21 = " << s21_set.max_size() << std::endl;
  // std::cout << "std = " << std_set.max_size() << std::endl;
  EXPECT_TRUE(s21_set.max_size() == std_set.max_size());
}

TEST(Capacity, test_double_set_3) {
  s21::set<double> s21_set;
  std::set<double> std_set;
  EXPECT_TRUE(s21_set.empty() == std_set.empty());
  EXPECT_TRUE(true == std_set.empty());
  EXPECT_TRUE(s21_set.empty() == true);
}

//------------------------------------------------------------- Modifiers

TEST(Modifiers, test_double_set_0) {
  std::initializer_list<double> data = {88.0, 1.1, 2.2, 3.3, 4.4,
                                        5.5,  6.6, 7.7, 8.8, 99};
  s21::set<double> s21_set = data;
  std::set<double> std_set = data;
  s21_set.clear();
  std_set.clear();
  EXPECT_TRUE(s21_set.empty() == std_set.empty());
  EXPECT_TRUE(s21_set.empty() == true);
  EXPECT_TRUE(true == std_set.empty());
}

TEST(Modifiers, test_double_set_1) {
  std::initializer_list<double> data = {88.0, 1.1, 2.2, 3.3, 4.4,
                                        5.5,  6.6, 7.7, 8.8, 99};
  s21::set<double> s21_set = data;
  std::set<double> std_set = data;
  s21_set.insert(13);
  std_set.insert(13);
  EXPECT_TRUE(CompaireTree(s21_set, std_set));
  EXPECT_TRUE(s21_set.size() == std_set.size());
}

TEST(Modifiers, test_double_set_2) {
  std::initializer_list<double> data = {88.0, 1.1, 2.2, 3.3, 4.4,
                                        5.5,  6.6, 7.7, 8.8, 99};
  s21::set<double> s21_set = data;
  std::set<double> std_set = data;
  auto iter_s21 = s21_set.begin();
  auto iter_std = std_set.begin();
  for (double i = 0; i < 5; i++) {
    ++iter_s21;
    ++iter_std;
  }
  s21_set.erase(iter_s21);
  std_set.erase(iter_std);
  // std::cout << "s21 = " << s21_set.size() << std::endl;
  // std::cout << "std = " << std_set.size() << std::endl;
  EXPECT_TRUE(CompaireTree(s21_set, std_set));
  EXPECT_TRUE(s21_set.size() == std_set.size());
}

TEST(Modifiers, test_double_set_3) {
  std::initializer_list<double> data_1 = {88.0, 1.1, 2.2, 3.3, 4.4,
                                          5.5,  6.6, 7.7, 8.8, 99};
  std::initializer_list<double> data_2 = {11, 12, 13, 14, 15,
                                          16, 17, 18, 19, 20};
  s21::set<double> s21_set_1 = data_1;
  s21::set<double> s21_set_2 = data_2;
  std::set<double> std_set_1 = data_1;
  std::set<double> std_set_2 = data_2;
  s21_set_1.merge(s21_set_2);
  std_set_1.merge(std_set_2);
  // std::cout << "s21 = " << s21_set_1.size() << std::endl;
  // std::cout << "std = " << std_set_1.size() << std::endl;
  EXPECT_TRUE(CompaireTree(s21_set_1, std_set_1));
  EXPECT_TRUE(s21_set_1.size() == std_set_1.size());
}

//------------------------------------------------------------- Lookup

TEST(Lookup, test_double_set_0) {
  std::initializer_list<double> data = {88.0, 1.1, 2.2, 3.3, 4.4,
                                        5.5,  6.6, 7.7, 8.8, 99};
  s21::set<double> s21_set = data;
  std::set<double> std_set = data;
  auto iter_s21 = s21_set.find(6.6);
  auto iter_std = std_set.find(6.6);
  EXPECT_TRUE(*iter_s21 == *iter_std);
}

//-------------------------------------------------------------

TEST(MapModifiers, test_double_set_insert_many) {
  s21::set<double> s21_set = {0.1, 1.2, 2.3, 3.4, 4.5, 5.6};
  auto result = s21_set.insert_many(5.6, 6.7, 7.8);
  std::set<double> std_set = {0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8};
  EXPECT_TRUE(CompaireTree(s21_set, std_set));
  EXPECT_TRUE(s21_set.max_size() == std_set.max_size());
}

//-------------------------------------------------------------
