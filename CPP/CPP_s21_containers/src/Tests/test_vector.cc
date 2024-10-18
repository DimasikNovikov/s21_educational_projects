#include <vector>

#include "my_test.h"

TEST(Vector, DefaultConstructor) {
  s21::Vector<int> my_vec_int;
  s21::Vector<double> my_vec_double;
  s21::Vector<std::string> my_vec_string;
  s21::Vector<s21::Vector<int>> my_vec_Vector;

  std::vector<int> std_vec_int;
  std::vector<double> std_vec_double;
  std::vector<std::string> std_vec_string;
  std::vector<std::vector<int>> std_vec_vector;

  EXPECT_EQ(my_vec_int.Size(), std_vec_int.size());
  EXPECT_EQ(my_vec_int.Capacity(), std_vec_int.capacity());
  EXPECT_EQ(my_vec_int.Empty(), std_vec_int.empty());

  EXPECT_EQ(my_vec_double.Size(), std_vec_double.size());
  EXPECT_EQ(my_vec_double.Capacity(), std_vec_double.capacity());
  EXPECT_EQ(my_vec_double.Empty(), std_vec_double.empty());

  EXPECT_EQ(my_vec_string.Size(), std_vec_string.size());
  EXPECT_EQ(my_vec_string.Capacity(), std_vec_string.capacity());
  EXPECT_EQ(my_vec_string.Empty(), std_vec_string.empty());

  EXPECT_EQ(my_vec_Vector.Size(), std_vec_vector.size());
  EXPECT_EQ(my_vec_Vector.Capacity(), std_vec_vector.capacity());
  EXPECT_EQ(my_vec_Vector.Empty(), std_vec_vector.empty());
}

TEST(Vector, ParamConstructorZero) {
  s21::Vector<int> my_vec_int(0);
  s21::Vector<double> my_vec_double(0);
  s21::Vector<std::string> my_vec_string(0);

  std::vector<int> std_vec_int(0);
  std::vector<double> std_vec_double(0);
  std::vector<std::string> std_vec_string(0);

  EXPECT_EQ(my_vec_int.Size(), std_vec_int.size());
  EXPECT_EQ(my_vec_int.Capacity(), std_vec_int.capacity());
  EXPECT_EQ(my_vec_int.Empty(), std_vec_int.empty());

  EXPECT_EQ(my_vec_double.Size(), std_vec_double.size());
  EXPECT_EQ(my_vec_double.Capacity(), std_vec_double.capacity());
  EXPECT_EQ(my_vec_double.Empty(), std_vec_double.empty());

  EXPECT_EQ(my_vec_string.Size(), std_vec_string.size());
  EXPECT_EQ(my_vec_string.Capacity(), std_vec_string.capacity());
  EXPECT_EQ(my_vec_string.Empty(), std_vec_string.empty());

  EXPECT_EQ(my_vec_int.Data(), std_vec_int.data());
}

TEST(Vector, ParamConstructorAllocated) {
  s21::Vector<int> my_vec_int(5);
  s21::Vector<double> my_vec_double(5);
  s21::Vector<std::string> my_vec_string(5);

  std::vector<int> std_vec_int(5);
  std::vector<double> std_vec_double(5);
  std::vector<std::string> std_vec_string(5);

  EXPECT_EQ(my_vec_int.Size(), std_vec_int.size());
  EXPECT_EQ(my_vec_int.Capacity(), std_vec_int.capacity());
  EXPECT_EQ(my_vec_int.Empty(), std_vec_int.empty());

  EXPECT_EQ(my_vec_double.Size(), std_vec_double.size());
  EXPECT_EQ(my_vec_double.Capacity(), std_vec_double.capacity());
  EXPECT_EQ(my_vec_double.Empty(), std_vec_double.empty());

  EXPECT_EQ(my_vec_string.Size(), std_vec_string.size());
  EXPECT_EQ(my_vec_string.Capacity(), std_vec_string.capacity());
  EXPECT_EQ(my_vec_string.Empty(), std_vec_string.empty());
}

TEST(Vector, OperatorSquareBrackets) {
  s21::Vector<int> my_vec_int(3);
  s21::Vector<double> my_vec_double(3);
  s21::Vector<std::string> my_vec_string(3);

  std::vector<int> std_vec_int(3);
  std::vector<double> std_vec_double(3);
  std::vector<std::string> std_vec_string(3);

  my_vec_int[0] = 1;
  my_vec_int[1] = 2;
  my_vec_int[2] = 3;
  std_vec_int[0] = 1;
  std_vec_int[1] = 2;
  std_vec_int[2] = 3;

  my_vec_double[0] = 1.1;
  my_vec_double[1] = 2.2;
  my_vec_double[2] = 3.3;
  std_vec_double[0] = 1.1;
  std_vec_double[1] = 2.2;
  std_vec_double[2] = 3.3;

  my_vec_string[0] = "Hello";
  my_vec_string[1] = "Hi";
  my_vec_string[2] = "Hey";
  std_vec_string[0] = "Hello";
  std_vec_string[1] = "Hi";
  std_vec_string[2] = "Hey";

  for (size_t i = 0; i < my_vec_int.Size(); i++) {
    EXPECT_EQ(my_vec_int[i], std_vec_int[i]);
  }

  for (size_t i = 0; i < my_vec_double.Size(); i++) {
    EXPECT_DOUBLE_EQ(my_vec_double[i], std_vec_double[i]);
  }

  for (size_t i = 0; i < my_vec_string.Size(); i++) {
    EXPECT_EQ(my_vec_string[i], std_vec_string[i]);
  }
}

