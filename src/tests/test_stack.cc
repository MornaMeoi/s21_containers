#include <gtest/gtest.h>

#include <stack>

#include "../s21_containers.h"

using namespace s21;

TEST(StackTest, ConstructorDefault) {
  s21::stack<int, list<int>> stack;
  std::stack<int> std_stack;
  EXPECT_EQ(stack.size(), std_stack.size());
}

TEST(StackTest, ConstructorInitializerList_1) {
  s21::stack<int, list<int>> stack{1, 2, 4};
  const long unsigned int a = 3;
  EXPECT_EQ(stack.size(), a);
  EXPECT_EQ(stack.top(), 4);
}

TEST(StackTest, ConstructorInitializerList_2) {
  std::initializer_list<int> b;
  s21::stack<int, list<int>> stack{b};
  std::stack<int> std_stack{b};
  EXPECT_EQ(stack.size(), std_stack.size());
}

TEST(StackTest, ConstructorCopy_1) {
  std::initializer_list<int> il1 = {1, 2, 3};
  s21::stack<int, list<int>> stack{il1};
  s21::stack<int, list<int>> stack_copy{stack};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_copy{std_stack};
  EXPECT_EQ(stack_copy.size(), std_stack_copy.size());
  EXPECT_EQ(stack_copy.top(), std_stack_copy.top());
}

TEST(StackTest, ConstructorMove_1) {
  std::initializer_list<int> il1 = {1, 2, 3};
  s21::stack<int, list<int>> stack{il1};
  s21::stack<int, list<int>> stack_move{stack};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_move{std_stack};
  EXPECT_EQ(stack_move.size(), std_stack_move.size());
  EXPECT_EQ(stack_move.top(), std_stack_move.top());
}

TEST(StackTest, OpertatorMove_1) {
  std::initializer_list<int> il1 = {1, 2, 3};
  std::initializer_list<int> il2 = {4, 5, 6, 7};

  s21::stack<int, list<int>> stack{il1};
  s21::stack<int, list<int>> stack_move{il2};
  stack = std::move(stack_move);

  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_move{il2};
  std_stack = std::move(std_stack_move);

  EXPECT_EQ(stack.size(), std_stack.size());
  EXPECT_EQ(stack.top(), std_stack.top());
}

TEST(StackTest, OpertatorMove_2) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};
  std::initializer_list<int> il2 = {1, 2, 3};

  s21::stack<int, list<int>> stack{il1};
  s21::stack<int, list<int>> stack_move{il2};
  stack = std::move(stack_move);

  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_move{il2};
  std_stack = std::move(std_stack_move);

  EXPECT_EQ(stack.size(), std_stack.size());
  EXPECT_EQ(stack.top(), std_stack.top());
}

TEST(StackTest, OpertatorMove_3) {
  std::initializer_list<int> il1;
  std::initializer_list<int> il2 = {4, 5, 6, 7};

  s21::stack<int, list<int>> stack{il1};
  s21::stack<int, list<int>> stack_move{il2};
  stack = std::move(stack_move);

  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_move{il2};
  std_stack = std::move(std_stack_move);

  EXPECT_EQ(stack.size(), std_stack.size());
  EXPECT_EQ(stack.top(), std_stack.top());
}

TEST(StackTest, Top_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};
  s21::stack<int, list<int>> stack{il1};
  std::stack<int> std_stack{il1};
  EXPECT_EQ(stack.top(), std_stack.top());
}

TEST(StackTest, Empty_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};
  s21::stack<int, list<int>> stack{il1};
  std::stack<int> std_stack{il1};
  EXPECT_EQ(stack.empty(), std_stack.empty());
}

TEST(StackTest, Empty_2) {
  std::initializer_list<int> il1;
  s21::stack<int, list<int>> stack{il1};
  std::stack<int> std_stack{il1};
  EXPECT_EQ(stack.empty(), std_stack.empty());
}

TEST(StackTest, Size_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};
  s21::stack<int, list<int>> stack{il1};
  std::stack<int> std_stack{il1};
  EXPECT_EQ(stack.size(), std_stack.size());
}

