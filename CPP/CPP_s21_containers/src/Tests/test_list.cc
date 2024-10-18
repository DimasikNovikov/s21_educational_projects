#include <list>

#include "my_test.h"

TEST(List, DefaultConstructor) {
  s21::List<int> s21_list;
  std::list<int> std_list;

  EXPECT_EQ(s21_list.Empty(), std_list.empty());
  EXPECT_EQ(s21_list.Size(), std_list.size());
}

TEST(List, ParameterizedConstructor) {
  s21::List<int> s21_list(5);
  std::list<int> std_list(5);

  EXPECT_EQ(s21_list.Size(), std_list.size());
  EXPECT_EQ(s21_list.Empty(), std_list.empty());
}

TEST(List, InitializeListConstructor) {
  s21::List<int> s21_list{1, 2, 3};
  std::list<int> std_list{1, 2, 3};

  EXPECT_EQ(s21_list.Front(), std_list.front());
  EXPECT_EQ(s21_list.Back(), std_list.back());
  EXPECT_EQ(s21_list.Size(), std_list.size());
  EXPECT_EQ(s21_list.Empty(), std_list.empty());

  auto s21_iter{s21_list.Begin()};
  auto std_iter{std_list.begin()};
  while (s21_iter != s21_list.End() && std_iter != std_list.end()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    s21_iter++;
    std_iter++;
  }
}

TEST(List, CopyConstructor) {
  s21::List<double> s21_list{1.1, 2.2, 3.3};
  std::list<double> std_list{1.1, 2.2, 3.3};

  s21::List<double> s21_list_copy(s21_list);
  std::list<double> std_list_copy(std_list);

  EXPECT_EQ(s21_list.Size(), std_list.size());
  EXPECT_EQ(s21_list.Empty(), std_list.empty());

  auto s21_iter{s21_list.Begin()};
  auto std_iter{std_list.begin()};
  while (s21_iter != s21_list.End() && std_iter != std_list.end()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    s21_iter++;
    std_iter++;
  }
}

TEST(List, CopyAssignmentOperator) {
  s21::List<double> s21_list{1.1, 2.2, 3.3};
  std::list<double> std_list{1.1, 2.2, 3.3};

  s21::List<double> s21_list_copy;
  s21_list_copy = s21_list;
  std::list<double> std_list_copy;
  std_list_copy = std_list;

  EXPECT_EQ(s21_list.Size(), std_list.size());
  EXPECT_EQ(s21_list.Empty(), std_list.empty());

  auto s21_iter{s21_list.Begin()};
  auto std_iter{std_list.begin()};
  while (s21_iter != s21_list.End() && std_iter != std_list.end()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    s21_iter++;
    std_iter++;
  }
}

TEST(List, MoveConstructor) {
  s21::List<char> s21_list{'a', 'b', 'c'};
  std::list<char> std_list{'a', 'b', 'c'};

  s21::List<char> s21_list_copy(std::move(s21_list));
  std::list<char> std_list_copy(std::move(std_list));

  EXPECT_EQ(s21_list.Size(), std_list.size());
  EXPECT_EQ(s21_list.Empty(), std_list.empty());

  EXPECT_EQ(s21_list_copy.Size(), std_list_copy.size());
  EXPECT_EQ(s21_list_copy.Empty(), std_list_copy.empty());

  auto s21_iter{s21_list_copy.Begin()};
  auto std_iter{std_list_copy.begin()};
  while (s21_iter != s21_list_copy.End() && std_iter != std_list_copy.end()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    s21_iter++;
    std_iter++;
  }
}

TEST(List, MoveAssignmentOperator) {
  s21::List<double> s21_list{1.1, 2.2, 3.3};
  std::list<double> std_list{1.1, 2.2, 3.3};

  s21::List<double> s21_list_copy;
  s21_list_copy = std::move(s21_list);
  std::list<double> std_list_copy;
  std_list_copy = std::move(std_list);

  EXPECT_EQ(s21_list.Size(), std_list.size());
  EXPECT_EQ(s21_list.Empty(), std_list.empty());

  EXPECT_EQ(s21_list_copy.Size(), std_list_copy.size());
  EXPECT_EQ(s21_list_copy.Empty(), std_list_copy.empty());

  auto s21_iter{s21_list_copy.Begin()};
  auto std_iter{std_list_copy.begin()};
  while (s21_iter != s21_list_copy.End() && std_iter != std_list_copy.end()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    s21_iter++;
    std_iter++;
  }
}

TEST(List, MaxSize) {
  s21::List<int> s21_list;
  std::list<int> std_list;

  EXPECT_EQ(s21_list.Max_size(), std_list.max_size());
}

