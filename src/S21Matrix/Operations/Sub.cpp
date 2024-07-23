#include "../S21Matrix.hpp"

void S21Matrix::SubMatrix(const S21Matrix &other) {

  if (!CheckSameSize(other.rows_, other.cols_))
    throw std::invalid_argument(DiffSizesMatrices);

  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++)
      matrix_[i][j] -= other.matrix_[i][j];
}