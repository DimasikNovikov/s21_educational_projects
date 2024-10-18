#include <list>
#include <set>
#include <utility>
#include <vector>

#include "my_test.h"

TEST(Set, DefaultConstrustor) {
  s21::Set<int> s21_s;
  std::set<int> std_s;

  EXPECT_EQ(s21_s.Empty(), std_s.empty());
  EXPECT_EQ(s21_s.Size(), std_s.size());
}

TEST(Set, MaxSize) {
  s21::Set<int> s21_s;
  std::list<int> std_s;

  EXPECT_EQ(s21_s.Max_size(), std_s.max_size());
}

TEST(Set, ItitializerListConstructorInt) {
  s21::Set<int> s21_s{1, 3, 54, 33, 1, 43, 34, 43};
  std::set<int> std_s{1, 3, 54, 33, 1, 43, 34, 43};

  EXPECT_EQ(s21_s.Empty(), std_s.empty());
  EXPECT_EQ(s21_s.Size(), std_s.size());

  auto s21_iter = s21_s.Begin();
  auto std_iter = std_s.begin();

  while (s21_iter != s21_s.End()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    s21_iter++;
    std_iter++;
  }
}

TEST(Set, ItitializerListConstructorDouble) {
  s21::Set<double> s21_s{45.123, 3.89,  2.12,  45.123,
                         1.11,   8.321, 9.222, 10.321};

  std::set<double> std_s{45.123, 3.89,  2.12,  45.123,
                         1.11,   8.321, 9.222, 10.321};

  EXPECT_EQ(s21_s.Empty(), std_s.empty());
  EXPECT_EQ(s21_s.Size(), std_s.size());

  auto s21_iter = s21_s.Begin();
  auto std_iter = std_s.begin();

  while (s21_iter != s21_s.End()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    s21_iter++;
    std_iter++;
  }
}

TEST(Set, ItitializerListConstructorChar) {
  s21::Set<char> s21_s{'t', 'e', 't', 'w', '[', 'a', '1'};

  std::set<char> std_s{'t', 'e', 't', 'w', '[', 'a', '1'};

  EXPECT_EQ(s21_s.Empty(), std_s.empty());
  EXPECT_EQ(s21_s.Size(), std_s.size());

  auto s21_iter = s21_s.Begin();
  auto std_iter = std_s.begin();

  while (s21_iter != s21_s.End()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    s21_iter++;
    std_iter++;
  }
}

TEST(Set, CopyConstructor) {
  s21::Set<int> s21_s{3, 1, 4, 1, 5};
  s21::Set<int> s21_s_copy(s21_s);

  std::set<int> std_s({3, 1, 4, 1, 5});
  std::set<int> std_s_copy(std_s);

  EXPECT_EQ(s21_s_copy.Empty(), std_s_copy.empty());
  EXPECT_EQ(s21_s_copy.Size(), std_s_copy.size());

  auto s21_iter = s21_s_copy.Begin();
  auto std_iter = std_s_copy.begin();

  while (s21_iter != s21_s_copy.End()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    s21_iter++;
    std_iter++;
  }
}

TEST(Set, MoveConstructor) {
  s21::Set<int> s21_s{3, 1, 4, 1, 5};
  s21::Set<int> s21_s_copy(std::move(s21_s));

  std::set<int> std_s({3, 1, 4, 1, 5});
  std::set<int> std_s_copy(std::move(std_s));

  EXPECT_EQ(s21_s_copy.Empty(), std_s_copy.empty());
  EXPECT_EQ(s21_s_copy.Size(), std_s_copy.size());

  auto s21_iter = s21_s_copy.Begin();
  auto std_iter = std_s_copy.begin();

  while (s21_iter != s21_s_copy.End()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    s21_iter++;
    std_iter++;
  }

  EXPECT_EQ(s21_s.Empty(), std_s.empty());
  EXPECT_EQ(s21_s.Size(), std_s.size());
}

TEST(Set, CopyAssignmentOperator) {
  s21::Set<int> s21_s{3, 1, 4, 1, 5};
  s21::Set<int> s21_s_copy;
  s21_s_copy = s21_s;

  std::set<int> std_s({3, 1, 4, 1, 5});
  std::set<int> std_s_copy;
  std_s_copy = std_s;

  EXPECT_EQ(s21_s_copy.Empty(), std_s_copy.empty());
  EXPECT_EQ(s21_s_copy.Size(), std_s_copy.size());

  auto s21_iter = s21_s_copy.Begin();
  auto std_iter = std_s_copy.begin();

  while (s21_iter != s21_s_copy.End()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    s21_iter++;
    std_iter++;
  }
}

