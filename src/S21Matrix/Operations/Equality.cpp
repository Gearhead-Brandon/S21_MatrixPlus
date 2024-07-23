#include "../S21Matrix.hpp"

bool S21Matrix::EqMatrix(const S21Matrix &other) {

  if (!CheckSameSize(other.rows_, other.cols_))
    return false;

  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++)
      if (matrix_[i][j] != other.matrix_[i][j])
        return false;

  return true;
}