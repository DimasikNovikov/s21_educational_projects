#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

TEST(CreateMatrix, Negative) {
  EXPECT_ANY_THROW(S21Matrix obj(-1, 3));
  EXPECT_ANY_THROW({ S21Matrix obj(3, -1); });
  EXPECT_ANY_THROW({ S21Matrix obj(-1, -1); });
}

TEST(CreateMatrix, Positive) {
  S21Matrix obj1;
  S21Matrix obj2(2, 5);

  EXPECT_EQ(obj1.GetRows(), 0);
  EXPECT_EQ(obj1.GetCols(), 0);
  ASSERT_EQ(obj1.GetMatrix(), nullptr);

  EXPECT_EQ(obj2.GetRows(), 2);
  EXPECT_EQ(obj2.GetCols(), 5);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 5; j++) {
      ASSERT_NO_THROW(obj2(i, j));
      EXPECT_DOUBLE_EQ(obj2(i, j), 0);
    }
  }
}

TEST(AccessToMatrixItem, Negative) {
  S21Matrix obj;
  EXPECT_ANY_THROW(obj(-1, 2));
  EXPECT_ANY_THROW(obj(2, -1));
  EXPECT_ANY_THROW(obj(2, 3));
  EXPECT_ANY_THROW(obj(4, 2));
}

TEST(AccessToMatrixItem, Positive) {
  S21Matrix obj(3, 3);
  ASSERT_NO_THROW(obj(0, 0));
  ASSERT_NO_THROW(obj(2, 2));

  obj(0, 0) = 25;
  obj(2, 2) = 33;

  EXPECT_DOUBLE_EQ(obj(0, 0), 25);
  EXPECT_DOUBLE_EQ(obj(2, 2), 33);
}

TEST(AssignmentToObject, CopyConstructor) {
  S21Matrix obj1(2, 4);
  obj1(0, 0) = 11;
  obj1(1, 3) = 22;

  S21Matrix obj2(obj1);
  EXPECT_EQ(obj2.GetRows(), 2);
  EXPECT_EQ(obj2.GetCols(), 4);
  EXPECT_DOUBLE_EQ(obj2(0, 0), 11);
  EXPECT_DOUBLE_EQ(obj2(1, 3), 22);
}

TEST(AssignmentToObject, CopyAssignmentOperator) {
  S21Matrix obj1(2, 4);
  obj1(0, 0) = 11;
  obj1(1, 3) = 22;

  S21Matrix obj2;
  obj2 = obj1;
  EXPECT_EQ(obj2.GetRows(), 2);
  EXPECT_EQ(obj2.GetCols(), 4);
  EXPECT_DOUBLE_EQ(obj2(0, 0), 11);
  EXPECT_DOUBLE_EQ(obj2(1, 3), 22);
}

TEST(AssignmentToObject, MoveConstructor) {
  S21Matrix obj1(2, 4);
  obj1(0, 0) = 11;
  obj1(1, 3) = 22;

  S21Matrix obj2(std::move(obj1));
  EXPECT_EQ(obj2.GetRows(), 2);
  EXPECT_EQ(obj2.GetCols(), 4);
  EXPECT_DOUBLE_EQ(obj2(0, 0), 11);
  EXPECT_DOUBLE_EQ(obj2(1, 3), 22);

  EXPECT_EQ(obj1.GetRows(), 0);
  EXPECT_EQ(obj1.GetCols(), 0);
  EXPECT_TRUE(obj1.GetMatrix() == nullptr);
}

TEST(AssignmentToObject, MoveAssignmentOperator) {
  S21Matrix obj1(2, 4);
  obj1(0, 0) = 11;
  obj1(1, 3) = 22;

  S21Matrix obj2;
  obj2 = std::move(obj1);
  EXPECT_EQ(obj2.GetRows(), 2);
  EXPECT_EQ(obj2.GetCols(), 4);
  EXPECT_DOUBLE_EQ(obj2(0, 0), 11);
  EXPECT_DOUBLE_EQ(obj2(1, 3), 22);

  EXPECT_EQ(obj1.GetRows(), 0);
  EXPECT_EQ(obj1.GetCols(), 0);
  EXPECT_TRUE(obj1.GetMatrix() == nullptr);
}

