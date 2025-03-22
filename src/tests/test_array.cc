#include <gtest/gtest.h>

#include <array>
#include <string>

#include "../s21_containers.h"

/* _____________Int_____________ */
/* ________MemberFunctions________ */

TEST(ArrayMemberFunctions, testArrayInt1) {
  s21::array<int, 2> s21_array;
  std::array<int, 2> std_array;
  EXPECT_TRUE(s21_array.size() == std_array.size());
}

TEST(ArrayMemberFunctions, testArrayInt2) {
  s21::array<int, 3> s21_array{1, 2, 3};
  std::array<int, 3> std_array{1, 2, 3};
  for (size_t i = 0; i < s21_array.size(); ++i)
    EXPECT_TRUE(s21_array[i] == std_array[i]);
}

TEST(ArrayMemberFunctions, testArrayInt3) {
  s21::array<int, 3> s21_array = {5, 3, 78};
  std::array<int, 3> std_array = {5, 3, 78};
  for (size_t i = 0; i < s21_array.size(); ++i)
    EXPECT_TRUE(s21_array[i] == std_array[i]);
}

TEST(ArrayMemberFunctions, testArrayInt4) {
  s21::array<int, 0> s21_array;
  std::array<int, 0> std_array;
  EXPECT_TRUE(s21_array.size() == std_array.size());
}

TEST(ArrayMemberFunctions, testArrayInt5) {
  s21::array<int, 6> s21_array{1, 3, 4, 5};
  std::array<int, 6> std_array{1, 3, 4, 5};
  for (size_t i = 0; i < s21_array.size(); ++i)
    EXPECT_TRUE(s21_array[i] == std_array[i]);
}

TEST(ArrayMemberFunctions, testArrayInt6) {
  s21::array<int, 6> s21_array_1{1, 2};
  s21::array<int, 6> s21_array_2(s21_array_1);
  for (size_t i = 0; i < s21_array_1.size(); ++i)
    EXPECT_TRUE(s21_array_1[i] == s21_array_2[i]);
}

TEST(ArrayMemberFunctions, testArrayInt7) {
  s21::array<int, 2> s21_array_1{1, 2};
  s21::array<int, 2> s21_array_2{0, 3};
  s21_array_1 = s21_array_2;
  for (size_t i = 0; i < s21_array_1.size(); ++i)
    EXPECT_TRUE(s21_array_1[i] == s21_array_2[i]);
}

TEST(ArrayMemberFunctions, testArrayInt8) {
  s21::array<int, 5> s21_array_1{1, 2, 4, 5, 3};
  s21::array<int, 5> s21_array_2 = s21_array_1;
  for (size_t i = 0; i < s21_array_1.size(); ++i)
    EXPECT_TRUE(s21_array_1[i] == s21_array_2[i]);
}

/* ________ElementAccess________ */

TEST(ArrayElementAccess, testArrayInt1) {
  s21::array<int, 4> s21_array{1, 2, 3, 4};
  EXPECT_TRUE(s21_array.at(0) == 1);
  EXPECT_TRUE(s21_array.at(1) == 2);
  EXPECT_TRUE(s21_array.at(2) == 3);
  EXPECT_TRUE(s21_array.at(3) == 4);
}

TEST(ArrayElementAccess, testArrayInt2) {
  s21::array<int, 4> s21_array{1, 2, 3, 4};
  std::array<int, 4> std_array{1, 2, 3, 4};
  EXPECT_TRUE(s21_array.at(0) == std_array.at(0));
  EXPECT_TRUE(s21_array.at(1) == std_array.at(1));
  EXPECT_TRUE(s21_array.at(2) == std_array.at(2));
  EXPECT_TRUE(s21_array.at(3) == std_array.at(3));
}

TEST(ArrayElementAccess, testArrayInt3) {
  s21::array<int, 6> s21_array{1, 2, 3, 4, 5, 6};
  std::array<int, 6> std_array{1, 2, 3, 4, 5, 6};
  EXPECT_TRUE(s21_array[0] == std_array[0]);
  EXPECT_TRUE(s21_array[1] == std_array[1]);
  EXPECT_TRUE(s21_array[2] == std_array[2]);
  EXPECT_TRUE(s21_array[3] == std_array[3]);
  EXPECT_TRUE(s21_array[4] == std_array[4]);
  EXPECT_TRUE(s21_array[5] == std_array[5]);
}

TEST(ArrayElementAccess, testArrayInt4) {
  s21::array<int, 6> s21_array{1, 2, 3, 4, 5, 6};
  std::array<int, 6> std_array{1, 2, 3, 4, 5, 6};
  int s21 = s21_array.front();
  int std = std_array.front();
  EXPECT_TRUE(s21 == std);
}

TEST(ArrayElementAccess, testArrayInt5) {
  s21::array<int, 6> s21_array{1, 2, 3, 4, 5, 6};
  std::array<int, 6> std_array{1, 2, 3, 4, 5, 6};
  int s21 = s21_array.back();
  int std = std_array.back();
  EXPECT_TRUE(s21 == std);
}

TEST(ArrayElementAccess, testArrayInt6) {
  s21::array<int, 6> s21_array{1, 2, 3};
  std::array<int, 6> std_array{1, 2, 3};
  EXPECT_TRUE(s21_array[0] == std_array[0]);
  EXPECT_TRUE(s21_array[1] == std_array[1]);
  EXPECT_TRUE(s21_array[2] == std_array[2]);
  EXPECT_TRUE(s21_array[3] == std_array[3]);
  EXPECT_TRUE(s21_array[4] == std_array[4]);
  EXPECT_TRUE(s21_array[5] == std_array[5]);
}

// TEST(ArrayElementAccess, testArrayInt7) {
//   s21::array<int, 6> s21_array{1, 2, 3};
//   EXPECT_ANY_THROW(s21_array.at(-1));
// }

// TEST(ArrayElementAccess, testArrayInt8) {
//   s21::array<int, 6> s21_array{1, 2, 3};
//   EXPECT_ANY_THROW(s21_array.at(6));
// }

TEST(ArrayElementAccess, testArrayInt9) {
  s21::array<int, 6> s21_array{1, 2, 3, 4, 5, 6};
  std::array<int, 6> std_array{1, 2, 3, 4, 5, 6};
  EXPECT_TRUE(*s21_array.data() == *std_array.data());
}

/* _________Iterators_________ */

TEST(ArrayIterators, testArrayInt1) {
  s21::array<int, 6> s21_array{1, 2, 3, 4, 5, 6};
  std::array<int, 6> std_array{1, 2, 3, 4, 5, 6};
  EXPECT_TRUE(*s21_array.begin() == *std_array.begin());
}

TEST(ArrayIterators, testArrayInt2) {
  s21::array<int, 6> s21_array{1, 2, 3, 4, 5, 6};
  std::array<int, 6> std_array{1, 2, 3, 4, 5, 6};
  EXPECT_TRUE(*(s21_array.end() - 1) == *(std_array.end() - 1));
}

/* _________Capacity_________ */

TEST(ArrayCapacity, testArrayInt1) {
  s21::array<int, 0> s21_array;
  EXPECT_TRUE(s21_array.empty() == 1);
}

TEST(ArrayCapacity, testArrayInt2) {
  s21::array<int, 1> s21_array;
  EXPECT_TRUE(s21_array.empty() == 0);
}

TEST(ArrayCapacity, testArrayInt3) {
  s21::array<int, 3> s21_array{1, 2, 3};
  std::array<int, 6> std_array{1, 2, 3, 4, 3, 5};
  EXPECT_TRUE(s21_array.empty() == std_array.empty());
}

TEST(ArrayCapacity, testArrayInt4) {
  s21::array<int, 8> s21_array{1, 2, 3};
  std::array<int, 8> std_array{1, 2, 3};
  EXPECT_TRUE(s21_array.size() == std_array.size());
}

