#include "../S21Matrix.hpp"

double &S21Matrix::operator()(int i, int j) {
  CheckMatrixSize(i, j);
  return matrix_[i][j];
}
