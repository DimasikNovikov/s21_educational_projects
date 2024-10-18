#include <stack>

#include "my_test.h"

TEST(Stack, DefaultConstructor) {
  s21::Stack<int> s21_s;
  std::stack<int> std_s;

  EXPECT_EQ(s21_s.Size(), std_s.size());
  EXPECT_EQ(s21_s.Empty(), std_s.empty());
}

TEST(Stack, InitializerListConstructor) {
  s21::Stack<int> s21_s{1, 2, 3};
  std::stack<int> std_s({1, 2, 3});

  EXPECT_EQ(s21_s.Size(), std_s.size());
  EXPECT_EQ(s21_s.Empty(), std_s.empty());
  EXPECT_EQ(s21_s.Top(), std_s.top());

  s21_s.Push(5);
  s21_s.Push(5);
  std_s.push(5);
  std_s.push(5);

  EXPECT_EQ(s21_s.Size(), std_s.size());
  EXPECT_EQ(s21_s.Empty(), std_s.empty());
  EXPECT_EQ(s21_s.Top(), std_s.top());

  s21_s.Pop();
  std_s.pop();

  EXPECT_EQ(s21_s.Size(), std_s.size());
  EXPECT_EQ(s21_s.Empty(), std_s.empty());
  EXPECT_EQ(s21_s.Top(), std_s.top());
}

TEST(Stack, CopyConstructor) {
  s21::Stack<double> s21_s{1.1, 2.22, 3.333};
  s21::Stack<double> s21_s_copy(s21_s);

  std::stack<double> std_s({1.1, 2.22, 3.333});
  std::stack<double> std_s_copy(std_s);

  EXPECT_EQ(s21_s_copy.Size(), std_s_copy.size());
  EXPECT_EQ(s21_s_copy.Empty(), std_s_copy.empty());
  EXPECT_EQ(s21_s_copy.Top(), std_s_copy.top());

  EXPECT_EQ(s21_s.Size(), std_s.size());
  EXPECT_EQ(s21_s.Empty(), std_s.empty());
  EXPECT_EQ(s21_s.Top(), std_s.top());
}

TEST(Stack, CopyAssignmentOperator) {
  s21::Stack<double> s21_s{1.1, 2.22, 3.333};
  s21::Stack<double> s21_s_copy;
  s21_s_copy = s21_s;

  std::stack<double> std_s({1.1, 2.22, 3.333});
  std::stack<double> std_s_copy;
  std_s_copy = std_s;

  EXPECT_EQ(s21_s_copy.Size(), std_s_copy.size());
  EXPECT_EQ(s21_s_copy.Empty(), std_s_copy.empty());
  EXPECT_EQ(s21_s_copy.Top(), std_s_copy.top());

  EXPECT_EQ(s21_s.Size(), std_s.size());
  EXPECT_EQ(s21_s.Empty(), std_s.empty());
  EXPECT_EQ(s21_s.Top(), std_s.top());
}

TEST(Stack, MoveConstructor) {
  s21::Stack<double> s21_s{1.1, 2.22, 3.333};
  s21::Stack<double> s21_s_copy(std::move(s21_s));

  std::stack<double> std_s({1.1, 2.22, 3.333});
  std::stack<double> std_s_copy(std::move(std_s));

  EXPECT_EQ(s21_s_copy.Size(), std_s_copy.size());
  EXPECT_EQ(s21_s_copy.Empty(), std_s_copy.empty());
  EXPECT_EQ(s21_s_copy.Top(), std_s_copy.top());

  EXPECT_EQ(s21_s.Size(), std_s.size());
  EXPECT_EQ(s21_s.Empty(), std_s.empty());
}

TEST(Stack, MoveAssignmentOperator) {
  s21::Stack<double> s21_s{1.1, 2.22, 3.333};
  s21::Stack<double> s21_s_copy;
  s21_s_copy = std::move(s21_s);

  std::stack<double> std_s({1.1, 2.22, 3.333});
  std::stack<double> std_s_copy;
  std_s_copy = std::move(std_s);

  EXPECT_EQ(s21_s_copy.Size(), std_s_copy.size());
  EXPECT_EQ(s21_s_copy.Empty(), std_s_copy.empty());
  EXPECT_EQ(s21_s_copy.Top(), std_s_copy.top());

  EXPECT_EQ(s21_s.Size(), std_s.size());
  EXPECT_EQ(s21_s.Empty(), std_s.empty());
}

TEST(Stack, Swap) {
  s21::Stack<double> s21_s1{1.1, 2.22, 3.333};
  s21::Stack<double> s21_s2{100.999};

  std::stack<double> std_s1({1.1, 2.22, 3.333});
  std::stack<double> std_s2({100.999});

  EXPECT_EQ(s21_s1.Size(), std_s1.size());
  EXPECT_EQ(s21_s1.Empty(), std_s1.empty());
  EXPECT_EQ(s21_s1.Top(), std_s1.top());

  EXPECT_EQ(s21_s2.Size(), std_s2.size());
  EXPECT_EQ(s21_s2.Empty(), std_s2.empty());
  EXPECT_EQ(s21_s2.Top(), std_s2.top());
}

TEST(Stack, InsertManyBack) {
  s21::Stack<const char*> s21_s;

  s21_s.Push("Dragon");

  s21_s.Insert_many_back("I am", "The Great", "God");

  EXPECT_EQ(s21_s.Top(), "God");
  EXPECT_EQ(s21_s.Size(), 4);
}