TEST(ArrayCapacity, testArrayInt5) {
  s21::array<int, 8> s21_array{1, 2, 3, 4, 5, 6};
  std::array<int, 8> std_array{1, 2, 3};
  EXPECT_TRUE(s21_array.size() == std_array.size());
}

TEST(ArrayCapacity, testArrayInt6) {
  s21::array<int, 8> s21_array{1, 2, 3, 4, 5, 6};
  std::array<int, 8> std_array{1, 2, 3};
  EXPECT_TRUE(s21_array.max_size() == std_array.max_size());
}

/* _________Modifiers_________ */

TEST(ArrayModifiers, testArrayInt1) {
  s21::array<int, 3> s21_array_1{1, 2, 3};
  s21::array<int, 3> s21_array_2{4, 5, 6};
  std::array<int, 3> std_array_1{1, 2, 3};
  std::array<int, 3> std_array_2{4, 5, 6};
  s21_array_1.swap(s21_array_2);
  std_array_1.swap(std_array_2);
  for (size_t i = 0; i < s21_array_1.size(); ++i)
    EXPECT_TRUE(s21_array_1[i] == std_array_1[i]);
}

TEST(ArrayModifiers, testArrayInt2) {
  s21::array<int, 3> s21_array{1, 2, 3};
  std::array<int, 3> std_array{1, 2, 3};
  std_array.fill(3);
  s21_array.fill(3);
  for (size_t i = 0; i < s21_array.size(); ++i)
    EXPECT_TRUE(s21_array[i] == std_array[i]);
}

TEST(ArrayModifiers, testArrayInt3) {
  s21::array<int, 3> s21_array{1, 2, 3};
  std::array<int, 3> std_array{1, 2, 3};
  std_array.fill(0);
  s21_array.fill(0);
  EXPECT_TRUE(s21_array[0] == 0);
}

/* _____________Float_____________ */
/* ________MemberFunctions________ */

TEST(ArrayMemberFunctions, testArrayFloat1) {
  s21::array<float, 2> s21_array;
  std::array<float, 2> std_array;
  EXPECT_TRUE(s21_array.size() == std_array.size());
}

TEST(ArrayMemberFunctions, testArrayFloat2) {
  s21::array<float, 3> s21_array{1.324, 2.23, 3.55};
  std::array<float, 3> std_array{1.324, 2.23, 3.55};
  for (size_t i = 0; i < s21_array.size(); ++i)
    EXPECT_TRUE(s21_array[i] == std_array[i]);
}

TEST(ArrayMemberFunctions, testArrayFloat3) {
  s21::array<float, 3> s21_array = {5.444, 3.434, 78.03123};
  std::array<float, 3> std_array = {5.444, 3.434, 78.03123};
  for (size_t i = 0; i < s21_array.size(); ++i)
    EXPECT_TRUE(s21_array[i] == std_array[i]);
}

TEST(ArrayMemberFunctions, testArrayFloat4) {
  s21::array<float, 0> s21_array;
  std::array<float, 0> std_array;
  EXPECT_TRUE(s21_array.size() == std_array.size());
}

TEST(ArrayMemberFunctions, testArrayFloat5) {
  s21::array<float, 6> s21_array{1., 3.00002, 4.343242, -5.3413};
  std::array<float, 6> std_array{1., 3.00002, 4.343242, -5.3413};
  for (size_t i = 0; i < s21_array.size(); ++i)
    EXPECT_TRUE(s21_array[i] == std_array[i]);
}

TEST(ArrayMemberFunctions, testArrayFloat6) {
  s21::array<float, 6> s21_array_1{1.33, 2.0000012};
  s21::array<float, 6> s21_array_2(s21_array_1);
  for (size_t i = 0; i < s21_array_1.size(); ++i)
    EXPECT_TRUE(s21_array_1[i] == s21_array_2[i]);
}

TEST(ArrayMemberFunctions, testArrayFloat7) {
  s21::array<float, 2> s21_array_1{1.432421, 2.876543};
  s21::array<float, 2> s21_array_2{0.0003, 3.87677777};
  s21_array_1 = s21_array_2;
  for (size_t i = 0; i < s21_array_1.size(); ++i)
    EXPECT_TRUE(s21_array_1[i] == s21_array_2[i]);
}

TEST(ArrayMemberFunctions, testArrayFloat8) {
  s21::array<float, 5> s21_array_1{1.00002, -2.003, 4.43444, 5.099999, 3.34234};
  s21::array<float, 5> s21_array_2 = s21_array_1;
  for (size_t i = 0; i < s21_array_1.size(); ++i)
    EXPECT_TRUE(s21_array_1[i] == s21_array_2[i]);
}

/* ________ElementAccess________ */

TEST(ArrayElementAccess, testArrayFloat1) {
  s21::array<float, 4> s21_array{1.0001, -2.3341, 3.00004, 4.1111114};
  std::array<float, 4> std_array{1.0001, -2.3341, 3.00004, 4.1111114};
  EXPECT_TRUE(s21_array.at(0) == std_array.at(0));
  EXPECT_TRUE(s21_array.at(1) == std_array.at(1));
  EXPECT_TRUE(s21_array.at(2) == std_array.at(2));
  EXPECT_TRUE(s21_array.at(3) == std_array.at(3));
}

TEST(ArrayElementAccess, testArrayFloat2) {
  s21::array<float, 4> s21_array{1.0001, -2.3341, 3.00004, 4.1111114};
  std::array<float, 4> std_array{1.0001, -2.3341, 3.00004, 4.1111114};
  EXPECT_TRUE(s21_array.at(0) == std_array.at(0));
  EXPECT_TRUE(s21_array.at(1) == std_array.at(1));
  EXPECT_TRUE(s21_array.at(2) == std_array.at(2));
  EXPECT_TRUE(s21_array.at(3) == std_array.at(3));
}

TEST(ArrayElementAccess, testArrayFloat3) {
  s21::array<float, 6> s21_array{1.020001, 2.3485374192, 3.304134,
                                 4.040409, 5.439845,     6.4440099};
  std::array<float, 6> std_array{1.020001, 2.3485374192, 3.304134,
                                 4.040409, 5.439845,     6.4440099};
  EXPECT_TRUE(s21_array[0] == std_array[0]);
  EXPECT_TRUE(s21_array[1] == std_array[1]);
  EXPECT_TRUE(s21_array[2] == std_array[2]);
  EXPECT_TRUE(s21_array[3] == std_array[3]);
  EXPECT_TRUE(s21_array[4] == std_array[4]);
  EXPECT_TRUE(s21_array[5] == std_array[5]);
}

TEST(ArrayElementAccess, testArrayFloat4) {
  s21::array<float, 6> s21_array{1.020001, 2.3485374192, 3.304134,
                                 4.040409, 5.439845,     6.4440099};
  std::array<float, 6> std_array{1.020001, 2.3485374192, 3.304134,
                                 4.040409, 5.439845,     6.4440099};
  float s21 = s21_array.front();
  float std = std_array.front();
  EXPECT_TRUE(s21 == std);
}

TEST(ArrayElementAccess, testArrayFloat5) {
  s21::array<float, 6> s21_array{1.020001, 2.3485374192, 3.304134,
                                 4.040409, 5.439845,     6.4440099};
  std::array<float, 6> std_array{1.020001, 2.3485374192, 3.304134,
                                 4.040409, 5.439845,     6.4440099};
  float s21 = s21_array.back();
  float std = std_array.back();
  EXPECT_TRUE(s21 == std);
}

TEST(ArrayElementAccess, testArrayFloat6) {
  s21::array<float, 6> s21_array{1.0001, -2.3341, 3.00004, 4.1111114};
  std::array<float, 6> std_array{1.0001, -2.3341, 3.00004, 4.1111114};
  EXPECT_TRUE(s21_array[0] == std_array[0]);
  EXPECT_TRUE(s21_array[1] == std_array[1]);
  EXPECT_TRUE(s21_array[2] == std_array[2]);
  EXPECT_TRUE(s21_array[3] == std_array[3]);
  EXPECT_TRUE(s21_array[4] == std_array[4]);
  EXPECT_TRUE(s21_array[5] == std_array[5]);
}