TEST(CompareForEquality, BothZeroTrue) {
  S21Matrix obj1;
  S21Matrix obj2;

  EXPECT_TRUE(obj1.EqMatrix(obj2));
  EXPECT_TRUE(obj1 == obj2);
}

TEST(CompareForEquality, BothFilledTrue) {
  S21Matrix obj1{3, 3};
  S21Matrix obj2{3, 3};

  EXPECT_TRUE(obj1.EqMatrix(obj2));
  EXPECT_TRUE(obj1 == obj2);

  obj1(2, 2) = 5;
  obj2(2, 2) = 5;

  EXPECT_TRUE(obj1.EqMatrix(obj2));
  EXPECT_TRUE(obj1 == obj2);
}

TEST(CompareForEquality, OneZeroOneFilledFalse) {
  S21Matrix obj1;
  S21Matrix obj2{3, 3};

  EXPECT_FALSE(obj1.EqMatrix(obj2));
  EXPECT_FALSE(obj1 == obj2);

  obj2(2, 2) = 5;

  EXPECT_FALSE(obj1.EqMatrix(obj2));
  EXPECT_FALSE(obj1 == obj2);
}

TEST(CompareForEquality, BothFilledSameSizeFalse) {
  S21Matrix obj1{3, 3};
  S21Matrix obj2{3, 3};

  obj2(2, 2) = 5;

  EXPECT_FALSE(obj1.EqMatrix(obj2));
  EXPECT_FALSE(obj1 == obj2);
}

TEST(CompareForEquality, BothFilledDiffSizeFalse) {
  S21Matrix obj1{2, 3};
  S21Matrix obj2{3, 3};

  EXPECT_FALSE(obj1.EqMatrix(obj2));
  EXPECT_FALSE(obj1 == obj2);
}

TEST(AdditionMatrices, Negative) {
  S21Matrix obj1;
  S21Matrix obj2;
  S21Matrix obj3(2, 2);
  S21Matrix obj4(4, 2);

  EXPECT_ANY_THROW(obj1.SumMatrix(obj2));
  EXPECT_ANY_THROW(obj1.SumMatrix(obj3));
  EXPECT_ANY_THROW(obj3.SumMatrix(obj4));

  EXPECT_ANY_THROW(obj1 + obj2);
  EXPECT_ANY_THROW(obj1 + obj3);
  EXPECT_ANY_THROW(obj3 + obj4);
}

TEST(AdditionMatrices, Positive) {
  S21Matrix obj1(3, 3);
  obj1(0, 0) = 50.34;
  obj1(0, 1) = 4654.453;
  obj1(0, 2) = 345;

  obj1(1, 0) = 56.563;
  obj1(1, 1) = 56.345;
  obj1(1, 2) = 456;

  obj1(2, 0) = 345;
  obj1(2, 1) = 433;
  obj1(2, 2) = 3345;

  S21Matrix obj2(3, 3);
  obj2(0, 0) = 345;
  obj2(0, 1) = 68;
  obj2(0, 2) = 345;

  obj2(1, 0) = -456.56;
  obj2(1, 1) = -345;
  obj2(1, 2) = 86;

  obj2(2, 0) = -456.5;
  obj2(2, 1) = 57;
  obj2(2, 2) = 0.987;

  S21Matrix obj4{obj1};

  obj1.SumMatrix(obj2);
  EXPECT_DOUBLE_EQ(obj1(0, 0), 395.34);
  EXPECT_DOUBLE_EQ(obj1(0, 1), 4722.453);
  EXPECT_DOUBLE_EQ(obj1(0, 2), 690);
  EXPECT_DOUBLE_EQ(obj1(1, 0), -399.997);
  EXPECT_DOUBLE_EQ(obj1(1, 1), -288.655);
  EXPECT_DOUBLE_EQ(obj1(1, 2), 542);
  EXPECT_DOUBLE_EQ(obj1(2, 0), -111.5);
  EXPECT_DOUBLE_EQ(obj1(2, 1), 490);
  EXPECT_DOUBLE_EQ(obj1(2, 2), 3345.987);

  S21Matrix obj3{obj4 + obj2};
  EXPECT_NO_THROW(obj4 + obj2);
  EXPECT_DOUBLE_EQ(obj3(0, 0), 395.34);
  EXPECT_DOUBLE_EQ(obj3(0, 1), 4722.453);
  EXPECT_DOUBLE_EQ(obj3(0, 2), 690);
  EXPECT_DOUBLE_EQ(obj3(1, 0), -399.997);
  EXPECT_DOUBLE_EQ(obj3(1, 1), -288.655);
  EXPECT_DOUBLE_EQ(obj3(1, 2), 542);
  EXPECT_DOUBLE_EQ(obj3(2, 0), -111.5);
  EXPECT_DOUBLE_EQ(obj3(2, 1), 490);
  EXPECT_DOUBLE_EQ(obj3(2, 2), 3345.987);

  obj1 = obj4;
  obj1 += obj2;
  EXPECT_DOUBLE_EQ(obj1(0, 0), 395.34);
  EXPECT_DOUBLE_EQ(obj1(0, 1), 4722.453);
  EXPECT_DOUBLE_EQ(obj1(0, 2), 690);
  EXPECT_DOUBLE_EQ(obj1(1, 0), -399.997);
  EXPECT_DOUBLE_EQ(obj1(1, 1), -288.655);
  EXPECT_DOUBLE_EQ(obj1(1, 2), 542);
  EXPECT_DOUBLE_EQ(obj1(2, 0), -111.5);
  EXPECT_DOUBLE_EQ(obj1(2, 1), 490);
  EXPECT_DOUBLE_EQ(obj1(2, 2), 3345.987);
}

