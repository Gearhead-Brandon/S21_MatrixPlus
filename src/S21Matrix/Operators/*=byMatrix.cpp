#include "../S21Matrix.hpp"

S21Matrix &S21Matrix::operator*=(const S21Matrix &other) {

  MulMatrix(other);

  return *this;
}