// TEST(ArrayElementAccess, testArrayFloat7) {
//   s21::array<float, 6> s21_array{0.0003, 3.87677777, 9.9999999};
//   EXPECT_ANY_THROW(s21_array.at(-1));
// }

// TEST(ArrayElementAccess, testArrayFloat8) {
//   s21::array<float, 6> s21_array{0.0003, -3.87677777, 9.9999999};
//   EXPECT_ANY_THROW(s21_array.at(6));
// }

TEST(ArrayElementAccess, testArrayFloat9) {
  s21::array<float, 6> s21_array{1.020001, 2.3485374192, 3.304134,
                                 4.040409, 5.439845,     6.4440099};
  std::array<float, 6> std_array{1.020001, 2.3485374192, 3.304134,
                                 4.040409, 5.439845,     6.4440099};
  EXPECT_TRUE(*s21_array.data() == *std_array.data());
}

/* _________Iterators_________ */

TEST(ArrayIterators, testArrayFloat1) {
  s21::array<float, 6> s21_array{1.00002,  -2.003,  4.43444,
                                 5.099999, 1.00002, -2.003};
  std::array<float, 6> std_array{1.00002,  -2.003,  4.43444,
                                 5.099999, 1.00002, -2.003};
  EXPECT_TRUE(*s21_array.begin() == *std_array.begin());
}

TEST(ArrayIterators, testArrayFloat2) {
  s21::array<float, 6> s21_array{1.00002,  -2.003,  4.43444,
                                 5.099999, 1.00002, -2.003};
  std::array<float, 6> std_array{1.00002,  -2.003,  4.43444,
                                 5.099999, 1.00002, -2.003};
  EXPECT_TRUE(*(s21_array.end() - 1) == *(std_array.end() - 1));
}

/* _________Capacity_________ */

TEST(ArrayCapacity, testArrayFloat1) {
  s21::array<float, 0> s21_array;
  EXPECT_TRUE(s21_array.empty() == 1);
}

TEST(ArrayCapacity, testArrayFloat2) {
  s21::array<float, 1> s21_array;
  EXPECT_TRUE(s21_array.empty() == 0);
}

TEST(ArrayCapacity, testArrayFloat3) {
  s21::array<float, 3> s21_array{1.123, 2.421342, 0.333003};
  std::array<float, 6> std_array{0.23412, 2.3241, 3.34, 4.03, 3.31, 5.23};
  EXPECT_TRUE(s21_array.empty() == std_array.empty());
}

TEST(ArrayCapacity, testArrayFloat4) {
  s21::array<float, 8> s21_array{1.444, 2.222, 3.445};
  std::array<float, 8> std_array{1.341, 2.3412, 3.42134};
  EXPECT_TRUE(s21_array.size() == std_array.size());
}

TEST(ArrayCapacity, testArrayFloat5) {
  s21::array<float, 8> s21_array{1.333, 2.444, 3.555, 4.123, 0.5, 3.6};
  std::array<float, 8> std_array{1.1, 9.2, 34.3};
  EXPECT_TRUE(s21_array.size() == std_array.size());
}

TEST(ArrayCapacity, testArrayFloat6) {
  s21::array<float, 8> s21_array{143.14, 24235.2341, 344.134,
                                 4.5551, 5.423,      6.424};
  std::array<float, 8> std_array{0.1, -0.2, 41340.3};
  EXPECT_TRUE(s21_array.max_size() == std_array.max_size());
}

/* _________Modifiers_________ */

TEST(ArrayModifiers, testArrayFloat1) {
  s21::array<float, 3> s21_array_1{1.444, -0.2, -34321.4};
  s21::array<float, 3> s21_array_2{-8.421, 0.45, 6.9348};
  std::array<float, 3> std_array_1{1.444, -0.2, -34321.4};
  std::array<float, 3> std_array_2{-8.421, 0.45, 6.9348};
  s21_array_1.swap(s21_array_2);
  std_array_1.swap(std_array_2);
  for (size_t i = 0; i < s21_array_1.size(); ++i) {
    EXPECT_TRUE(s21_array_1[i] == std_array_1[i]);
    EXPECT_TRUE(s21_array_2[i] == std_array_2[i]);
  }
}

TEST(ArrayModifiers, testArrayFloat2) {
  s21::array<float, 3> s21_array{1.332, 2.00342, 3.212};
  std::array<float, 3> std_array{0.1, 0.342, 3.342};
  std_array.fill(3);
  s21_array.fill(3);
  for (size_t i = 0; i < s21_array.size(); ++i)
    EXPECT_TRUE(s21_array[i] == std_array[i]);
}

TEST(ArrayModifiers, testArrayFloat3) {
  s21::array<float, 3> s21_array{1.333, -2.314, 3.341};
  std::array<float, 3> std_array{1.999, 2.3001, -3.341};
  std_array.fill(0);
  s21_array.fill(0);
  EXPECT_TRUE(s21_array[0] == 0);
}

/* _____________Double_____________ */
/* ________MemberFunctions________ */

TEST(ArrayMemberFunctions, testArrayDouble1) {
  s21::array<double, 2> s21_array;
  std::array<double, 2> std_array;
  EXPECT_TRUE(s21_array.size() == std_array.size());
}

TEST(ArrayMemberFunctions, testArrayDouble2) {
  s21::array<double, 3> s21_array{1.324, 2.23, 3.55};
  std::array<double, 3> std_array{1.324, 2.23, 3.55};
  for (size_t i = 0; i < s21_array.size(); ++i)
    EXPECT_TRUE(s21_array[i] == std_array[i]);
}

TEST(ArrayMemberFunctions, testArrayDouble3) {
  s21::array<double, 3> s21_array = {5.444, 3.434, 78.03123};
  std::array<double, 3> std_array = {5.444, 3.434, 78.03123};
  for (size_t i = 0; i < s21_array.size(); ++i)
    EXPECT_TRUE(s21_array[i] == std_array[i]);
}

TEST(ArrayMemberFunctions, testArrayDouble4) {
  s21::array<double, 0> s21_array;
  std::array<double, 0> std_array;
  EXPECT_TRUE(s21_array.size() == std_array.size());
}

TEST(ArrayMemberFunctions, testArrayDouble5) {
  s21::array<double, 6> s21_array{1., 3.00002, 4.343242, -5.3413};
  std::array<double, 6> std_array{1., 3.00002, 4.343242, -5.3413};
  for (size_t i = 0; i < s21_array.size(); ++i)
    EXPECT_TRUE(s21_array[i] == std_array[i]);
}

TEST(ArrayMemberFunctions, testArrayDouble6) {
  s21::array<double, 6> s21_array_1{1.33, 2.0000012};
  s21::array<double, 6> s21_array_2(s21_array_1);
  for (size_t i = 0; i < s21_array_1.size(); ++i)
    EXPECT_TRUE(s21_array_1[i] == s21_array_2[i]);
}

TEST(ArrayMemberFunctions, testArrayDouble7) {
  s21::array<double, 2> s21_array_1{1.432421, 2.876543};
  s21::array<double, 2> s21_array_2{0.0003, 3.87677777};
  s21_array_1 = s21_array_2;
  for (size_t i = 0; i < s21_array_1.size(); ++i)
    EXPECT_TRUE(s21_array_1[i] == s21_array_2[i]);
}

TEST(ArrayMemberFunctions, testArrayDouble8) {
  s21::array<double, 5> s21_array_1{1.00002, -2.003, 4.43444, 5.099999,
                                    3.34234};
  s21::array<double, 5> s21_array_2 = s21_array_1;
  for (size_t i = 0; i < s21_array_1.size(); ++i)
    EXPECT_TRUE(s21_array_1[i] == s21_array_2[i]);
}

