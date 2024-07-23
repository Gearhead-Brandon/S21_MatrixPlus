#include "../S21Matrix.hpp"

S21Matrix S21Matrix::CalcComplements() {

  CheckMatrixQuadraticity();

  S21Matrix result(rows_, cols_);

  if (rows_ != 1) {

    S21Matrix minor(rows_ - 1, cols_ - 1);

    for (int sign = 0, i = 0; i < rows_; i++)
      for (int j = 0; j < cols_; j++) {
        CreateMinor(minor, i, j);
        sign = ((i + j) % 2 == 0) ? 1 : -1;
        result.matrix_[i][j] = sign * minor.FindDet();
      }
  }

  return result;
}