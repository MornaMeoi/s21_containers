#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "../s21_containers.h"

// TEST(MemberFunctions, test_vector_int) {
//   std::initializer_list<std::pair<s21::rbt<std::pair<const int,
//   double>>::iterator,bool>> test =
//   {{nullptr,true},{nullptr,true},{nullptr,true}};
//   s21::vector<std::pair<s21::rbt<std::pair<const int,
//   double>>::iterator,bool>> s21_vector;
//   std::vector<std::pair<s21::rbt<std::pair<const int,
//   double>>::iterator,bool>> std_vector; for(auto iter = test.begin(); iter !=
//   test.end(); ++iter)
//   {
//     s21_vector.push_back(*iter);
//     std_vector.push_back(*iter);
//   }
//   EXPECT_TRUE(s21_vector[1] == std_vector[1]);
//   EXPECT_TRUE(s21_vector.size() == std_vector.size());
//   EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
// }
// int
//------------------------------------------------------------- MemberFunctions

TEST(MemberFunctions, test_vector_int_1) {
  s21::vector<int> s21_vector;
  std::vector<int> std_vector;
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

// TEST(MemberFunctions, test_vector_int_2) {
//   EXPECT_ANY_THROW({ s21::vector<int> s21_vector(-1); });
// }

TEST(MemberFunctions, test_vector_int_3) {
  EXPECT_NO_THROW({ s21::vector<int> s21_vector; });
}

TEST(MemberFunctions, test_vector_int_4) {
  EXPECT_NO_THROW({ s21::vector<int> s21_vector(13); });
}

TEST(MemberFunctions, test_vector_int_4_1) {
  s21::vector<int> s21_vector(13);
  std::vector<int> std_vector(13);
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(MemberFunctions, test_vector_int_4_2) {
  s21::vector<int> s21_vector(130);
  std::vector<int> std_vector(130);
  for (size_t i = 0; i < s21_vector.size(); ++i) {
    EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }
}

TEST(MemberFunctions, test_vector_int_5) {
  EXPECT_NO_THROW(
      { s21::vector<int> s21_vector({0, 1, 2, 3, 4, 5, 6, 7, 8, 9}); });
}

TEST(MemberFunctions, test_vector_int_6) {
  s21::vector<int> s21_vector_1({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
  s21::vector<int> s21_vector_2(s21_vector_1);
  for (size_t i = 0; i < s21_vector_1.size(); ++i) {
    EXPECT_TRUE(s21_vector_1[i] == s21_vector_2[i]);
  }
}

TEST(MemberFunctions, test_vector_int_7) {
  s21::vector<int> s21_vector_1({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
  s21::vector<int> s21_vector_2 = s21_vector_1;
  for (size_t i = 0; i < s21_vector_1.size(); ++i) {
    EXPECT_TRUE(s21_vector_1[i] == s21_vector_2[i]);
  }
}

TEST(MemberFunctions, test_vector_int_8) {
  s21::vector<int> s21_vector_1({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
  s21::vector<int> s21_vector_2;
  s21_vector_2 = std::move(s21_vector_1);
  for (size_t i = 0; i < s21_vector_1.size(); ++i) {
    EXPECT_TRUE(s21_vector_1[i] == s21_vector_2[i]);
  }
}

TEST(MemberFunctions, test_vector_int_9) {
  s21::vector<int> s21_vector_1({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
  int *p = s21_vector_1.data();
  s21::vector<int> s21_vector_2(std::move(s21_vector_1));

  // for(size_t i = 0; i < s21_vector_1.size() ; ++i) {
  // EXPECT_TRUE(s21_vector_1[i] == s21_vector_4[i]);
  // }
  EXPECT_TRUE(p == s21_vector_2.data());
}

//------------------------------------------------------------- ElementAccess

TEST(ElementAaccess, test_vector_int_1) {
  s21::vector<int> s21_vector({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
  std::vector<int> std_vector({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
  EXPECT_TRUE(s21_vector.at(5) == std_vector.at(5));
}

// TEST(ElementAaccess, test_vector_int_2) {
//   EXPECT_ANY_THROW({
//     s21::vector<int> s21_vector({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
//     s21_vector.at(100);
//   });
// }

// TEST(ElementAaccess, test_vector_int_3) {
//   EXPECT_ANY_THROW({
//     s21::vector<int> s21_vector({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
//     s21_vector.at(-10);
//   });
// }

TEST(ElementAaccess, test_vector_int_4) {
  s21::vector<int> s21_vector({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
  std::vector<int> std_vector({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
  EXPECT_TRUE(*s21_vector.data() == *std_vector.data());
}

TEST(ElementAaccess, test_vector_int_5) {
  s21::vector<int> s21_vector({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
  std::vector<int> std_vector({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
  EXPECT_TRUE(s21_vector[5] == std_vector[5]);
}

TEST(ElementAaccess, test_vector_int_6) {
  s21::vector<int> s21_vector({88, 1, 2, 3, 4, 5, 6, 7, 8, 9});
  std::vector<int> std_vector({88, 1, 2, 3, 4, 5, 6, 7, 8, 9});
  int my = s21_vector.front();
  int std = std_vector.front();
  EXPECT_TRUE(my == std);
}

TEST(ElementAaccess, test_vector_int_7) {
  s21::vector<int> s21_vector({88, 1, 2, 3, 4, 5, 6, 7, 8, 99});
  std::vector<int> std_vector({88, 1, 2, 3, 4, 5, 6, 7, 8, 99});
  int my = s21_vector.back();
  int std = std_vector.back();
  EXPECT_TRUE(my == std);
}

//------------------------------------------------------------- Iterators

TEST(Iterators, test_vector_int_1) {
  s21::vector<int> s21_vector({88, 1, 2, 3, 4, 5, 6, 7, 8, 99});
  std::vector<int> std_vector({88, 1, 2, 3, 4, 5, 6, 7, 8, 99});
  EXPECT_TRUE(*s21_vector.begin() == *std_vector.begin());
}

TEST(Iterators, test_vector_int_2) {
  s21::vector<int> s21_vector({88, 1, 2, 3, 4, 5, 6, 7, 8, 99});
  std::vector<int> std_vector({88, 1, 2, 3, 4, 5, 6, 7, 8, 99});
  EXPECT_TRUE(*(s21_vector.end() - 1) == *(std_vector.end() - 1));
}

//------------------------------------------------------------- revIterators

TEST(revIterators, test_vector_int_1) {
  s21::vector<int> s21_vector({88, 1, 2, 3, 4, 5, 6, 7, 8, 99});
  std::vector<int> std_vector({88, 1, 2, 3, 4, 5, 6, 7, 8, 99});
  EXPECT_TRUE(*s21_vector.rbegin() == *std_vector.rbegin());
}

TEST(revIterators, test_vector_int_2) {
  s21::vector<int> s21_vector({88, 1, 2, 3, 4, 5, 6, 7, 8, 99});
  std::vector<int> std_vector({88, 1, 2, 3, 4, 5, 6, 7, 8, 99});
  EXPECT_TRUE(*(s21_vector.rend() - 1) == *(std_vector.rend() - 1));
}

//------------------------------------------------------------- Capacity

TEST(Capacity, test_vector_int_3) {
  s21::vector<int> s21_vector({88, 1, 2, 3, 4, 5, 6, 7, 8, 99});
  std::vector<int> std_vector({88, 1, 2, 3, 4, 5, 6, 7, 8, 99});
  EXPECT_TRUE(s21_vector.empty() == std_vector.empty());
}

TEST(Capacity, test_vector_int_4) {
  s21::vector<int> s21_vector;
  std::vector<int> std_vector;
  EXPECT_TRUE(s21_vector.empty() == std_vector.empty());
}

TEST(Capacity, test_vector_int_5) {
  s21::vector<int> s21_vector({88, 1, 2, 3, 4, 5, 6, 7, 8, 99});
  std::vector<int> std_vector({88, 1, 2, 3, 4, 5, 6, 7, 8, 99});
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
}

TEST(Capacity, test_vector_int_6) {
  s21::vector<int> s21_vector({88, 1, 2, 3, 4, 5, 6, 7, 8, 99});
  std::vector<int> std_vector({88, 1, 2, 3, 4, 5, 6, 7, 8, 99});
  EXPECT_TRUE(s21_vector.max_size() == std_vector.max_size());
}

TEST(Capacity, test_vector_int_7) {
  s21::vector<int> s21_vector({88, 1, 2, 3, 4, 5, 6, 7, 8, 99});
  std::vector<int> std_vector({88, 1, 2, 3, 4, 5, 6, 7, 8, 99});
  //   std::cout << "s21_vector.size = " << s21_vector.size() << std::endl;
  // std::cout << "std_vector.size = " << std_vector.size() << std::endl;
  // std::cout << "s21_vector.capacity = " << s21_vector.capacity() <<
  // std::endl; std::cout << "std_vector.capacity = " << std_vector.capacity()
  // << std::endl;

  s21_vector.reserve(s21_vector.size() + s21_vector.capacity());
  std_vector.reserve(std_vector.size() + std_vector.capacity());
  //   std::cout << "s21_vector.size = " << s21_vector.size() << std::endl;
  // std::cout << "std_vector.size = " << std_vector.size() << std::endl;
  // std::cout << "s21_vector.capacity = " << s21_vector.capacity() <<
  // std::endl; std::cout << "std_vector.capacity = " << std_vector.capacity()
  // << std::endl;

  EXPECT_TRUE(s21_vector.size() == std_vector.size());
}

TEST(Capacity, test_vector_int_7_1) {
  s21::vector<int> s21_vector({88, 1, 2, 3, 4, 5, 6, 7, 8, 99});
  std::vector<int> std_vector({88, 1, 2, 3, 4, 5, 6, 7, 8, 99});
  s21_vector.reserve(s21_vector.size() / 2);
  std_vector.reserve(std_vector.size() / 2);
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
}

// TEST(Capacity, test_vector_int_7_2) {
//   s21::vector<int> s21_vector({88, 1, 2, 3, 4, 5, 6, 7, 8, 99});
//   std::vector<int> std_vector({88, 1, 2, 3, 4, 5, 6, 7, 8, 99});
//   EXPECT_ANY_THROW({ s21::vector<int> s21_vector(-1); });
//   EXPECT_ANY_THROW({ std::vector<int> std_vector(-1); });
// }

TEST(Capacity, test_vector_int_8) {
  s21::vector<int> s21_vector({88, 1, 2, 3, 4, 5, 6, 7, 8, 99});
  std::vector<int> std_vector({88, 1, 2, 3, 4, 5, 6, 7, 8, 99});
  s21_vector.reserve(s21_vector.size() + s21_vector.capacity());
  std_vector.reserve(std_vector.size() + std_vector.capacity());
  s21_vector.insert(s21_vector.begin() + 3, 13);
  std_vector.insert(std_vector.begin() + 3, 13);
  s21_vector.shrink_to_fit();
  std_vector.shrink_to_fit();
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Capacity, test_vector_int_9) {
  s21::vector<int> s21_vector({88, 1, 2, 3, 4, 5, 6, 7, 8, 99});
  std::vector<int> std_vector({88, 1, 2, 3, 4, 5, 6, 7, 8, 99});
  s21_vector.reserve(s21_vector.size() + s21_vector.capacity());
  std_vector.reserve(std_vector.size() + std_vector.capacity());
  s21_vector.insert(s21_vector.begin() + 14, 13);
  std_vector.insert(std_vector.begin() + 13, 13);
  s21_vector.shrink_to_fit();
  std_vector.shrink_to_fit();
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Capacity, test_vector_int_10) {
  s21::vector<int> s21_vector({88, 1, 2, 3, 4, 5, 6, 7, 8, 99});
  std::vector<int> std_vector({88, 1, 2, 3, 4, 5, 6, 7, 8, 99});
  s21_vector.resize(s21_vector.size() + s21_vector.capacity());
  std_vector.resize(std_vector.size() + std_vector.capacity());
  for (size_t i = 0; i < s21_vector.size(); ++i) {
    EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
}

TEST(Capacity, test_vector_int_11) {
  s21::vector<int> s21_vector({88, 1, 2, 3, 4, 5, 6, 7, 8, 99});
  std::vector<int> std_vector({88, 1, 2, 3, 4, 5, 6, 7, 8, 99});
  s21_vector.resize(s21_vector.size() / 2);
  std_vector.resize(std_vector.size() / 2);
  for (size_t i = 0; i < s21_vector.size(); ++i) {
    EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
}

//--------------------------------------------------- Vector Modifiers

TEST(Modifiers, test_vector_int_0) {
  s21::vector<int> s21_vector({88, 1, 2, 3, 4, 5, 6, 7, 8, 99});
  std::vector<int> std_vector({88, 1, 2, 3, 4, 5, 6, 7, 8, 99});
  s21_vector.reserve(s21_vector.size() + s21_vector.capacity());
  std_vector.reserve(std_vector.size() + std_vector.capacity());
  s21_vector.insert(s21_vector.begin() + 3, 13);
  s21_vector.shrink_to_fit();
  std_vector.shrink_to_fit();
  EXPECT_TRUE(s21_vector.capacity() != std_vector.capacity());
}

TEST(Modifiers, test_vector_int_0_0) {
  s21::vector<int> s21_vector({88, 1, 2, 3, 4, 5, 6, 7, 8, 99});
  std::vector<int> std_vector({88, 1, 2, 3, 4, 5, 6, 7, 8, 99});
  s21_vector.insert(s21_vector.begin() + 3, 4, 13);
  std_vector.insert(std_vector.begin() + 3, 4, 13);
  for (size_t i = 0; i < std_vector.size(); ++i) {
    EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Modifiers, test_vector_int_0_1) {
  s21::vector<int> s21_vector({88, 1, 2, 3, 4, 5, 6, 7, 8, 99});
  std::vector<int> std_vector({88, 1, 2, 3, 4, 5, 6, 7, 8, 99});
  // size_t len = s21_vector.size();
  s21_vector.clear();
  std_vector.clear();
  //  for(size_t i = 0; i < len; i ++) {
  //   EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  // }
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
  EXPECT_TRUE(*s21_vector.end() == *std_vector.end());
}

TEST(Modifiers, test_vector_int_1) {
  s21::vector<int> s21_vector({88, 1, 2, 3, 4, 5, 6, 7, 8, 99});
  std::vector<int> std_vector({88, 1, 2, 3, 4, 5, 6, 7, 8, 99});
  s21_vector.erase(s21_vector.begin() + 3);
  std_vector.erase(std_vector.begin() + 3);
  for (size_t i = 0; i < std_vector.capacity(); i++) {
    EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Modifiers, test_vector_int_2) {
  s21::vector<int> s21_vector({88, 1, 2, 3, 4, 5, 6, 7, 8, 99});
  std::vector<int> std_vector({88, 1, 2, 3, 4, 5, 6, 7, 8, 99});
  s21_vector.erase(s21_vector.begin() + 3);
  std_vector.erase(std_vector.begin() + 5);
  for (size_t i = 0; i < s21_vector.size(); i++) {
    if (i == 3 || i == 4)
      EXPECT_TRUE(s21_vector[i] != std_vector[i]);
    else
      EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }

  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Modifiers, test_vector_int_2_1) {
  s21::vector<int> s21_vector({88, 1, 2, 3, 4, 5, 6, 7, 8, 99});
  std::vector<int> std_vector({88, 1, 2, 3, 4, 5, 6, 7, 8, 99});
  s21_vector.erase(s21_vector.begin() + 3, s21_vector.begin() + 8);
  std_vector.erase(std_vector.begin() + 3, std_vector.begin() + 8);
  for (size_t i = 0; i < std_vector.capacity(); i++) {
    // std::cout << s21_vector[i] << " =|= " << std_vector[i]<< std::endl;
    EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Modifiers, test_vector_int_3) {
  s21::vector<int> s21_vector({88, 1, 2, 3, 4, 5, 6, 7, 8, 99});
  std::vector<int> std_vector({88, 1, 2, 3, 4, 5, 6, 7, 8, 99});
  std_vector.erase(std_vector.begin());

  for (size_t i = 0; i < s21_vector.capacity() - 1; i++) {
    EXPECT_TRUE(s21_vector[i] != std_vector[i]);
  }

  EXPECT_TRUE(s21_vector.size() != std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Modifiers, test_vector_int_4) {
  s21::vector<int> s21_vector({88, 1, 2, 3, 4, 5, 6, 7, 8, 99});
  std::vector<int> std_vector({88, 1, 2, 3, 4, 5, 6, 7, 8, 99});
  s21_vector.push_back(66);
  std_vector.push_back(66);
  for (size_t i = 0; i < s21_vector.capacity(); i++) {
    EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }

  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Modifiers, test_vector_int_5) {
  s21::vector<int> s21_vector({88, 1, 2, 3, 4, 5, 6, 7, 8, 99});
  std::vector<int> std_vector({88, 1, 2, 3, 4, 5, 6, 7, 8, 99});

  s21_vector.pop_back();
  std_vector.pop_back();

  for (size_t i = 0; i < s21_vector.size(); i++) {
    EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }

  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Modifiers, test_vector_int_6) {
  s21::vector<int> s21_vector_1({1, 1, 1, 1, 1, 1, 1, 1, 1, 1});
  s21::vector<int> s21_vector_2({3, 3, 3, 3, 3, 3, 3, 3, 3, 3});
  s21::vector<int> s21_vector_tmp_1(s21_vector_1);
  s21::vector<int> s21_vector_tmp_2(s21_vector_2);

  std::vector<int> std_vector_1({1, 1, 1, 1, 1, 1, 1, 1, 1, 1});
  std::vector<int> std_vector_2({3, 3, 3, 3, 3, 3, 3, 3, 3, 3});
  std::vector<int> std_vector_tmp_1(std_vector_1);
  std::vector<int> std_vector_tmp_2(std_vector_2);

  s21_vector_1.swap(s21_vector_2);
  std_vector_1.swap(std_vector_2);

  for (size_t i = 0; i < s21_vector_1.size(); i++) {
    EXPECT_TRUE(s21_vector_1[i] == s21_vector_tmp_2[i]);
    EXPECT_TRUE(s21_vector_2[i] == s21_vector_tmp_1[i]);
  }

  for (size_t i = 0; i < std_vector_1.size(); i++) {
    EXPECT_TRUE(std_vector_1[i] == std_vector_tmp_2[i]);
    EXPECT_TRUE(std_vector_2[i] == std_vector_tmp_1[i]);
  }

  EXPECT_TRUE(s21_vector_1.size() == std_vector_1.size());
  EXPECT_TRUE(s21_vector_1.capacity() == std_vector_2.capacity());
}

TEST(Modifiers, test_vector_int_7) {
  s21::vector<int> s21_vector_1({1, 1, 1, 1, 1});
  s21::vector<int> s21_vector_2({3, 3, 3, 3, 3, 3, 3, 3, 3, 3});
  s21::vector<int> s21_vector_tmp_1(s21_vector_1);
  s21::vector<int> s21_vector_tmp_2(s21_vector_2);

  std::vector<int> std_vector_1({1, 1, 1, 1, 1});
  std::vector<int> std_vector_2({3, 3, 3, 3, 3, 3, 3, 3, 3, 3});
  std::vector<int> std_vector_tmp_1(std_vector_1);
  std::vector<int> std_vector_tmp_2(std_vector_2);

  s21_vector_1.swap(s21_vector_2);
  std_vector_1.swap(std_vector_2);

  for (size_t i = 0; i < s21_vector_1.size(); i++) {
    EXPECT_TRUE(s21_vector_1[i] == s21_vector_tmp_2[i]);
    EXPECT_TRUE(std_vector_1[i] == std_vector_tmp_2[i]);
  }

  for (size_t i = 0; i < s21_vector_2.size(); i++) {
    EXPECT_TRUE(s21_vector_2[i] == s21_vector_tmp_1[i]);
    EXPECT_TRUE(std_vector_2[i] == std_vector_tmp_1[i]);
  }

  EXPECT_TRUE(std_vector_1.size() == std_vector_tmp_2.size());
  EXPECT_TRUE(std_vector_2.size() == std_vector_tmp_1.size());

  EXPECT_TRUE(s21_vector_1.size() == s21_vector_tmp_2.size());
  EXPECT_TRUE(s21_vector_2.size() == s21_vector_tmp_1.size());

  EXPECT_TRUE(s21_vector_1.capacity() == std_vector_1.capacity());
  EXPECT_TRUE(s21_vector_2.capacity() == std_vector_2.capacity());
}

//-------------------------------------------------------------

// float
//------------------------------------------------------------- MemberFunctions

TEST(MemberFunctions, test_vector_float_1) {
  s21::vector<float> s21_vector;
  std::vector<float> std_vector;
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

// TEST(MemberFunctions, test_vector_float_2) {
//   EXPECT_ANY_THROW({ s21::vector<float> s21_vector(-1); });
// }

TEST(MemberFunctions, test_vector_float_3) {
  EXPECT_NO_THROW({ s21::vector<float> s21_vector; });
}

TEST(MemberFunctions, test_vector_float_4) {
  EXPECT_NO_THROW({ s21::vector<float> s21_vector(13); });
}

TEST(MemberFunctions, test_vector_float_4_1) {
  s21::vector<float> s21_vector(13);
  std::vector<float> std_vector(13);
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(MemberFunctions, test_vector_float_4_2) {
  s21::vector<float> s21_vector(130);
  std::vector<float> std_vector(130);
  for (size_t i = 0; i < s21_vector.size(); ++i) {
    EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }
}

TEST(MemberFunctions, test_vector_float_5) {
  EXPECT_NO_THROW({
    s21::vector<float> s21_vector(
        {0.1, 1.1, 2.1, 3.1, 4.1, 5.1, 6.1, 7.1, 8.1, 9.1});
  });
}

TEST(MemberFunctions, test_vector_float_6) {
  s21::vector<float> s21_vector_1(
      {0.1, 1.1, 2.1, 3.1, 4.1, 5.1, 6.1, 7.1, 8.1, 9.1});
  s21::vector<float> s21_vector_2(s21_vector_1);
  for (size_t i = 0; i < s21_vector_1.size(); ++i) {
    EXPECT_TRUE(s21_vector_1[i] == s21_vector_2[i]);
  }
}

TEST(MemberFunctions, test_vector_float_7) {
  s21::vector<float> s21_vector_1(
      {0.1, 1.1, 2.1, 3.1, 4.1, 5.1, 6.1, 7.1, 8.1, 9.1});
  s21::vector<float> s21_vector_2 = s21_vector_1;
  for (size_t i = 0; i < s21_vector_1.size(); ++i) {
    EXPECT_TRUE(s21_vector_1[i] == s21_vector_2[i]);
  }
}

TEST(MemberFunctions, test_vector_float_8) {
  s21::vector<float> s21_vector_1(
      {0.1, 1.1, 2.1, 3.1, 4.1, 5.1, 6.1, 7.1, 8.1, 9.1});
  s21::vector<float> s21_vector_2;
  s21_vector_2 = std::move(s21_vector_1);
  for (size_t i = 0; i < s21_vector_1.size(); ++i) {
    EXPECT_TRUE(s21_vector_1[i] == s21_vector_2[i]);
  }
}

TEST(MemberFunctions, test_vector_float_9) {
  s21::vector<float> s21_vector_1(
      {0.1, 1.1, 2.1, 3.1, 4.1, 5.1, 6.1, 7.1, 8.1, 9.1});
  float *p = s21_vector_1.data();
  s21::vector<float> s21_vector_2(std::move(s21_vector_1));

  EXPECT_TRUE(p == s21_vector_2.data());
}

//------------------------------------------------------------- ElementAccess

TEST(ElementAaccess, test_vector_float_1) {
  s21::vector<float> s21_vector(
      {0.1, 1.1, 2.1, 3.1, 4.1, 5.1, 6.1, 7.1, 8.1, 9.1});
  std::vector<float> std_vector(
      {0.1, 1.1, 2.1, 3.1, 4.1, 5.1, 6.1, 7.1, 8.1, 9.1});
  EXPECT_TRUE(s21_vector.at(5) == std_vector.at(5));
}

// TEST(ElementAaccess, test_vector_float_2) {
//   EXPECT_ANY_THROW({
//     s21::vector<float> s21_vector(
//         {0.1, 1.1, 2.1, 3.1, 4.1, 5.1, 6.1, 7.1, 8.1, 9.1});
//     s21_vector.at(100);
//   });
// }

// TEST(ElementAaccess, test_vector_float_3) {
//   EXPECT_ANY_THROW({
//     s21::vector<float> s21_vector(
//         {0.1, 1.1, 2.1, 3.1, 4.1, 5.1, 6.1, 7.1, 8.1, 9.1});
//     s21_vector.at(-10);
//   });
// }

TEST(ElementAaccess, test_vector_float_4) {
  s21::vector<float> s21_vector(
      {0.1, 1.1, 2.1, 3.1, 4.1, 5.1, 6.1, 7.1, 8.1, 9.1});
  std::vector<float> std_vector(
      {0.1, 1.1, 2.1, 3.1, 4.1, 5.1, 6.1, 7.1, 8.1, 9.1});
  EXPECT_TRUE(*s21_vector.data() == *std_vector.data());
}

TEST(ElementAaccess, test_vector_float_5) {
  s21::vector<float> s21_vector(
      {0.1, 1.1, 2.1, 3.1, 4.1, 5.1, 6.1, 7.1, 8.1, 9.1});
  std::vector<float> std_vector(
      {0.1, 1.1, 2.1, 3.1, 4.1, 5.1, 6.1, 7.1, 8.1, 9.1});
  EXPECT_TRUE(s21_vector[5] == std_vector[5]);
}

TEST(ElementAaccess, test_vector_float_6) {
  s21::vector<float> s21_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.9});
  std::vector<float> std_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.9});
  float my = s21_vector.front();
  float std = std_vector.front();
  EXPECT_TRUE(my == std);
}

TEST(ElementAaccess, test_vector_float_7) {
  s21::vector<float> s21_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  std::vector<float> std_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  float my = s21_vector.back();
  float std = std_vector.back();
  EXPECT_TRUE(my == std);
}

//------------------------------------------------------------- Iterators

TEST(Iterators, test_vector_float_1) {
  s21::vector<float> s21_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  std::vector<float> std_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  EXPECT_TRUE(*s21_vector.begin() == *std_vector.begin());
}

TEST(Iterators, test_vector_float_2) {
  s21::vector<float> s21_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  std::vector<float> std_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  EXPECT_TRUE(*(s21_vector.end() - 1) == *(std_vector.end() - 1));
}

//------------------------------------------------------------- revIterators

TEST(revIterators, test_vector_float_1) {
  s21::vector<float> s21_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  std::vector<float> std_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  EXPECT_TRUE(*s21_vector.rbegin() == *std_vector.rbegin());
}

TEST(revIterators, test_vector_float_2) {
  s21::vector<float> s21_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  std::vector<float> std_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  EXPECT_TRUE(*(s21_vector.rend() - 1) == *(std_vector.rend() - 1));
}

//------------------------------------------------------------- Capacity

TEST(Capacity, test_vector_float_3) {
  s21::vector<float> s21_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  std::vector<float> std_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  EXPECT_TRUE(s21_vector.empty() == std_vector.empty());
}

TEST(Capacity, test_vector_float_4) {
  s21::vector<float> s21_vector;
  std::vector<float> std_vector;
  EXPECT_TRUE(s21_vector.empty() == std_vector.empty());
}

TEST(Capacity, test_vector_float_5) {
  s21::vector<float> s21_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  std::vector<float> std_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
}

TEST(Capacity, test_vector_float_6) {
  s21::vector<float> s21_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  std::vector<float> std_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  EXPECT_TRUE(s21_vector.max_size() == std_vector.max_size());
}

TEST(Capacity, test_vector_float_7) {
  s21::vector<float> s21_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  std::vector<float> std_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  s21_vector.reserve(s21_vector.size() + s21_vector.capacity());
  std_vector.reserve(std_vector.size() + std_vector.capacity());
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
}

TEST(Capacity, test_vector_float_7_1) {
  s21::vector<float> s21_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  std::vector<float> std_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  s21_vector.reserve(s21_vector.size() / 2);
  std_vector.reserve(std_vector.size() / 2);
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
}

// TEST(Capacity, test_vector_float_7_2) {
//   s21::vector<float> s21_vector(
//       {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
//   std::vector<float> std_vector(
//       {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
//   EXPECT_ANY_THROW({ s21::vector<float> s21_vector(-1); });
//   EXPECT_ANY_THROW({ std::vector<float> std_vector(-1); });
// }

TEST(Capacity, test_vector_float_8) {
  s21::vector<float> s21_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  std::vector<float> std_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  s21_vector.reserve(s21_vector.size() + s21_vector.capacity());
  std_vector.reserve(std_vector.size() + std_vector.capacity());
  s21_vector.insert(s21_vector.begin() + 3, 13);
  std_vector.insert(std_vector.begin() + 3, 13);
  s21_vector.shrink_to_fit();
  std_vector.shrink_to_fit();
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Capacity, test_vector_float_9) {
  s21::vector<float> s21_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  std::vector<float> std_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  s21_vector.reserve(s21_vector.size() + s21_vector.capacity());
  std_vector.reserve(std_vector.size() + std_vector.capacity());
  s21_vector.insert(s21_vector.begin() + 14, 13);
  std_vector.insert(std_vector.begin() + 13, 13);
  s21_vector.shrink_to_fit();
  std_vector.shrink_to_fit();
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Capacity, test_vector_float_10) {
  s21::vector<float> s21_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  std::vector<float> std_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  s21_vector.resize(s21_vector.size() + s21_vector.capacity());
  std_vector.resize(std_vector.size() + std_vector.capacity());
  for (size_t i = 0; i < s21_vector.size(); ++i) {
    EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
}

TEST(Capacity, test_vector_float_11) {
  s21::vector<float> s21_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  std::vector<float> std_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  s21_vector.resize(s21_vector.size() / 2);
  std_vector.resize(std_vector.size() / 2);
  for (size_t i = 0; i < s21_vector.size(); ++i) {
    EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
}
//--------------------------------------------------- Vector Modifiers

TEST(Modifiers, test_vector_float_0) {
  s21::vector<float> s21_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  std::vector<float> std_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  s21_vector.reserve(s21_vector.size() + s21_vector.capacity());
  std_vector.reserve(std_vector.size() + std_vector.capacity());
  s21_vector.insert(s21_vector.begin() + 3, 13);
  s21_vector.shrink_to_fit();
  std_vector.shrink_to_fit();
  EXPECT_TRUE(s21_vector.capacity() != std_vector.capacity());
}

TEST(Modifiers, test_vector_float_0_0) {
  s21::vector<float> s21_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  std::vector<float> std_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  s21_vector.insert(s21_vector.begin() + 3, 4, 13);
  std_vector.insert(std_vector.begin() + 3, 4, 13);
  for (size_t i = 0; i < std_vector.size(); ++i) {
    EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Modifiers, test_vector_float_0_1) {
  s21::vector<float> s21_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  std::vector<float> std_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  // size_t len = s21_vector.size();
  s21_vector.clear();
  std_vector.clear();
  //  for(size_t i = 0; i < len; i ++) {
  //   EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  // }
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
  EXPECT_TRUE(*s21_vector.end() == *std_vector.end());
}

TEST(Modifiers, test_vector_float_1) {
  s21::vector<float> s21_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  std::vector<float> std_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  s21_vector.erase(s21_vector.begin() + 3);
  std_vector.erase(std_vector.begin() + 3);
  for (size_t i = 0; i < std_vector.capacity(); i++) {
    EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Modifiers, test_vector_float_2) {
  s21::vector<float> s21_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  std::vector<float> std_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  s21_vector.erase(s21_vector.begin() + 3);
  std_vector.erase(std_vector.begin() + 5);
  for (size_t i = 0; i < s21_vector.size(); i++) {
    if (i == 3 || i == 4)
      EXPECT_TRUE(s21_vector[i] != std_vector[i]);
    else
      EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }

  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Modifiers, test_vector_float_2_1) {
  s21::vector<float> s21_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  std::vector<float> std_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  s21_vector.erase(s21_vector.begin() + 3, s21_vector.begin() + 8);
  std_vector.erase(std_vector.begin() + 3, std_vector.begin() + 8);
  for (size_t i = 0; i < std_vector.capacity(); i++) {
    // std::cout << s21_vector[i] << " =|= " << std_vector[i]<< std::endl;
    EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Modifiers, test_vector_float_3) {
  s21::vector<float> s21_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  std::vector<float> std_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  std_vector.erase(std_vector.begin());

  for (size_t i = 0; i < s21_vector.capacity() - 1; i++) {
    EXPECT_TRUE(s21_vector[i] != std_vector[i]);
  }

  EXPECT_TRUE(s21_vector.size() != std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Modifiers, test_vector_float_4) {
  s21::vector<float> s21_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  std::vector<float> std_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  s21_vector.push_back(66);
  std_vector.push_back(66);
  for (size_t i = 0; i < s21_vector.capacity(); i++) {
    EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }

  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Modifiers, test_vector_float_5) {
  s21::vector<float> s21_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  std::vector<float> std_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});

  s21_vector.pop_back();
  std_vector.pop_back();

  for (size_t i = 0; i < s21_vector.size(); i++) {
    EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }

  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Modifiers, test_vector_float_6) {
  s21::vector<float> s21_vector_1(
      {1.0, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9});
  s21::vector<float> s21_vector_2(
      {3.0, 3.1, 3.2, 3.3, 3.4, 3.5, 3.6, 3.7, 3.8, 3.9});
  s21::vector<float> s21_vector_tmp_1(s21_vector_1);
  s21::vector<float> s21_vector_tmp_2(s21_vector_2);

  std::vector<float> std_vector_1(
      {1.0, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9});
  std::vector<float> std_vector_2(
      {3.0, 3.1, 3.2, 3.3, 3.4, 3.5, 3.6, 3.7, 3.8, 3.9});
  std::vector<float> std_vector_tmp_1(std_vector_1);
  std::vector<float> std_vector_tmp_2(std_vector_2);

  s21_vector_1.swap(s21_vector_2);
  std_vector_1.swap(std_vector_2);

  for (size_t i = 0; i < s21_vector_1.size(); i++) {
    EXPECT_TRUE(s21_vector_1[i] == s21_vector_tmp_2[i]);
    EXPECT_TRUE(s21_vector_2[i] == s21_vector_tmp_1[i]);
  }

  for (size_t i = 0; i < std_vector_1.size(); i++) {
    EXPECT_TRUE(std_vector_1[i] == std_vector_tmp_2[i]);
    EXPECT_TRUE(std_vector_2[i] == std_vector_tmp_1[i]);
  }

  EXPECT_TRUE(s21_vector_1.size() == std_vector_1.size());
  EXPECT_TRUE(s21_vector_1.capacity() == std_vector_2.capacity());
}

TEST(Modifiers, test_vector_float_7) {
  s21::vector<float> s21_vector_1({1.1, 1.5, 1.9, 1.7, 1.3});
  s21::vector<float> s21_vector_2(
      {3.0, 3.1, 3.2, 3.3, 3.4, 3.5, 3.6, 3.7, 3.8, 3.9});
  s21::vector<float> s21_vector_tmp_1(s21_vector_1);
  s21::vector<float> s21_vector_tmp_2(s21_vector_2);

  std::vector<float> std_vector_1({1.1, 1.5, 1.9, 1.7, 1.3});
  std::vector<float> std_vector_2(
      {3.0, 3.1, 3.2, 3.3, 3.4, 3.5, 3.6, 3.7, 3.8, 3.9});
  std::vector<float> std_vector_tmp_1(std_vector_1);
  std::vector<float> std_vector_tmp_2(std_vector_2);

  s21_vector_1.swap(s21_vector_2);
  std_vector_1.swap(std_vector_2);

  for (size_t i = 0; i < s21_vector_1.size(); i++) {
    EXPECT_TRUE(s21_vector_1[i] == s21_vector_tmp_2[i]);
    EXPECT_TRUE(std_vector_1[i] == std_vector_tmp_2[i]);
  }

  for (size_t i = 0; i < s21_vector_2.size(); i++) {
    EXPECT_TRUE(s21_vector_2[i] == s21_vector_tmp_1[i]);
    EXPECT_TRUE(std_vector_2[i] == std_vector_tmp_1[i]);
  }

  EXPECT_TRUE(std_vector_1.size() == std_vector_tmp_2.size());
  EXPECT_TRUE(std_vector_2.size() == std_vector_tmp_1.size());

  EXPECT_TRUE(s21_vector_1.size() == s21_vector_tmp_2.size());
  EXPECT_TRUE(s21_vector_2.size() == s21_vector_tmp_1.size());

  EXPECT_TRUE(s21_vector_1.capacity() == std_vector_1.capacity());
  EXPECT_TRUE(s21_vector_2.capacity() == std_vector_2.capacity());
}

//-------------------------------------------------------------

// double
//------------------------------------------------------------- MemberFunctions

TEST(MemberFunctions, test_vector_double_1) {
  s21::vector<double> s21_vector;
  std::vector<double> std_vector;
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

// TEST(MemberFunctions, test_vector_double_2) {
//   EXPECT_ANY_THROW({ s21::vector<double> s21_vector(-1); });
// }

TEST(MemberFunctions, test_vector_double_3) {
  EXPECT_NO_THROW({ s21::vector<double> s21_vector; });
}

TEST(MemberFunctions, test_vector_double_4) {
  EXPECT_NO_THROW({ s21::vector<double> s21_vector(13); });
}

TEST(MemberFunctions, test_vector_double_4_1) {
  s21::vector<double> s21_vector(13);
  std::vector<double> std_vector(13);
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(MemberFunctions, test_vector_double_4_2) {
  s21::vector<double> s21_vector(130);
  std::vector<double> std_vector(130);
  for (size_t i = 0; i < s21_vector.size(); ++i) {
    EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }
}

TEST(MemberFunctions, test_vector_double_5) {
  EXPECT_NO_THROW({
    s21::vector<double> s21_vector(
        {0.1, 1.1, 2.1, 3.1, 4.1, 5.1, 6.1, 7.1, 8.1, 9.1});
  });
}

TEST(MemberFunctions, test_vector_double_6) {
  s21::vector<double> s21_vector_1(
      {0.1, 1.1, 2.1, 3.1, 4.1, 5.1, 6.1, 7.1, 8.1, 9.1});
  s21::vector<double> s21_vector_2(s21_vector_1);
  for (size_t i = 0; i < s21_vector_1.size(); ++i) {
    EXPECT_TRUE(s21_vector_1[i] == s21_vector_2[i]);
  }
}

TEST(MemberFunctions, test_vector_double_7) {
  s21::vector<double> s21_vector_1(
      {0.1, 1.1, 2.1, 3.1, 4.1, 5.1, 6.1, 7.1, 8.1, 9.1});
  s21::vector<double> s21_vector_2 = s21_vector_1;
  for (size_t i = 0; i < s21_vector_1.size(); ++i) {
    EXPECT_TRUE(s21_vector_1[i] == s21_vector_2[i]);
  }
}

TEST(MemberFunctions, test_vector_double_8) {
  s21::vector<double> s21_vector_1(
      {0.1, 1.1, 2.1, 3.1, 4.1, 5.1, 6.1, 7.1, 8.1, 9.1});
  s21::vector<double> s21_vector_2;
  s21_vector_2 = std::move(s21_vector_1);
  for (size_t i = 0; i < s21_vector_1.size(); ++i) {
    EXPECT_TRUE(s21_vector_1[i] == s21_vector_2[i]);
  }
}

TEST(MemberFunctions, test_vector_double_9) {
  s21::vector<double> s21_vector_1(
      {0.1, 1.1, 2.1, 3.1, 4.1, 5.1, 6.1, 7.1, 8.1, 9.1});
  double *p = s21_vector_1.data();
  s21::vector<double> s21_vector_2(std::move(s21_vector_1));

  EXPECT_TRUE(p == s21_vector_2.data());
}

//------------------------------------------------------------- ElementAccess

TEST(ElementAaccess, test_vector_double_1) {
  s21::vector<double> s21_vector(
      {0.1, 1.1, 2.1, 3.1, 4.1, 5.1, 6.1, 7.1, 8.1, 9.1});
  std::vector<double> std_vector(
      {0.1, 1.1, 2.1, 3.1, 4.1, 5.1, 6.1, 7.1, 8.1, 9.1});
  EXPECT_TRUE(s21_vector.at(5) == std_vector.at(5));
}

// TEST(ElementAaccess, test_vector_double_2) {
//   EXPECT_ANY_THROW({
//     s21::vector<double> s21_vector(
//         {0.1, 1.1, 2.1, 3.1, 4.1, 5.1, 6.1, 7.1, 8.1, 9.1});
//     s21_vector.at(100);
//   });
// }

// TEST(ElementAaccess, test_vector_double_3) {
//   EXPECT_ANY_THROW({
//     s21::vector<double> s21_vector(
//         {0.1, 1.1, 2.1, 3.1, 4.1, 5.1, 6.1, 7.1, 8.1, 9.1});
//     s21_vector.at(-10);
//   });
// }

TEST(ElementAaccess, test_vector_double_4) {
  s21::vector<double> s21_vector(
      {0.1, 1.1, 2.1, 3.1, 4.1, 5.1, 6.1, 7.1, 8.1, 9.1});
  std::vector<double> std_vector(
      {0.1, 1.1, 2.1, 3.1, 4.1, 5.1, 6.1, 7.1, 8.1, 9.1});
  EXPECT_TRUE(*s21_vector.data() == *std_vector.data());
}

TEST(ElementAaccess, test_vector_double_5) {
  s21::vector<double> s21_vector(
      {0.1, 1.1, 2.1, 3.1, 4.1, 5.1, 6.1, 7.1, 8.1, 9.1});
  std::vector<double> std_vector(
      {0.1, 1.1, 2.1, 3.1, 4.1, 5.1, 6.1, 7.1, 8.1, 9.1});
  EXPECT_TRUE(s21_vector[5] == std_vector[5]);
}

TEST(ElementAaccess, test_vector_double_6) {
  s21::vector<double> s21_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.9});
  std::vector<double> std_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.9});
  double my = s21_vector.front();
  double std = std_vector.front();
  EXPECT_TRUE(my == std);
}

TEST(ElementAaccess, test_vector_double_7) {
  s21::vector<double> s21_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  std::vector<double> std_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  double my = s21_vector.back();
  double std = std_vector.back();
  EXPECT_TRUE(my == std);
}

//------------------------------------------------------------- Iterators

TEST(Iterators, test_vector_double_1) {
  s21::vector<double> s21_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  std::vector<double> std_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  EXPECT_TRUE(*s21_vector.begin() == *std_vector.begin());
}

TEST(Iterators, test_vector_double_2) {
  s21::vector<double> s21_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  std::vector<double> std_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  EXPECT_TRUE(*(s21_vector.end() - 1) == *(std_vector.end() - 1));
}

//------------------------------------------------------------- revIterators

TEST(revIterators, test_vector_double_1) {
  s21::vector<double> s21_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  std::vector<double> std_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  EXPECT_TRUE(*s21_vector.rbegin() == *std_vector.rbegin());
}

TEST(revIterators, test_vector_double_2) {
  s21::vector<double> s21_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  std::vector<double> std_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  EXPECT_TRUE(*(s21_vector.rend() - 1) == *(std_vector.rend() - 1));
}

//------------------------------------------------------------- Capacity

TEST(Capacity, test_vector_double_3) {
  s21::vector<double> s21_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  std::vector<double> std_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  EXPECT_TRUE(s21_vector.empty() == std_vector.empty());
}

TEST(Capacity, test_vector_double_4) {
  s21::vector<double> s21_vector;
  std::vector<double> std_vector;
  EXPECT_TRUE(s21_vector.empty() == std_vector.empty());
}

TEST(Capacity, test_vector_double_5) {
  s21::vector<double> s21_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  std::vector<double> std_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
}

TEST(Capacity, test_vector_double_6) {
  s21::vector<double> s21_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  std::vector<double> std_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  EXPECT_TRUE(s21_vector.max_size() == std_vector.max_size());
}

TEST(Capacity, test_vector_double_7) {
  s21::vector<double> s21_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  std::vector<double> std_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  s21_vector.reserve(s21_vector.size() + s21_vector.capacity());
  std_vector.reserve(std_vector.size() + std_vector.capacity());
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
}

TEST(Capacity, test_vector_double_7_1) {
  s21::vector<double> s21_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  std::vector<double> std_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  s21_vector.reserve(s21_vector.size() / 2);
  std_vector.reserve(std_vector.size() / 2);
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
}

// TEST(Capacity, test_vector_double_7_2) {
//   s21::vector<double> s21_vector(
//       {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
//   std::vector<double> std_vector(
//       {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
//   EXPECT_ANY_THROW({ s21::vector<double> s21_vector(-1); });
//   EXPECT_ANY_THROW({ std::vector<double> std_vector(-1); });
// }

TEST(Capacity, test_vector_double_8) {
  s21::vector<double> s21_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  std::vector<double> std_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  s21_vector.reserve(s21_vector.size() + s21_vector.capacity());
  std_vector.reserve(std_vector.size() + std_vector.capacity());
  s21_vector.insert(s21_vector.begin() + 3, 13);
  std_vector.insert(std_vector.begin() + 3, 13);
  s21_vector.shrink_to_fit();
  std_vector.shrink_to_fit();
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Capacity, test_vector_double_9) {
  s21::vector<double> s21_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  std::vector<double> std_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  s21_vector.reserve(s21_vector.size() + s21_vector.capacity());
  std_vector.reserve(std_vector.size() + std_vector.capacity());
  s21_vector.insert(s21_vector.begin() + 14, 13);
  std_vector.insert(std_vector.begin() + 13, 13);
  s21_vector.shrink_to_fit();
  std_vector.shrink_to_fit();
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Capacity, test_vector_double_10) {
  s21::vector<double> s21_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  std::vector<double> std_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  s21_vector.resize(s21_vector.size() + s21_vector.capacity());
  std_vector.resize(std_vector.size() + std_vector.capacity());
  for (size_t i = 0; i < s21_vector.size(); ++i) {
    EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
}

TEST(Capacity, test_vector_double_11) {
  s21::vector<double> s21_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  std::vector<double> std_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  s21_vector.resize(s21_vector.size() / 2);
  std_vector.resize(std_vector.size() / 2);
  for (size_t i = 0; i < std_vector.capacity(); ++i) {
    EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }
  for (size_t i = 0; i < s21_vector.size(); ++i) {
    EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
}
//--------------------------------------------------- Vector Modifiers

TEST(Modifiers, test_vector_double_0) {
  s21::vector<double> s21_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  std::vector<double> std_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  s21_vector.reserve(s21_vector.size() + s21_vector.capacity());
  std_vector.reserve(std_vector.size() + std_vector.capacity());
  s21_vector.insert(s21_vector.begin() + 3, 13);
  s21_vector.shrink_to_fit();
  std_vector.shrink_to_fit();
  EXPECT_TRUE(s21_vector.capacity() != std_vector.capacity());
}

TEST(Modifiers, test_vector_double_0_0) {
  s21::vector<double> s21_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  std::vector<double> std_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  s21_vector.insert(s21_vector.begin() + 3, 4, 13);
  std_vector.insert(std_vector.begin() + 3, 4, 13);
  for (size_t i = 0; i < std_vector.size(); ++i) {
    EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Modifiers, test_vector_double_0_1) {
  s21::vector<double> s21_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  std::vector<double> std_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  // size_t len = s21_vector.size();
  s21_vector.clear();
  std_vector.clear();
  //  for(size_t i = 0; i < len; i ++) {
  //   EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  // }
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
  EXPECT_TRUE(*s21_vector.end() == *std_vector.end());
}

TEST(Modifiers, test_vector_double_1) {
  s21::vector<double> s21_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  std::vector<double> std_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  s21_vector.erase(s21_vector.begin() + 3);
  std_vector.erase(std_vector.begin() + 3);
  for (size_t i = 0; i < std_vector.capacity(); i++) {
    EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Modifiers, test_vector_double_2) {
  s21::vector<double> s21_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  std::vector<double> std_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  s21_vector.erase(s21_vector.begin() + 3);
  std_vector.erase(std_vector.begin() + 5);
  for (size_t i = 0; i < s21_vector.size(); i++) {
    if (i == 3 || i == 4)
      EXPECT_TRUE(s21_vector[i] != std_vector[i]);
    else
      EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }

  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Modifiers, test_vector_double_2_1) {
  s21::vector<double> s21_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  std::vector<double> std_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  s21_vector.erase(s21_vector.begin() + 3, s21_vector.begin() + 8);
  std_vector.erase(std_vector.begin() + 3, std_vector.begin() + 8);
  for (size_t i = 0; i < std_vector.capacity(); i++) {
    // std::cout << s21_vector[i] << " =|= " << std_vector[i]<< std::endl;
    EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Modifiers, test_vector_double_3) {
  s21::vector<double> s21_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  std::vector<double> std_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  std_vector.erase(std_vector.begin());

  for (size_t i = 0; i < s21_vector.capacity() - 1; i++) {
    EXPECT_TRUE(s21_vector[i] != std_vector[i]);
  }

  EXPECT_TRUE(s21_vector.size() != std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Modifiers, test_vector_double_4) {
  s21::vector<double> s21_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  std::vector<double> std_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  s21_vector.push_back(66);
  std_vector.push_back(66);
  for (size_t i = 0; i < s21_vector.capacity(); i++) {
    EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }

  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Modifiers, test_vector_double_5) {
  s21::vector<double> s21_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});
  std::vector<double> std_vector(
      {88.8, 1.35, 2.45, 3.987, 4.1, 5.2, 6.3, 7.4, 8.5, 9.99});

  s21_vector.pop_back();
  std_vector.pop_back();

  for (size_t i = 0; i < s21_vector.size(); i++) {
    EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }

  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Modifiers, test_vector_double_6) {
  s21::vector<double> s21_vector_1(
      {1.0, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9});
  s21::vector<double> s21_vector_2(
      {3.0, 3.1, 3.2, 3.3, 3.4, 3.5, 3.6, 3.7, 3.8, 3.9});
  s21::vector<double> s21_vector_tmp_1(s21_vector_1);
  s21::vector<double> s21_vector_tmp_2(s21_vector_2);

  std::vector<double> std_vector_1(
      {1.0, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9});
  std::vector<double> std_vector_2(
      {3.0, 3.1, 3.2, 3.3, 3.4, 3.5, 3.6, 3.7, 3.8, 3.9});
  std::vector<double> std_vector_tmp_1(std_vector_1);
  std::vector<double> std_vector_tmp_2(std_vector_2);

  s21_vector_1.swap(s21_vector_2);
  std_vector_1.swap(std_vector_2);

  for (size_t i = 0; i < s21_vector_1.size(); i++) {
    EXPECT_TRUE(s21_vector_1[i] == s21_vector_tmp_2[i]);
    EXPECT_TRUE(s21_vector_2[i] == s21_vector_tmp_1[i]);
  }

  for (size_t i = 0; i < std_vector_1.size(); i++) {
    EXPECT_TRUE(std_vector_1[i] == std_vector_tmp_2[i]);
    EXPECT_TRUE(std_vector_2[i] == std_vector_tmp_1[i]);
  }

  EXPECT_TRUE(s21_vector_1.size() == std_vector_1.size());
  EXPECT_TRUE(s21_vector_1.capacity() == std_vector_2.capacity());
}

TEST(Modifiers, test_vector_double_7) {
  s21::vector<double> s21_vector_1({1.1, 1.5, 1.9, 1.7, 1.3});
  s21::vector<double> s21_vector_2(
      {3.0, 3.1, 3.2, 3.3, 3.4, 3.5, 3.6, 3.7, 3.8, 3.9});
  s21::vector<double> s21_vector_tmp_1(s21_vector_1);
  s21::vector<double> s21_vector_tmp_2(s21_vector_2);

  std::vector<double> std_vector_1({1.1, 1.5, 1.9, 1.7, 1.3});
  std::vector<double> std_vector_2(
      {3.0, 3.1, 3.2, 3.3, 3.4, 3.5, 3.6, 3.7, 3.8, 3.9});
  std::vector<double> std_vector_tmp_1(std_vector_1);
  std::vector<double> std_vector_tmp_2(std_vector_2);

  s21_vector_1.swap(s21_vector_2);
  std_vector_1.swap(std_vector_2);

  for (size_t i = 0; i < s21_vector_1.size(); i++) {
    EXPECT_TRUE(s21_vector_1[i] == s21_vector_tmp_2[i]);
    EXPECT_TRUE(std_vector_1[i] == std_vector_tmp_2[i]);
  }

  for (size_t i = 0; i < s21_vector_2.size(); i++) {
    EXPECT_TRUE(s21_vector_2[i] == s21_vector_tmp_1[i]);
    EXPECT_TRUE(std_vector_2[i] == std_vector_tmp_1[i]);
  }

  EXPECT_TRUE(std_vector_1.size() == std_vector_tmp_2.size());
  EXPECT_TRUE(std_vector_2.size() == std_vector_tmp_1.size());

  EXPECT_TRUE(s21_vector_1.size() == s21_vector_tmp_2.size());
  EXPECT_TRUE(s21_vector_2.size() == s21_vector_tmp_1.size());

  EXPECT_TRUE(s21_vector_1.capacity() == std_vector_1.capacity());
  EXPECT_TRUE(s21_vector_2.capacity() == std_vector_2.capacity());
}

//-------------------------------------------------------------

// char
//------------------------------------------------------------- MemberFunctions

TEST(MemberFunctions, test_vector_char_1) {
  s21::vector<char> s21_vector;
  std::vector<char> std_vector;
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

// TEST(MemberFunctions, test_vector_char_2) {
//   EXPECT_ANY_THROW({ s21::vector<char> s21_vector(-1); });
// }

TEST(MemberFunctions, test_vector_char_3) {
  EXPECT_NO_THROW({ s21::vector<char> s21_vector; });
}

TEST(MemberFunctions, test_vector_char_4) {
  EXPECT_NO_THROW({ s21::vector<char> s21_vector('a'); });
}

TEST(MemberFunctions, test_vector_char_4_1) {
  s21::vector<char> s21_vector(13);
  std::vector<char> std_vector(13);
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(MemberFunctions, test_vector_char_4_2) {
  s21::vector<char> s21_vector(130);
  std::vector<char> std_vector(130);
  for (size_t i = 0; i < s21_vector.size(); ++i) {
    EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }
}

TEST(MemberFunctions, test_vector_char_5) {
  EXPECT_NO_THROW({
    s21::vector<char> s21_vector(
        {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  });
}

TEST(MemberFunctions, test_vector_char_6) {
  s21::vector<char> s21_vector_1(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  s21::vector<char> s21_vector_2(s21_vector_1);
  for (size_t i = 0; i < s21_vector_1.size(); ++i) {
    EXPECT_TRUE(s21_vector_1[i] == s21_vector_2[i]);
  }
}

TEST(MemberFunctions, test_vector_char_7) {
  s21::vector<char> s21_vector_1(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  s21::vector<char> s21_vector_2 = s21_vector_1;
  for (size_t i = 0; i < s21_vector_1.size(); ++i) {
    EXPECT_TRUE(s21_vector_1[i] == s21_vector_2[i]);
  }
}

TEST(MemberFunctions, test_vector_char_8) {
  s21::vector<char> s21_vector_1(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  s21::vector<char> s21_vector_2;
  s21_vector_2 = std::move(s21_vector_1);
  for (size_t i = 0; i < s21_vector_1.size(); ++i) {
    EXPECT_TRUE(s21_vector_1[i] == s21_vector_2[i]);
  }
}

TEST(MemberFunctions, test_vector_char_9) {
  s21::vector<char> s21_vector_1(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  char *p = s21_vector_1.data();
  s21::vector<char> s21_vector_2(std::move(s21_vector_1));

  EXPECT_TRUE(p == s21_vector_2.data());
}

//------------------------------------------------------------- ElementAccess

TEST(ElementAaccess, test_vector_char_1) {
  s21::vector<char> s21_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  std::vector<char> std_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  EXPECT_TRUE(s21_vector.at(5) == std_vector.at(5));
}

// TEST(ElementAaccess, test_vector_char_2) {
//   EXPECT_ANY_THROW({
//     s21::vector<char> s21_vector(
//         {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
//     s21_vector.at(100);
//   });
// }

// TEST(ElementAaccess, test_vector_char_3) {
//   EXPECT_ANY_THROW({
//     s21::vector<char> s21_vector(
//         {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
//     s21_vector.at(-10);
//   });
// }

TEST(ElementAaccess, test_vector_char_4) {
  s21::vector<char> s21_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  std::vector<char> std_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  EXPECT_TRUE(*s21_vector.data() == *std_vector.data());
}

TEST(ElementAaccess, test_vector_char_5) {
  s21::vector<char> s21_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  std::vector<char> std_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  EXPECT_TRUE(s21_vector[5] == std_vector[5]);
}

TEST(ElementAaccess, test_vector_char_6) {
  s21::vector<char> s21_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  std::vector<char> std_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  char my = s21_vector.front();
  char std = std_vector.front();
  EXPECT_TRUE(my == std);
}

TEST(ElementAaccess, test_vector_char_7) {
  s21::vector<char> s21_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  std::vector<char> std_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  char my = s21_vector.back();
  char std = std_vector.back();
  EXPECT_TRUE(my == std);
}

//------------------------------------------------------------- Iterators

TEST(Iterators, test_vector_char_1) {
  s21::vector<char> s21_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  std::vector<char> std_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  EXPECT_TRUE(*s21_vector.begin() == *std_vector.begin());
}

TEST(Iterators, test_vector_char_2) {
  s21::vector<char> s21_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  std::vector<char> std_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  EXPECT_TRUE(*(s21_vector.end() - 1) == *(std_vector.end() - 1));
}

//------------------------------------------------------------- revIterators

TEST(revIterators, test_vector_char_1) {
  s21::vector<char> s21_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  std::vector<char> std_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  EXPECT_TRUE(*s21_vector.rbegin() == *std_vector.rbegin());
}

TEST(revIterators, test_vector_char_2) {
  s21::vector<char> s21_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  std::vector<char> std_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  EXPECT_TRUE(*(s21_vector.rend() - 1) == *(std_vector.rend() - 1));
}

//------------------------------------------------------------- Capacity

TEST(Capacity, test_vector_char_3) {
  s21::vector<char> s21_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  std::vector<char> std_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  EXPECT_TRUE(s21_vector.empty() == std_vector.empty());
}

TEST(Capacity, test_vector_char_4) {
  s21::vector<char> s21_vector;
  std::vector<char> std_vector;
  EXPECT_TRUE(s21_vector.empty() == std_vector.empty());
}

TEST(Capacity, test_vector_char_5) {
  s21::vector<char> s21_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  std::vector<char> std_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
}

TEST(Capacity, test_vector_char_6) {
  s21::vector<char> s21_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  std::vector<char> std_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  EXPECT_TRUE(s21_vector.max_size() == std_vector.max_size());
}

TEST(Capacity, test_vector_char_7) {
  s21::vector<char> s21_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  std::vector<char> std_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  s21_vector.reserve(s21_vector.size() + s21_vector.capacity());
  std_vector.reserve(std_vector.size() + std_vector.capacity());
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
}

TEST(Capacity, test_vector_char_7_1) {
  s21::vector<char> s21_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  std::vector<char> std_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  s21_vector.reserve(s21_vector.size() / 2);
  std_vector.reserve(std_vector.size() / 2);
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
}

// TEST(Capacity, test_vector_char_7_2) {
//   s21::vector<char> s21_vector(
//       {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
//   std::vector<char> std_vector(
//       {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
//   EXPECT_ANY_THROW({ s21::vector<char> s21_vector(-1); });
//   EXPECT_ANY_THROW({ std::vector<char> std_vector(-1); });
// }

TEST(Capacity, test_vector_char_8) {
  s21::vector<char> s21_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  std::vector<char> std_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  s21_vector.reserve(s21_vector.size() + s21_vector.capacity());
  std_vector.reserve(std_vector.size() + std_vector.capacity());
  s21_vector.insert(s21_vector.begin() + 3, 13);
  std_vector.insert(std_vector.begin() + 3, 13);
  s21_vector.shrink_to_fit();
  std_vector.shrink_to_fit();
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Capacity, test_vector_char_9) {
  s21::vector<char> s21_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  std::vector<char> std_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  s21_vector.reserve(s21_vector.size() + s21_vector.capacity());
  std_vector.reserve(std_vector.size() + std_vector.capacity());
  s21_vector.insert(s21_vector.begin() + 14, 13);
  std_vector.insert(std_vector.begin() + 13, 13);
  s21_vector.shrink_to_fit();
  std_vector.shrink_to_fit();
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Capacity, test_vector_char_10) {
  s21::vector<char> s21_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  std::vector<char> std_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  s21_vector.resize(s21_vector.size() + s21_vector.capacity());
  std_vector.resize(std_vector.size() + std_vector.capacity());
  for (size_t i = 0; i < s21_vector.size(); ++i) {
    EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
}

TEST(Capacity, test_vector_char_11) {
  s21::vector<char> s21_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  std::vector<char> std_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  s21_vector.resize(s21_vector.size() / 2);
  std_vector.resize(std_vector.size() / 2);
  for (size_t i = 0; i < s21_vector.size(); ++i) {
    EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
}

//--------------------------------------------------- Vector Modifiers

TEST(Modifiers, test_vector_char_0) {
  s21::vector<char> s21_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  std::vector<char> std_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  s21_vector.reserve(s21_vector.size() + s21_vector.capacity());
  std_vector.reserve(std_vector.size() + std_vector.capacity());
  s21_vector.insert(s21_vector.begin() + 3, 13);
  s21_vector.shrink_to_fit();
  std_vector.shrink_to_fit();
  EXPECT_TRUE(s21_vector.capacity() != std_vector.capacity());
}

TEST(Modifiers, test_vector_char_0_0) {
  s21::vector<char> s21_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  std::vector<char> std_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  s21_vector.insert(s21_vector.begin() + 3, 4, 13);
  std_vector.insert(std_vector.begin() + 3, 4, 13);
  for (size_t i = 0; i < std_vector.size(); ++i) {
    EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Modifiers, test_vector_char_0_1) {
  s21::vector<char> s21_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  std::vector<char> std_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  // size_t len = s21_vector.size();
  s21_vector.clear();
  std_vector.clear();
  //  for(size_t i = 0; i < len; i ++) {
  //   EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  // }
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
  EXPECT_TRUE(*s21_vector.end() == *std_vector.end());
}

TEST(Modifiers, test_vector_char_1) {
  s21::vector<char> s21_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  std::vector<char> std_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  s21_vector.erase(s21_vector.begin() + 3);
  std_vector.erase(std_vector.begin() + 3);
  for (size_t i = 0; i < std_vector.capacity(); i++) {
    EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Modifiers, test_vector_char_2) {
  s21::vector<char> s21_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  std::vector<char> std_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  s21_vector.erase(s21_vector.begin() + 3);
  std_vector.erase(std_vector.begin() + 5);
  for (size_t i = 0; i < s21_vector.size(); i++) {
    if (i == 3 || i == 4)
      EXPECT_TRUE(s21_vector[i] != std_vector[i]);
    else
      EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }

  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Modifiers, test_vector_char_2_1) {
  s21::vector<char> s21_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  std::vector<char> std_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  s21_vector.erase(s21_vector.begin() + 3, s21_vector.begin() + 8);
  std_vector.erase(std_vector.begin() + 3, std_vector.begin() + 8);
  for (size_t i = 0; i < std_vector.capacity(); i++) {
    // std::cout << s21_vector[i] << " =|= " << std_vector[i]<< std::endl;
    EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Modifiers, test_vector_char_3) {
  s21::vector<char> s21_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  std::vector<char> std_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  std_vector.erase(std_vector.begin());

  for (size_t i = 0; i < s21_vector.capacity() - 1; i++) {
    EXPECT_TRUE(s21_vector[i] != std_vector[i]);
  }

  EXPECT_TRUE(s21_vector.size() != std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Modifiers, test_vector_char_4) {
  s21::vector<char> s21_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  std::vector<char> std_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  s21_vector.push_back(66);
  std_vector.push_back(66);
  for (size_t i = 0; i < s21_vector.capacity(); i++) {
    EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }

  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Modifiers, test_vector_char_5) {
  s21::vector<char> s21_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});
  std::vector<char> std_vector(
      {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l'});

  s21_vector.pop_back();
  std_vector.pop_back();

  for (size_t i = 0; i < s21_vector.size(); i++) {
    EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }

  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Modifiers, test_vector_char_6) {
  s21::vector<char> s21_vector_1(
      {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'});
  s21::vector<char> s21_vector_2(
      {'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'});
  s21::vector<char> s21_vector_tmp_1(s21_vector_1);
  s21::vector<char> s21_vector_tmp_2(s21_vector_2);

  std::vector<char> std_vector_1(
      {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'});
  std::vector<char> std_vector_2(
      {'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'});
  std::vector<char> std_vector_tmp_1(std_vector_1);
  std::vector<char> std_vector_tmp_2(std_vector_2);

  s21_vector_1.swap(s21_vector_2);
  std_vector_1.swap(std_vector_2);

  for (size_t i = 0; i < s21_vector_1.size(); i++) {
    EXPECT_TRUE(s21_vector_1[i] == s21_vector_tmp_2[i]);
    EXPECT_TRUE(s21_vector_2[i] == s21_vector_tmp_1[i]);
  }

  for (size_t i = 0; i < std_vector_1.size(); i++) {
    EXPECT_TRUE(std_vector_1[i] == std_vector_tmp_2[i]);
    EXPECT_TRUE(std_vector_2[i] == std_vector_tmp_1[i]);
  }

  EXPECT_TRUE(s21_vector_1.size() == std_vector_1.size());
  EXPECT_TRUE(s21_vector_1.capacity() == std_vector_2.capacity());
}

TEST(Modifiers, test_vector_char_7) {
  s21::vector<char> s21_vector_1({'a', 'a', 'a', 'a', 'a'});
  s21::vector<char> s21_vector_2(
      {'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'});
  s21::vector<char> s21_vector_tmp_1(s21_vector_1);
  s21::vector<char> s21_vector_tmp_2(s21_vector_2);

  std::vector<char> std_vector_1({'a', 'a', 'a', 'a', 'a'});
  std::vector<char> std_vector_2(
      {'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'});
  std::vector<char> std_vector_tmp_1(std_vector_1);
  std::vector<char> std_vector_tmp_2(std_vector_2);

  s21_vector_1.swap(s21_vector_2);
  std_vector_1.swap(std_vector_2);

  for (size_t i = 0; i < s21_vector_1.size(); i++) {
    EXPECT_TRUE(s21_vector_1[i] == s21_vector_tmp_2[i]);
    EXPECT_TRUE(std_vector_1[i] == std_vector_tmp_2[i]);
  }

  for (size_t i = 0; i < s21_vector_2.size(); i++) {
    EXPECT_TRUE(s21_vector_2[i] == s21_vector_tmp_1[i]);
    EXPECT_TRUE(std_vector_2[i] == std_vector_tmp_1[i]);
  }

  EXPECT_TRUE(std_vector_1.size() == std_vector_tmp_2.size());
  EXPECT_TRUE(std_vector_2.size() == std_vector_tmp_1.size());

  EXPECT_TRUE(s21_vector_1.size() == s21_vector_tmp_2.size());
  EXPECT_TRUE(s21_vector_2.size() == s21_vector_tmp_1.size());

  EXPECT_TRUE(s21_vector_1.capacity() == std_vector_1.capacity());
  EXPECT_TRUE(s21_vector_2.capacity() == std_vector_2.capacity());
}

//-------------------------------------------------------------

// string
//------------------------------------------------------------- MemberFunctions

TEST(MemberFunctions, test_vector_string_1) {
  s21::vector<std::string> s21_vector;
  std::vector<std::string> std_vector;
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

// TEST(MemberFunctions, test_vector_string_2) {
//   EXPECT_ANY_THROW({ s21::vector<std::string> s21_vector(-1); });
// }

TEST(MemberFunctions, test_vector_string_3) {
  EXPECT_NO_THROW({ s21::vector<std::string> s21_vector; });
}

TEST(MemberFunctions, test_vector_string_4) {
  EXPECT_NO_THROW({ s21::vector<std::string> s21_vector = {"string"}; });
}

TEST(MemberFunctions, test_vector_string_4_1) {
  s21::vector<std::string> s21_vector(13);
  std::vector<std::string> std_vector(13);
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(MemberFunctions, test_vector_string_4_2) {
  s21::vector<std::string> s21_vector(130);
  std::vector<std::string> std_vector(130);
  for (size_t i = 0; i < s21_vector.size(); ++i) {
    EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }
}
TEST(MemberFunctions, test_vector_string_5) {
  s21::vector<std::string> s21_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
}

TEST(MemberFunctions, test_vector_string_6) {
  s21::vector<std::string> s21_vector_1 = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  s21::vector<std::string> s21_vector_2(s21_vector_1);
  for (size_t i = 0; i < s21_vector_1.size(); ++i) {
    EXPECT_TRUE(s21_vector_1[i] == s21_vector_2[i]);
  }
}

TEST(MemberFunctions, test_vector_string_7) {
  s21::vector<std::string> s21_vector_1 = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  s21::vector<std::string> s21_vector_2 = s21_vector_1;
  for (size_t i = 0; i < s21_vector_1.size(); ++i) {
    EXPECT_TRUE(s21_vector_1[i] == s21_vector_2[i]);
  }
}

TEST(MemberFunctions, test_vector_string_8) {
  s21::vector<std::string> s21_vector_1 = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  s21::vector<std::string> s21_vector_2;
  s21_vector_2 = std::move(s21_vector_1);
  for (size_t i = 0; i < s21_vector_1.size(); ++i) {
    EXPECT_TRUE(s21_vector_1[i] == s21_vector_2[i]);
  }
}

TEST(MemberFunctions, test_vector_string_9) {
  s21::vector<std::string> s21_vector_1 = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  std::string *p = s21_vector_1.data();
  s21::vector<std::string> s21_vector_2(std::move(s21_vector_1));

  EXPECT_TRUE(p == s21_vector_2.data());
}

//------------------------------------------------------------- ElementAccess

TEST(ElementAaccess, test_vector_string_1) {
  s21::vector<std::string> s21_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  std::vector<std::string> std_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  EXPECT_TRUE(s21_vector.at(5) == std_vector.at(5));
}

// TEST(ElementAccess, test_vector_string_2) {
//   try {
//     s21::vector<std::string> s21_vector = {
//         "string_a", "string_b", "string_c", "string_d", "string_e",
//         "string_g", "string_i", "string_j", "string_k", "string_l"};
//     s21_vector.at(100);
//     FAIL() << "Expected out_of_range exception";
//   } catch (const std::out_of_range &e) {
//     SUCCEED() << "Caught out_of_range exception";
//   }
// }

// TEST(ElementAaccess, test_vector_string_3) {
//   try {
//     s21::vector<std::string> s21_vector = {
//         "string_a", "string_b", "string_c", "string_d", "string_e",
//         "string_g", "string_i", "string_j", "string_k", "string_l"};
//     s21_vector.at(-10);
//     FAIL() << "Expected out_of_range exception";
//   } catch (const std::out_of_range &e) {
//     SUCCEED() << "Caught out_of_range exception";
//   }
// }

TEST(ElementAaccess, test_vector_string_4) {
  s21::vector<std::string> s21_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  std::vector<std::string> std_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  EXPECT_TRUE(*s21_vector.data() == *std_vector.data());
}

TEST(ElementAaccess, test_vector_string_5) {
  s21::vector<std::string> s21_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  std::vector<std::string> std_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  EXPECT_TRUE(s21_vector[5] == std_vector[5]);
}

TEST(ElementAaccess, test_vector_string_6) {
  s21::vector<std::string> s21_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  std::vector<std::string> std_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  std::string my = s21_vector.front();
  std::string std = std_vector.front();
  EXPECT_TRUE(my == std);
}

TEST(ElementAaccess, test_vector_string_7) {
  s21::vector<std::string> s21_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  std::vector<std::string> std_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  std::string my = s21_vector.back();
  std::string std = std_vector.back();
  EXPECT_TRUE(my == std);
}

//------------------------------------------------------------- Iterators

TEST(Iterators, test_vector_string_1) {
  s21::vector<std::string> s21_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  std::vector<std::string> std_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  EXPECT_TRUE(*s21_vector.begin() == *std_vector.begin());
}

TEST(Iterators, test_vector_string_2) {
  s21::vector<std::string> s21_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  std::vector<std::string> std_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  EXPECT_TRUE(*(s21_vector.end() - 1) == *(std_vector.end() - 1));
}

//------------------------------------------------------------- revIterators

TEST(revIterators, test_vector_string_1) {
  s21::vector<std::string> s21_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  std::vector<std::string> std_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  EXPECT_TRUE(*s21_vector.rbegin() == *std_vector.rbegin());
}

TEST(revIterators, test_vector_string_2) {
  s21::vector<std::string> s21_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  std::vector<std::string> std_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  EXPECT_TRUE(*(s21_vector.rend() - 1) == *(std_vector.rend() - 1));
}

//------------------------------------------------------------- Capacity

TEST(Capacity, test_vector_string_3) {
  s21::vector<std::string> s21_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  std::vector<std::string> std_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  EXPECT_TRUE(s21_vector.empty() == std_vector.empty());
}

TEST(Capacity, test_vector_string_4) {
  s21::vector<std::string> s21_vector;
  std::vector<std::string> std_vector;
  EXPECT_TRUE(s21_vector.empty() == std_vector.empty());
}

TEST(Capacity, test_vector_string_5) {
  s21::vector<std::string> s21_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  std::vector<std::string> std_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
}

TEST(Capacity, test_vector_string_6) {
  s21::vector<std::string> s21_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  std::vector<std::string> std_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  EXPECT_TRUE(s21_vector.max_size() == std_vector.max_size());
}

TEST(Capacity, test_vector_string_7) {
  s21::vector<std::string> s21_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  std::vector<std::string> std_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  s21_vector.reserve(s21_vector.size() + s21_vector.capacity());
  std_vector.reserve(std_vector.size() + std_vector.capacity());
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
}

TEST(Capacity, test_vector_string_7_1) {
  s21::vector<std::string> s21_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  std::vector<std::string> std_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  s21_vector.reserve(s21_vector.size() / 2);
  std_vector.reserve(std_vector.size() / 2);
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
}

// TEST(Capacity, test_vector_string_7_2) {
//   s21::vector<std::string> s21_vector = {
//       "string_a", "string_b", "string_c", "string_d", "string_e",
//       "string_g", "string_i", "string_j", "string_k", "string_l"};
//   std::vector<std::string> std_vector = {
//       "string_a", "string_b", "string_c", "string_d", "string_e",
//       "string_g", "string_i", "string_j", "string_k", "string_l"};
//   EXPECT_ANY_THROW({ s21::vector<std::string> s21_vector(-1); });
//   EXPECT_ANY_THROW({ std::vector<std::string> std_vector(-1); });
// }

TEST(Capacity, test_vector_string_8) {
  s21::vector<std::string> s21_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  std::vector<std::string> std_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  s21_vector.reserve(s21_vector.size() + s21_vector.capacity());
  std_vector.reserve(std_vector.size() + std_vector.capacity());
  s21_vector.insert(s21_vector.begin() + 3, "aboba");
  std_vector.insert(std_vector.begin() + 3, "aboba");
  s21_vector.shrink_to_fit();
  std_vector.shrink_to_fit();
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Capacity, test_vector_string_9) {
  s21::vector<std::string> s21_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  std::vector<std::string> std_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  s21_vector.reserve(s21_vector.size() + s21_vector.capacity());
  std_vector.reserve(std_vector.size() + std_vector.capacity());
  // std::cout << "s21 len = " << s21_vector.size() << std::endl;
  // std::cout << "std len = " << std_vector.size() << std::endl;
  // std::cout << "s21 cap = " << s21_vector.capacity() << std::endl;
  // std::cout << "std cap = " << std_vector.capacity() << std::endl;
  //    std::cout << "insert.s21_vector  = ";
  // for(size_t i = 0; i < s21_vector.capacity(); ++i) {
  //   std::cout << s21_vector[i] << ", ";
  // }
  // std::cout << std::endl;
  //   std::cout << "insert.std_vector = ";
  // for(size_t i = 0; i < std_vector.capacity(); ++i) {
  //   std::cout << std_vector[i] << ", ";
  // }
  // std::cout << std::endl;
  s21_vector.insert(s21_vector.end(), "aboba");
  std_vector.insert(std_vector.end(), "aboba");
  s21_vector.shrink_to_fit();
  std_vector.shrink_to_fit();
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Capacity, test_vector_string_10) {
  s21::vector<std::string> s21_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  std::vector<std::string> std_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  s21_vector.resize(s21_vector.size() + s21_vector.capacity());
  std_vector.resize(std_vector.size() + std_vector.capacity());
  for (size_t i = 0; i < s21_vector.size(); ++i) {
    EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
}

TEST(Capacity, test_vector_string_11) {
  s21::vector<std::string> s21_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  std::vector<std::string> std_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  s21_vector.resize(s21_vector.size() / 2);
  std_vector.resize(std_vector.size() / 2);
  for (size_t i = 0; i < s21_vector.size(); ++i) {
    EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
}

//--------------------------------------------------- Vector Modifiers

TEST(Modifiers, test_vector_string_0) {
  s21::vector<std::string> s21_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  std::vector<std::string> std_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  s21_vector.reserve(s21_vector.size() + s21_vector.capacity());
  std_vector.reserve(std_vector.size() + std_vector.capacity());
  s21_vector.insert(s21_vector.begin() + 3, "aboba");
  s21_vector.shrink_to_fit();
  std_vector.shrink_to_fit();
  EXPECT_TRUE(s21_vector.capacity() != std_vector.capacity());
}

TEST(Modifiers, test_vector_string_0_0) {
  s21::vector<std::string> s21_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  std::vector<std::string> std_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  s21_vector.insert(s21_vector.begin() + 3, 4, "13");
  std_vector.insert(std_vector.begin() + 3, 4, "13");
  for (size_t i = 0; i < std_vector.size(); ++i) {
    EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Modifiers, test_vector_string_0_1) {
  s21::vector<std::string> s21_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  std::vector<std::string> std_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  s21_vector.clear();
  std_vector.clear();
  for (size_t i = 0; i < s21_vector.size(); i++) {
    EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
  EXPECT_TRUE(*s21_vector.end() == *std_vector.end());
}

TEST(Modifiers, test_vector_string_1) {
  s21::vector<std::string> s21_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  std::vector<std::string> std_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  s21_vector.erase(s21_vector.begin() + 3);
  std_vector.erase(std_vector.begin() + 3);
  for (size_t i = 0; i < std_vector.size(); i++) {
    EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Modifiers, test_vector_string_2) {
  s21::vector<std::string> s21_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  std::vector<std::string> std_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  s21_vector.erase(s21_vector.begin() + 3);
  std_vector.erase(std_vector.begin() + 5);
  for (size_t i = 0; i < s21_vector.size(); i++) {
    if (i == 3 || i == 4) {
      // std::cout << "i = " << i << " " << s21_vector[i] << " != " <<
      // std_vector[i] << std::endl;
      EXPECT_TRUE(s21_vector[i] != std_vector[i]);
    } else {
      // std::cout << "i = " << i << " " << s21_vector[i] << " == " <<
      // std_vector[i] << std::endl;
      EXPECT_TRUE(s21_vector[i] == std_vector[i]);
    }
  }
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Modifiers, test_vector_string_2_1) {
  s21::vector<std::string> s21_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  std::vector<std::string> std_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  s21_vector.erase(s21_vector.begin() + 3, s21_vector.begin() + 8);
  std_vector.erase(std_vector.begin() + 3, std_vector.begin() + 8);
  for (size_t i = 0; i < s21_vector.size(); i++) {
    // std::cout << s21_vector[i] << " =|= " << std_vector[i]<< std::endl;
    EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Modifiers, test_vector_string_3) {
  s21::vector<std::string> s21_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  std::vector<std::string> std_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  std_vector.erase(std_vector.begin());

  for (size_t i = 0; i < s21_vector.capacity() - 1; i++) {
    EXPECT_TRUE(s21_vector[i] != std_vector[i]);
  }

  EXPECT_TRUE(s21_vector.size() != std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Modifiers, test_vector_string_4) {
  std::initializer_list<std::string> data = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  s21::vector<std::string> s21_vector = data;
  std::vector<std::string> std_vector = data;
  std::string test = "aboba";
  s21_vector.push_back(test);
  std_vector.push_back(test);
  for (size_t i = 0; i < s21_vector.size(); i++) {
    EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }

  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Modifiers, test_vector_string_5) {
  s21::vector<std::string> s21_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};
  std::vector<std::string> std_vector = {
      "string_a", "string_b", "string_c", "string_d", "string_e",
      "string_g", "string_i", "string_j", "string_k", "string_l"};

  s21_vector.pop_back();
  std_vector.pop_back();

  for (size_t i = 0; i < s21_vector.size(); i++) {
    EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }

  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Modifiers, test_vector_string_6) {
  s21::vector<std::string> s21_vector_1 = {
      "string", "string", "string", "string", "string",
      "string", "string", "string", "string", "string"};
  s21::vector<std::string> s21_vector_2 = {"aboba", "aboba", "aboba", "aboba",
                                           "aboba", "aboba", "aboba", "aboba",
                                           "aboba", "aboba"};
  s21::vector<std::string> s21_vector_tmp_1(s21_vector_1);
  s21::vector<std::string> s21_vector_tmp_2(s21_vector_2);

  std::vector<std::string> std_vector_1 = {
      "string", "string", "string", "string", "string",
      "string", "string", "string", "string", "string"};
  std::vector<std::string> std_vector_2 = {"aboba", "aboba", "aboba", "aboba",
                                           "aboba", "aboba", "aboba", "aboba",
                                           "aboba", "aboba"};
  std::vector<std::string> std_vector_tmp_1(std_vector_1);
  std::vector<std::string> std_vector_tmp_2(std_vector_2);

  s21_vector_1.swap(s21_vector_2);
  std_vector_1.swap(std_vector_2);

  for (size_t i = 0; i < s21_vector_1.size(); i++) {
    EXPECT_TRUE(s21_vector_1[i] == s21_vector_tmp_2[i]);
    EXPECT_TRUE(s21_vector_2[i] == s21_vector_tmp_1[i]);
  }

  for (size_t i = 0; i < std_vector_1.size(); i++) {
    EXPECT_TRUE(std_vector_1[i] == std_vector_tmp_2[i]);
    EXPECT_TRUE(std_vector_2[i] == std_vector_tmp_1[i]);
  }

  EXPECT_TRUE(s21_vector_1.size() == std_vector_1.size());
  EXPECT_TRUE(s21_vector_1.capacity() == std_vector_2.capacity());
}

TEST(Modifiers, test_vector_string_7) {
  s21::vector<std::string> s21_vector_1 = {"string", "string", "string",
                                           "string", "string"};
  s21::vector<std::string> s21_vector_2 = {"aboba", "aboba", "aboba", "aboba",
                                           "aboba", "aboba", "aboba", "aboba",
                                           "aboba", "aboba"};
  s21::vector<std::string> s21_vector_tmp_1(s21_vector_1);
  s21::vector<std::string> s21_vector_tmp_2(s21_vector_2);

  std::vector<std::string> std_vector_1 = {"string", "string", "string",
                                           "string", "string"};
  std::vector<std::string> std_vector_2 = {"aboba", "aboba", "aboba", "aboba",
                                           "aboba", "aboba", "aboba", "aboba",
                                           "aboba", "aboba"};
  std::vector<std::string> std_vector_tmp_1(std_vector_1);
  std::vector<std::string> std_vector_tmp_2(std_vector_2);

  s21_vector_1.swap(s21_vector_2);
  std_vector_1.swap(std_vector_2);

  for (size_t i = 0; i < s21_vector_1.size(); i++) {
    EXPECT_TRUE(s21_vector_1[i] == s21_vector_tmp_2[i]);
    EXPECT_TRUE(std_vector_1[i] == std_vector_tmp_2[i]);
  }

  for (size_t i = 0; i < s21_vector_2.size(); i++) {
    EXPECT_TRUE(s21_vector_2[i] == s21_vector_tmp_1[i]);
    EXPECT_TRUE(std_vector_2[i] == std_vector_tmp_1[i]);
  }

  EXPECT_TRUE(std_vector_1.size() == std_vector_tmp_2.size());
  EXPECT_TRUE(std_vector_2.size() == std_vector_tmp_1.size());

  EXPECT_TRUE(s21_vector_1.size() == s21_vector_tmp_2.size());
  EXPECT_TRUE(s21_vector_2.size() == s21_vector_tmp_1.size());

  EXPECT_TRUE(s21_vector_1.capacity() == std_vector_1.capacity());
  EXPECT_TRUE(s21_vector_2.capacity() == std_vector_2.capacity());
}

//-------------------------------------------------------------
// bool
//------------------------------------------------------------- MemberFunctions
TEST(MemberFunctions, test_vector_bool_1) {
  s21::vector<bool> s21_vector;
  std::vector<bool> std_vector;
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

// TEST(MemberFunctions, test_vector_bool_2) {
//   EXPECT_ANY_THROW({ s21::vector<bool> s21_vector(-1); });
// }

TEST(MemberFunctions, test_vector_bool_3) {
  EXPECT_NO_THROW({ s21::vector<bool> s21_vector; });
}

TEST(MemberFunctions, test_vector_bool_4) {
  EXPECT_NO_THROW({ s21::vector<bool> s21_vector(13); });
}

TEST(MemberFunctions, test_vector_bool_4_1) {
  s21::vector<bool> s21_vector(70);
  std::vector<bool> std_vector(70);
  // std::cout << "s21 len = " << s21_vector.size() << std::endl;
  // std::cout << "std len = " << std_vector.size() << std::endl;
  // std::cout << "s21 cap = " << s21_vector.capacity() << std::endl;
  // std::cout << "std cap = " << std_vector.capacity() << std::endl;
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(MemberFunctions, test_vector_bool_4_2) {
  s21::vector<bool> s21_vector(130);
  std::vector<bool> std_vector(130);
  for (size_t i = 0; i < s21_vector.size(); ++i) {
    EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }
}

TEST(MemberFunctions, test_vector_bool_5) {
  EXPECT_NO_THROW(
      { s21::vector<bool> s21_vector({0, 1, 0, 0, 1, 1, 1, 0, 0, 1}); });
}

TEST(MemberFunctions, test_vector_bool_6) {
  s21::vector<bool> s21_vector_1({0, 1, 0, 0, 1, 1, 1, 0, 0, 1});
  s21::vector<bool> s21_vector_2(s21_vector_1);
  for (size_t i = 0; i < s21_vector_1.size(); ++i) {
    EXPECT_TRUE(s21_vector_1[i] == s21_vector_2[i]);
  }
}

TEST(MemberFunctions, test_vector_bool_7) {
  s21::vector<bool> s21_vector_1({0, 1, 0, 0, 1, 1, 1, 0, 0, 1});
  s21::vector<bool> s21_vector_2 = s21_vector_1;
  for (size_t i = 0; i < s21_vector_1.size(); ++i) {
    EXPECT_TRUE(s21_vector_1[i] == s21_vector_2[i]);
  }
}

TEST(MemberFunctions, test_vector_bool_8) {
  s21::vector<bool> s21_vector_1({0, 1, 0, 0, 1, 1, 1, 0, 0, 1});
  s21::vector<bool> s21_vector_2;
  s21_vector_2 = std::move(s21_vector_1);
  for (size_t i = 0; i < s21_vector_1.size(); ++i) {
    EXPECT_TRUE(s21_vector_1[i] == s21_vector_2[i]);
  }
}

TEST(MemberFunctions, test_vector_bool_9) {
  s21::vector<bool> s21_vector_1({0, 1, 0, 0, 1, 1, 1, 0, 0, 1});
  bool *p = s21_vector_1.data();
  s21::vector<bool> s21_vector_2(std::move(s21_vector_1));

  // for(size_t i = 0; i < s21_vector_1.size() ; ++i) {
  // EXPECT_TRUE(s21_vector_1[i] == s21_vector_4[i]);
  // }
  EXPECT_TRUE(p == s21_vector_2.data());
}

//------------------------------------------------------------- ElementAccess

TEST(ElementAaccess, test_vector_bool_1) {
  s21::vector<bool> s21_vector({0, 1, 0, 0, 1, 1, 1, 0, 0, 1});
  std::vector<bool> std_vector({0, 1, 0, 0, 1, 1, 1, 0, 0, 1});
  EXPECT_TRUE(s21_vector.at(5) == std_vector.at(5));
}

// TEST(ElementAaccess, test_vector_bool_2) {
//   EXPECT_ANY_THROW({
//     s21::vector<bool> s21_vector({0, 1, 0, 0, 1, 1, 1, 0, 0, 1});
//     s21_vector.at(100);
//   });
// }

// TEST(ElementAaccess, test_vector_bool_3) {
//   EXPECT_ANY_THROW({
//     s21::vector<bool> s21_vector({0, 1, 0, 0, 1, 1, 1, 0, 0, 1});
//     s21_vector.at(-10);
//   });
// }

TEST(ElementAaccess, test_vector_bool_4) {
  s21::vector<bool> s21_vector({0, 1, 0, 0, 1, 1, 1, 0, 0, 1});
  std::vector<bool> std_vector({0, 1, 0, 0, 1, 1, 1, 0, 0, 1});
  // std::cout << "s21 data = " << s21_vector.data() << std::endl;
  // std::cout << "s21 data = " << std_vector.begin() << std::endl;
  // std::cout << s21_vector[i] << " != " << std_vector[i]<< std::endl;
  // std::cout << s21_vector[i] << " == " << std_vector[i]<< std::endl;
  // std::cout << "s21 size = " << s21_vector.size() << std::endl;
  // std::cout << "std size = " << std_vector.size() << std::endl;
  // std::cout << "s21 capa = " << s21_vector.capacity() << std::endl;
  // std::cout << "std capa = " << std_vector.capacity() << std::endl;
  EXPECT_TRUE(*s21_vector.data() == *std_vector.begin());
}
TEST(ElementAaccess, test_vector_bool_5) {
  s21::vector<bool> s21_vector({0, 1, 0, 0, 1, 1, 1, 0, 0, 1});
  std::vector<bool> std_vector({0, 1, 0, 0, 1, 1, 1, 0, 0, 1});
  EXPECT_TRUE(s21_vector[5] == std_vector[5]);
}

TEST(ElementAaccess, test_vector_bool_6) {
  s21::vector<bool> s21_vector({1, 1, 0, 0, 1, 1, 1, 1, 0, 0});
  std::vector<bool> std_vector({1, 1, 0, 0, 1, 1, 1, 1, 0, 0});
  bool my = s21_vector.front();
  bool std = std_vector.front();
  EXPECT_TRUE(my == std);
}

TEST(ElementAaccess, test_vector_bool_7) {
  s21::vector<bool> s21_vector({1, 1, 0, 0, 1, 1, 1, 1, 0, 0});
  std::vector<bool> std_vector({1, 1, 0, 0, 1, 1, 1, 1, 0, 0});
  bool my = s21_vector.back();
  bool std = std_vector.back();
  EXPECT_TRUE(my == std);
}

//------------------------------------------------------------- Iterators

TEST(Iterators, test_vector_bool_1) {
  s21::vector<bool> s21_vector({1, 1, 0, 0, 1, 1, 1, 1, 0, 0});
  std::vector<bool> std_vector({1, 1, 0, 0, 1, 1, 1, 1, 0, 0});
  EXPECT_TRUE(*s21_vector.begin() == *std_vector.begin());
}

TEST(Iterators, test_vector_bool_2) {
  s21::vector<bool> s21_vector({1, 1, 0, 0, 1, 1, 1, 1, 0, 0});
  std::vector<bool> std_vector({1, 1, 0, 0, 1, 1, 1, 1, 0, 0});
  EXPECT_TRUE(*(s21_vector.end() - 1) == *(std_vector.end() - 1));
}

//------------------------------------------------------------- revIterators

TEST(revIterators, test_vector_bool_1) {
  s21::vector<bool> s21_vector({1, 1, 0, 0, 1, 1, 1, 1, 0, 0});
  std::vector<bool> std_vector({1, 1, 0, 0, 1, 1, 1, 1, 0, 0});
  EXPECT_TRUE(*s21_vector.rbegin() == *std_vector.rbegin());
}

TEST(revIterators, test_vector_bool_2) {
  s21::vector<bool> s21_vector({1, 1, 0, 0, 1, 1, 1, 1, 0, 0});
  std::vector<bool> std_vector({1, 1, 0, 0, 1, 1, 1, 1, 0, 0});
  EXPECT_TRUE(*(s21_vector.rend() - 1) == *(std_vector.rend() - 1));
}

//------------------------------------------------------------- Capacity

TEST(Capacity, test_vector_bool_3) {
  s21::vector<bool> s21_vector({1, 1, 0, 0, 1, 1, 1, 1, 0, 0});
  std::vector<bool> std_vector({1, 1, 0, 0, 1, 1, 1, 1, 0, 0});
  EXPECT_TRUE(s21_vector.empty() == std_vector.empty());
}

TEST(Capacity, test_vector_bool_4) {
  s21::vector<bool> s21_vector;
  std::vector<bool> std_vector;
  EXPECT_TRUE(s21_vector.empty() == std_vector.empty());
}

TEST(Capacity, test_vector_bool_5) {
  s21::vector<bool> s21_vector({1, 1, 0, 0, 1, 1, 1, 1, 0, 0});
  std::vector<bool> std_vector({1, 1, 0, 0, 1, 1, 1, 1, 0, 0});
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
}

TEST(Capacity, test_vector_bool_6) {
  s21::vector<bool> s21_vector({1, 1, 0, 0, 1, 1, 1, 1, 0, 0});
  std::vector<bool> std_vector({1, 1, 0, 0, 1, 1, 1, 1, 0, 0});
  // std::cout << "s21 max_size = " << s21_vector.max_size() << std::endl;
  // std::cout << "std max_size = " << std_vector.max_size() << std::endl;
  EXPECT_TRUE(s21_vector.max_size() == std_vector.max_size());
}

TEST(Capacity, test_vector_bool_7) {
  s21::vector<bool> s21_vector({1, 1, 0, 0, 1, 1, 1, 1, 0, 0});
  std::vector<bool> std_vector({1, 1, 0, 0, 1, 1, 1, 1, 0, 0});
  s21_vector.reserve(s21_vector.size() + s21_vector.capacity());
  std_vector.reserve(std_vector.size() + std_vector.capacity());

  EXPECT_TRUE(s21_vector.size() == std_vector.size());
}

TEST(Capacity, test_vector_bool_7_1) {
  s21::vector<bool> s21_vector({1, 1, 0, 0, 1, 1, 1, 1, 0, 0});
  std::vector<bool> std_vector({1, 1, 0, 0, 1, 1, 1, 1, 0, 0});
  s21_vector.reserve(s21_vector.size() / 2);
  std_vector.reserve(std_vector.size() / 2);
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
}

// TEST(Capacity, test_vector_bool_7_2) {
//   s21::vector<bool> s21_vector({1, 1, 0, 0, 1, 1, 1, 1, 0, 0});
//   std::vector<bool> std_vector({1, 1, 0, 0, 1, 1, 1, 1, 0, 0});
//   EXPECT_ANY_THROW({ s21::vector<bool> s21_vector(-1); });
//   EXPECT_ANY_THROW({ std::vector<bool> std_vector(-1); });
// }

TEST(Capacity, test_vector_bool_8) {
  s21::vector<bool> s21_vector({1, 1, 0, 0, 1, 1, 1, 1, 0, 0});
  std::vector<bool> std_vector({1, 1, 0, 0, 1, 1, 1, 1, 0, 0});
  s21_vector.reserve(s21_vector.size() + s21_vector.capacity());
  std_vector.reserve(std_vector.size() + std_vector.capacity());
  s21_vector.insert(s21_vector.begin() + 3, 13);
  std_vector.insert(std_vector.begin() + 3, 13);
  s21_vector.shrink_to_fit();
  std_vector.shrink_to_fit();
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Capacity, test_vector_bool_9) {
  s21::vector<bool> s21_vector({1, 1, 0, 0, 1, 1, 1, 1, 0, 0});
  std::vector<bool> std_vector({1, 1, 0, 0, 1, 1, 1, 1, 0, 0});
  s21_vector.reserve(s21_vector.size() + s21_vector.capacity());
  std_vector.reserve(std_vector.size() + std_vector.capacity());
  s21_vector.insert(s21_vector.begin() + 14, 13);
  std_vector.insert(std_vector.begin() + 13, 13);
  s21_vector.shrink_to_fit();
  std_vector.shrink_to_fit();
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Capacity, test_vector_bool_10) {
  s21::vector<bool> s21_vector({1, 1, 0, 0, 1, 1, 1, 1, 0, 0});
  std::vector<bool> std_vector({1, 1, 0, 0, 1, 1, 1, 1, 0, 0});
  s21_vector.resize(s21_vector.size() + s21_vector.capacity());
  std_vector.resize(std_vector.size() + std_vector.capacity());
  for (size_t i = 0; i < s21_vector.size(); ++i) {
    EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
}

TEST(Capacity, test_vector_bool_11) {
  s21::vector<bool> s21_vector({1, 1, 0, 0, 1, 1, 1, 1, 0, 0});
  std::vector<bool> std_vector({1, 1, 0, 0, 1, 1, 1, 1, 0, 0});
  s21_vector.resize(s21_vector.size() / 2);
  std_vector.resize(std_vector.size() / 2);
  for (size_t i = 0; i < s21_vector.size(); ++i) {
    EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
}

//--------------------------------------------------- Vector Modifiers

TEST(Modifiers, test_vector_bool_0) {
  s21::vector<bool> s21_vector({1, 1, 0, 0, 1, 1, 1, 1, 0, 0});
  std::vector<bool> std_vector({1, 1, 0, 0, 1, 1, 1, 1, 0, 0});
  s21_vector.reserve(s21_vector.size() + s21_vector.capacity());
  std_vector.reserve(std_vector.size() + std_vector.capacity());
  s21_vector.insert(s21_vector.begin() + 3, 13);
  s21_vector.shrink_to_fit();
  std_vector.shrink_to_fit();
  EXPECT_TRUE(s21_vector.size() != std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Modifiers, test_vector_bool_0_0) {
  s21::vector<bool> s21_vector({1, 1, 0, 0, 1, 1, 1, 1, 0, 0});
  std::vector<bool> std_vector({1, 1, 0, 0, 1, 1, 1, 1, 0, 0});
  s21_vector.insert(s21_vector.begin() + 3, 4, 13);
  std_vector.insert(std_vector.begin() + 3, 4, 13);
  for (size_t i = 0; i < std_vector.size(); ++i) {
    EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Modifiers, test_vector_bool_0_1) {
  s21::vector<bool> s21_vector({1, 1, 0, 0, 1, 1, 1, 1, 0, 0});
  std::vector<bool> std_vector({1, 1, 0, 0, 1, 1, 1, 1, 0, 0});
  // size_t len = s21_vector.size();
  s21_vector.clear();
  std_vector.clear();
  //  for(size_t i = 0; i < len; i ++) {
  //   EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  // }
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
  EXPECT_TRUE(*s21_vector.end() == *std_vector.end());
}

TEST(Modifiers, test_vector_bool_1) {
  s21::vector<bool> s21_vector({1, 1, 0, 0, 1, 1, 1, 1, 0, 0});
  std::vector<bool> std_vector({1, 1, 0, 0, 1, 1, 1, 1, 0, 0});
  s21_vector.erase(s21_vector.begin() + 3);
  std_vector.erase(std_vector.begin() + 3);
  for (size_t i = 0; i < std_vector.size(); i++) {
    EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }
  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Modifiers, test_vector_bool_2) {
  s21::vector<bool> s21_vector({1, 0, 1, 0, 1, 0, 1, 0, 1, 0});
  std::vector<bool> std_vector({1, 0, 1, 0, 1, 0, 1, 0, 1, 0});
  s21_vector.erase(s21_vector.begin() + 3);
  std_vector.erase(std_vector.begin() + 5);
  for (size_t i = 0; i < s21_vector.size(); i++) {
    if (i == 3 || i == 4) {
      EXPECT_TRUE(s21_vector[i] != std_vector[i]);
    } else {
      EXPECT_TRUE(s21_vector[i] == std_vector[i]);
    }
  }

  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Modifiers, test_vector_bool_2_1) {
  s21::vector<bool> s21_vector({1, 0, 1, 0, 1, 0, 1, 0, 1, 0});
  std::vector<bool> std_vector({1, 0, 1, 0, 1, 0, 1, 0, 1, 0});
  s21_vector.erase(s21_vector.begin() + 3, s21_vector.begin() + 8);
  std_vector.erase(std_vector.begin() + 3, std_vector.begin() + 8);

  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Modifiers, test_vector_bool_3) {
  s21::vector<bool> s21_vector({1, 0, 1, 0, 1, 0, 1, 0, 1, 0});
  std::vector<bool> std_vector({1, 0, 1, 0, 1, 0, 1, 0, 1, 0});
  std_vector.erase(std_vector.begin());

  for (size_t i = 0; i < s21_vector.size() - 1; i++) {
    EXPECT_TRUE(s21_vector[i] != std_vector[i]);
  }

  EXPECT_TRUE(s21_vector.size() != std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Modifiers, test_vector_bool_4) {
  s21::vector<bool> s21_vector({1, 0, 1, 0, 1, 0, 1, 0, 1, 0});
  std::vector<bool> std_vector({1, 0, 1, 0, 1, 0, 1, 0, 1, 0});
  s21_vector.push_back(1);
  std_vector.push_back(1);
  for (size_t i = 0; i < s21_vector.size(); i++) {
    EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }

  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Modifiers, test_vector_bool_5) {
  s21::vector<bool> s21_vector({1, 1, 0, 0, 1, 1, 1, 1, 0, 0});
  std::vector<bool> std_vector({1, 1, 0, 0, 1, 1, 1, 1, 0, 0});

  s21_vector.pop_back();
  std_vector.pop_back();

  for (size_t i = 0; i < s21_vector.size(); i++) {
    EXPECT_TRUE(s21_vector[i] == std_vector[i]);
  }

  EXPECT_TRUE(s21_vector.size() == std_vector.size());
  EXPECT_TRUE(s21_vector.capacity() == std_vector.capacity());
}

TEST(Modifiers, test_vector_bool_6) {
  s21::vector<bool> s21_vector_1({1, 1, 1, 1, 1, 1, 1, 1, 1, 1});
  s21::vector<bool> s21_vector_2({0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
  s21::vector<bool> s21_vector_tmp_1(s21_vector_1);
  s21::vector<bool> s21_vector_tmp_2(s21_vector_2);

  std::vector<bool> std_vector_1({1, 1, 1, 1, 1, 1, 1, 1, 1, 1});
  std::vector<bool> std_vector_2({0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
  std::vector<bool> std_vector_tmp_1(std_vector_1);
  std::vector<bool> std_vector_tmp_2(std_vector_2);

  s21_vector_1.swap(s21_vector_2);
  std_vector_1.swap(std_vector_2);

  for (size_t i = 0; i < s21_vector_1.size(); i++) {
    EXPECT_TRUE(s21_vector_1[i] == s21_vector_tmp_2[i]);
    EXPECT_TRUE(s21_vector_2[i] == s21_vector_tmp_1[i]);
  }

  for (size_t i = 0; i < std_vector_1.size(); i++) {
    EXPECT_TRUE(std_vector_1[i] == std_vector_tmp_2[i]);
    EXPECT_TRUE(std_vector_2[i] == std_vector_tmp_1[i]);
  }

  EXPECT_TRUE(s21_vector_1.size() == std_vector_1.size());
  EXPECT_TRUE(s21_vector_1.capacity() == std_vector_2.capacity());
}

TEST(Modifiers, test_vector_bool_7) {
  s21::vector<bool> s21_vector_1({1, 1, 1, 1, 1});
  s21::vector<bool> s21_vector_2({0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
  s21::vector<bool> s21_vector_tmp_1(s21_vector_1);
  s21::vector<bool> s21_vector_tmp_2(s21_vector_2);

  std::vector<bool> std_vector_1({1, 1, 1, 1, 1});
  std::vector<bool> std_vector_2({0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
  std::vector<bool> std_vector_tmp_1(std_vector_1);
  std::vector<bool> std_vector_tmp_2(std_vector_2);

  s21_vector_1.swap(s21_vector_2);
  std_vector_1.swap(std_vector_2);

  for (size_t i = 0; i < s21_vector_1.size(); i++) {
    EXPECT_TRUE(s21_vector_1[i] == s21_vector_tmp_2[i]);
    EXPECT_TRUE(std_vector_1[i] == std_vector_tmp_2[i]);
  }

  for (size_t i = 0; i < s21_vector_2.size(); i++) {
    EXPECT_TRUE(s21_vector_2[i] == s21_vector_tmp_1[i]);
    EXPECT_TRUE(std_vector_2[i] == std_vector_tmp_1[i]);
  }

  EXPECT_TRUE(std_vector_1.size() == std_vector_tmp_2.size());
  EXPECT_TRUE(std_vector_2.size() == std_vector_tmp_1.size());

  EXPECT_TRUE(s21_vector_1.size() == s21_vector_tmp_2.size());
  EXPECT_TRUE(s21_vector_2.size() == s21_vector_tmp_1.size());

  EXPECT_TRUE(s21_vector_1.capacity() == std_vector_1.capacity());
  EXPECT_TRUE(s21_vector_2.capacity() == std_vector_2.capacity());
}

//-------------------------------------------------------------