TEST(List, Clear) {
  s21::List<char> s21_list{'a', 'b', 'c'};
  std::list<char> std_list{'a', 'b', 'c'};

  s21_list.Clear();
  std_list.clear();

  EXPECT_EQ(s21_list.Size(), std_list.size());
  EXPECT_EQ(s21_list.Empty(), std_list.empty());
}

TEST(List, Insert) {
  s21::List<int> s21_list{100, 100, 100};
  std::list<int> std_list{100, 100, 100};

  s21_list.Insert(s21_list.Begin(), 200);
  s21_list.Insert(s21_list.Begin(), 300);
  s21_list.Insert(s21_list.Begin()++, 400);
  s21_list.Insert(++s21_list.Begin(), 400);
  s21_list.Insert(s21_list.End(), 500);
  std_list.insert(std_list.begin(), 200);
  std_list.insert(std_list.begin(), 300);
  std_list.insert(std_list.begin()++, 400);
  std_list.insert(++std_list.begin(), 400);
  std_list.insert(std_list.end(), 500);

  EXPECT_EQ(s21_list.Size(), std_list.size());
  EXPECT_EQ(s21_list.Empty(), std_list.empty());

  auto s21_iter{s21_list.Begin()};
  auto std_iter{std_list.begin()};
  while (s21_iter != s21_list.End() && std_iter != std_list.end()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    s21_iter++;
    std_iter++;
  }
}

TEST(List, PopBack) {
  s21::List<int> s21_list{100, 200, 300};
  std::list<int> std_list{100, 200, 300};

  s21_list.Pop_back();
  s21_list.Pop_back();
  std_list.pop_back();
  std_list.pop_back();

  EXPECT_EQ(s21_list.Size(), std_list.size());
  EXPECT_EQ(s21_list.Empty(), std_list.empty());

  auto s21_iter{s21_list.Begin()};
  auto std_iter{std_list.begin()};
  while (s21_iter != s21_list.End() && std_iter != std_list.end()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    s21_iter++;
    std_iter++;
  }

  s21_list.Pop_back();
  std_list.pop_back();

  EXPECT_EQ(s21_list.Size(), std_list.size());
  EXPECT_EQ(s21_list.Empty(), std_list.empty());
}

TEST(List, PushFront) {
  s21::List<int> s21_list;
  std::list<int> std_list;

  s21_list.Push_front(10);
  std_list.push_front(10);

  EXPECT_EQ(s21_list.Size(), std_list.size());
  EXPECT_EQ(s21_list.Empty(), std_list.empty());

  auto s21_iter{s21_list.Begin()};
  auto std_iter{std_list.begin()};
  while (s21_iter != s21_list.End() && std_iter != std_list.end()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    s21_iter++;
    std_iter++;
  }
}

TEST(List, PopFront) {
  s21::List<int> s21_list{100, 200, 300};
  std::list<int> std_list{100, 200, 300};

  s21_list.Pop_front();
  s21_list.Pop_front();
  std_list.pop_front();
  std_list.pop_front();

  EXPECT_EQ(s21_list.Size(), std_list.size());
  EXPECT_EQ(s21_list.Empty(), std_list.empty());

  auto s21_iter{s21_list.Begin()};
  auto std_iter{std_list.begin()};
  while (s21_iter != s21_list.End() && std_iter != std_list.end()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    s21_iter++;
    std_iter++;
  }

  s21_list.Pop_front();
  std_list.pop_front();

  EXPECT_EQ(s21_list.Size(), std_list.size());
  EXPECT_EQ(s21_list.Empty(), std_list.empty());
}

TEST(List, Erase) {
  s21::List<const char*> s21_list{"Hello", "Hi", "Hey", "What's up!", "Holla"};
  std::list<const char*> std_list{"Hello", "Hi", "Hey", "What's up!", "Holla"};

  s21_list.Erase(s21_list.Begin());
  s21_list.Erase(s21_list.Begin()++);
  std_list.erase(std_list.begin());
  std_list.erase(std_list.begin()++);

  EXPECT_EQ(s21_list.Size(), std_list.size());
  EXPECT_EQ(s21_list.Empty(), std_list.empty());

  auto s21_iter{s21_list.Begin()};
  auto std_iter{std_list.begin()};
  while (s21_iter != s21_list.End() && std_iter != std_list.end()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    s21_iter++;
    std_iter++;
  }
}

TEST(List, EraseHead) {
  s21::List<const char*> s21_list{"Hello"};
  std::list<const char*> std_list{"Hello"};

  s21_list.Erase(s21_list.Begin());
  std_list.erase(std_list.begin());

  EXPECT_EQ(s21_list.Size(), std_list.size());
  EXPECT_EQ(s21_list.Empty(), std_list.empty());
}