TEST(Vector, At) {
  s21::Vector<int> my_vec_int(3);
  s21::Vector<double> my_vec_double(3);
  s21::Vector<std::string> my_vec_string(3);

  std::vector<int> std_vec_int(3);
  std::vector<double> std_vec_double(3);
  std::vector<std::string> std_vec_string(3);

  EXPECT_NO_THROW(my_vec_int.At(0) = 1);
  my_vec_int.At(1) = 2;
  my_vec_int.At(2) = 3;
  std_vec_int.at(0) = 1;
  std_vec_int.at(1) = 2;
  std_vec_int.at(2) = 3;

  my_vec_double.At(0) = 1.1;
  EXPECT_NO_THROW(my_vec_double.At(1) = 2.2);
  my_vec_double.At(2) = 3.3;
  std_vec_double.at(0) = 1.1;
  std_vec_double.at(1) = 2.2;
  std_vec_double.at(2) = 3.3;

  my_vec_string.At(0) = "Hello";
  my_vec_string.At(1) = "Hi";
  EXPECT_NO_THROW(my_vec_string.At(2) = "Hey");
  std_vec_string.at(0) = "Hello";
  std_vec_string.at(1) = "Hi";
  std_vec_string.at(2) = "Hey";

  for (size_t i = 0; i < my_vec_int.Size(); i++) {
    EXPECT_EQ(my_vec_int.At(i), std_vec_int.at(i));
  }

  for (size_t i = 0; i < my_vec_double.Size(); i++) {
    EXPECT_DOUBLE_EQ(my_vec_double.At(i), std_vec_double.at(i));
  }

  for (size_t i = 0; i < my_vec_string.Size(); i++) {
    EXPECT_EQ(my_vec_string.At(i), std_vec_string.at(i));
  }

  EXPECT_ANY_THROW(my_vec_int.At(-1));
  EXPECT_ANY_THROW(my_vec_double.At(3));
}

TEST(Vector, InitListConstructor) {
  s21::Vector<int> my_vec_int{1, 2, 3};
  s21::Vector<double> my_vec_double{1.1, 2.2, 3.3};
  s21::Vector<std::string> my_vec_string{"Hello", "Hi", "Hey"};

  std::vector<int> std_vec_int{1, 2, 3};
  std::vector<double> std_vec_double{1.1, 2.2, 3.3};
  std::vector<std::string> std_vec_string{"Hello", "Hi", "Hey"};

  EXPECT_EQ(my_vec_int.Size(), std_vec_int.size());
  EXPECT_EQ(my_vec_int.Capacity(), std_vec_int.capacity());
  EXPECT_EQ(my_vec_int.Empty(), std_vec_int.empty());

  EXPECT_EQ(my_vec_double.Size(), std_vec_double.size());
  EXPECT_EQ(my_vec_double.Capacity(), std_vec_double.capacity());
  EXPECT_EQ(my_vec_double.Empty(), std_vec_double.empty());

  EXPECT_EQ(my_vec_string.Size(), std_vec_string.size());
  EXPECT_EQ(my_vec_string.Capacity(), std_vec_string.capacity());
  EXPECT_EQ(my_vec_string.Empty(), std_vec_string.empty());

  for (size_t i = 0; i < my_vec_int.Size(); i++) {
    EXPECT_EQ(my_vec_int[i], std_vec_int[i]);
  }

  for (size_t i = 0; i < my_vec_double.Size(); i++) {
    EXPECT_DOUBLE_EQ(my_vec_double[i], std_vec_double[i]);
  }

  for (size_t i = 0; i < my_vec_string.Size(); i++) {
    EXPECT_EQ(my_vec_string[i], std_vec_string[i]);
  }
}

TEST(Vector, CopyConstructor) {
  s21::Vector<int> my_vec_int_1{1, 2, 3};
  s21::Vector<double> my_vec_double_1{1.1, 2.2, 3.3};
  s21::Vector<std::string> my_vec_string_1{"Hello", "Hi", "Hey"};

  s21::Vector<int> my_vec_int_2(my_vec_int_1);
  s21::Vector<double> my_vec_double_2(my_vec_double_1);
  s21::Vector<std::string> my_vec_string_2(my_vec_string_1);

  std::vector<int> std_vec_int_1{1, 2, 3};
  std::vector<double> std_vec_double_1{1.1, 2.2, 3.3};
  std::vector<std::string> std_vec_string_1{"Hello", "Hi", "Hey"};

  std::vector<int> std_vec_int_2(std_vec_int_1);
  std::vector<double> std_vec_double_2(std_vec_double_1);
  std::vector<std::string> std_vec_string_2(std_vec_string_1);

  EXPECT_EQ(my_vec_int_2.Size(), std_vec_int_2.size());
  EXPECT_EQ(my_vec_int_2.Capacity(), std_vec_int_2.capacity());
  EXPECT_EQ(my_vec_int_2.Empty(), std_vec_int_2.empty());

  EXPECT_EQ(my_vec_double_2.Size(), std_vec_double_2.size());
  EXPECT_EQ(my_vec_double_2.Capacity(), std_vec_double_2.capacity());
  EXPECT_EQ(my_vec_double_2.Empty(), std_vec_double_2.empty());

  EXPECT_EQ(my_vec_string_2.Size(), std_vec_string_2.size());
  EXPECT_EQ(my_vec_string_2.Capacity(), std_vec_string_2.capacity());
  EXPECT_EQ(my_vec_string_2.Empty(), std_vec_string_2.empty());

  for (size_t i = 0; i < my_vec_int_2.Size(); i++) {
    EXPECT_EQ(my_vec_int_2[i], std_vec_int_2[i]);
  }

  for (size_t i = 0; i < my_vec_double_2.Size(); i++) {
    EXPECT_DOUBLE_EQ(my_vec_double_2[i], std_vec_double_2[i]);
  }

  for (size_t i = 0; i < my_vec_string_2.Size(); i++) {
    EXPECT_EQ(my_vec_string_2[i], std_vec_string_2[i]);
  }
}

