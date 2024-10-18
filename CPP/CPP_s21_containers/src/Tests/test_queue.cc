#include <queue>

#include "my_test.h"

TEST(Queue, DefaultConstructor) {
  s21::Queue<int> s21_q;
  std::queue<int> std_q;

  EXPECT_EQ(s21_q.Empty(), std_q.empty());
  EXPECT_EQ(s21_q.Size(), std_q.size());

  s21_q.Push(5);
  std_q.push(5);

  EXPECT_EQ(s21_q.Empty(), std_q.empty());
  EXPECT_EQ(s21_q.Size(), std_q.size());
  EXPECT_EQ(s21_q.Front(), std_q.front());
  EXPECT_EQ(s21_q.Back(), std_q.back());
}

TEST(Queue, InitListConstructor) {
  s21::Queue<int> s21_q{3, 1, 4, 1, 5};
  std::queue<int> std_q({3, 1, 4, 1, 5});

  EXPECT_EQ(s21_q.Empty(), std_q.empty());
  EXPECT_EQ(s21_q.Size(), std_q.size());
  EXPECT_EQ(s21_q.Front(), std_q.front());
  EXPECT_EQ(s21_q.Back(), std_q.back());

  s21_q.Pop();
  std_q.pop();

  EXPECT_EQ(s21_q.Empty(), std_q.empty());
  EXPECT_EQ(s21_q.Size(), std_q.size());
  EXPECT_EQ(s21_q.Front(), std_q.front());
  EXPECT_EQ(s21_q.Back(), std_q.back());
}

TEST(Queue, CopyConstructor) {
  s21::Queue<int> s21_q{3, 1, 4, 1, 5};
  s21::Queue<int> s21_q_copy(s21_q);

  std::queue<int> std_q({3, 1, 4, 1, 5});
  std::queue<int> std_q_copy(std_q);

  EXPECT_EQ(s21_q_copy.Empty(), std_q_copy.empty());
  EXPECT_EQ(s21_q_copy.Size(), std_q_copy.size());
  EXPECT_EQ(s21_q_copy.Front(), std_q_copy.front());
  EXPECT_EQ(s21_q_copy.Back(), std_q_copy.back());
}

TEST(Queue, MoveConstructor) {
  s21::Queue<int> s21_q{3, 1, 4, 1, 5};
  s21::Queue<int> s21_q_copy(std::move(s21_q));

  std::queue<int> std_q({3, 1, 4, 1, 5});
  std::queue<int> std_q_copy(std::move(std_q));

  EXPECT_EQ(s21_q_copy.Empty(), std_q_copy.empty());
  EXPECT_EQ(s21_q_copy.Size(), std_q_copy.size());
  EXPECT_EQ(s21_q_copy.Front(), std_q_copy.front());
  EXPECT_EQ(s21_q_copy.Back(), std_q_copy.back());

  EXPECT_EQ(s21_q.Empty(), std_q.empty());
  EXPECT_EQ(s21_q.Size(), std_q.size());
}

TEST(Queue, CopyAssignmentOperator) {
  s21::Queue<int> s21_q{3, 1, 4, 1, 5};
  s21::Queue<int> s21_q_copy;
  s21_q_copy = s21_q;

  std::queue<int> std_q({3, 1, 4, 1, 5});
  std::queue<int> std_q_copy;
  std_q_copy = std_q;

  EXPECT_EQ(s21_q_copy.Empty(), std_q_copy.empty());
  EXPECT_EQ(s21_q_copy.Size(), std_q_copy.size());
  EXPECT_EQ(s21_q_copy.Front(), std_q_copy.front());
  EXPECT_EQ(s21_q_copy.Back(), std_q_copy.back());
}

TEST(Queue, MoveAssignmentOperator) {
  s21::Queue<int> s21_q{3, 1, 4, 1, 5};
  s21::Queue<int> s21_q_copy;
  s21_q_copy = std::move(s21_q);

  std::queue<int> std_q({3, 1, 4, 1, 5});
  std::queue<int> std_q_copy;
  std_q_copy = std::move(std_q);

  EXPECT_EQ(s21_q_copy.Empty(), std_q_copy.empty());
  EXPECT_EQ(s21_q_copy.Size(), std_q_copy.size());
  EXPECT_EQ(s21_q_copy.Front(), std_q_copy.front());
  EXPECT_EQ(s21_q_copy.Back(), std_q_copy.back());

  EXPECT_EQ(s21_q.Empty(), std_q.empty());
  EXPECT_EQ(s21_q.Size(), std_q.size());
}

TEST(Queue, Swap) {
  s21::Queue<char> s21_q1{'1', '2', '3', '4', '5'};
  s21::Queue<char> s21_q2{'A', 'B', 'C'};
  std::queue<char> std_q1({'1', '2', '3', '4', '5'});
  std::queue<char> std_q2({'A', 'B', 'C'});

  s21_q1.Swap(s21_q2);
  std_q1.swap(std_q2);

  EXPECT_EQ(s21_q1.Empty(), std_q1.empty());
  EXPECT_EQ(s21_q1.Size(), std_q1.size());
  EXPECT_EQ(s21_q1.Front(), std_q1.front());
  EXPECT_EQ(s21_q1.Back(), std_q1.back());

  EXPECT_EQ(s21_q2.Empty(), std_q2.empty());
  EXPECT_EQ(s21_q2.Size(), std_q2.size());
  EXPECT_EQ(s21_q2.Front(), std_q2.front());
  EXPECT_EQ(s21_q2.Back(), std_q2.back());
}

TEST(Queue, InsertManyBack) {
  s21::Queue<int> s21_q;
  s21_q.Insert_many_back(30, 8, 2024);
  EXPECT_EQ(s21_q.Size(), 3);
  EXPECT_EQ(s21_q.Front(), 30);
  EXPECT_EQ(s21_q.Back(), 2024);

  s21::Queue<int> s21_q1{100, 200, 300};
  s21_q1.Insert_many_back(30, 8, 2024);
  EXPECT_EQ(s21_q1.Size(), 6);
  EXPECT_EQ(s21_q1.Front(), 100);
  EXPECT_EQ(s21_q1.Back(), 2024);
}