TEST(StackTest, Size_2) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};
  s21::stack<int, list<int>> stack{il1};
  std::stack<int> std_stack{il1};
  EXPECT_EQ(stack.size(), std_stack.size());
}

TEST(StackTest, Push_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};
  s21::stack<int, list<int>> stack{il1};
  std::stack<int> std_stack{il1};
  stack.push(1);
  std_stack.push(1);
  EXPECT_EQ(stack.size(), std_stack.size());
  EXPECT_EQ(stack.top(), std_stack.top());
}

TEST(StackTest, Push_2) {
  std::initializer_list<int> il1;
  s21::stack<int, list<int>> stack{il1};
  std::stack<int> std_stack{il1};
  stack.push(1);
  std_stack.push(1);
  EXPECT_EQ(stack.size(), std_stack.size());
  EXPECT_EQ(stack.top(), std_stack.top());
}

TEST(StackTest, Pop_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};
  s21::stack<int, list<int>> stack{il1};
  std::stack<int> std_stack{il1};
  stack.pop();
  std_stack.pop();
  EXPECT_EQ(stack.size(), std_stack.size());
  EXPECT_EQ(stack.top(), std_stack.top());
}

TEST(StackTest, Swap_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};
  std::initializer_list<int> il2 = {1, 2, 3};
  s21::stack<int, list<int>> stack{il1};
  s21::stack<int, list<int>> stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  stack.swap(stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(stack.size(), std_stack.size());
  EXPECT_EQ(stack.top(), std_stack.top());

  EXPECT_EQ(stack_swap.size(), std_stack_swap.size());
  EXPECT_EQ(stack_swap.top(), std_stack_swap.top());
}

TEST(StackTest, Swap_2) {
  std::initializer_list<int> il1 = {1, 2, 3};
  std::initializer_list<int> il2 = {4, 5, 6, 7};

  s21::stack<int, list<int>> stack{il1};
  s21::stack<int, list<int>> stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  stack.swap(stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(stack.size(), std_stack.size());
  EXPECT_EQ(stack.top(), std_stack.top());

  EXPECT_EQ(stack_swap.size(), std_stack_swap.size());
  EXPECT_EQ(stack_swap.top(), std_stack_swap.top());
}

TEST(StackTest, Swap_3) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};
  std::initializer_list<int> il2;

  s21::stack<int, list<int>> stack{il1};
  s21::stack<int, list<int>> stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  stack.swap(stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(stack.size(), std_stack.size());

  EXPECT_EQ(stack_swap.size(), std_stack_swap.size());
}

TEST(StackTest, Swap_4) {
  std::initializer_list<int> il1;
  std::initializer_list<int> il2 = {4, 5, 6, 7};

  s21::stack<int, list<int>> stack{il1};
  s21::stack<int, list<int>> stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  stack.swap(stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(stack.size(), std_stack.size());

  EXPECT_EQ(stack_swap.size(), std_stack_swap.size());
}

TEST(StackTest, Swap_5) {
  std::initializer_list<int> il1;
  std::initializer_list<int> il2;

  s21::stack<int, list<int>> stack{il1};
  s21::stack<int, list<int>> stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  stack.swap(stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(stack.size(), std_stack.size());

  EXPECT_EQ(stack_swap.size(), std_stack_swap.size());
}

TEST(StackTest, Swap_6) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};
  std::initializer_list<int> il2 = {4, 5, 6, 7};

  s21::stack<int> stack{il1};
  s21::stack<int, list<int>> stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  stack.swap(stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(stack.size(), std_stack.size());
  EXPECT_EQ(stack.top(), std_stack.top());

  EXPECT_EQ(stack_swap.size(), std_stack_swap.size());
  EXPECT_EQ(stack_swap.top(), std_stack_swap.top());
}

TEST(StackTest, InsertManyBack) {
  s21::stack<int, list<int>> stack{1, 2, 3};
  stack.insert_many_back(4, 5, 6);
  const long unsigned int a = 6;
  EXPECT_EQ(stack.size(), a);
  EXPECT_EQ(stack.top(), 6);
  stack.pop();
  EXPECT_EQ(stack.top(), 5);
}