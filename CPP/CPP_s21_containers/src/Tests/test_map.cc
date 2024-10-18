#include <list>
#include <utility>

#include "my_test.h"

TEST(Map, DefaultConstructor) {
  s21::Map<int, char> s21_map;
  std::map<int, char> std_map;

  EXPECT_EQ(s21_map.Empty(), std_map.empty());
  EXPECT_EQ(s21_map.Size(), std_map.size());
}

TEST(Map, MaxSize) {
  s21::Map<int, char> s21_map;
  std::list<std::pair<int, char>> std_map;

  EXPECT_EQ(s21_map.Max_size(), std_map.max_size());
}

TEST(Map, ItitializerListConstructor) {
  s21::Map<int, char> s21_m{
      {14, 'r'}, {2, 'u'}, {19, 's'}, {92, 'l'}, {14, 'a'}};
  std::map<int, char> std_m{
      {14, 'r'}, {2, 'u'}, {19, 's'}, {92, 'l'}, {14, 'a'}};

  EXPECT_EQ(s21_m.Empty(), std_m.empty());
  EXPECT_EQ(s21_m.Size(), std_m.size());

  auto s21_iter = s21_m.Begin();
  auto std_iter = std_m.begin();

  while (s21_iter != s21_m.End()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    EXPECT_EQ(s21_iter->first, std_iter->first);
    EXPECT_EQ(s21_iter->second, std_iter->second);

    s21_iter++;
    std_iter++;
  }
}

TEST(Map, CopyConstructor) {
  s21::Map<int, char> s21_m{
      {14, 'r'}, {2, 'u'}, {19, 's'}, {92, 'l'}, {14, 'a'}};

  s21::Map<int, char> s21_m_copy(s21_m);

  std::map<int, char> std_m{
      {14, 'r'}, {2, 'u'}, {19, 's'}, {92, 'l'}, {14, 'a'}};
  std::map<int, char> std_m_copy(std_m);

  EXPECT_EQ(s21_m_copy.Empty(), std_m_copy.empty());
  EXPECT_EQ(s21_m_copy.Size(), std_m_copy.size());

  auto s21_iter = s21_m_copy.Begin();
  auto std_iter = std_m_copy.begin();

  while (s21_iter != s21_m_copy.End()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    s21_iter++;
    std_iter++;
  }
}

TEST(Map, MoveConstructor) {
  s21::Map<int, char> s21_m{
      {14, 'r'}, {2, 'u'}, {19, 's'}, {92, 'l'}, {14, 'a'}};

  s21::Map<int, char> s21_m_copy(std::move(s21_m));

  std::map<int, char> std_m{
      {14, 'r'}, {2, 'u'}, {19, 's'}, {92, 'l'}, {14, 'a'}};
  std::map<int, char> std_m_copy(std::move(std_m));

  EXPECT_EQ(s21_m_copy.Empty(), std_m_copy.empty());
  EXPECT_EQ(s21_m_copy.Size(), std_m_copy.size());

  auto s21_iter = s21_m_copy.Begin();
  auto std_iter = std_m_copy.begin();

  while (s21_iter != s21_m_copy.End()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    s21_iter++;
    std_iter++;
  }
}

TEST(Map, CopyAssignmentOperator) {
  s21::Map<int, char> s21_m{
      {14, 'r'}, {2, 'u'}, {19, 's'}, {92, 'l'}, {14, 'a'}};

  s21::Map<int, char> s21_m_copy;
  s21_m_copy = s21_m;

  std::map<int, char> std_m{
      {14, 'r'}, {2, 'u'}, {19, 's'}, {92, 'l'}, {14, 'a'}};
  std::map<int, char> std_m_copy;
  std_m_copy = std_m;

  EXPECT_EQ(s21_m_copy.Empty(), std_m_copy.empty());
  EXPECT_EQ(s21_m_copy.Size(), std_m_copy.size());

  auto s21_iter = s21_m_copy.Begin();
  auto std_iter = std_m_copy.begin();

  while (s21_iter != s21_m_copy.End()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    s21_iter++;
    std_iter++;
  }
}