TEST(List, EraseTail) {
  s21::List<const char*> s21_list{"Hello", "Hi"};
  std::list<const char*> std_list{"Hello", "Hi"};

  s21_list.Erase(++s21_list.Begin());
  std_list.erase(++std_list.begin());

  EXPECT_EQ(s21_list.Size(), std_list.size());
  EXPECT_EQ(s21_list.Empty(), std_list.empty());
}

TEST(List, Swap) {
  s21::List<int> s21_list1{1, 2, 3};
  s21::List<int> s21_list2{4, 5};
  std::list<int> std_list1{1, 2, 3};
  std::list<int> std_list2{4, 5};

  s21_list1.Swap(s21_list2);
  std_list1.swap(std_list2);

  EXPECT_EQ(s21_list1.Size(), std_list1.size());
  EXPECT_EQ(s21_list2.Size(), std_list2.size());

  auto s21_iter{s21_list1.Begin()};
  auto std_iter{std_list1.begin()};
  while (s21_iter != s21_list1.End() && std_iter != std_list1.end()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    s21_iter++;
    std_iter++;
  }

  s21_iter = s21_list2.Begin();
  std_iter = std_list2.begin();
  while (s21_iter != s21_list2.End() && std_iter != std_list2.end()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    s21_iter++;
    std_iter++;
  }
}

