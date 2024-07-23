#include "../S21Matrix.hpp"

S21Matrix S21Matrix::InverseMatrix() {

  double det = Determinant();

  if (det == 0.0)
    throw std::invalid_argument(DetIsZero);

  S21Matrix temp = CalcComplements(), result(rows_, cols_);

  temp = temp.Transpose();

  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++)
      result.matrix_[i][j] = temp.matrix_[i][j] / det;

  return result;
}