TEST(Map, MoveAssignmentOperator) {
  s21::Map<int, char> s21_m{
      {14, 'r'}, {2, 'u'}, {19, 's'}, {92, 'l'}, {14, 'a'}};

  s21::Map<int, char> s21_m_copy;
  s21_m_copy = std::move(s21_m);

  std::map<int, char> std_m{
      {14, 'r'}, {2, 'u'}, {19, 's'}, {92, 'l'}, {14, 'a'}};
  std::map<int, char> std_m_copy;
  std_m_copy = std::move(std_m);

  EXPECT_EQ(s21_m_copy.Empty(), std_m_copy.empty());
  EXPECT_EQ(s21_m_copy.Size(), std_m_copy.size());

  auto s21_iter = s21_m_copy.Begin();
  auto std_iter = std_m_copy.begin();

  while (s21_iter != s21_m_copy.End()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    s21_iter++;
    std_iter++;
  }
}

TEST(Map, ContainsInEmptyMap) {
  s21::Map<int, char> s21_map;
  EXPECT_FALSE(s21_map.Contains(5));
}

TEST(Map, ContainsInFilledMap) {
  s21::Map<int, char> s21_m{
      {14, 'r'}, {2, 'u'}, {19, 's'}, {92, 'l'}, {14, 'a'}};
  EXPECT_FALSE(s21_m.Contains(5));
  EXPECT_TRUE(s21_m.Contains(19));
}

TEST(Map, InsertPair) {
  s21::Map<int, char> s21_map;
  std::map<int, char> std_map;

  auto s21_check1 = s21_map.Insert({10, 'a'});
  s21_map.Insert({14, 'b'});
  s21_map.Insert({2, 'k'});
  auto s21_check2 = s21_map.Insert({14, 'k'});

  auto std_check1 = std_map.insert({10, 'a'});
  std_map.insert({14, 'b'});
  std_map.insert({2, 'k'});
  auto std_check2 = std_map.insert({14, 'k'});

  EXPECT_EQ(s21_map.Empty(), std_map.empty());
  EXPECT_EQ(s21_map.Size(), std_map.size());

  auto s21_iter = s21_map.Begin();
  auto std_iter = std_map.begin();

  while (s21_iter != s21_map.End()) {
    EXPECT_EQ(*s21_iter, *std_iter);

    s21_iter++;
    std_iter++;
  }

  EXPECT_EQ(*s21_check1.first, *std_check1.first);
  EXPECT_EQ(s21_check1.second, std_check1.second);
  EXPECT_EQ(*s21_check2.first, *std_check2.first);
  EXPECT_EQ(s21_check2.second, std_check2.second);
}

TEST(Map, InsertKey) {
  s21::Map<char, int> s21_map;
  std::map<char, int> check{{'a', 10}, {'b', 14}, {'k', 2}};

  auto s21_check1 = s21_map.Insert('a', 10);
  s21_map.Insert('b', 14);
  s21_map.Insert('k', 2);
  auto s21_check2 = s21_map.Insert('b', 55);

  EXPECT_EQ(s21_map.Size(), 3);

  auto s21_iter = s21_map.Begin();
  auto std_iter = check.begin();

  while (s21_iter != s21_map.End()) {
    EXPECT_EQ(*s21_iter, *std_iter);

    s21_iter++;
    std_iter++;
  }

  EXPECT_EQ(s21_check1.first->first, 'a');
  EXPECT_EQ(s21_check1.second, true);
  EXPECT_EQ(s21_check2.first->first, 'b');
  EXPECT_EQ(s21_check2.second, false);
}

TEST(Map, InsertOrAssign) {
  s21::Map<char, int> s21_map;
  std::map<char, int> std_map;

  auto s21_check1 = s21_map.Insert_or_assign('a', 10);
  s21_map.Insert_or_assign('b', 14);
  s21_map.Insert_or_assign('k', 2);
  auto s21_check2 = s21_map.Insert_or_assign('b', 55);

  auto std_check1 = std_map.insert_or_assign('a', 10);
  std_map.insert_or_assign('b', 14);
  std_map.insert_or_assign('k', 2);
  auto std_check2 = std_map.insert_or_assign('b', 55);

  EXPECT_EQ(s21_map.Empty(), std_map.empty());
  EXPECT_EQ(s21_map.Size(), std_map.size());

  auto s21_iter = s21_map.Begin();
  auto std_iter = std_map.begin();

  while (s21_iter != s21_map.End()) {
    EXPECT_EQ(*s21_iter, *std_iter);

    s21_iter++;
    std_iter++;
  }

  EXPECT_EQ(*s21_check1.first, *std_check1.first);
  EXPECT_EQ(s21_check1.second, std_check1.second);
  EXPECT_EQ(*s21_check2.first, *std_check2.first);
  EXPECT_EQ(s21_check2.second, std_check2.second);
}

