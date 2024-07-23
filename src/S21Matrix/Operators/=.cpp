#include "../S21Matrix.hpp"

S21Matrix &S21Matrix::operator=(const S21Matrix &other) {

  if (this != &other)
    CopyMatrix(other);

  return *this;
}