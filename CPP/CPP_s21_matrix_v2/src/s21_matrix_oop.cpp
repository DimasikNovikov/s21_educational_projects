#include "s21_matrix_oop.h"

//=================================================================
//================== Constructors and Destructor ==================
//=================================================================

S21Matrix::S21Matrix() : S21Matrix(0, 0) {}

S21Matrix::S21Matrix(int rows, int cols) {
  if (rows > 0 && cols > 0) {
    rows_ = rows;
    cols_ = cols;

    matrix_ = new double* [rows_] {};

    for (int i = 0; i < rows_; i++) {
      matrix_[i] = new double[cols_]{};
    }
  } else if (rows == 0 && cols == 0) {
    rows_ = 0;
    cols_ = 0;
    matrix_ = nullptr;
  } else {
    throw "ERROR: Pointed size of the matrix is not correct!";
  }
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : S21Matrix(other.rows_, other.cols_) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix&& other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = other.matrix_;
  other.matrix_ = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;
}

S21Matrix::~S21Matrix() {
  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; i++) {
      if (matrix_[i] != nullptr) {
        delete[] matrix_[i];
        matrix_[i] = nullptr;
      }
    }

    delete[] matrix_;
    matrix_ = nullptr;
  }
}

//=================================================================
//================== Basic Methods ================================
//=================================================================

bool S21Matrix::EqMatrix(const S21Matrix& other) const {
  const double kEps = 1e-7;
  bool return_value{false};

  if (matrix_ != nullptr && other.matrix_ != nullptr) {
    if (rows_ == other.rows_ && cols_ == other.cols_) {
      return_value = true;
      for (int i = 0; i < rows_ && return_value; i++) {
        for (int j = 0; j < cols_ && return_value; j++) {
          if (fabs(matrix_[i][j] - other.matrix_[i][j]) > kEps) {
            return_value = false;
          }
        }
      }
    }
  } else if (matrix_ == nullptr && other.matrix_ == nullptr) {
    return_value = true;
  }

  return return_value;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (matrix_ != nullptr && other.matrix_ != nullptr) {
    if (rows_ == other.rows_ && cols_ == other.cols_) {
      for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
          matrix_[i][j] += other.matrix_[i][j];
        }
      }
    } else {
      throw "ERROR: Different matrix dimensions.";
    }

  } else {
    throw "ERROR: One of the two or both matrices are not initialized.";
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (matrix_ != nullptr && other.matrix_ != nullptr) {
    if (rows_ == other.rows_ && cols_ == other.cols_) {
      for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
          matrix_[i][j] -= other.matrix_[i][j];
        }
      }
    } else {
      throw "ERROR: Different matrix dimensions.";
    }

  } else {
    throw "ERROR: One of the two or both matrices are not initialized.";
  }
}

void S21Matrix::MulNumber(const double num) {
  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] *= num;
      }
    }
  } else {
    throw "ERROR: The matrix is not initialized.";
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (matrix_ != nullptr && other.matrix_ != nullptr) {
    if (cols_ == other.rows_) {
      S21Matrix temp{*this};
      cols_ = other.cols_;
      for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
          double sum = 0;
          for (int k = 0; k < temp.cols_; k++) {
            sum += temp.matrix_[i][k] * other.matrix_[k][j];
          }
          matrix_[i][j] = sum;
        }
      }
    } else {
      throw "The number of columns of the first matrix does not equal the number of rows of the second matrix.";
    }
  } else {
    throw "ERROR: One of the two or both matrices are not initialized.";
  }
}

S21Matrix S21Matrix::Transpose() {
  if (matrix_ != nullptr) {
    S21Matrix temp{cols_, rows_};
    for (int i = 0; i < temp.rows_; i++) {
      for (int j = 0; j < temp.cols_; j++) {
        temp.matrix_[i][j] = matrix_[j][i];
      }
    }

    return temp;

  } else {
    throw "ERROR: The matrix is not initialized.";
  }
}