TEST(Map, Clear) {
  s21::Map<int, char> s21_m{
      {14, 'r'}, {2, 'u'}, {19, 's'}, {92, 'l'}, {14, 'a'}};

  std::map<int, char> std_m{
      {14, 'r'}, {2, 'u'}, {19, 's'}, {92, 'l'}, {14, 'a'}};
  s21_m.Clear();
  std_m.clear();

  EXPECT_EQ(s21_m.Size(), std_m.size());
  EXPECT_EQ(s21_m.Empty(), std_m.empty());
}

TEST(Map, Erase) {
  s21::Map<int, char> s21_m{
      {14, 'r'}, {2, 'u'}, {19, 's'}, {92, 'l'}, {14, 'a'}};

  std::map<int, char> std_m{
      {14, 'r'}, {2, 'u'}, {19, 's'}, {92, 'l'}, {14, 'a'}};

  auto s21_it = s21_m.Begin();
  auto std_it = std_m.begin();
  ++s21_it;
  ++s21_it;
  ++std_it;
  ++std_it;

  s21_m.Erase(s21_it);
  std_m.erase(std_it);

  EXPECT_EQ(s21_m.Empty(), std_m.empty());
  EXPECT_EQ(s21_m.Size(), std_m.size());

  auto s21_iter = s21_m.Begin();
  auto std_iter = std_m.begin();

  while (s21_iter != s21_m.End()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    s21_iter++;
    std_iter++;
  }
}

TEST(Map, Swap) {
  s21::Map<int, char> s21_m1{
      {14, 'r'}, {2, 'u'}, {19, 's'}, {92, 'l'}, {14, 'a'}};
  s21::Map<int, char> s21_m2{{22, 'r'}, {54, 'u'}};

  std::map<int, char> std_m1{
      {14, 'r'}, {2, 'u'}, {19, 's'}, {92, 'l'}, {14, 'a'}};
  std::map<int, char> std_m2{{22, 'r'}, {54, 'u'}};

  s21_m1.Swap(s21_m2);
  std_m1.swap(std_m2);

  EXPECT_EQ(s21_m1.Empty(), std_m1.empty());
  EXPECT_EQ(s21_m1.Size(), std_m1.size());

  auto s21_iter = s21_m1.Begin();
  auto std_iter = std_m1.begin();

  while (s21_iter != s21_m1.End()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    s21_iter++;
    std_iter++;
  }

  EXPECT_EQ(s21_m2.Empty(), std_m2.empty());
  EXPECT_EQ(s21_m2.Size(), std_m2.size());

  s21_iter = s21_m2.Begin();
  std_iter = std_m2.begin();

  while (s21_iter != s21_m2.End()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    s21_iter++;
    std_iter++;
  }
}

TEST(Map, Merge) {
  s21::Map<int, std::string> s21_ma{{1, "apple"}, {5, "pear"}, {10, "banana"}};
  s21::Map<int, std::string> s21_mb{
      {2, "zorro"}, {4, "batman"}, {5, "X"}, {8, "alpaca"}};
  s21::Map<int, std::string> s21_u;

  std::map<int, std::string> std_ma{{1, "apple"}, {5, "pear"}, {10, "banana"}};
  std::map<int, std::string> std_mb{
      {2, "zorro"}, {4, "batman"}, {5, "X"}, {8, "alpaca"}};
  std::map<int, std::string> std_u;

  s21_u.Merge(s21_ma);
  std_u.merge(std_ma);

  EXPECT_EQ(s21_u.Size(), std_u.size());
  EXPECT_EQ(s21_ma.Size(), std_ma.size());

  auto s21_iter = s21_u.Begin();
  auto std_iter = std_u.begin();

  while (s21_iter != s21_u.End()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    s21_iter++;
    std_iter++;
  }

  s21_u.Merge(s21_mb);
  std_u.merge(std_mb);

  EXPECT_EQ(s21_u.Size(), std_u.size());
  EXPECT_EQ(s21_mb.Size(), std_mb.size());

  s21_iter = s21_u.Begin();
  std_iter = std_u.begin();

  while (s21_iter != s21_u.End()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    s21_iter++;
    std_iter++;
  }

  EXPECT_EQ(s21_mb[5], "X");
}

