#include <gtest/gtest.h>

#include <list>
#include <queue>
#include <string>

#include "../s21_containers.h"

using namespace s21;

TEST(listqueueTest, DefaultConstructor) {
  s21::queue<int, list<int>> queue_1;
  std::queue<int, std::list<int>> queue_2;
  EXPECT_EQ(queue_1.size(), queue_2.size());
  EXPECT_EQ(queue_1.empty(), queue_2.empty());
}

TEST(queueTest, ConstructorInitializerList) {
  s21::queue<std::string> queue_1{"1", "1", "1", "1"};
  std::queue<std::string, std::list<std::string>> queue_2;
  queue_2.push("1");
  queue_2.push("1");
  queue_2.push("1");
  queue_2.push("1");

  EXPECT_EQ(queue_1.size(), queue_2.size());
  while (!(queue_1.empty())) {
    EXPECT_EQ(queue_1.back(), queue_2.back());
    queue_1.pop();
    queue_2.pop();
  }
}

TEST(queueTest, InitializerListConstructor) {
  s21::queue<int, list<int>> queue_1{1, 2, 3};
  const long unsigned int a = 3;
  EXPECT_EQ(queue_1.size(), a);
  EXPECT_EQ(queue_1.front(), 1);
  EXPECT_EQ(queue_1.back(), 3);
}

TEST(queueTest, CopyConstructor) {
  s21::queue<std::string> queue_1{"10", "20", "30", "40"};
  s21::queue<std::string> queue_2(queue_1);
  EXPECT_EQ(queue_1.size(), queue_2.size());
  while (!(queue_1.empty())) {
    EXPECT_EQ(queue_1.back(), queue_2.back());
    queue_1.pop();
    queue_2.pop();
  }
}

TEST(queueTest, MoveConstructor) {
  s21::queue<std::string> queue_1{"10", "20", "30", "40"};
  s21::queue<std::string> queue_2(std::move(queue_1));
  const long unsigned int a = 0;
  const long unsigned int b = 4;
  EXPECT_EQ(queue_1.size(), a);
  EXPECT_EQ(queue_2.size(), b);
}

TEST(queueTest, MoveConstructor2) {
  s21::queue<int, list<int>> queue_1{1, 2, 3};
  s21::queue<int, list<int>> queue_2(std::move(queue_1));
  EXPECT_TRUE(queue_1.empty());
  const long unsigned int a = 3;
  EXPECT_EQ(queue_2.size(), a);
  EXPECT_EQ(queue_2.front(), 1);
  EXPECT_EQ(queue_2.back(), 3);
}

TEST(queueTest, MoveOperator) {
  s21::queue<std::string> queue_1{"10", "20", "30", "40"};
  s21::queue<std::string> queue_2(std::move(queue_1));
  const long unsigned int a = 0;
  const long unsigned int b = 4;
  EXPECT_EQ(queue_1.size(), a);
  EXPECT_EQ(queue_2.size(), b);
}

TEST(queueTest, MoveOperator_2) {
  s21::queue<int, list<int>> queue_1{1, 2, 3};
  s21::queue<int, list<int>> queue_2;
  queue_2 = std::move(queue_1);
  EXPECT_TRUE(queue_1.empty());
  const long unsigned int a = 3;
  EXPECT_EQ(queue_2.size(), a);
  EXPECT_EQ(queue_2.front(), 1);
  EXPECT_EQ(queue_2.back(), 3);
}

TEST(queueTest, Push) {
  s21::queue<int, list<int>> queue_1;
  queue_1.push(10);
  queue_1.push(20);
  const long unsigned int a = 2;
  EXPECT_EQ(queue_1.size(), a);
  EXPECT_EQ(queue_1.front(), 10);
  EXPECT_EQ(queue_1.back(), 20);
}

TEST(queueTest, Pop) {
  s21::queue<int, list<int>> queue_1{1, 2, 3};
  queue_1.pop();
  const long unsigned int a = 2;
  EXPECT_EQ(queue_1.size(), a);
  EXPECT_EQ(queue_1.front(), 2);
  EXPECT_EQ(queue_1.back(), 3);
}

TEST(queueTest, Front) {
  s21::queue<int, list<int>> queue_1{1, 2, 3};
  EXPECT_EQ(queue_1.front(), 1);
}

TEST(queueTest, Back) {
  s21::queue<int, list<int>> queue_1{1, 2, 3};
  EXPECT_EQ(queue_1.back(), 3);
}

TEST(queueTest, Empty) {
  s21::queue<int, list<int>> queue_1;
  EXPECT_TRUE(queue_1.empty());
  queue_1.push(1);
  EXPECT_FALSE(queue_1.empty());
}

TEST(queueTest, Size) {
  s21::queue<int, list<int>> queue_1{1, 2, 3};
  const long unsigned int a = 3;
  EXPECT_EQ(queue_1.size(), a);
  queue_1.pop();
  const long unsigned int b = 2;
  EXPECT_EQ(queue_1.size(), b);
}

TEST(queueTest, Swap) {
  s21::queue<int, list<int>> queue_1{1, 2, 3};
  s21::queue<int, list<int>> queue_2{4, 5};
  queue_1.swap(queue_2);
  const long unsigned int a = 2;
  const long unsigned int b = 3;
  EXPECT_EQ(queue_1.size(), a);
  EXPECT_EQ(queue_1.front(), 4);
  EXPECT_EQ(queue_1.back(), 5);
  EXPECT_EQ(queue_2.size(), b);
  EXPECT_EQ(queue_2.front(), 1);
  EXPECT_EQ(queue_2.back(), 3);
}

TEST(queueTest, InsertManyBack) {
  s21::queue<int, list<int>> queue_1{1, 2, 3};
  queue_1.insert_many_back(4, 5, 6);
  const long unsigned int a = 6;
  EXPECT_EQ(queue_1.size(), a);
  EXPECT_EQ(queue_1.back(), 6);
  queue_1.pop();
  EXPECT_EQ(queue_1.front(), 2);
}