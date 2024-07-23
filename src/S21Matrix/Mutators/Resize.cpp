#include "../S21Matrix.hpp"

void S21Matrix::Resize(int newRows, int newCols) {

  if ((newRows < 0) || (newCols < 0))
    throw std::invalid_argument(IncorrectValuesRowsOrColumnsResize);

  S21Matrix temp(newRows, newCols);

  int minRows = (newRows < rows_) ? newRows : rows_;
  int minCols = (newCols < cols_) ? newCols : cols_;

  for (int i = 0; i < minRows; i++)
    for (int j = 0; j < minCols; j++)
      temp.matrix_[i][j] = matrix_[i][j];

  *this = temp;
}