TEST(Vector, CopyAssignmentOperator) {
  s21::Vector<int> my_vec_int_1{1, 2, 3};
  s21::Vector<double> my_vec_double_1{1.1, 2.2, 3.3};
  s21::Vector<std::string> my_vec_string_1{"Hello", "Hi", "Hey"};

  s21::Vector<int> my_vec_int_2;
  my_vec_int_2 = my_vec_int_1;
  s21::Vector<double> my_vec_double_2;
  my_vec_double_2 = my_vec_double_1;
  s21::Vector<std::string> my_vec_string_2;
  my_vec_string_2 = my_vec_string_1;

  std::vector<int> std_vec_int_1{1, 2, 3};
  std::vector<double> std_vec_double_1{1.1, 2.2, 3.3};
  std::vector<std::string> std_vec_string_1{"Hello", "Hi", "Hey"};

  std::vector<int> std_vec_int_2;
  std_vec_int_2 = std_vec_int_1;
  std::vector<double> std_vec_double_2;
  std_vec_double_2 = std_vec_double_1;
  std::vector<std::string> std_vec_string_2;
  std_vec_string_2 = std_vec_string_1;

  EXPECT_EQ(my_vec_int_2.Size(), std_vec_int_2.size());
  EXPECT_EQ(my_vec_int_2.Capacity(), std_vec_int_2.capacity());
  EXPECT_EQ(my_vec_int_2.Empty(), std_vec_int_2.empty());

  EXPECT_EQ(my_vec_double_2.Size(), std_vec_double_2.size());
  EXPECT_EQ(my_vec_double_2.Capacity(), std_vec_double_2.capacity());
  EXPECT_EQ(my_vec_double_2.Empty(), std_vec_double_2.empty());

  EXPECT_EQ(my_vec_string_2.Size(), std_vec_string_2.size());
  EXPECT_EQ(my_vec_string_2.Capacity(), std_vec_string_2.capacity());
  EXPECT_EQ(my_vec_string_2.Empty(), std_vec_string_2.empty());

  for (size_t i = 0; i < my_vec_int_2.Size(); i++) {
    EXPECT_EQ(my_vec_int_2[i], std_vec_int_2[i]);
  }

  for (size_t i = 0; i < my_vec_double_2.Size(); i++) {
    EXPECT_DOUBLE_EQ(my_vec_double_2[i], std_vec_double_2[i]);
  }

  for (size_t i = 0; i < my_vec_string_2.Size(); i++) {
    EXPECT_EQ(my_vec_string_2[i], std_vec_string_2[i]);
  }
}

TEST(Vector, MoveConstructor) {
  s21::Vector<int> my_vec_int_1{1, 2, 3};
  s21::Vector<std::string> my_vec_string_1{"Hello", "Hi", "Hey"};

  s21::Vector<int> my_vec_int_2(std::move(my_vec_int_1));
  s21::Vector<std::string> my_vec_string_2(std::move(my_vec_string_1));

  std::vector<int> std_vec_int_1{1, 2, 3};
  std::vector<std::string> std_vec_string_1{"Hello", "Hi", "Hey"};

  std::vector<int> std_vec_int_2(std::move(std_vec_int_1));
  std::vector<std::string> std_vec_string_2(std::move(std_vec_string_1));

  EXPECT_EQ(my_vec_int_2.Size(), std_vec_int_2.size());
  EXPECT_EQ(my_vec_int_2.Capacity(), std_vec_int_2.capacity());
  EXPECT_EQ(my_vec_int_2.Empty(), std_vec_int_2.empty());

  EXPECT_EQ(my_vec_int_1.Size(), std_vec_int_1.size());
  EXPECT_EQ(my_vec_int_1.Capacity(), std_vec_int_1.capacity());
  EXPECT_EQ(my_vec_int_1.Empty(), std_vec_int_1.empty());

  EXPECT_EQ(my_vec_string_2.Size(), std_vec_string_2.size());
  EXPECT_EQ(my_vec_string_2.Capacity(), std_vec_string_2.capacity());
  EXPECT_EQ(my_vec_string_2.Empty(), std_vec_string_2.empty());

  EXPECT_EQ(my_vec_string_1.Size(), std_vec_string_1.size());
  EXPECT_EQ(my_vec_string_1.Capacity(), std_vec_string_1.capacity());
  EXPECT_EQ(my_vec_string_1.Empty(), std_vec_string_1.empty());

  for (size_t i = 0; i < my_vec_int_2.Size(); i++) {
    EXPECT_EQ(my_vec_int_2[i], std_vec_int_2[i]);
  }

  for (size_t i = 0; i < my_vec_string_2.Size(); i++) {
    EXPECT_EQ(my_vec_string_2[i], std_vec_string_2[i]);
  }
}