TEST(SubtractionMatrices, Positive) {
  S21Matrix obj1(3, 3);
  obj1(0, 0) = 234;
  obj1(0, 1) = 5698;
  obj1(0, 2) = 23716;

  obj1(1, 0) = 682812.487;
  obj1(1, 1) = 21234;
  obj1(1, 2) = 3459877.34875;

  obj1(2, 0) = 23587.3487;
  obj1(2, 1) = 1.2345;
  obj1(2, 2) = 13.3452;

  S21Matrix obj2(3, 3);
  obj2(0, 0) = 123874;
  obj2(0, 1) = 2387;
  obj2(0, 2) = -3846;

  obj2(1, 0) = 23948.3472;
  obj2(1, 1) = 0.98762;
  obj2(1, 2) = 123.23;

  obj2(2, 0) = 696387.12;
  obj2(2, 1) = 343.43;
  obj2(2, 2) = 9999.9999;

  S21Matrix obj1_copy{obj1};

  obj1.SubMatrix(obj2);
  EXPECT_DOUBLE_EQ(obj1(0, 0), -123640);
  EXPECT_DOUBLE_EQ(obj1(0, 1), 3311);
  EXPECT_DOUBLE_EQ(obj1(0, 2), 27562);
  EXPECT_DOUBLE_EQ(obj1(1, 0), 658864.1398);
  EXPECT_DOUBLE_EQ(obj1(1, 1), 21233.01238);
  EXPECT_DOUBLE_EQ(obj1(1, 2), 3459754.11875);
  EXPECT_DOUBLE_EQ(obj1(2, 0), -672799.7713);
  EXPECT_DOUBLE_EQ(obj1(2, 1), -342.1955);
  EXPECT_DOUBLE_EQ(obj1(2, 2), -9986.6547);

  obj1 = obj1_copy;
  S21Matrix obj3{obj1 - obj2};
  EXPECT_NO_THROW(obj1 - obj2);
  EXPECT_DOUBLE_EQ(obj3(0, 0), -123640);
  EXPECT_DOUBLE_EQ(obj3(0, 1), 3311);
  EXPECT_DOUBLE_EQ(obj3(0, 2), 27562);
  EXPECT_DOUBLE_EQ(obj3(1, 0), 658864.1398);
  EXPECT_DOUBLE_EQ(obj3(1, 1), 21233.01238);
  EXPECT_DOUBLE_EQ(obj3(1, 2), 3459754.11875);
  EXPECT_DOUBLE_EQ(obj3(2, 0), -672799.7713);
  EXPECT_DOUBLE_EQ(obj3(2, 1), -342.1955);
  EXPECT_DOUBLE_EQ(obj3(2, 2), -9986.6547);

  obj1 -= obj2;
  EXPECT_DOUBLE_EQ(obj1(0, 0), -123640);
  EXPECT_DOUBLE_EQ(obj1(0, 1), 3311);
  EXPECT_DOUBLE_EQ(obj1(0, 2), 27562);
  EXPECT_DOUBLE_EQ(obj1(1, 0), 658864.1398);
  EXPECT_DOUBLE_EQ(obj1(1, 1), 21233.01238);
  EXPECT_DOUBLE_EQ(obj1(1, 2), 3459754.11875);
  EXPECT_DOUBLE_EQ(obj1(2, 0), -672799.7713);
  EXPECT_DOUBLE_EQ(obj1(2, 1), -342.1955);
  EXPECT_DOUBLE_EQ(obj1(2, 2), -9986.6547);
}

