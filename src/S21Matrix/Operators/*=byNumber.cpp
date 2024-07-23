#include "../S21Matrix.hpp"

S21Matrix &S21Matrix::operator*=(const double &value) {

  MulNumber(value);

  return *this;
}