TEST(Vector, MoveAssignmentOperator) {
  s21::Vector<int> my_vec_int_1{1, 2, 3};
  s21::Vector<std::string> my_vec_string_1{"Hello", "Hi", "Hey"};

  s21::Vector<int> my_vec_int_2;
  my_vec_int_2 = std::move(my_vec_int_1);
  s21::Vector<std::string> my_vec_string_2;
  my_vec_string_2 = std::move(my_vec_string_1);

  std::vector<int> std_vec_int_1{1, 2, 3};
  std::vector<std::string> std_vec_string_1{"Hello", "Hi", "Hey"};

  std::vector<int> std_vec_int_2;
  std_vec_int_2 = std::move(std_vec_int_1);
  std::vector<std::string> std_vec_string_2;
  std_vec_string_2 = std::move(std_vec_string_1);

  EXPECT_EQ(my_vec_int_2.Size(), std_vec_int_2.size());
  EXPECT_EQ(my_vec_int_2.Capacity(), std_vec_int_2.capacity());
  EXPECT_EQ(my_vec_int_2.Empty(), std_vec_int_2.empty());

  EXPECT_EQ(my_vec_int_1.Size(), std_vec_int_1.size());
  EXPECT_EQ(my_vec_int_1.Capacity(), std_vec_int_1.capacity());
  EXPECT_EQ(my_vec_int_1.Empty(), std_vec_int_1.empty());

  EXPECT_EQ(my_vec_string_2.Size(), std_vec_string_2.size());
  EXPECT_EQ(my_vec_string_2.Capacity(), std_vec_string_2.capacity());
  EXPECT_EQ(my_vec_string_2.Empty(), std_vec_string_2.empty());

  EXPECT_EQ(my_vec_string_1.Size(), std_vec_string_1.size());
  EXPECT_EQ(my_vec_string_1.Capacity(), std_vec_string_1.capacity());
  EXPECT_EQ(my_vec_string_1.Empty(), std_vec_string_1.empty());

  for (size_t i = 0; i < my_vec_int_2.Size(); i++) {
    EXPECT_EQ(my_vec_int_2[i], std_vec_int_2[i]);
  }

  for (size_t i = 0; i < my_vec_string_2.Size(); i++) {
    EXPECT_EQ(my_vec_string_2[i], std_vec_string_2[i]);
  }
}

TEST(Vector, FrontBackData) {
  s21::Vector<int> my_vec_int_1{1, 2, 3};
  s21::Vector<std::string> my_vec_string_1{"Hello", "Hi", "Hey"};

  std::vector<int> std_vec_int_1{1, 2, 3};
  std::vector<std::string> std_vec_string_1{"Hello", "Hi", "Hey"};

  EXPECT_EQ(my_vec_int_1.Front(), std_vec_int_1.front());
  EXPECT_EQ(my_vec_string_1.Front(), std_vec_string_1.front());
  EXPECT_EQ(my_vec_int_1.Back(), std_vec_int_1.back());
  EXPECT_EQ(my_vec_string_1.Back(), std_vec_string_1.back());

  EXPECT_EQ(&my_vec_int_1.Front(), my_vec_int_1.Data());
  EXPECT_EQ(&my_vec_string_1.Front(), my_vec_string_1.Data());
}

TEST(Vector, IteratorsZero) {
  s21::Vector<int> my_vec_int;

  EXPECT_EQ(my_vec_int.Begin(), my_vec_int.End());
}

TEST(Vector, Iterators) {
  s21::Vector<int> my_vec_int{1, 2, 3};
  s21::Vector<std::string> my_vec_string{"Hello", "Hi", "Hey"};

  std::vector<int> std_vec_int{1, 2, 3};
  std::vector<std::string> std_vec_string{"Hello", "Hi", "Hey"};

  size_t i_int{0};
  auto my_iter_int = my_vec_int.Begin();
  auto std_iter_int = std_vec_int.begin();
  while (my_iter_int != my_vec_int.End()) {
    EXPECT_EQ(*my_iter_int, my_vec_int[i_int]);
    EXPECT_EQ(*my_iter_int, *std_iter_int);
    i_int++;
    my_iter_int++;
    std_iter_int++;
  }

  size_t i_string{0};
  auto my_iter_string = my_vec_string.Begin();
  auto std_iter_string = std_vec_string.begin();
  while (my_iter_string != my_vec_string.End()) {
    EXPECT_EQ(*my_iter_string, my_vec_string[i_string]);
    EXPECT_EQ(*my_iter_string, *std_iter_string);
    i_string++;
    my_iter_string++;
    std_iter_string++;
  }
}

