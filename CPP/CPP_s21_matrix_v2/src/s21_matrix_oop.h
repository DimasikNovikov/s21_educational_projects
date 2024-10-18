#ifndef S21_MATRIX_OOP_H_
#define S21_MATRIX_OOP_H_

#include <cmath>
#include <iostream>

class S21Matrix {
 private:
  int rows_;
  int cols_;
  double** matrix_;

 public:
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  ~S21Matrix();

  bool EqMatrix(const S21Matrix& other) const;

  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);

  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  S21Matrix operator+(const S21Matrix& other) const;
  S21Matrix operator-(const S21Matrix& other) const;
  S21Matrix operator*(const int number) const;
  S21Matrix operator*(const S21Matrix& other) const;

  bool operator==(const S21Matrix& other) const;

  S21Matrix operator+=(const S21Matrix& other);
  S21Matrix operator-=(const S21Matrix& other);
  S21Matrix operator*=(const int number);
  S21Matrix operator*=(const S21Matrix other);
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator=(S21Matrix&& other);
  double& operator()(int i, int j);

  int GetRows() const;
  int GetCols() const;
  double** GetMatrix() const;
  S21Matrix GetMinor(int row, int col);
};

#endif