/* ________ElementAccess________ */

TEST(ArrayElementAccess, testArrayDouble1) {
  s21::array<double, 4> s21_array{1.0001, -2.3341, 3.00004, 4.1111114};
  std::array<double, 4> std_array{1.0001, -2.3341, 3.00004, 4.1111114};
  EXPECT_TRUE(s21_array.at(0) == std_array.at(0));
  EXPECT_TRUE(s21_array.at(1) == std_array.at(1));
  EXPECT_TRUE(s21_array.at(2) == std_array.at(2));
  EXPECT_TRUE(s21_array.at(3) == std_array.at(3));
}

TEST(ArrayElementAccess, testArrayDouble2) {
  s21::array<double, 4> s21_array{1.0001, -2.3341, 3.00004, 4.1111114};
  std::array<double, 4> std_array{1.0001, -2.3341, 3.00004, 4.1111114};
  EXPECT_TRUE(s21_array.at(0) == std_array.at(0));
  EXPECT_TRUE(s21_array.at(1) == std_array.at(1));
  EXPECT_TRUE(s21_array.at(2) == std_array.at(2));
  EXPECT_TRUE(s21_array.at(3) == std_array.at(3));
}

TEST(ArrayElementAccess, testArrayDouble3) {
  s21::array<double, 6> s21_array{1.020001, 2.3485374192, 3.304134,
                                  4.040409, 5.439845,     6.4440099};
  std::array<double, 6> std_array{1.020001, 2.3485374192, 3.304134,
                                  4.040409, 5.439845,     6.4440099};
  EXPECT_TRUE(s21_array[0] == std_array[0]);
  EXPECT_TRUE(s21_array[1] == std_array[1]);
  EXPECT_TRUE(s21_array[2] == std_array[2]);
  EXPECT_TRUE(s21_array[3] == std_array[3]);
  EXPECT_TRUE(s21_array[4] == std_array[4]);
  EXPECT_TRUE(s21_array[5] == std_array[5]);
}

TEST(ArrayElementAccess, testArrayDouble4) {
  s21::array<double, 6> s21_array{1.020001, 2.3485374192, 3.304134,
                                  4.040409, 5.439845,     6.4440099};
  std::array<double, 6> std_array{1.020001, 2.3485374192, 3.304134,
                                  4.040409, 5.439845,     6.4440099};
  double s21 = s21_array.front();
  double std = std_array.front();
  EXPECT_TRUE(s21 == std);
}

TEST(ArrayElementAccess, testArrayDouble5) {
  s21::array<double, 6> s21_array{1.020001, 2.3485374192, 3.304134,
                                  4.040409, 5.439845,     6.4440099};
  std::array<double, 6> std_array{1.020001, 2.3485374192, 3.304134,
                                  4.040409, 5.439845,     6.4440099};
  double s21 = s21_array.back();
  double std = std_array.back();
  EXPECT_TRUE(s21 == std);
}

TEST(ArrayElementAccess, testArrayDouble6) {
  s21::array<double, 6> s21_array{1.0001, -2.3341, 3.00004, 4.1111114};
  std::array<double, 6> std_array{1.0001, -2.3341, 3.00004, 4.1111114};
  EXPECT_TRUE(s21_array[0] == std_array[0]);
  EXPECT_TRUE(s21_array[1] == std_array[1]);
  EXPECT_TRUE(s21_array[2] == std_array[2]);
  EXPECT_TRUE(s21_array[3] == std_array[3]);
  EXPECT_TRUE(s21_array[4] == std_array[4]);
  EXPECT_TRUE(s21_array[5] == std_array[5]);
}

// TEST(ArrayElementAccess, testArrayDouble7) {
//   s21::array<double, 6> s21_array{0.0003, 3.87677777, 9.9999999};
//   EXPECT_ANY_THROW(s21_array.at(-1));
// }

// TEST(ArrayElementAccess, testArrayDouble8) {
//   s21::array<double, 6> s21_array{0.0003, -3.87677777, 9.9999999};
//   EXPECT_ANY_THROW(s21_array.at(6));
// }

TEST(ArrayElementAccess, testArrayDouble9) {
  s21::array<double, 6> s21_array{1.020001, 2.3485374192, 3.304134,
                                  4.040409, 5.439845,     6.4440099};
  std::array<double, 6> std_array{1.020001, 2.3485374192, 3.304134,
                                  4.040409, 5.439845,     6.4440099};
  EXPECT_TRUE(*s21_array.data() == *std_array.data());
}

/* _________Iterators_________ */

TEST(ArrayIterators, testArrayDouble1) {
  s21::array<double, 6> s21_array{1.00002,  -2.003,  4.43444,
                                  5.099999, 1.00002, -2.003};
  std::array<double, 6> std_array{1.00002,  -2.003,  4.43444,
                                  5.099999, 1.00002, -2.003};
  EXPECT_TRUE(*s21_array.begin() == *std_array.begin());
}

TEST(ArrayIterators, testArrayDouble2) {
  s21::array<double, 6> s21_array{1.00002,  -2.003,  4.43444,
                                  5.099999, 1.00002, -2.003};
  std::array<double, 6> std_array{1.00002,  -2.003,  4.43444,
                                  5.099999, 1.00002, -2.003};
  EXPECT_TRUE(*(s21_array.end() - 1) == *(std_array.end() - 1));
}

/* _________Capacity_________ */

TEST(ArrayCapacity, testArrayDouble1) {
  s21::array<double, 0> s21_array;
  EXPECT_TRUE(s21_array.empty() == 1);
}

TEST(ArrayCapacity, testArrayDouble2) {
  s21::array<double, 1> s21_array;
  EXPECT_TRUE(s21_array.empty() == 0);
}

TEST(ArrayCapacity, testArrayDouble3) {
  s21::array<double, 3> s21_array{1.123, 2.421342, 0.333003};
  std::array<double, 6> std_array{0.23412, 2.3241, 3.34, 4.03, 3.31, 5.23};
  EXPECT_TRUE(s21_array.empty() == std_array.empty());
}

TEST(ArrayCapacity, testArrayDouble4) {
  s21::array<double, 8> s21_array{1.444, 2.222, 3.445};
  std::array<double, 8> std_array{1.341, 2.3412, 3.42134};
  EXPECT_TRUE(s21_array.size() == std_array.size());
}

TEST(ArrayCapacity, testArrayDouble5) {
  s21::array<double, 8> s21_array{1.333, 2.444, 3.555, 4.123, 0.5, 3.6};
  std::array<double, 8> std_array{1.1, 9.2, 34.3};
  EXPECT_TRUE(s21_array.size() == std_array.size());
}

TEST(ArrayCapacity, testArrayDouble6) {
  s21::array<double, 8> s21_array{143.14, 24235.2341, 344.134,
                                  4.5551, 5.423,      6.424};
  std::array<double, 8> std_array{0.1, -0.2, 41340.3};
  EXPECT_TRUE(s21_array.max_size() == std_array.max_size());
}

/* _________Modifiers_________ */

TEST(ArrayModifiers, testArrayDouble1) {
  s21::array<double, 3> s21_array_1{1.444, -0.2, -34321.4};
  s21::array<double, 3> s21_array_2{-8.421, 0.45, 6.9348};
  std::array<double, 3> std_array_1{1.444, -0.2, -34321.4};
  std::array<double, 3> std_array_2{-8.421, 0.45, 6.9348};
  s21_array_1.swap(s21_array_2);
  std_array_1.swap(std_array_2);
  for (size_t i = 0; i < s21_array_1.size(); ++i) {
    EXPECT_TRUE(s21_array_1[i] == std_array_1[i]);
    EXPECT_TRUE(s21_array_2[i] == std_array_2[i]);
  }
}

