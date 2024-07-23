#include "../S21Matrix.hpp"

S21Matrix::S21Matrix(const S21Matrix &other) : matrix_(nullptr) {

  CopyMatrix(other);
}

void S21Matrix::CopyMatrix(const S21Matrix &other) {

  RemoveMatrix();

  rows_ = other.rows_;
  cols_ = other.cols_;

  CreateMatrix();

  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++)
      matrix_[i][j] = other.matrix_[i][j];
}