TEST(Set, MoveAssignmentOperator) {
  s21::Set<int> s21_s{3, 1, 4, 1, 5};
  s21::Set<int> s21_s_copy;
  s21_s_copy = std::move(s21_s);

  std::set<int> std_s({3, 1, 4, 1, 5});
  std::set<int> std_s_copy;
  std_s_copy = std::move(std_s);

  EXPECT_EQ(s21_s_copy.Empty(), std_s_copy.empty());
  EXPECT_EQ(s21_s_copy.Size(), std_s_copy.size());

  auto s21_iter = s21_s_copy.Begin();
  auto std_iter = std_s_copy.begin();

  while (s21_iter != s21_s_copy.End()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    s21_iter++;
    std_iter++;
  }

  EXPECT_EQ(s21_s.Empty(), std_s.empty());
  EXPECT_EQ(s21_s.Size(), std_s.size());
}

TEST(Set, Clear) {
  s21::Set<int> s21_s{9, 30, 11, 34, 54};
  std::set<int> std_s{9, 30, 11, 34, 54};

  s21_s.Clear();
  std_s.clear();

  EXPECT_EQ(s21_s.Size(), std_s.size());
  EXPECT_EQ(s21_s.Empty(), std_s.empty());
}

TEST(Set, Swap) {
  s21::Set<char> s21_s1{'a', '3', '4', 'i', '!', '*', '('};
  s21::Set<char> s21_s2{'e', 'q', 'e', 'q'};
  std::set<char> std_s1{'a', '3', '4', 'i', '!', '*', '('};
  std::set<char> std_s2{'e', 'q', 'e', 'q'};

  s21_s1.Swap(s21_s2);
  std_s1.swap(std_s2);

  EXPECT_EQ(s21_s1.Empty(), std_s1.empty());
  EXPECT_EQ(s21_s1.Size(), std_s1.size());

  auto s21_iter = s21_s1.Begin();
  auto std_iter = std_s1.begin();

  while (s21_iter != s21_s1.End()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    s21_iter++;
    std_iter++;
  }

  EXPECT_EQ(s21_s2.Empty(), std_s2.empty());
  EXPECT_EQ(s21_s2.Size(), std_s2.size());

  s21_iter = s21_s2.Begin();
  std_iter = std_s2.begin();

  while (s21_iter != s21_s2.End()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    s21_iter++;
    std_iter++;
  }
}

TEST(Set, Merge) {
  s21::Set<char> s21_s1{'a', '3', '4', 'i', '!', '*', '('};
  s21::Set<char> s21_s2{'e', 'q', 'e', 'q'};
  std::set<char> std_s1{'a', '3', '4', 'i', '!', '*', '('};
  std::set<char> std_s2{'e', 'q', 'e', 'q'};

  s21_s1.Merge(s21_s2);
  std_s1.merge(std_s2);

  EXPECT_EQ(s21_s1.Empty(), std_s1.empty());
  EXPECT_EQ(s21_s1.Size(), std_s1.size());

  auto s21_iter = s21_s1.Begin();
  auto std_iter = std_s1.begin();

  while (s21_iter != s21_s1.End()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    s21_iter++;
    std_iter++;
  }

  EXPECT_EQ(s21_s2.Empty(), std_s2.empty());
  EXPECT_EQ(s21_s2.Size(), std_s2.size());
}

TEST(Set, Insert) {
  s21::Set<int> s21_s{10, 3, 4, 8, 0, 11};
  std::set<int> std_s{10, 3, 4, 8, 0, 11};

  auto s21_pair1 = s21_s.Insert(2);
  auto std_pair1 = std_s.insert(2);

  EXPECT_EQ(s21_s.Empty(), std_s.empty());
  EXPECT_EQ(s21_s.Size(), std_s.size());

  auto s21_pair2 = s21_s.Insert(4);
  auto std_pair2 = std_s.insert(4);

  EXPECT_EQ(s21_s.Empty(), std_s.empty());
  EXPECT_EQ(s21_s.Size(), std_s.size());

  EXPECT_EQ(s21_pair1.second, std_pair1.second);
  EXPECT_EQ(s21_pair2.second, std_pair2.second);
  EXPECT_EQ(*s21_pair1.first, *std_pair1.first);
  EXPECT_EQ(*s21_pair2.first, *std_pair2.first);

  auto s21_iter = s21_s.Begin();
  auto std_iter = std_s.begin();

  while (s21_iter != s21_s.End()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    s21_iter++;
    std_iter++;
  }
}

