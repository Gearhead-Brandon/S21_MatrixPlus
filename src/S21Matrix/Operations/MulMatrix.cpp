#include "../S21Matrix.hpp"

void S21Matrix::MulMatrix(const S21Matrix &other) {

  if (!EqColsToRows(other.rows_))
    throw std::invalid_argument(NumColsNotEqNumRows);

  S21Matrix temp(rows_, other.cols_);

  for (int i = 0; i < this->rows_; i++)
    for (int j = 0; j < other.cols_; j++)
      for (int k = 0; k < other.rows_; k++)
        temp.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];

  CopyMatrix(temp);
}