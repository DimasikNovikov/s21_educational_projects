#include <array>

#include "my_test.h"

TEST(Array, DafaultConstructorZero) {
  s21::Array<int, 0> s21_arr_int;
  s21::Array<std::string, 0> s21_arr_string;

  std::array<int, 0> std_arr_int;
  std::array<std::string, 0> std_arr_string;

  EXPECT_EQ(s21_arr_int.Empty(), std_arr_int.empty());
  EXPECT_EQ(s21_arr_string.Empty(), std_arr_string.empty());

  EXPECT_EQ(s21_arr_int.Size(), std_arr_int.size());
  EXPECT_EQ(s21_arr_string.Size(), std_arr_string.size());
}

TEST(Array, DafaultConstructor) {
  s21::Array<int, 5> s21_arr_int;
  s21::Array<std::string, 5> s21_arr_string;

  std::array<int, 5> std_arr_int;
  std::array<std::string, 5> std_arr_string;

  EXPECT_EQ(s21_arr_int.Empty(), std_arr_int.empty());
  EXPECT_EQ(s21_arr_string.Empty(), std_arr_string.empty());

  EXPECT_EQ(s21_arr_int.Size(), std_arr_int.size());
  EXPECT_EQ(s21_arr_string.Size(), std_arr_string.size());
}

TEST(Array, InitListConstructor) {
  s21::Array<int, 5> s21_arr_int{1, 2, 3};
  s21::Array<std::string, 5> s21_arr_string{"Hello", "Hi", "Hey"};

  std::array<int, 5> std_arr_int{1, 2, 3};
  std::array<std::string, 5> std_arr_string{"Hello", "Hi", "Hey"};

  EXPECT_EQ(s21_arr_int.Empty(), std_arr_int.empty());
  EXPECT_EQ(s21_arr_string.Empty(), std_arr_string.empty());

  EXPECT_EQ(s21_arr_int.Size(), std_arr_int.size());
  EXPECT_EQ(s21_arr_string.Size(), std_arr_string.size());

  for (size_t i = 0; i < s21_arr_int.Size(); i++) {
    EXPECT_EQ(s21_arr_int[i], std_arr_int[i]);
  }

  for (size_t i = 0; i < s21_arr_string.Size(); i++) {
    EXPECT_EQ(s21_arr_string[i], std_arr_string[i]);
  }
}

TEST(Array, CopyConstructor) {
  s21::Array<int, 5> s21_arr_int{1, 2, 3};
  s21::Array<std::string, 5> s21_arr_string{"Hello", "Hi", "Hey"};

  s21::Array<int, 5> s21_arr_int_copy(s21_arr_int);
  s21::Array<std::string, 5> s21_arr_string_copy(s21_arr_string);

  std::array<int, 5> std_arr_int{1, 2, 3};
  std::array<std::string, 5> std_arr_string{"Hello", "Hi", "Hey"};

  std::array<int, 5> std_arr_int_copy(std_arr_int);
  std::array<std::string, 5> std_arr_string_copy(std_arr_string);

  EXPECT_EQ(s21_arr_int_copy.Empty(), std_arr_int_copy.empty());
  EXPECT_EQ(s21_arr_string_copy.Empty(), std_arr_string_copy.empty());

  EXPECT_EQ(s21_arr_int_copy.Size(), std_arr_int_copy.size());
  EXPECT_EQ(s21_arr_string_copy.Size(), std_arr_string_copy.size());

  for (size_t i = 0; i < s21_arr_int_copy.Size(); i++) {
    EXPECT_EQ(s21_arr_int_copy[i], std_arr_int_copy[i]);
  }

  for (size_t i = 0; i < s21_arr_string_copy.Size(); i++) {
    EXPECT_EQ(s21_arr_string_copy[i], std_arr_string_copy[i]);
  }
}

