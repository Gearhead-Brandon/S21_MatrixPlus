#include "../S21Matrix.hpp"

void S21Matrix::SetRows(int newRows) {

  if (newRows != rows_)
    Resize(newRows, cols_);
}
