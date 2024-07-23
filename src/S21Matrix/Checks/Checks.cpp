#include "../S21Matrix.hpp"

bool S21Matrix::CheckSameSize(int other_rows, int other_cols) {
  if ((rows_ != other_rows) || (cols_ != other_cols))
    return false;

  return true;
}

bool S21Matrix::EqColsToRows(int other_rows) {

  if (cols_ != other_rows)
    return false;

  return true;
}

void S21Matrix::CheckMatrixQuadraticity() {

  if (rows_ != cols_)
    throw std::invalid_argument(MatrixNotSquare);
}

void S21Matrix::CheckMatrixSize(int row, int col) {

  if ((row < 0) || (col < 0) || (row >= rows_) || (col >= cols_))
    throw std::invalid_argument(IndexesOutOfRange);
}