#include "../S21Matrix.hpp"

void S21Matrix::SetCols(int newCols) {

  if (newCols != cols_)
    Resize(rows_, newCols);
}