TEST(Map, SquareBrackets) {
  s21::Map<int, float> s21_m;
  std::map<int, float> std_m;

  s21_m[4] = 4.13;
  s21_m[9] = 9.24;
  s21_m[1] = 1.09;
  s21_m[4] = 10.09;
  s21_m[5];

  std_m[4] = 4.13;
  std_m[9] = 9.24;
  std_m[1] = 1.09;
  std_m[4] = 10.09;
  std_m[5];

  EXPECT_EQ(s21_m.Empty(), std_m.empty());
  EXPECT_EQ(s21_m.Size(), std_m.size());

  auto s21_iter = s21_m.Begin();
  auto std_iter = std_m.begin();

  while (s21_iter != s21_m.End()) {
    EXPECT_EQ(*s21_iter, *std_iter);
    s21_iter++;
    std_iter++;
  }
}

TEST(Map, At) {
  s21::Map<int, char> s21_m{
      {14, 'r'}, {2, 'u'}, {19, 's'}, {92, 'l'}, {14, 'a'}};

  std::map<int, char> std_m{
      {14, 'r'}, {2, 'u'}, {19, 's'}, {92, 'l'}, {14, 'a'}};

  EXPECT_ANY_THROW(s21_m.At(1));
  EXPECT_ANY_THROW(std_m.at(1));

  ASSERT_NO_THROW(s21_m.At(19));
  ASSERT_NO_THROW(std_m.at(19));

  EXPECT_EQ(s21_m.At(14), std_m.at(14));

  s21_m.At(92) = 'p';
  std_m.at(92) = 'p';

  EXPECT_EQ(s21_m.At(14), std_m.at(14));
}

TEST(Map, InsertMany) {
  s21::Map<int, char> s21_m{
      {14, 'r'}, {2, 'u'}, {19, 's'}, {92, 'l'}, {14, 'a'}};

  s21::Map<int, char> check1{{14, 'r'}, {2, 'u'},   {19, 's'},  {92, 'l'},
                             {14, 'a'}, {100, 'e'}, {222, 'i'}, {-33, 'w'},
                             {19, 'q'}, {-25, 'r'}};

  std::vector<std::pair<typename s21::Map<int, char>::iterator, bool>> vect;
  vect = s21_m.Insert_many(std::make_pair(100, 'e'), std::make_pair(222, 'i'),
                           std::make_pair(-33, 'w'), std::make_pair(19, 'q'),
                           std::make_pair(-25, 'r'));

  EXPECT_EQ(s21_m.Size(), 8);

  EXPECT_EQ(vect[0].first->first, 100);
  EXPECT_EQ(vect[0].first->second, 'e');
  EXPECT_EQ(vect[0].second, true);
  EXPECT_EQ(vect[1].first->first, 222);
  EXPECT_EQ(vect[1].first->second, 'i');
  EXPECT_EQ(vect[1].second, true);
  EXPECT_EQ(vect[2].first->first, -33);
  EXPECT_EQ(vect[2].first->second, 'w');
  EXPECT_EQ(vect[2].second, true);
  EXPECT_EQ(vect[3].first->first, 19);
  EXPECT_EQ(vect[3].first->second, 's');
  EXPECT_EQ(vect[3].second, false);
  EXPECT_EQ(vect[4].first->first, -25);
  EXPECT_EQ(vect[4].first->second, 'r');
  EXPECT_EQ(vect[4].second, true);

  auto s21_iter = s21_m.Begin();
  auto check1_iter = check1.Begin();

  while (s21_iter != s21_m.End()) {
    EXPECT_EQ(*s21_iter, *check1_iter);
    s21_iter++;
    check1_iter++;
  }
}