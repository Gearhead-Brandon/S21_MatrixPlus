#include "../S21Matrix.hpp"

void S21Matrix::CreateMatrix() {

  if (rows_ > 0 && cols_ > 0) {

    matrix_ = new double *[rows_];

    for (int i = 0; i < rows_; i++)
      matrix_[i] = new double[cols_];

      calloc();


  } else
    throw std::invalid_argument(IncorrectValuesRowsOrColumns);
}