TEST(MultiplicationMatrices, NumberAndMatricesNegative) {
  S21Matrix obj1;
  S21Matrix obj2{2, 2};

  EXPECT_ANY_THROW(obj1.MulNumber(2));
  EXPECT_ANY_THROW(obj1 * 2);
  EXPECT_ANY_THROW(obj1 *= 2);

  EXPECT_ANY_THROW(obj1.MulMatrix(obj2));
  EXPECT_ANY_THROW(obj1 * obj2);
  EXPECT_ANY_THROW(obj1 *= obj2);
}

TEST(MultiplicationMatrices, NumberPositive) {
  S21Matrix obj1(3, 3);
  obj1(0, 0) = 50.34;
  obj1(0, 1) = 4654.453;
  obj1(0, 2) = 345;

  obj1(1, 0) = 56.563;
  obj1(1, 1) = 56.345;
  obj1(1, 2) = 456;

  obj1(2, 0) = 345;
  obj1(2, 1) = 433;
  obj1(2, 2) = 3345;

  S21Matrix obj1_copy{obj1};

  obj1.MulNumber(178);
  EXPECT_DOUBLE_EQ(obj1(0, 0), 8960.52);
  EXPECT_DOUBLE_EQ(obj1(0, 1), 828492.634);
  EXPECT_DOUBLE_EQ(obj1(0, 2), 61410);
  EXPECT_DOUBLE_EQ(obj1(1, 0), 10068.214);
  EXPECT_DOUBLE_EQ(obj1(1, 1), 10029.41);
  EXPECT_DOUBLE_EQ(obj1(1, 2), 81168);
  EXPECT_DOUBLE_EQ(obj1(2, 0), 61410);
  EXPECT_DOUBLE_EQ(obj1(2, 1), 77074);
  EXPECT_DOUBLE_EQ(obj1(2, 2), 595410);

  obj1 = obj1_copy;
  S21Matrix obj2{obj1 * 178};
  EXPECT_DOUBLE_EQ(obj2(0, 0), 8960.52);
  EXPECT_DOUBLE_EQ(obj2(0, 1), 828492.634);
  EXPECT_DOUBLE_EQ(obj2(0, 2), 61410);
  EXPECT_DOUBLE_EQ(obj2(1, 0), 10068.214);
  EXPECT_DOUBLE_EQ(obj2(1, 1), 10029.41);
  EXPECT_DOUBLE_EQ(obj2(1, 2), 81168);
  EXPECT_DOUBLE_EQ(obj2(2, 0), 61410);
  EXPECT_DOUBLE_EQ(obj2(2, 1), 77074);

  obj1 *= 178;
  EXPECT_DOUBLE_EQ(obj1(0, 0), 8960.52);
  EXPECT_DOUBLE_EQ(obj1(0, 1), 828492.634);
  EXPECT_DOUBLE_EQ(obj1(0, 2), 61410);
  EXPECT_DOUBLE_EQ(obj1(1, 0), 10068.214);
  EXPECT_DOUBLE_EQ(obj1(1, 1), 10029.41);
  EXPECT_DOUBLE_EQ(obj1(1, 2), 81168);
  EXPECT_DOUBLE_EQ(obj1(2, 0), 61410);
  EXPECT_DOUBLE_EQ(obj1(2, 1), 77074);
  EXPECT_DOUBLE_EQ(obj1(2, 2), 595410);
}