TEST(Array, CopyAssignmentOperator) {
  s21::Array<int, 5> s21_arr_int{1, 2, 3};
  s21::Array<std::string, 5> s21_arr_string{"Hello", "Hi", "Hey"};

  s21::Array<int, 5> s21_arr_int_copy;
  s21_arr_int_copy = s21_arr_int;
  s21::Array<std::string, 5> s21_arr_string_copy;
  s21_arr_string_copy = s21_arr_string;

  std::array<int, 5> std_arr_int{1, 2, 3};
  std::array<std::string, 5> std_arr_string{"Hello", "Hi", "Hey"};

  std::array<int, 5> std_arr_int_copy;
  std_arr_int_copy = std_arr_int;
  std::array<std::string, 5> std_arr_string_copy;
  std_arr_string_copy = std_arr_string;

  EXPECT_EQ(s21_arr_int_copy.Empty(), std_arr_int_copy.empty());
  EXPECT_EQ(s21_arr_string_copy.Empty(), std_arr_string_copy.empty());

  EXPECT_EQ(s21_arr_int_copy.Size(), std_arr_int_copy.size());
  EXPECT_EQ(s21_arr_string_copy.Size(), std_arr_string_copy.size());

  for (size_t i = 0; i < s21_arr_int_copy.Size(); i++) {
    EXPECT_EQ(s21_arr_int_copy[i], std_arr_int_copy[i]);
  }

  for (size_t i = 0; i < s21_arr_string_copy.Size(); i++) {
    EXPECT_EQ(s21_arr_string_copy[i], std_arr_string_copy[i]);
  }
}

TEST(Array, MoveConstructor) {
  s21::Array<int, 5> s21_arr_int{1, 2, 3};
  s21::Array<std::string, 5> s21_arr_string{"Hello", "Hi", "Hey"};

  s21::Array<int, 5> s21_arr_int_copy(std::move(s21_arr_int));
  s21::Array<std::string, 5> s21_arr_string_copy(std::move(s21_arr_string));

  std::array<int, 5> std_arr_int{1, 2, 3};
  std::array<std::string, 5> std_arr_string{"Hello", "Hi", "Hey"};

  std::array<int, 5> std_arr_int_copy(std::move(std_arr_int));
  std::array<std::string, 5> std_arr_string_copy(std::move(std_arr_string));

  EXPECT_EQ(s21_arr_int_copy.Empty(), std_arr_int_copy.empty());
  EXPECT_EQ(s21_arr_string_copy.Empty(), std_arr_string_copy.empty());

  EXPECT_EQ(s21_arr_int_copy.Size(), std_arr_int_copy.size());
  EXPECT_EQ(s21_arr_string_copy.Size(), std_arr_string_copy.size());

  for (size_t i = 0; i < s21_arr_int_copy.Size(); i++) {
    EXPECT_EQ(s21_arr_int_copy[i], std_arr_int_copy[i]);
  }

  for (size_t i = 0; i < s21_arr_string_copy.Size(); i++) {
    EXPECT_EQ(s21_arr_string_copy[i], std_arr_string_copy[i]);
  }
}

TEST(Array, MoveAssignmentOperator) {
  s21::Array<int, 5> s21_arr_int{1, 2, 3};
  s21::Array<std::string, 5> s21_arr_string{"Hello", "Hi", "Hey"};

  s21::Array<int, 5> s21_arr_int_copy;
  s21_arr_int_copy = std::move(s21_arr_int);
  s21::Array<std::string, 5> s21_arr_string_copy;
  s21_arr_string_copy = std::move(s21_arr_string);

  std::array<int, 5> std_arr_int{1, 2, 3};
  std::array<std::string, 5> std_arr_string{"Hello", "Hi", "Hey"};

  std::array<int, 5> std_arr_int_copy;
  std_arr_int_copy = std::move(std_arr_int);
  std::array<std::string, 5> std_arr_string_copy;
  std_arr_string_copy = std::move(std_arr_string);

  EXPECT_EQ(s21_arr_int_copy.Empty(), std_arr_int_copy.empty());
  EXPECT_EQ(s21_arr_string_copy.Empty(), std_arr_string_copy.empty());

  EXPECT_EQ(s21_arr_int_copy.Size(), std_arr_int_copy.size());
  EXPECT_EQ(s21_arr_string_copy.Size(), std_arr_string_copy.size());

  for (size_t i = 0; i < s21_arr_int_copy.Size(); i++) {
    EXPECT_EQ(s21_arr_int_copy[i], std_arr_int_copy[i]);
  }

  for (size_t i = 0; i < s21_arr_string_copy.Size(); i++) {
    EXPECT_EQ(s21_arr_string_copy[i], std_arr_string_copy[i]);
  }
}