TEST(ArrayModifiers, testArrayDouble2) {
  s21::array<double, 3> s21_array{1.332, 2.00342, 3.212};
  std::array<double, 3> std_array{0.1, 0.342, 3.342};
  std_array.fill(3);
  s21_array.fill(3);
  for (size_t i = 0; i < s21_array.size(); ++i)
    EXPECT_TRUE(s21_array[i] == std_array[i]);
}

TEST(ArrayModifiers, testArrayDouble3) {
  s21::array<double, 3> s21_array{1.333, -2.314, 3.341};
  std::array<double, 3> std_array{1.999, 2.3001, -3.341};
  std_array.fill(0);
  s21_array.fill(0);
  EXPECT_TRUE(s21_array[0] == 0);
}

/* _____________Char_____________ */
/* ________MemberFunctions________ */

TEST(ArrayMemberFunctions, testArrayChar1) {
  s21::array<char, 2> s21_array;
  std::array<char, 2> std_array;
  EXPECT_TRUE(s21_array.size() == std_array.size());
}

TEST(ArrayMemberFunctions, testArrayChar2) {
  s21::array<char, 3> s21_array{'u', 'w', 'u'};
  std::array<char, 3> std_array{'u', 'w', 'u'};
  for (size_t i = 0; i < s21_array.size(); ++i)
    EXPECT_TRUE(s21_array[i] == std_array[i]);
}

TEST(ArrayMemberFunctions, testArrayChar3) {
  s21::array<char, 3> s21_array = {'m', 'u', 'r'};
  std::array<char, 3> std_array = {'m', 'u', 'r'};
  for (size_t i = 0; i < s21_array.size(); ++i)
    EXPECT_TRUE(s21_array[i] == std_array[i]);
}

TEST(ArrayMemberFunctions, testArrayChar4) {
  s21::array<char, 0> s21_array;
  std::array<char, 0> std_array;
  EXPECT_TRUE(s21_array.size() == std_array.size());
}

TEST(ArrayMemberFunctions, testArrayChar5) {
  s21::array<char, 6> s21_array{'m', 'e', 'o', 'w'};
  std::array<char, 6> std_array{'m', 'e', 'o', 'w'};
  for (size_t i = 0; i < s21_array.size(); ++i)
    EXPECT_TRUE(s21_array[i] == std_array[i]);
}

TEST(ArrayMemberFunctions, testArrayChar6) {
  s21::array<char, 6> s21_array_1{'h', 'i'};
  s21::array<char, 6> s21_array_2(s21_array_1);
  for (size_t i = 0; i < s21_array_1.size(); ++i)
    EXPECT_TRUE(s21_array_1[i] == s21_array_2[i]);
}

TEST(ArrayMemberFunctions, testArrayChar7) {
  s21::array<char, 2> s21_array_1{'h', 'i'};
  s21::array<char, 2> s21_array_2{'m', 'e'};
  s21_array_1 = s21_array_2;
  for (size_t i = 0; i < s21_array_1.size(); ++i)
    EXPECT_TRUE(s21_array_1[i] == s21_array_2[i]);
}

TEST(ArrayMemberFunctions, testArrayChar8) {
  s21::array<char, 4> s21_array_1{'h', 'e', 'l', 'p'};
  s21::array<char, 4> s21_array_2 = s21_array_1;
  for (size_t i = 0; i < s21_array_1.size(); ++i)
    EXPECT_TRUE(s21_array_1[i] == s21_array_2[i]);
}

/* ________ElementAccess________ */

TEST(ArrayElementAccess, testArrayChar1) {
  s21::array<char, 4> s21_array{'m', 'u', 'r', 'k'};
  std::array<char, 4> std_array{'m', 'u', 'r', 'k'};
  EXPECT_TRUE(s21_array.at(0) == std_array.at(0));
  EXPECT_TRUE(s21_array.at(1) == std_array.at(1));
  EXPECT_TRUE(s21_array.at(2) == std_array.at(2));
  EXPECT_TRUE(s21_array.at(3) == std_array.at(3));
}

TEST(ArrayElementAccess, testArrayChar2) {
  s21::array<char, 4> s21_array{'h', 'e', 'l', 'o'};
  std::array<char, 4> std_array{'h', 'e', 'l', 'o'};
  EXPECT_TRUE(s21_array.at(0) == std_array.at(0));
  EXPECT_TRUE(s21_array.at(1) == std_array.at(1));
  EXPECT_TRUE(s21_array.at(2) == std_array.at(2));
  EXPECT_TRUE(s21_array.at(3) == std_array.at(3));
}

TEST(ArrayElementAccess, testArrayChar3) {
  s21::array<char, 6> s21_array{'g', 'g', 'h', 'f', 'w', 'p'};
  std::array<char, 6> std_array{'g', 'g', 'h', 'f', 'w', 'p'};
  EXPECT_TRUE(s21_array[0] == std_array[0]);
  EXPECT_TRUE(s21_array[1] == std_array[1]);
  EXPECT_TRUE(s21_array[2] == std_array[2]);
  EXPECT_TRUE(s21_array[3] == std_array[3]);
  EXPECT_TRUE(s21_array[4] == std_array[4]);
  EXPECT_TRUE(s21_array[5] == std_array[5]);
}

TEST(ArrayElementAccess, testArrayChar4) {
  s21::array<char, 5> s21_array{'g', 'r', 'e', 'a', 't'};
  std::array<char, 5> std_array{'g', 'r', 'e', 'a', 't'};
  char s21 = s21_array.front();
  char std = std_array.front();
  EXPECT_TRUE(s21 == std);
}

TEST(ArrayElementAccess, testArrayChar5) {
  s21::array<char, 6> s21_array{'i', 'l', 'i', 'k', 'e', 'u'};
  std::array<char, 6> std_array{'i', 'l', 'i', 'k', 'e', 'u'};
  char s21 = s21_array.back();
  char std = std_array.back();
  EXPECT_TRUE(s21 == std);
}

TEST(ArrayElementAccess, testArrayChar6) {
  s21::array<char, 6> s21_array{'c', 'u', 't', 'e'};
  std::array<char, 6> std_array{'c', 'u', 't', 'e'};
  EXPECT_TRUE(s21_array[0] == std_array[0]);
  EXPECT_TRUE(s21_array[1] == std_array[1]);
  EXPECT_TRUE(s21_array[2] == std_array[2]);
  EXPECT_TRUE(s21_array[3] == std_array[3]);
  EXPECT_TRUE(s21_array[4] == std_array[4]);
  EXPECT_TRUE(s21_array[5] == std_array[5]);
}

// TEST(ArrayElementAccess, testArrayChar7) {
//   s21::array<char, 6> s21_array{'m', 'u', 'r'};
//   EXPECT_ANY_THROW(s21_array.at(-1));
// }

// TEST(ArrayElementAccess, testArrayChar8) {
//   s21::array<char, 6> s21_array{'m', 'e', 'w'};
//   EXPECT_ANY_THROW(s21_array.at(6));
// }

TEST(ArrayElementAccess, testArrayChar9) {
  s21::array<char, 6> s21_array{'t', 'h', 'a', 'n', 'k', 's'};
  std::array<char, 6> std_array{'t', 'h', 'a', 'n', 'k', 's'};
  EXPECT_TRUE(*s21_array.data() == *std_array.data());
}

/* _________Iterators_________ */

TEST(ArrayIterators, testArrayChar1) {
  s21::array<char, 8> s21_array{'f', 'i', 'r', 'e', 's', 't', 'a', 't'};
  std::array<char, 8> std_array{'f', 'i', 'r', 'e', 's', 't', 'a', 't'};
  EXPECT_TRUE(*s21_array.begin() == *std_array.begin());
}

TEST(ArrayIterators, testArrayChar2) {
  s21::array<char, 8> s21_array{'f', 'i', 'r', 'e', 's', 't', 'a', 't'};
  std::array<char, 8> std_array{'f', 'i', 'r', 'e', 's', 't', 'a', 't'};
  EXPECT_TRUE(*(s21_array.end() - 1) == *(std_array.end() - 1));
}