TEST(Set, Erase) {
  s21::Set<double> s21_s{10.11, 3.12, 4.13, 8.14, 0.15, 11.16};
  std::set<double> std_s{10.11, 3.12, 4.13, 8.14, 0.15, 11.16};

  auto s21_it = s21_s.Begin();
  auto std_it = std_s.begin();
  ++s21_it;
  ++s21_it;
  ++std_it;
  ++std_it;

  s21_s.Erase(s21_it);
  std_s.erase(std_it);

  EXPECT_EQ(s21_s.Empty(), std_s.empty());
  EXPECT_EQ(s21_s.Size(), std_s.size());

  auto s21_iter = s21_s.Begin();
  auto std_iter = std_s.begin();

  while (s21_iter != s21_s.End()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    s21_iter++;
    std_iter++;
  }
}

TEST(Set, Find1) {
  s21::Set<double> s21_s{10.11, 3.12, 4.13, 8.14, 0.15, 11.16};
  std::set<double> std_s{10.11, 3.12, 4.13, 8.14, 0.15, 11.16};

  auto s21_it = s21_s.Find(8.14);
  auto std_it = std_s.find(8.14);

  s21_s.Erase(s21_it);
  std_s.erase(std_it);

  EXPECT_EQ(s21_s.Empty(), std_s.empty());
  EXPECT_EQ(s21_s.Size(), std_s.size());

  auto s21_iter = s21_s.Begin();
  auto std_iter = std_s.begin();

  while (s21_iter != s21_s.End()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    s21_iter++;
    std_iter++;
  }
}

TEST(Set, Find2) {
  s21::Set<double> s21_s{10.11, 3.12, 4.13, 8.14, 0.15, 11.16};
  std::set<double> std_s{10.11, 3.12, 4.13, 8.14, 0.15, 11.16};

  EXPECT_EQ(s21_s.Empty(), std_s.empty());
  EXPECT_EQ(s21_s.Size(), std_s.size());

  EXPECT_EQ(*s21_s.Find(8.14), *std_s.find(8.14));
  EXPECT_EQ(s21_s.Find(1).iter_list.node_ptr_, nullptr);
  EXPECT_EQ(*s21_s.Find(11.16), *std_s.find(11.16));
}

TEST(Set, Contains) {
  s21::Set<char> s21_s{'a', '3', '4', 'i', '!', '*', '('};

  EXPECT_EQ(s21_s.Contains('4'), true);
  EXPECT_EQ(s21_s.Contains('Y'), false);
}

TEST(Set, InsertMany) {
  s21::Set<int> s21_s{10, 3, 0, 11};
  s21::Set<int> check1{10, 3, 0, 11, 1, 3, 5, 7};
  int check2[]{0, 1, 3, 5, 7, 10, 11};
  std::vector<std::pair<typename s21::Set<int>::iterator, bool>> vect;
  vect = s21_s.Insert_many(1, 3, 5, 7);

  EXPECT_EQ(s21_s.Size(), 7);

  EXPECT_EQ(*vect[0].first, 1);
  EXPECT_EQ(vect[0].second, true);
  EXPECT_EQ(*vect[1].first, 3);
  EXPECT_EQ(vect[1].second, false);
  EXPECT_EQ(*vect[2].first, 5);
  EXPECT_EQ(vect[2].second, true);
  EXPECT_EQ(*vect[3].first, 7);
  EXPECT_EQ(vect[3].second, true);

  auto s21_iter = s21_s.Begin();
  auto check1_iter = check1.Begin();
  size_t i = 0;

  while (s21_iter != s21_s.End()) {
    EXPECT_EQ(*s21_iter, *check1_iter);
    EXPECT_EQ(*s21_iter, check2[i]);
    s21_iter++;
    check1_iter++;
    i++;
  }
}