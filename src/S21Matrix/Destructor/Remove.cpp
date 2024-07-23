#include "../S21Matrix.hpp"

void S21Matrix::RemoveMatrix() {

  if (matrix_) {

    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
      matrix_[i] = nullptr;
    }

    delete[] matrix_;
    matrix_ = nullptr;
    rows_ = 0;
    cols_ = 0;
  }
}