TEST(Vector, MaxSize) {
  s21::Vector<int> s21_vec_int;
  s21::Vector<double> s21_vec_double;
  s21::Vector<char> s21_vec_char;
  s21::Vector<std::string> s21_vec_string;

  std::vector<int> std_vec_int;
  std::vector<double> std_vec_double;
  std::vector<char> std_vec_char;
  std::vector<std::string> std_vec_string;

  EXPECT_EQ(s21_vec_int.Max_size(), std_vec_int.max_size());
  EXPECT_EQ(s21_vec_double.Max_size(), std_vec_double.max_size());
  EXPECT_EQ(s21_vec_char.Max_size(), std_vec_char.max_size());
  EXPECT_EQ(s21_vec_string.Max_size(), std_vec_string.max_size());
}

TEST(Vector, ReserveSizeLess) {
  s21::Vector<int> s21_vec_int{1, 2, 3};
  s21::Vector<std::string> s21_vec_string{"Hello", "Hi", "Hey"};

  std::vector<int> std_vec_int{1, 2, 3};
  std::vector<std::string> std_vec_string{"Hello", "Hi", "Hey"};

  s21_vec_int.Reserve(1);
  s21_vec_string.Reserve(2);
  std_vec_int.reserve(1);
  std_vec_string.reserve(2);

  EXPECT_EQ(s21_vec_int.Size(), std_vec_int.size());
  EXPECT_EQ(s21_vec_int.Capacity(), std_vec_int.capacity());
  EXPECT_EQ(s21_vec_int.Empty(), std_vec_int.empty());

  EXPECT_EQ(s21_vec_string.Size(), std_vec_string.size());
  EXPECT_EQ(s21_vec_string.Capacity(), std_vec_string.capacity());
  EXPECT_EQ(s21_vec_string.Empty(), std_vec_string.empty());

  for (size_t i = 0; i < s21_vec_int.Size(); i++) {
    EXPECT_EQ(s21_vec_int[i], std_vec_int[i]);
  }

  for (size_t i = 0; i < s21_vec_string.Size(); i++) {
    EXPECT_EQ(s21_vec_string[i], std_vec_string[i]);
  }
}

TEST(Vector, ReserveSizeMore) {
  s21::Vector<int> s21_vec_int{1, 2, 3};
  s21::Vector<std::string> s21_vec_string{"Hello", "Hi", "Hey"};

  std::vector<int> std_vec_int{1, 2, 3};
  std::vector<std::string> std_vec_string{"Hello", "Hi", "Hey"};

  s21_vec_int.Reserve(7);
  s21_vec_string.Reserve(7);
  std_vec_int.reserve(7);
  std_vec_string.reserve(7);

  EXPECT_EQ(s21_vec_int.Size(), std_vec_int.size());
  EXPECT_EQ(s21_vec_int.Capacity(), std_vec_int.capacity());
  EXPECT_EQ(s21_vec_int.Empty(), std_vec_int.empty());

  EXPECT_EQ(s21_vec_string.Size(), std_vec_string.size());
  EXPECT_EQ(s21_vec_string.Capacity(), std_vec_string.capacity());
  EXPECT_EQ(s21_vec_string.Empty(), std_vec_string.empty());

  for (size_t i = 0; i < s21_vec_int.Size(); i++) {
    EXPECT_EQ(s21_vec_int[i], std_vec_int[i]);
  }

  for (size_t i = 0; i < s21_vec_string.Size(); i++) {
    EXPECT_EQ(s21_vec_string[i], std_vec_string[i]);
  }
}

TEST(Vector, Clear) {
  s21::Vector<int> s21_vec{1, 2, 3, 4, 5};
  std::vector<int> std_vec{1, 2, 3, 4, 5};

  s21_vec.Clear();
  std_vec.clear();
  EXPECT_EQ(s21_vec.Size(), std_vec.size());
  for (size_t i = 0; i < s21_vec.Capacity(); i++) {
    EXPECT_EQ(std_vec[i], s21_vec[i]);
  }
}

TEST(Vector, PushBack) {
  s21::Vector<int> s21_vec_int{1, 2, 3};
  s21::Vector<std::string> s21_vec_string{"Hello", "Hi", "Hey"};

  std::vector<int> std_vec_int{1, 2, 3};
  std::vector<std::string> std_vec_string{"Hello", "Hi", "Hey"};

  s21_vec_int.Push_back(4);
  s21_vec_int.Push_back(5);
  s21_vec_string.Push_back("Holla");
  s21_vec_string.Push_back("Aloha");

  std_vec_int.push_back(4);
  std_vec_int.push_back(5);
  std_vec_string.push_back("Holla");
  std_vec_string.push_back("Aloha");

  EXPECT_EQ(s21_vec_int.Size(), std_vec_int.size());
  EXPECT_EQ(s21_vec_int.Capacity(), std_vec_int.capacity());
  EXPECT_EQ(s21_vec_string.Size(), std_vec_string.size());
  EXPECT_EQ(s21_vec_string.Capacity(), std_vec_string.capacity());

  EXPECT_EQ(s21_vec_int.Size(), std_vec_int.size());
  EXPECT_EQ(s21_vec_int.Capacity(), std_vec_int.capacity());
  EXPECT_EQ(s21_vec_string.Size(), std_vec_string.size());
  EXPECT_EQ(s21_vec_string.Capacity(), std_vec_string.capacity());

  for (size_t i = 0; i < s21_vec_int.Size(); i++) {
    EXPECT_EQ(s21_vec_int[i], std_vec_int[i]);
  }

  for (size_t i = 0; i < s21_vec_string.Size(); i++) {
    EXPECT_EQ(s21_vec_string[i], std_vec_string[i]);
  }
}

