#include "../S21Matrix.hpp"

bool S21Matrix::PrintMatrix() const {

  if (matrix_ == nullptr) {
    std::cout << "Matrix pointer is null in print" << std::endl;
    return false;
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      std::cout << matrix_[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << "\n";

  return true;
}