TEST(List, Sort) {
  s21::List<int> s21_list{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
  std::list<int> std_list{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};

  s21_list.Sort();
  std_list.sort();

  EXPECT_EQ(s21_list.Size(), std_list.size());

  auto s21_iter{s21_list.Begin()};
  auto std_iter{std_list.begin()};
  while (s21_iter != s21_list.End() && std_iter != std_list.end()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    s21_iter++;
    std_iter++;
  }
}

TEST(List, Merge) {
  s21::List<int> s21_list1{5, 9, 1, 3, 3};
  s21::List<int> s21_list2{8, 7, 2, 3, 4, 4};

  std::list<int> std_list1{5, 9, 1, 3, 3};
  std::list<int> std_list2{8, 7, 2, 3, 4, 4};

  s21_list1.Sort();
  s21_list2.Sort();
  std_list1.sort();
  std_list2.sort();

  s21_list1.Merge(s21_list2);
  std_list1.merge(std_list2);

  EXPECT_EQ(s21_list1.Size(), std_list1.size());
  EXPECT_EQ(s21_list2.Size(), std_list2.size());

  auto s21_iter{s21_list1.Begin()};
  auto std_iter{std_list1.begin()};
  while (s21_iter != s21_list1.End() && std_iter != std_list1.end()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    s21_iter++;
    std_iter++;
  }
}

TEST(List, SpliceMiddle) {
  s21::List<int> s21_list1{1, 2, 3, 4, 5};
  s21::List<int> s21_list2{10, 20, 30, 40, 50};

  std::list<int> std_list1{1, 2, 3, 4, 5};
  std::list<int> std_list2{10, 20, 30, 40, 50};

  auto s21_it = s21_list1.CBegin();
  auto std_it = std_list1.begin();
  s21_it++;
  s21_it++;
  std_it++;
  std_it++;

  s21_list1.Splice(s21_it, s21_list2);
  std_list1.splice(std_it, std_list2);

  EXPECT_EQ(s21_list1.Size(), std_list1.size());
  EXPECT_EQ(s21_list2.Size(), std_list2.size());

  auto s21_iter{s21_list1.Begin()};
  auto std_iter{std_list1.begin()};
  while (s21_iter != s21_list1.End() && std_iter != std_list1.end()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    s21_iter++;
    std_iter++;
  }
}

TEST(List, SpliceEnd) {
  s21::List<int> s21_list1{1, 2};
  s21::List<int> s21_list2{10, 20, 30, 40, 50};

  std::list<int> std_list1{1, 2};
  std::list<int> std_list2{10, 20, 30, 40, 50};

  auto s21_it = s21_list1.CEnd();
  auto std_it = std_list1.end();

  s21_list1.Splice(s21_it, s21_list2);
  std_list1.splice(std_it, std_list2);

  EXPECT_EQ(s21_list1.Size(), std_list1.size());
  EXPECT_EQ(s21_list2.Size(), std_list2.size());

  auto s21_iter{s21_list1.Begin()};
  auto std_iter{std_list1.begin()};
  while (s21_iter != s21_list1.End() && std_iter != std_list1.end()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    s21_iter++;
    std_iter++;
  }
}

TEST(List, SpliceHead) {
  s21::List<int> s21_list1{1, 2};
  s21::List<int> s21_list2{10, 20, 30, 40, 50};

  std::list<int> std_list1{1, 2};
  std::list<int> std_list2{10, 20, 30, 40, 50};

  auto s21_it = s21_list1.CBegin();
  auto std_it = std_list1.begin();

  s21_list1.Splice(s21_it, s21_list2);
  std_list1.splice(std_it, std_list2);

  EXPECT_EQ(s21_list1.Size(), std_list1.size());
  EXPECT_EQ(s21_list2.Size(), std_list2.size());

  auto s21_iter{s21_list1.Begin()};
  auto std_iter{std_list1.begin()};
  while (s21_iter != s21_list1.End() && std_iter != std_list1.end()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    s21_iter++;
    std_iter++;
  }
}

TEST(List, SpliceThisEmpty) {
  s21::List<int> s21_list1;
  s21::List<int> s21_list2{10, 20, 30, 40, 50};

  std::list<int> std_list1;
  std::list<int> std_list2{10, 20, 30, 40, 50};

  auto s21_it = s21_list1.CBegin();
  auto std_it = std_list1.begin();

  s21_list1.Splice(s21_it, s21_list2);
  std_list1.splice(std_it, std_list2);

  EXPECT_EQ(s21_list1.Size(), std_list1.size());
  EXPECT_EQ(s21_list2.Size(), std_list2.size());

  auto s21_iter{s21_list1.Begin()};
  auto std_iter{std_list1.begin()};
  while (s21_iter != s21_list1.End() && std_iter != std_list1.end()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    s21_iter++;
    std_iter++;
  }
}

TEST(List, Reverse) {
  s21::List<int> s21_list{1, 2, 3, 4, 5};
  std::list<int> std_list{1, 2, 3, 4, 5};
  s21_list.Reverse();
  std_list.reverse();

  EXPECT_EQ(s21_list.Size(), std_list.size());

  auto s21_iter{s21_list.Begin()};
  auto std_iter{std_list.begin()};
  while (s21_iter != s21_list.End() && std_iter != std_list.end()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    s21_iter++;
    std_iter++;
  }
}

TEST(List, Unique) {
  s21::List<int> s21_list{1, 2, 2, 3, 3, 2, 1, 1, 2};
  std::list<int> std_list{1, 2, 2, 3, 3, 2, 1, 1, 2};

  s21_list.Unique();
  std_list.unique();

  EXPECT_EQ(s21_list.Size(), std_list.size());

  auto s21_iter{s21_list.Begin()};
  auto std_iter{std_list.begin()};
  while (s21_iter != s21_list.End() && std_iter != std_list.end()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    s21_iter++;
    std_iter++;
  }
}

TEST(List, InsertMany) {
  s21::List<const char*> s21_list;
  std::list<const char*> std_list;

  const char* two{"two"};
  const char* three{"three"};

  s21_list.Insert_many(s21_list.CEnd(), "one", two, std::move(three));
  std_list.emplace(std_list.end(), "one");
  std_list.emplace(std_list.end(), two);
  std_list.emplace(std_list.end(), std::move(three));

  EXPECT_EQ(s21_list.Size(), std_list.size());

  auto s21_iter{s21_list.Begin()};
  auto std_iter{std_list.begin()};
  while (s21_iter != s21_list.End() && std_iter != std_list.end()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    s21_iter++;
    std_iter++;
  }
}

TEST(List, InsertManyBack) {
  s21::List<int> s21_list{1, 2, 3, 4, 5};
  s21::List<int> s21_check{1, 2, 3, 4, 5, 7, 8, 9};

  s21_list.Insert_many_back(7, 8, 9);

  EXPECT_EQ(s21_list.Size(), 8);

  auto s21_iter{s21_list.Begin()};
  auto std_iter{s21_check.Begin()};
  while (s21_iter != s21_list.End() && std_iter != s21_check.End()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    s21_iter++;
    std_iter++;
  }
}

TEST(List, Insert_Many_Front) {
  s21::List<int> s21_list{1, 2, 3, 4, 5};
  s21::List<int> s21_check{9, 8, 7, 1, 2, 3, 4, 5};

  s21_list.Insert_many_front(7, 8, 9);

  EXPECT_EQ(s21_list.Size(), 8);

  auto s21_iter{s21_list.Begin()};
  auto std_iter{s21_check.Begin()};
  while (s21_iter != s21_list.End() && std_iter != s21_check.End()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    s21_iter++;
    std_iter++;
  }
}