TEST(Vector, PushBackZero) {
  s21::Vector<int> s21_vec_int;
  s21::Vector<std::string> s21_vec_string;

  std::vector<int> std_vec_int;
  std::vector<std::string> std_vec_string;

  s21_vec_int.Push_back(4);
  s21_vec_int.Push_back(5);
  s21_vec_string.Push_back("Holla");
  s21_vec_string.Push_back("Aloha");

  std_vec_int.push_back(4);
  std_vec_int.push_back(5);
  std_vec_string.push_back("Holla");
  std_vec_string.push_back("Aloha");

  EXPECT_EQ(s21_vec_int.Size(), std_vec_int.size());
  EXPECT_EQ(s21_vec_int.Capacity(), std_vec_int.capacity());
  EXPECT_EQ(s21_vec_string.Size(), std_vec_string.size());
  EXPECT_EQ(s21_vec_string.Capacity(), std_vec_string.capacity());

  EXPECT_EQ(s21_vec_int.Size(), std_vec_int.size());
  EXPECT_EQ(s21_vec_int.Capacity(), std_vec_int.capacity());
  EXPECT_EQ(s21_vec_string.Size(), std_vec_string.size());
  EXPECT_EQ(s21_vec_string.Capacity(), std_vec_string.capacity());

  for (size_t i = 0; i < s21_vec_int.Size(); i++) {
    EXPECT_EQ(s21_vec_int[i], std_vec_int[i]);
  }

  for (size_t i = 0; i < s21_vec_string.Size(); i++) {
    EXPECT_EQ(s21_vec_string[i], std_vec_string[i]);
  }
}

TEST(Vector, PopBack) {
  s21::Vector<int> s21_vec_int{1, 2, 3, 4, 5};
  s21::Vector<std::string> s21_vec_string{"Hello", "Hi", "Hey", "Holla",
                                          "Aloha"};

  std::vector<int> std_vec_int{1, 2, 3, 4, 5};
  std::vector<std::string> std_vec_string{"Hello", "Hi", "Hey", "Holla",
                                          "Aloha"};

  s21_vec_int.Pop_back();
  s21_vec_int.Pop_back();
  s21_vec_string.Pop_back();
  s21_vec_string.Pop_back();

  std_vec_int.pop_back();
  std_vec_int.pop_back();
  std_vec_string.pop_back();
  std_vec_string.pop_back();

  EXPECT_EQ(s21_vec_int.Size(), std_vec_int.size());
  EXPECT_EQ(s21_vec_int.Capacity(), std_vec_int.capacity());
  EXPECT_EQ(s21_vec_string.Size(), std_vec_string.size());
  EXPECT_EQ(s21_vec_string.Capacity(), std_vec_string.capacity());

  EXPECT_EQ(s21_vec_int.Size(), std_vec_int.size());
  EXPECT_EQ(s21_vec_int.Capacity(), std_vec_int.capacity());
  EXPECT_EQ(s21_vec_string.Size(), std_vec_string.size());
  EXPECT_EQ(s21_vec_string.Capacity(), std_vec_string.capacity());

  for (size_t i = 0; i < s21_vec_int.Size(); i++) {
    EXPECT_EQ(s21_vec_int[i], std_vec_int[i]);
  }

  for (size_t i = 0; i < s21_vec_string.Size(); i++) {
    EXPECT_EQ(s21_vec_string[i], std_vec_string[i]);
  }
}

TEST(Vector, ShrinkToFit) {
  s21::Vector<int> s21_vec_int{1, 2, 3, 4, 5};
  s21::Vector<std::string> s21_vec_string{"Hello", "Hi", "Hey", "Holla",
                                          "Aloha"};

  std::vector<int> std_vec_int{1, 2, 3, 4, 5};
  std::vector<std::string> std_vec_string{"Hello", "Hi", "Hey", "Holla",
                                          "Aloha"};

  s21_vec_int.Pop_back();
  s21_vec_int.Pop_back();
  s21_vec_string.Pop_back();
  s21_vec_string.Pop_back();

  std_vec_int.pop_back();
  std_vec_int.pop_back();
  std_vec_string.pop_back();
  std_vec_string.pop_back();

  s21_vec_int.Shrink_to_fit();
  s21_vec_string.Shrink_to_fit();
  std_vec_int.shrink_to_fit();
  std_vec_string.shrink_to_fit();

  EXPECT_EQ(s21_vec_int.Size(), std_vec_int.size());
  EXPECT_EQ(s21_vec_int.Capacity(), std_vec_int.capacity());
  EXPECT_EQ(s21_vec_string.Size(), std_vec_string.size());
  EXPECT_EQ(s21_vec_string.Capacity(), std_vec_string.capacity());

  EXPECT_EQ(s21_vec_int.Size(), std_vec_int.size());
  EXPECT_EQ(s21_vec_int.Capacity(), std_vec_int.capacity());
  EXPECT_EQ(s21_vec_string.Size(), std_vec_string.size());
  EXPECT_EQ(s21_vec_string.Capacity(), std_vec_string.capacity());

  for (size_t i = 0; i < s21_vec_int.Size(); i++) {
    EXPECT_EQ(s21_vec_int[i], std_vec_int[i]);
  }

  for (size_t i = 0; i < s21_vec_string.Size(); i++) {
    EXPECT_EQ(s21_vec_string[i], std_vec_string[i]);
  }
}