TEST(MultiplicationMatrices, MatricesPositive) {
  S21Matrix obj1(4, 5);
  S21Matrix obj2(5, 4);

  obj1(0, 0) = 38;
  obj1(0, 1) = 45.56;
  obj1(0, 2) = 12.484;
  obj1(0, 3) = 17892;
  obj1(0, 4) = 41.54;

  obj1(1, 0) = 12.1;
  obj1(1, 1) = 0.999;
  obj1(1, 2) = 99;
  obj1(1, 3) = 9;
  obj1(1, 4) = 12.4;

  obj1(2, 0) = 0.154;
  obj1(2, 1) = 0.487;
  obj1(2, 2) = 4110.4;
  obj1(2, 3) = 12;
  obj1(2, 4) = 38;

  obj1(3, 0) = 45.58;
  obj1(3, 1) = 0.1;
  obj1(3, 2) = 0.12;
  obj1(3, 3) = 38;
  obj1(3, 4) = 3825;

  obj2(0, 0) = 0;
  obj2(0, 1) = 14;
  obj2(0, 2) = 1;
  obj2(0, 3) = 85.2;

  obj2(1, 0) = 1.254;
  obj2(1, 1) = 13.544;
  obj2(1, 2) = 12;
  obj2(1, 3) = 1;

  obj2(2, 0) = 148;
  obj2(2, 1) = 58;
  obj2(2, 2) = 698;
  obj2(2, 3) = 1.1235;

  obj2(3, 0) = 125;
  obj2(3, 1) = 48;
  obj2(3, 2) = 75.1;
  obj2(3, 3) = 2.25;

  obj2(4, 0) = 12.5;
  obj2(4, 1) = 51;
  obj2(4, 2) = 34;
  obj2(4, 3) = 12;

  S21Matrix obj1_copy{obj1};

  obj1.MulMatrix(obj2);
  EXPECT_DOUBLE_EQ(obj1(0, 0), 2238924.01424);
  EXPECT_DOUBLE_EQ(obj1(0, 1), 862807.67664);
  EXPECT_DOUBLE_EQ(obj1(0, 2), 1354400.112);
  EXPECT_DOUBLE_EQ(obj1(0, 3), 44052.665774);
  EXPECT_DOUBLE_EQ(obj1(1, 0), 15933.252746);
  EXPECT_DOUBLE_EQ(obj1(1, 1), 6989.330456);
  EXPECT_DOUBLE_EQ(obj1(1, 2), 70223.588);
  EXPECT_DOUBLE_EQ(obj1(1, 3), 1312.1955);
  EXPECT_DOUBLE_EQ(obj1(2, 0), 610314.810698);
  EXPECT_DOUBLE_EQ(obj1(2, 1), 240925.951928);
  EXPECT_DOUBLE_EQ(obj1(2, 2), 2871258.398);
  EXPECT_DOUBLE_EQ(obj1(2, 3), 5114.6422);
  EXPECT_DOUBLE_EQ(obj1(3, 0), 52580.3854);
  EXPECT_DOUBLE_EQ(obj1(3, 1), 197545.4344);
  EXPECT_DOUBLE_EQ(obj1(3, 2), 133034.34);
  EXPECT_DOUBLE_EQ(obj1(3, 3), 49869.15082);

  obj1 = obj1_copy * obj2;
  EXPECT_DOUBLE_EQ(obj1(0, 0), 2238924.01424);
  EXPECT_DOUBLE_EQ(obj1(0, 1), 862807.67664);
  EXPECT_DOUBLE_EQ(obj1(0, 2), 1354400.112);
  EXPECT_DOUBLE_EQ(obj1(0, 3), 44052.665774);
  EXPECT_DOUBLE_EQ(obj1(1, 0), 15933.252746);
  EXPECT_DOUBLE_EQ(obj1(1, 1), 6989.330456);
  EXPECT_DOUBLE_EQ(obj1(1, 2), 70223.588);
  EXPECT_DOUBLE_EQ(obj1(1, 3), 1312.1955);
  EXPECT_DOUBLE_EQ(obj1(2, 0), 610314.810698);
  EXPECT_DOUBLE_EQ(obj1(2, 1), 240925.951928);
  EXPECT_DOUBLE_EQ(obj1(2, 2), 2871258.398);
  EXPECT_DOUBLE_EQ(obj1(2, 3), 5114.6422);
  EXPECT_DOUBLE_EQ(obj1(3, 0), 52580.3854);
  EXPECT_DOUBLE_EQ(obj1(3, 1), 197545.4344);
  EXPECT_DOUBLE_EQ(obj1(3, 2), 133034.34);
  EXPECT_DOUBLE_EQ(obj1(3, 3), 49869.15082);

  obj1 = obj1_copy;
  obj1 *= obj2;
  EXPECT_DOUBLE_EQ(obj1(0, 0), 2238924.01424);
  EXPECT_DOUBLE_EQ(obj1(0, 1), 862807.67664);
  EXPECT_DOUBLE_EQ(obj1(0, 2), 1354400.112);
  EXPECT_DOUBLE_EQ(obj1(0, 3), 44052.665774);
  EXPECT_DOUBLE_EQ(obj1(1, 0), 15933.252746);
  EXPECT_DOUBLE_EQ(obj1(1, 1), 6989.330456);
  EXPECT_DOUBLE_EQ(obj1(1, 2), 70223.588);
  EXPECT_DOUBLE_EQ(obj1(1, 3), 1312.1955);
  EXPECT_DOUBLE_EQ(obj1(2, 0), 610314.810698);
  EXPECT_DOUBLE_EQ(obj1(2, 1), 240925.951928);
  EXPECT_DOUBLE_EQ(obj1(2, 2), 2871258.398);
  EXPECT_DOUBLE_EQ(obj1(2, 3), 5114.6422);
  EXPECT_DOUBLE_EQ(obj1(3, 0), 52580.3854);
  EXPECT_DOUBLE_EQ(obj1(3, 1), 197545.4344);
  EXPECT_DOUBLE_EQ(obj1(3, 2), 133034.34);
  EXPECT_DOUBLE_EQ(obj1(3, 3), 49869.15082);
}