TEST(Array, DataBeginEnd) {
  s21::Array<int, 5> s21_arr{1, 2, 3, 4, 5};
  std::array<int, 5> std_arr{1, 2, 3, 4, 5};

  int *s21_iter = s21_arr.Begin();
  int *std_iter = std_arr.begin();

  EXPECT_EQ(s21_iter, s21_arr.Data());
  EXPECT_EQ(std_iter, std_arr.data());

  for (; s21_iter != s21_arr.End(); s21_iter++, std_iter++) {
    EXPECT_EQ(*s21_iter, *std_iter);
  }
}

TEST(Array, AtAndMaxSize) {
  s21::Array<int, 3> s21_arr_int;
  s21::Array<std::string, 3> s21_arr_string;

  std::array<int, 3> std_arr_int{1, 2, 3};
  std::array<std::string, 3> std_arr_string{"Hello", "Hi", "Hey"};

  s21_arr_int[0] = 1;
  s21_arr_int[1] = 2;
  s21_arr_int[2] = 3;

  s21_arr_string.At(0) = "Hello";
  s21_arr_string.At(1) = "Hi";
  s21_arr_string.At(2) = "Hey";

  EXPECT_ANY_THROW(s21_arr_int.At(3) = 5);

  EXPECT_EQ(s21_arr_int.Size(), s21_arr_int.Max_size());
  EXPECT_EQ(s21_arr_int.Front(), 1);
  EXPECT_EQ(s21_arr_string.Back(), "Hey");

  for (size_t i = 0; i < s21_arr_int.Size(); i++) {
    EXPECT_EQ(s21_arr_int[i], std_arr_int[i]);
  }

  for (size_t i = 0; i < s21_arr_string.Size(); i++) {
    EXPECT_EQ(s21_arr_string.At(i), std_arr_string.at(i));
  }
}

TEST(Array, Fill) {
  s21::Array<int, 5> s21_arr_int;
  s21::Array<std::string, 3> s21_arr_string;

  std::array<int, 3> std_arr_int;
  std::array<std::string, 3> std_arr_string;

  s21_arr_int.Fill(9);
  s21_arr_string.Fill("Hi");

  std_arr_int.fill(9);
  std_arr_string.fill("Hi");

  for (size_t i = 0; i < s21_arr_int.Size(); i++) {
    EXPECT_EQ(s21_arr_int[i], std_arr_int[i]);
  }

  for (size_t i = 0; i < s21_arr_string.Size(); i++) {
    EXPECT_EQ(s21_arr_string.At(i), std_arr_string.at(i));
  }
}

TEST(Array, Swap) {
  s21::Array<int, 5> s21_arr_int1{1, 2, 3};
  s21::Array<int, 5> s21_arr_int2{0};

  std::array<int, 5> std_arr_int1{1, 2, 3};
  std::array<int, 5> std_arr_int2{0};

  s21_arr_int2.Swap(s21_arr_int1);
  std_arr_int2.swap(std_arr_int1);

  for (size_t i = 0; i < s21_arr_int2.Size(); i++) {
    EXPECT_EQ(s21_arr_int2[i], std_arr_int2[i]);
  }

  for (size_t i = 0; i < s21_arr_int1.Size(); i++) {
    EXPECT_EQ(s21_arr_int1[i], std_arr_int1[i]);
  }
}