TEST(Vector, InsertZeroBegin) {
  s21::Vector<int> s21_vec_int;
  std::vector<int> std_vec_int;

  s21_vec_int.Insert(s21_vec_int.Begin(), 10);
  std_vec_int.insert(std_vec_int.begin(), 10);

  EXPECT_EQ(s21_vec_int.Size(), std_vec_int.size());
  EXPECT_EQ(s21_vec_int.Capacity(), std_vec_int.capacity());

  EXPECT_EQ(s21_vec_int.Size(), std_vec_int.size());
  EXPECT_EQ(s21_vec_int.Capacity(), std_vec_int.capacity());

  for (size_t i = 0; i < s21_vec_int.Size(); i++) {
    EXPECT_EQ(s21_vec_int[i], std_vec_int[i]);
  }
}

TEST(Vector, InsertZeroEnd) {
  s21::Vector<int> s21_vec_int;
  std::vector<int> std_vec_int;

  s21_vec_int.Insert(s21_vec_int.End(), 10);
  std_vec_int.insert(std_vec_int.end(), 10);

  EXPECT_EQ(s21_vec_int.Size(), std_vec_int.size());
  EXPECT_EQ(s21_vec_int.Capacity(), std_vec_int.capacity());

  EXPECT_EQ(s21_vec_int.Size(), std_vec_int.size());
  EXPECT_EQ(s21_vec_int.Capacity(), std_vec_int.capacity());

  for (size_t i = 0; i < s21_vec_int.Size(); i++) {
    EXPECT_EQ(s21_vec_int[i], std_vec_int[i]);
  }
}

TEST(Vector, InsertFilledBegin) {
  s21::Vector<int> s21_vec_int{1, 2, 3};
  std::vector<int> std_vec_int{1, 2, 3};

  s21_vec_int.Insert(s21_vec_int.Begin(), 10);
  std_vec_int.insert(std_vec_int.begin(), 10);

  EXPECT_EQ(s21_vec_int.Size(), std_vec_int.size());
  EXPECT_EQ(s21_vec_int.Capacity(), std_vec_int.capacity());

  EXPECT_EQ(s21_vec_int.Size(), std_vec_int.size());
  EXPECT_EQ(s21_vec_int.Capacity(), std_vec_int.capacity());

  for (size_t i = 0; i < s21_vec_int.Size(); i++) {
    EXPECT_EQ(s21_vec_int[i], std_vec_int[i]);
  }
}

TEST(Vector, InsertFilledEnd) {
  s21::Vector<int> s21_vec_int{1, 2, 3};
  std::vector<int> std_vec_int{1, 2, 3};

  s21_vec_int.Insert(s21_vec_int.End(), 10);
  std_vec_int.insert(std_vec_int.end(), 10);

  EXPECT_EQ(s21_vec_int.Size(), std_vec_int.size());
  EXPECT_EQ(s21_vec_int.Capacity(), std_vec_int.capacity());

  EXPECT_EQ(s21_vec_int.Size(), std_vec_int.size());
  EXPECT_EQ(s21_vec_int.Capacity(), std_vec_int.capacity());

  for (size_t i = 0; i < s21_vec_int.Size(); i++) {
    EXPECT_EQ(s21_vec_int[i], std_vec_int[i]);
  }
}

TEST(Vector, InsertFilledSecondPosition) {
  s21::Vector<int> s21_vec_int{1, 2, 3};
  std::vector<int> std_vec_int{1, 2, 3};

  s21_vec_int.Insert(s21_vec_int.Begin() + 2, 10);
  std_vec_int.insert(std_vec_int.begin() + 2, 10);

  EXPECT_EQ(s21_vec_int.Size(), std_vec_int.size());
  EXPECT_EQ(s21_vec_int.Capacity(), std_vec_int.capacity());

  EXPECT_EQ(s21_vec_int.Size(), std_vec_int.size());
  EXPECT_EQ(s21_vec_int.Capacity(), std_vec_int.capacity());

  for (size_t i = 0; i < s21_vec_int.Size(); i++) {
    EXPECT_EQ(s21_vec_int[i], std_vec_int[i]);
  }
}

TEST(Vector, EraseBegin) {
  s21::Vector<int> s21_vec_int{1, 2, 3};
  std::vector<int> std_vec_int{1, 2, 3};

  s21_vec_int.Erase(s21_vec_int.Begin());
  std_vec_int.erase(std_vec_int.begin());

  EXPECT_EQ(s21_vec_int.Size(), std_vec_int.size());
  EXPECT_EQ(s21_vec_int.Capacity(), std_vec_int.capacity());

  EXPECT_EQ(s21_vec_int.Size(), std_vec_int.size());
  EXPECT_EQ(s21_vec_int.Capacity(), std_vec_int.capacity());

  for (size_t i = 0; i < s21_vec_int.Size(); i++) {
    EXPECT_EQ(s21_vec_int[i], std_vec_int[i]);
  }
}