TEST(TransposeMatrix, Negative) {
  S21Matrix obj;
  EXPECT_ANY_THROW(obj.Transpose());
}

TEST(TransposeMatrix, Positive) {
  S21Matrix obj{3, 2};

  obj(0, 0) = 1;
  obj(1, 0) = 2;
  obj(2, 0) = 3;
  obj(0, 1) = 4;
  obj(1, 1) = 5;
  obj(2, 1) = 6;

  S21Matrix obj1 = obj.Transpose();

  EXPECT_DOUBLE_EQ(obj1(0, 0), 1);
  EXPECT_DOUBLE_EQ(obj1(0, 1), 2);
  EXPECT_DOUBLE_EQ(obj1(0, 2), 3);
  EXPECT_DOUBLE_EQ(obj1(1, 0), 4);
  EXPECT_DOUBLE_EQ(obj1(1, 1), 5);
  EXPECT_DOUBLE_EQ(obj1(1, 2), 6);
}

TEST(DeterminantMatrix, Negative) {
  S21Matrix obj1;
  EXPECT_ANY_THROW(obj1.Determinant());

  S21Matrix obj2{2, 3};
  EXPECT_ANY_THROW(obj2.Determinant());
}

TEST(DeterminantMatrix, Positive) {
  S21Matrix obj1{1, 1};
  obj1(0, 0) = 5.25;
  EXPECT_DOUBLE_EQ(obj1.Determinant(), 5.25);

  S21Matrix obj2{3, 3};
  obj2(0, 0) = 1;
  obj2(0, 1) = 2;
  obj2(0, 2) = 3;
  obj2(1, 0) = 4;
  obj2(1, 1) = 5;
  obj2(1, 2) = 6;
  obj2(2, 0) = 7;
  obj2(2, 1) = 8;
  obj2(2, 2) = 9;
  EXPECT_DOUBLE_EQ(obj2.Determinant(), 0);

  S21Matrix obj3(4, 4);
  obj3(0, 0) = 1;
  obj3(0, 1) = 2;
  obj3(0, 2) = 3;
  obj3(0, 3) = 4;

  obj3(1, 0) = 4;
  obj3(1, 1) = 5;
  obj3(1, 2) = 3;
  obj3(1, 3) = 2;

  obj3(2, 0) = 5;
  obj3(2, 1) = 6;
  obj3(2, 2) = 6;
  obj3(2, 3) = 7;

  obj3(3, 0) = 9;
  obj3(3, 1) = 4;
  obj3(3, 2) = 1;
  obj3(3, 3) = 6;
  double res = obj3.Determinant();
  EXPECT_DOUBLE_EQ(res, -46.0);
}