/* _________Capacity_________ */

TEST(ArrayCapacity, testArrayChar1) {
  s21::array<char, 0> s21_array;
  EXPECT_TRUE(s21_array.empty() == 1);
}

TEST(ArrayCapacity, testArrayChar2) {
  s21::array<char, 1> s21_array;
  EXPECT_TRUE(s21_array.empty() == 0);
}

TEST(ArrayCapacity, testArrayChar3) {
  s21::array<char, 3> s21_array{'u', 'w', 'u'};
  std::array<char, 6> std_array{'u', 'r', 'g', 'o', 'o', 'd'};
  EXPECT_TRUE(s21_array.empty() == std_array.empty());
}

TEST(ArrayCapacity, testArrayChar4) {
  s21::array<char, 8> s21_array{'h', 'e', 'y'};
  std::array<char, 8> std_array{'m', 'u', 'r'};
  EXPECT_TRUE(s21_array.size() == std_array.size());
}

TEST(ArrayCapacity, testArrayChar5) {
  s21::array<char, 8> s21_array{'f', 'i', 'r', 'e', 's', 't', 'a', 't'};
  std::array<char, 8> std_array{'k', 'e', 'k'};
  EXPECT_TRUE(s21_array.size() == std_array.size());
}

TEST(ArrayCapacity, testArrayChar6) {
  s21::array<char, 8> s21_array{'m', 'a', 'x', '_', 's', 'i', 'z', 'e'};
  std::array<char, 8> std_array{'g', '+', '+'};
  EXPECT_TRUE(s21_array.max_size() == std_array.max_size());
}

/* _________Modifiers_________ */

TEST(ArrayModifiers, testArrayChar1) {
  s21::array<char, 3> s21_array_1{'k', 'e', 'k'};
  s21::array<char, 3> s21_array_2{'u', 'w', 'u'};
  std::array<char, 3> std_array_1{'k', 'e', 'k'};
  std::array<char, 3> std_array_2{'u', 'w', 'u'};
  s21_array_1.swap(s21_array_2);
  std_array_1.swap(std_array_2);
  for (size_t i = 0; i < s21_array_1.size(); ++i) {
    EXPECT_TRUE(s21_array_1[i] == std_array_1[i]);
    EXPECT_TRUE(s21_array_2[i] == std_array_2[i]);
  }
}

TEST(ArrayModifiers, testArrayChar2) {
  s21::array<char, 3> s21_array{'a', 'b', 'c'};
  std::array<char, 3> std_array{'d', 'e', 'f'};
  std_array.fill('+');
  s21_array.fill('+');
  for (size_t i = 0; i < s21_array.size(); ++i)
    EXPECT_TRUE(s21_array[i] == std_array[i]);
}

TEST(ArrayModifiers, testArrayChar3) {
  s21::array<char, 3> s21_array{'a', 'b', 'c'};
  std::array<char, 3> std_array{'d', 'e', 'f'};
  std_array.fill(' ');
  s21_array.fill(' ');
  EXPECT_TRUE(s21_array[0] == ' ');
  EXPECT_TRUE(std_array[0] == ' ');
}

/* _____________String_____________ */
/* ________MemberFunctions________ */

using string = std::string;

TEST(ArrayMemberFunctions, testArrayString1) {
  s21::array<string, 2> s21_array;
  std::array<string, 2> std_array;
  EXPECT_TRUE(s21_array.size() == std_array.size());
}

TEST(ArrayMemberFunctions, testArrayString2) {
  s21::array<string, 3> s21_array{"uwu", "uwu", "uwuu"};
  std::array<string, 3> std_array{"uwu", "uwu", "uwuu"};
  for (size_t i = 0; i < s21_array.size(); ++i)
    EXPECT_TRUE(s21_array[i] == std_array[i]);
}

TEST(ArrayMemberFunctions, testArrayString3) {
  s21::array<string, 3> s21_array = {"meow", "mur", "murrr"};
  std::array<string, 3> std_array = {"meow", "mur", "murrr"};
  for (size_t i = 0; i < s21_array.size(); ++i)
    EXPECT_TRUE(s21_array[i] == std_array[i]);
}

TEST(ArrayMemberFunctions, testArrayString4) {
  s21::array<string, 0> s21_array;
  std::array<string, 0> std_array;
  EXPECT_TRUE(s21_array.size() == std_array.size());
}

TEST(ArrayMemberFunctions, testArrayString5) {
  s21::array<string, 6> s21_array{"hello", "world", "and", "you"};
  std::array<string, 6> std_array{"hello", "world", "and", "you"};
  for (size_t i = 0; i < s21_array.size(); ++i)
    EXPECT_TRUE(s21_array[i] == std_array[i]);
}

TEST(ArrayMemberFunctions, testArrayString6) {
  s21::array<string, 6> s21_array_1{"hi", "hello"};
  s21::array<string, 6> s21_array_2(s21_array_1);
  for (size_t i = 0; i < s21_array_1.size(); ++i)
    EXPECT_TRUE(s21_array_1[i] == s21_array_2[i]);
}

TEST(ArrayMemberFunctions, testArrayString7) {
  s21::array<string, 2> s21_array_1{"Never gonna give you up",
                                    "Never gonna let you down"};
  s21::array<string, 2> s21_array_2{"Never gonna run around", "and desert you"};
  s21_array_1 = s21_array_2;
  for (size_t i = 0; i < s21_array_1.size(); ++i)
    EXPECT_TRUE(s21_array_1[i] == s21_array_2[i]);
}

TEST(ArrayMemberFunctions, testArrayString8) {
  s21::array<string, 4> s21_array_1{"But", "I\'m a creep", "I\'m a weirdo",
                                    "What the hell am I doing here?"};
  s21::array<string, 4> s21_array_2 = s21_array_1;
  for (size_t i = 0; i < s21_array_1.size(); ++i)
    EXPECT_TRUE(s21_array_1[i] == s21_array_2[i]);
}

/* ________ElementAccess________ */

TEST(ArrayElementAccess, testArrayString1) {
  s21::array<string, 4> s21_array{"Never gonna", "give you up", "Never gonna",
                                  "let you down"};
  std::array<string, 4> std_array{"Never gonna", "give you up", "Never gonna",
                                  "let you down"};
  EXPECT_TRUE(s21_array.at(0) == std_array.at(0));
  EXPECT_TRUE(s21_array.at(1) == std_array.at(1));
  EXPECT_TRUE(s21_array.at(2) == std_array.at(2));
  EXPECT_TRUE(s21_array.at(3) == std_array.at(3));
}

TEST(ArrayElementAccess, testArrayString2) {
  s21::array<string, 4> s21_array{"Never", "gonna"};
  std::array<string, 4> std_array{"Never", "gonna"};
  EXPECT_TRUE(s21_array.at(0) == std_array.at(0));
  EXPECT_TRUE(s21_array.at(1) == std_array.at(1));
  EXPECT_TRUE(s21_array.at(2) == std_array.at(2));
  EXPECT_TRUE(s21_array.at(3) == std_array.at(3));
}

TEST(ArrayElementAccess, testArrayString3) {
  s21::array<string, 6> s21_array{"Какой-то", "текст",          "для",
                                  "теста",    "замечательного", "проекта"};
  std::array<string, 6> std_array{"Какой-то", "текст",          "для",
                                  "теста",    "замечательного", "проекта"};
  EXPECT_TRUE(s21_array[0] == std_array[0]);
  EXPECT_TRUE(s21_array[1] == std_array[1]);
  EXPECT_TRUE(s21_array[2] == std_array[2]);
  EXPECT_TRUE(s21_array[3] == std_array[3]);
  EXPECT_TRUE(s21_array[4] == std_array[4]);
  EXPECT_TRUE(s21_array[5] == std_array[5]);
}