double S21Matrix::Determinant() {
  double return_value = 0;

  if (matrix_ != nullptr) {
    if (rows_ == cols_) {
      if (rows_ == 1) {
        return_value = matrix_[0][0];
      } else if (rows_ == 2) {
        return_value =
            matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
      } else {
        // По первой строке
        for (int j = 0; j < cols_; j++) {
          // S21Matrix minor{GetMinor(0, j)};
          return_value +=
              pow(-1, j) * matrix_[0][j] * GetMinor(0, j).Determinant();
        }
      }
    } else {
      throw "The matrix is not square.";
    }
  } else {
    throw "ERROR: The matrix is not initialized.";
  }

  return return_value;
}

S21Matrix S21Matrix::CalcComplements() {
  if (matrix_ != nullptr) {
    if (rows_ == cols_) {
      S21Matrix return_value{rows_, cols_};
      for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
          // S21Matrix minor {GetMinor(i, j)};
          return_value.matrix_[i][j] =
              pow(-1, i + j) * GetMinor(i, j).Determinant();
        }
      }

      return return_value;
    } else {
      throw "The matrix is not square.";
    }
  } else {
    throw "ERROR: The matrix is not initialized.";
  }
}

S21Matrix S21Matrix::InverseMatrix() {
  if (matrix_ != nullptr) {
    if (rows_ == cols_) {
      S21Matrix result{rows_, cols_};

      double det = this->Determinant();
      if (det == 0) {
        throw "Matrix determinant is 0.";
      }

      result = this->CalcComplements();
      result = result.Transpose();

      result.MulNumber(1.0 / det);

      return result;

    } else {
      throw "The matrix is not square.";
    }
  } else {
    throw "ERROR: The matrix is not initialized.";
  }
}

//=================================================================
//================== Overloaded operators =========================
//=================================================================

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    this->~S21Matrix();
    S21Matrix temp{other.rows_, other.cols_};
    rows_ = other.rows_;
    cols_ = other.cols_;
    matrix_ = temp.matrix_;
    temp.matrix_ = nullptr;
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }

  return *this;
}

S21Matrix& S21Matrix::operator=(S21Matrix&& other) {
  this->~S21Matrix();
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = other.matrix_;
  other.matrix_ = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;

  return *this;
}

bool S21Matrix::operator==(const S21Matrix& other) const {
  return EqMatrix(other);
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) const {
  S21Matrix result{*this};
  result.SumMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) const {
  S21Matrix result{*this};
  result.SubMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const int number) const {
  S21Matrix result{*this};
  result.MulNumber(number);
  return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) const {
  S21Matrix result{*this};
  result.MulMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator+=(const S21Matrix& other) {
  SumMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator-=(const S21Matrix& other) {
  SubMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator*=(const int number) {
  MulNumber(number);
  return *this;
}

S21Matrix S21Matrix::operator*=(const S21Matrix other) {
  MulMatrix(other);
  return *this;
}

double& S21Matrix::operator()(int i, int j) {
  if ((i < 0 || i >= rows_) || (j < 0 || j >= cols_)) {
    throw "Index is outside the matrix.";
  }

  return matrix_[i][j];
}

//=================================================================
//================== Extra methods ================================
//=================================================================

int S21Matrix::GetRows() const { return rows_; }

int S21Matrix::GetCols() const { return cols_; }

double** S21Matrix::GetMatrix() const { return matrix_; }

S21Matrix S21Matrix::GetMinor(int row, int col) {
  S21Matrix minor{rows_ - 1, cols_ - 1};
  for (int i = 0, i_minor = 0; i < rows_; i++) {
    if (i != row) {
      for (int j = 0, j_minor = 0; j < cols_; j++) {
        if (j != col) {
          minor.matrix_[i_minor][j_minor] = matrix_[i][j];
          j_minor++;
        }
      }
      i_minor++;
    }
  }

  return minor;
}