TEST(CalcComplements, Negative) {
  S21Matrix obj1;
  EXPECT_ANY_THROW(obj1.CalcComplements());

  S21Matrix obj2{2, 3};
  EXPECT_ANY_THROW(obj2.CalcComplements());
}

TEST(CalcComplements, Positive) {
  S21Matrix obj1{3, 3};

  obj1(0, 0) = 1;
  obj1(0, 1) = 2;
  obj1(0, 2) = 3;
  obj1(1, 0) = 0;
  obj1(1, 1) = 4;
  obj1(1, 2) = 2;
  obj1(2, 0) = 5;
  obj1(2, 1) = 2;
  obj1(2, 2) = 1;

  S21Matrix obj2{obj1.CalcComplements()};
  EXPECT_DOUBLE_EQ(obj2(0, 0), 0);
  EXPECT_DOUBLE_EQ(obj2(0, 1), 10);
  EXPECT_DOUBLE_EQ(obj2(0, 2), -20);
  EXPECT_DOUBLE_EQ(obj2(1, 0), 4);
  EXPECT_DOUBLE_EQ(obj2(1, 1), -14);
  EXPECT_DOUBLE_EQ(obj2(1, 2), 8);
  EXPECT_DOUBLE_EQ(obj2(2, 0), -8);
  EXPECT_DOUBLE_EQ(obj2(2, 1), -2);
  EXPECT_DOUBLE_EQ(obj2(2, 2), 4);
}

TEST(InverseMatrix, Negative) {
  S21Matrix obj1;
  EXPECT_ANY_THROW(obj1.InverseMatrix());

  S21Matrix obj2{2, 3};
  EXPECT_ANY_THROW(obj2.InverseMatrix());

  S21Matrix obj3{2, 2};
  obj3(0, 0) = 4;
  obj3(0, 1) = 2;
  obj3(1, 0) = 2;
  obj3(1, 1) = 1;
  EXPECT_ANY_THROW(obj3.InverseMatrix());
}

TEST(InverseMatrix, Positive) {
  S21Matrix obj1{3, 3};
  obj1(0, 0) = 2;
  obj1(0, 1) = 5;
  obj1(0, 2) = 7;
  obj1(1, 0) = 6;
  obj1(1, 1) = 3;
  obj1(1, 2) = 4;
  obj1(2, 0) = 5;
  obj1(2, 1) = -2;
  obj1(2, 2) = -3;

  S21Matrix obj2{obj1.InverseMatrix()};
  EXPECT_DOUBLE_EQ(obj2(0, 0), 1);
  EXPECT_DOUBLE_EQ(obj2(0, 1), -1);
  EXPECT_DOUBLE_EQ(obj2(0, 2), 1);
  EXPECT_DOUBLE_EQ(obj2(1, 0), -38);
  EXPECT_DOUBLE_EQ(obj2(1, 1), 41);
  EXPECT_DOUBLE_EQ(obj2(1, 2), -34);
  EXPECT_DOUBLE_EQ(obj2(2, 0), 27);
  EXPECT_DOUBLE_EQ(obj2(2, 1), -29);
  EXPECT_DOUBLE_EQ(obj2(2, 2), 24);

  obj1.MulMatrix(obj2);
  S21Matrix E{3, 3};
  E(0, 0) = 1;
  E(0, 1) = 0;
  E(0, 2) = 0;
  E(1, 0) = 0;
  E(1, 1) = 1;
  E(1, 2) = 0;
  E(2, 0) = 0;
  E(2, 1) = 0;
  E(2, 2) = 1;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      EXPECT_DOUBLE_EQ(obj1(i, j), E(i, j));
    }
  }
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}