TEST(ArrayElementAccess, testArrayString4) {
  s21::array<string, 5> s21_array{"one", "two", "three", "four", "five"};
  std::array<string, 5> std_array{"one", "two", "three", "four", "five"};
  string s21 = s21_array.front();
  string std = std_array.front();
  EXPECT_TRUE(s21 == std);
}

TEST(ArrayElementAccess, testArrayString5) {
  s21::array<string, 6> s21_array{"one", "two", "three", "four", "five", "six"};
  std::array<string, 6> std_array{"one", "two", "three", "four", "five", "six"};
  string s21 = s21_array.back();
  string std = std_array.back();
  EXPECT_TRUE(s21 == std);
}

TEST(ArrayElementAccess, testArrayString6) {
  s21::array<string, 6> s21_array{"THE", "BEST", "TEST", "EVER"};
  std::array<string, 6> std_array{"THE", "BEST", "TEST", "EVER"};
  EXPECT_TRUE(s21_array[0] == std_array[0]);
  EXPECT_TRUE(s21_array[1] == std_array[1]);
  EXPECT_TRUE(s21_array[2] == std_array[2]);
  EXPECT_TRUE(s21_array[3] == std_array[3]);
  EXPECT_TRUE(s21_array[4] == std_array[4]);
  EXPECT_TRUE(s21_array[5] == std_array[5]);
}

// TEST(ArrayElementAccess, testArrayString7) {
//   s21::array<string, 6> s21_array{"Do", "you", "like", "cats?"};
//   EXPECT_ANY_THROW(s21_array.at(-1));
// }

// TEST(ArrayElementAccess, testArrayString8) {
//   s21::array<string, 6> s21_array{"i", "testing", "this", "project"};
//   EXPECT_ANY_THROW(s21_array.at(6));
// }

TEST(ArrayElementAccess, testArrayString9) {
  s21::array<string, 6> s21_array{"i", "learn", "c++", "and", "feel", "pain"};
  std::array<string, 6> std_array{"i", "learn", "c++", "and", "feel", "pain"};
  EXPECT_TRUE(*s21_array.data() == *std_array.data());
}

// /* _________Iterators_________ */

TEST(ArrayIterators, testArrayString1) {
  s21::array<string, 3> s21_array{"array", "iterators:", " begin"};
  std::array<string, 3> std_array{"array", "iterators:", " begin"};
  EXPECT_TRUE(*s21_array.begin() == *std_array.begin());
}

TEST(ArrayIterators, testArrayString2) {
  s21::array<string, 8> s21_array{"array", "iterators:", " end"};
  std::array<string, 8> std_array{"array", "iterators:", " end"};
  EXPECT_TRUE(*(s21_array.end() - 1) == *(std_array.end() - 1));
}

// /* _________Capacity_________ */

TEST(ArrayCapacity, testArrayString1) {
  s21::array<string, 0> s21_array;
  EXPECT_TRUE(s21_array.empty() == 1);
}

TEST(ArrayCapacity, testArrayString2) {
  s21::array<string, 1> s21_array;
  EXPECT_TRUE(s21_array.empty() == 0);
}

TEST(ArrayCapacity, testArrayString3) {
  s21::array<string, 3> s21_array{"array", "is not", "empty"};
  std::array<string, 6> std_array{"Loading...", "20%...", "30%...",
                                  "40%...",     "50%...", "100%..."};
  EXPECT_TRUE(s21_array.empty() == std_array.empty());
}

TEST(ArrayCapacity, testArrayString4) {
  s21::array<string, 8> s21_array{"When", "i", "was"};
  std::array<string, 8> std_array{"a", "young", "boy"};
  EXPECT_TRUE(s21_array.size() == std_array.size());
}

TEST(ArrayCapacity, testArrayString5) {
  s21::array<string, 8> s21_array{"My",  "father", "me", "into",
                                  "the", "city",   "to", "see"};
  std::array<string, 8> std_array{"a", "marching", "band"};
  EXPECT_TRUE(s21_array.size() == std_array.size());
}

TEST(ArrayCapacity, testArrayString6) {
  s21::array<string, 8> s21_array{"i", "learn", "c++", "and", "feel", "pain"};
  std::array<string, 8> std_array{"i", "feel", "pain...."};
  EXPECT_TRUE(s21_array.max_size() == std_array.max_size());
}

/* _________Modifiers_________ */

TEST(ArrayModifiers, testArrayString1) {
  s21::array<string, 3> s21_array_1{"lorem", "ipsum", " "};
  s21::array<string, 3> s21_array_2{"dolor", "sit", "amet"};
  std::array<string, 3> std_array_1{"lorem", "ipsum", " "};
  std::array<string, 3> std_array_2{"dolor", "sit", "amet"};
  s21_array_1.swap(s21_array_2);
  std_array_1.swap(std_array_2);
  for (size_t i = 0; i < s21_array_1.size(); ++i) {
    EXPECT_TRUE(s21_array_1[i] == std_array_1[i]);
    EXPECT_TRUE(s21_array_2[i] == std_array_2[i]);
  }
}

TEST(ArrayModifiers, testArrayString2) {
  s21::array<string, 3> s21_array{"c++", "is", "hard"};
  std::array<string, 3> std_array{"i", "dont", "understand"};
  std_array.fill("p2p");
  s21_array.fill("p2p");
  for (size_t i = 0; i < s21_array.size(); ++i)
    EXPECT_TRUE(s21_array[i] == std_array[i]);
}

TEST(ArrayModifiers, testArrayString3) {
  s21::array<string, 3> s21_array{"i want", "make you", "happy"};
  std::array<string, 3> std_array{"so that", "you", "always smile"};
  std_array.fill("have a good day");
  s21_array.fill("have a good day");
  EXPECT_TRUE(s21_array[0] == "have a good day");
  EXPECT_TRUE(std_array[0] == "have a good day");
  EXPECT_TRUE(s21_array[0] == std_array[0]);
  EXPECT_TRUE(s21_array[2] == std_array[2]);
}

/* _____________Bool_____________ */
/* ________MemberFunctions________ */

TEST(ArrayMemberFunctions, testArrayBool1) {
  s21::array<bool, 2> s21_array;
  std::array<bool, 2> std_array;
  EXPECT_TRUE(s21_array.size() == std_array.size());
}

TEST(ArrayMemberFunctions, testArrayBool2) {
  s21::array<bool, 3> s21_array{true, true, true};
  std::array<bool, 3> std_array{true, true, true};
  for (size_t i = 0; i < s21_array.size(); ++i)
    EXPECT_TRUE(s21_array[i] == std_array[i]);
}

TEST(ArrayMemberFunctions, testArrayBool3) {
  s21::array<bool, 3> s21_array = {false, false, false};
  std::array<bool, 3> std_array = {false, false, false};
  for (size_t i = 0; i < s21_array.size(); ++i)
    EXPECT_TRUE(s21_array[i] == std_array[i]);
}

TEST(ArrayMemberFunctions, testArrayBool4) {
  s21::array<bool, 0> s21_array;
  std::array<bool, 0> std_array;
  EXPECT_TRUE(s21_array.size() == std_array.size());
}

TEST(ArrayMemberFunctions, testArrayBool5) {
  s21::array<bool, 6> s21_array{0, 1, 0, 0};
  std::array<bool, 6> std_array{0, 1, 0, 0};
  for (size_t i = 0; i < s21_array.size(); ++i)
    EXPECT_TRUE(s21_array[i] == std_array[i]);
}

TEST(ArrayMemberFunctions, testArrayBool6) {
  s21::array<bool, 6> s21_array_1{1, 0};
  s21::array<bool, 6> s21_array_2(s21_array_1);
  for (size_t i = 0; i < s21_array_1.size(); ++i)
    EXPECT_TRUE(s21_array_1[i] == s21_array_2[i]);
}