TEST(Vector, EraseEnd) {
  s21::Vector<int> s21_vec_int{1, 2, 3};
  std::vector<int> std_vec_int{1, 2, 3};

  s21_vec_int.Erase(s21_vec_int.End() - 1);
  std_vec_int.erase(std_vec_int.end() - 1);

  EXPECT_EQ(s21_vec_int.Size(), std_vec_int.size());
  EXPECT_EQ(s21_vec_int.Capacity(), std_vec_int.capacity());

  EXPECT_EQ(s21_vec_int.Size(), std_vec_int.size());
  EXPECT_EQ(s21_vec_int.Capacity(), std_vec_int.capacity());

  for (size_t i = 0; i < s21_vec_int.Size(); i++) {
    EXPECT_EQ(s21_vec_int[i], std_vec_int[i]);
  }
}

TEST(Vector, EraseSecondPosition) {
  s21::Vector<int> s21_vec_int{1, 2, 3};
  std::vector<int> std_vec_int{1, 2, 3};

  s21_vec_int.Erase(s21_vec_int.Begin() + 2);
  std_vec_int.erase(std_vec_int.begin() + 2);

  EXPECT_EQ(s21_vec_int.Size(), std_vec_int.size());
  EXPECT_EQ(s21_vec_int.Capacity(), std_vec_int.capacity());

  EXPECT_EQ(s21_vec_int.Size(), std_vec_int.size());
  EXPECT_EQ(s21_vec_int.Capacity(), std_vec_int.capacity());

  for (size_t i = 0; i < s21_vec_int.Size(); i++) {
    EXPECT_EQ(s21_vec_int[i], std_vec_int[i]);
  }
}

TEST(Vector, Swap) {
  s21::Vector<int> s21_vec1{1, 2, 3, 4, 5};
  s21::Vector<int> s21_vec2{6, 7, 8, 9};

  std::vector<int> std_vec1{1, 2, 3, 4, 5};
  std::vector<int> std_vec2{6, 7, 8, 9};
  s21_vec1.Swap(s21_vec2);
  std_vec1.swap(std_vec2);

  EXPECT_EQ(s21_vec1.Size(), std_vec1.size());
  EXPECT_EQ(s21_vec1.Capacity(), std_vec1.capacity());

  EXPECT_EQ(s21_vec2.Size(), std_vec2.size());
  EXPECT_EQ(s21_vec2.Capacity(), std_vec2.capacity());

  for (size_t i = 0; i < s21_vec1.Size(); i++) {
    EXPECT_EQ(s21_vec1[i], std_vec1[i]);
  }

  for (size_t i = 0; i < s21_vec2.Size(); i++) {
    EXPECT_EQ(s21_vec2[i], std_vec2[i]);
  }
}

TEST(Vector, InsertMany) {
  s21::Vector<int> s21_vec{1, 2, 3};
  s21_vec.Insert_many(s21_vec.Begin() + 2, 4, 5, 6);
  s21::Vector<int> check1{1, 2, 4, 5, 6, 3};

  for (size_t i = 0; i < check1.Size(); i++) {
    EXPECT_EQ(check1[i], s21_vec[i]);
  }

  s21_vec.Insert_many(s21_vec.Begin(), 10, 11);
  s21::Vector<int> check2 = {10, 11, 1, 2, 4, 5, 6, 3};
  for (size_t i = 0; i < check2.Size(); i++) {
    EXPECT_EQ(check2[i], s21_vec[i]);
  }

  s21_vec.Insert_many(s21_vec.End(), 20, 21);
  s21::Vector<int> check3 = {10, 11, 1, 2, 4, 5, 6, 3, 20, 21};
  for (size_t i = 0; i < check3.Size(); i++) {
    EXPECT_EQ(check3[i], s21_vec[i]);
  }
}

TEST(Vector, InsertManyZero) {
  s21::Vector<int> s21_vec;
  s21_vec.Insert_many(s21_vec.Begin(), 1, 2, 3);
  s21::Vector<int> check{1, 2, 3};
  for (size_t i = 0; i < check.Size(); i++) {
    EXPECT_EQ(check[i], s21_vec[i]);
  }
}

TEST(Vector, InsertManyBack) {
  s21::Vector<int> s21_vec{1, 2, 3};
  s21_vec.Insert_many_back(4, 5, 6);
  s21::Vector<int> check{1, 2, 3, 4, 5, 6};
  for (size_t i = 0; i < check.Size(); i++) {
    EXPECT_EQ(check[i], s21_vec[i]);
  }
}

TEST(Vector, InsertManyBackZero) {
  s21::Vector<int> s21_vec;
  s21_vec.Insert_many_back(1, 2, 3);
  s21::Vector<int> check{1, 2, 3};
  for (size_t i = 0; i < check.Size(); i++) {
    EXPECT_EQ(check[i], s21_vec[i]);
  }
}
