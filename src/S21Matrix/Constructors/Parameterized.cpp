#include "../S21Matrix.hpp"

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols)
{
  CreateMatrix();
}