TEST(ArrayMemberFunctions, testArrayBool7) {
  s21::array<bool, 2> s21_array_1{0, 0};
  s21::array<bool, 2> s21_array_2{1, 1};
  s21_array_1 = s21_array_2;
  for (size_t i = 0; i < s21_array_1.size(); ++i)
    EXPECT_TRUE(s21_array_1[i] == s21_array_2[i]);
}

TEST(ArrayMemberFunctions, testArrayBool8) {
  s21::array<bool, 4> s21_array_1{0, 1, 1, 0};
  s21::array<bool, 4> s21_array_2 = s21_array_1;
  for (size_t i = 0; i < s21_array_1.size(); ++i)
    EXPECT_TRUE(s21_array_1[i] == s21_array_2[i]);
}

// /* ________ElementAccess________ */

TEST(ArrayElementAccess, testArrayBool1) {
  s21::array<bool, 4> s21_array{0, 0, 1, 1};
  std::array<bool, 4> std_array{0, 0, 1, 1};
  EXPECT_TRUE(s21_array.at(0) == std_array.at(0));
  EXPECT_TRUE(s21_array.at(1) == std_array.at(1));
  EXPECT_TRUE(s21_array.at(2) == std_array.at(2));
  EXPECT_TRUE(s21_array.at(3) == std_array.at(3));
}

TEST(ArrayElementAccess, testArrayBool2) {
  s21::array<bool, 4> s21_array{0, 1, 0, 1};
  std::array<bool, 4> std_array{0, 1, 0, 1};
  EXPECT_TRUE(s21_array.at(0) == std_array.at(0));
  EXPECT_TRUE(s21_array.at(1) == std_array.at(1));
  EXPECT_TRUE(s21_array.at(2) == std_array.at(2));
  EXPECT_TRUE(s21_array.at(3) == std_array.at(3));
}

TEST(ArrayElementAccess, testArrayBool3) {
  s21::array<bool, 6> s21_array{1, 0, 0, 1, 0, 1};
  std::array<bool, 6> std_array{1, 0, 0, 1, 0, 1};
  EXPECT_TRUE(s21_array[0] == std_array[0]);
  EXPECT_TRUE(s21_array[1] == std_array[1]);
  EXPECT_TRUE(s21_array[2] == std_array[2]);
  EXPECT_TRUE(s21_array[3] == std_array[3]);
  EXPECT_TRUE(s21_array[4] == std_array[4]);
  EXPECT_TRUE(s21_array[5] == std_array[5]);
}

TEST(ArrayElementAccess, testArrayBool4) {
  s21::array<bool, 5> s21_array{1, 1, 1, 1, 0};
  std::array<bool, 5> std_array{1, 1, 1, 1, 0};
  bool s21 = s21_array.front();
  bool std = std_array.front();
  EXPECT_TRUE(s21 == std);
}

TEST(ArrayElementAccess, testArrayBool5) {
  s21::array<bool, 6> s21_array{0, 1, 1, 1, 1, 0};
  std::array<bool, 6> std_array{0, 1, 1, 1, 1, 0};
  bool s21 = s21_array.back();
  bool std = std_array.back();
  EXPECT_TRUE(s21 == std);
}

TEST(ArrayElementAccess, testArrayBool6) {
  s21::array<bool, 6> s21_array{0, 1, 0, 1};
  std::array<bool, 6> std_array{0, 1, 0, 1};
  EXPECT_TRUE(s21_array[0] == std_array[0]);
  EXPECT_TRUE(s21_array[1] == std_array[1]);
  EXPECT_TRUE(s21_array[2] == std_array[2]);
  EXPECT_TRUE(s21_array[3] == std_array[3]);
  EXPECT_TRUE(s21_array[4] == std_array[4]);
  EXPECT_TRUE(s21_array[5] == std_array[5]);
}

// TEST(ArrayElementAccess, testArrayBool7) {
//   s21::array<bool, 6> s21_array{0, 0, 1};
//   EXPECT_ANY_THROW(s21_array.at(-1));
// }

// TEST(ArrayElementAccess, testArrayBool8) {
//   s21::array<bool, 6> s21_array{1, 0, 1};
//   EXPECT_ANY_THROW(s21_array.at(6));
// }

TEST(ArrayElementAccess, testArrayBool9) {
  s21::array<bool, 6> s21_array{1, 0, 0, 1, 1, 0};
  std::array<bool, 6> std_array{1, 0, 0, 1, 1, 0};
  EXPECT_TRUE(*s21_array.data() == *std_array.data());
}

/* _________Iterators_________ */

TEST(ArrayIterators, testArrayBool1) {
  s21::array<bool, 6> s21_array{1, 0, 0, 1, 1, 0};
  std::array<bool, 6> std_array{1, 0, 0, 1, 1, 0};
  EXPECT_TRUE(*s21_array.begin() == *std_array.begin());
}

TEST(ArrayIterators, testArrayBool2) {
  s21::array<bool, 6> s21_array{1, 0, 0, 1, 0, 1};
  std::array<bool, 6> std_array{1, 0, 0, 1, 0, 1};
  EXPECT_TRUE(*(s21_array.end() - 1) == *(std_array.end() - 1));
}

/* _________Capacity_________ */

TEST(ArrayCapacity, testArrayBool1) {
  s21::array<bool, 0> s21_array;
  EXPECT_TRUE(s21_array.empty() == 1);
}

TEST(ArrayCapacity, testArrayBool2) {
  s21::array<bool, 1> s21_array;
  EXPECT_TRUE(s21_array.empty() == 0);
}

TEST(ArrayCapacity, testArrayBool3) {
  s21::array<bool, 3> s21_array{1, 1, 1};
  std::array<bool, 6> std_array{1, 1, 1, 0, 0, 0};
  EXPECT_TRUE(s21_array.empty() == std_array.empty());
}

TEST(ArrayCapacity, testArrayBool4) {
  s21::array<bool, 8> s21_array{1, 1, 0};
  std::array<bool, 8> std_array{1, 1, 0};
  EXPECT_TRUE(s21_array.size() == std_array.size());
}

TEST(ArrayCapacity, testArrayBool5) {
  s21::array<bool, 8> s21_array{1, 0, 1, 0, 0, 1};
  std::array<bool, 8> std_array{1, 0, 1};
  EXPECT_TRUE(s21_array.size() == std_array.size());
}

TEST(ArrayCapacity, testArrayBool6) {
  s21::array<bool, 8> s21_array{1, 0, 0, 1, 0, 1};
  std::array<bool, 8> std_array{1, 1, 0};
  EXPECT_TRUE(s21_array.max_size() == std_array.max_size());
}

/* _________Modifiers_________ */

TEST(ArrayModifiers, testArrayBool1) {
  s21::array<bool, 3> s21_array_1{1, 0, 0};
  s21::array<bool, 3> s21_array_2{0, 1, 1};
  std::array<bool, 3> std_array_1{1, 0, 0};
  std::array<bool, 3> std_array_2{0, 1, 1};
  s21_array_1.swap(s21_array_2);
  std_array_1.swap(std_array_2);
  for (size_t i = 0; i < s21_array_1.size(); ++i)
    EXPECT_TRUE(s21_array_1[i] == std_array_1[i]);
}

TEST(ArrayModifiers, testArrayBool2) {
  s21::array<bool, 3> s21_array{1, 1, 1};
  std::array<bool, 3> std_array{1, 1, 1};
  std_array.fill(0);
  s21_array.fill(0);
  for (size_t i = 0; i < s21_array.size(); ++i)
    EXPECT_TRUE(s21_array[i] == std_array[i]);
}

TEST(ArrayModifiers, testArrayBool3) {
  s21::array<bool, 3> s21_array{1, 0, 1};
  std::array<bool, 3> std_array{0, 0, 0};
  std_array.fill(1);
  s21_array.fill(1);
  EXPECT_TRUE(s21_array[0] == 1);
  EXPECT_TRUE(std_array[0] == 1);
  EXPECT_TRUE(s21_array[0] == std_array[0]);
}