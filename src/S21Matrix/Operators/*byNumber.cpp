#include "../S21Matrix.hpp"

S21Matrix S21Matrix::operator*(const double &value) {

  S21Matrix temp(*this);
  temp.MulNumber(value);

  return temp;
}