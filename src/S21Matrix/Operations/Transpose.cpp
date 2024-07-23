#include "../S21Matrix.hpp"
S21Matrix S21Matrix::Transpose() {

  S21Matrix temp(cols_, rows_);

  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++)
      temp.matrix_[j][i] = matrix_[i][j];

  return temp;
}