#include "../S21Matrix.hpp"

double S21Matrix::Determinant() {

  CheckMatrixQuadraticity();

  return FindDet();
}

double S21Matrix::FindDet() {

  if (rows_ == 1)
    return matrix_[0][0];

  S21Matrix temp(rows_ - 1, cols_ - 1);

  double result = 0;

  for (int sign = 1, i = 0; i < rows_; i++, sign *= -1) {
    CreateMinor(temp, 0, i);
    result += sign * (matrix_[0][i] * temp.FindDet());
  }

  return result;
}

void S21Matrix::CreateMinor(S21Matrix &temp, int skip_row, int skip_col) {

  for (int row = 0, i = 0; row < rows_; row++)
    for (int col = 0, j = 0; col < rows_; col++)
      if (row != skip_row && col != skip_col) {

        temp.matrix_[i][j++] = matrix_[row][col];

        if (j == rows_ - 1) {
          j = 0;
          i++;
        }
      }
}
