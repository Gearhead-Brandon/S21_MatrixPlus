#include <gtest/gtest.h>

#include "../S21Matrix/S21Matrix.hpp"

class S21MatrixTest : public ::testing::Test {
protected:
  void SetUp() override {}
  void TearDown() override {}
};

TEST_F(S21MatrixTest, DefaultConstructor) {
  S21Matrix matrix;
  EXPECT_EQ(matrix.GetRows(), 3);
  EXPECT_EQ(matrix.GetCols(), 3);

  //####################################################

  EXPECT_THROW(S21Matrix matrix1(2, -2), std::invalid_argument);
  EXPECT_THROW(S21Matrix matrix1(-2, 2), std::invalid_argument);
}

TEST_F(S21MatrixTest, ParameterizedConstructor) {
  int rows = 5, cols = 4;
  S21Matrix matrix(rows, cols);
  EXPECT_EQ(matrix.GetRows(), rows);
  EXPECT_EQ(matrix.GetCols(), cols);
}

TEST_F(S21MatrixTest, CopyConstructor) {
  S21Matrix original(2, 2);
  S21Matrix copy(original);
  EXPECT_EQ(copy.GetRows(), original.GetRows());
  EXPECT_EQ(copy.GetCols(), original.GetCols());
}

TEST_F(S21MatrixTest, MoveConstructor) {
  S21Matrix original(3, 3);
  S21Matrix moved(std::move(original));
  EXPECT_EQ(moved.GetRows(), 3);
  EXPECT_EQ(moved.GetCols(), 3);
  EXPECT_EQ(original.GetRows(), 0);
  EXPECT_EQ(original.GetCols(), 0);
}

TEST_F(S21MatrixTest, EqMatrix) {
  S21Matrix matrix1, matrix2;
  if (matrix1 == matrix2) {
    EXPECT_EQ(true, matrix1.EqMatrix(matrix2));
  }
  matrix2.Resize(4, 3);
  EXPECT_EQ(false, matrix1.EqMatrix(matrix2));
  matrix2.Resize(3, 4);
  EXPECT_EQ(false, matrix1.EqMatrix(matrix2));
  matrix2.Resize(3, 3);
  matrix2(1, 1) = 5;
  EXPECT_EQ(false, matrix1.EqMatrix(matrix2));

  //#################################################

  S21Matrix matrix3(3, 3), matrix4(3, 3);
  std::cout << std::endl;
  matrix3.FillNumbers();
  matrix4.FillNumbers();
  EXPECT_EQ(true, matrix3.EqMatrix(matrix4));
}

TEST_F(S21MatrixTest, Resize) {
  S21Matrix matrix(3, 3);
  EXPECT_THROW(matrix.Resize(2, -5), std::invalid_argument);
  EXPECT_THROW(matrix.Resize(-2, 3), std::invalid_argument);
}

TEST_F(S21MatrixTest, SumMatrix) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(2, 2);
  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  matrix2(0, 0) = 5;
  matrix2(0, 1) = 6;
  matrix2(1, 0) = 7;
  matrix2(1, 1) = 8;
  matrix1 += matrix2;
  EXPECT_EQ(matrix1(0, 0), 6);
  EXPECT_EQ(matrix1(0, 1), 8);
  EXPECT_EQ(matrix1(1, 0), 10);
  EXPECT_EQ(matrix1(1, 1), 12);
  matrix1 = matrix1 + matrix2;
  matrix1.Resize(5, 2);
  EXPECT_THROW(matrix1 = matrix1 + matrix2, std::invalid_argument);
  EXPECT_THROW(matrix1.SumMatrix(matrix2), std::invalid_argument);
  matrix1.Resize(2, 5);
  EXPECT_THROW(matrix1.SumMatrix(matrix2), std::invalid_argument);
}

TEST_F(S21MatrixTest, SubMatrix) {
  S21Matrix matrix1(2, 2);
  S21Matrix matrix2(2, 2);
  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  matrix2(0, 0) = 5;
  matrix2(0, 1) = 6;
  matrix2(1, 0) = 7;
  matrix2(1, 1) = 8;
  matrix1 -= matrix2;
  EXPECT_EQ(matrix1(0, 0), -4);
  EXPECT_EQ(matrix1(0, 1), -4);
  EXPECT_EQ(matrix1(1, 0), -4);
  EXPECT_EQ(matrix1(1, 1), -4);

  matrix1 = matrix1 - matrix2;
  matrix1.Resize(5, 2);
  EXPECT_THROW(matrix1 - matrix2, std::invalid_argument);
  EXPECT_THROW(matrix1.SubMatrix(matrix2), std::invalid_argument);

  matrix1.Resize(2, 5);
  EXPECT_THROW(matrix1.SubMatrix(matrix2), std::invalid_argument);
  matrix1 = matrix1;
}

TEST_F(S21MatrixTest, MulNumber) {
  S21Matrix matrix(2, 2);
  matrix.FillNumbers();
  matrix *= 5;
  EXPECT_EQ(matrix(0, 0), 5);
  EXPECT_EQ(matrix(0, 1), 10);
  EXPECT_EQ(matrix(1, 0), 15);
  EXPECT_EQ(matrix(1, 1), 20);
}

TEST_F(S21MatrixTest, MulMatrix) {
  S21Matrix matrix(2, 2);
  S21Matrix matrix1(2, 2);
  matrix1.FillNumbers();

  matrix.FillNumbers();
  matrix *= matrix1;
  S21Matrix matrix2;
  double tmp = matrix2(0, 0);
  EXPECT_EQ(matrix(0, 0), 7);
  EXPECT_EQ(matrix(0, 1), 10);
  EXPECT_EQ(matrix(1, 0), 15);
  EXPECT_EQ(matrix(1, 1), 22);
  matrix = matrix * matrix1;
  matrix1.Resize(4, 2);
  EXPECT_THROW(matrix = matrix * matrix1, std::invalid_argument);

  //########################################################################
  
  S21Matrix matrix3;
  matrix3.FillNumbers();
  S21Matrix matrix4 = matrix3 * 2;
  EXPECT_EQ(matrix4(0, 0), 2);
  EXPECT_EQ(matrix4(0, 1), 4);
  EXPECT_EQ(matrix4(0, 2), 6);
  EXPECT_EQ(matrix4(1, 0), 8);
  EXPECT_EQ(matrix4(1, 1), 10);
  EXPECT_EQ(matrix4(1, 2), 12);
  EXPECT_EQ(matrix4(2, 0), 14);
  EXPECT_EQ(matrix4(2, 1), 16);
  EXPECT_EQ(matrix4(2, 2), 18);
}

TEST_F(S21MatrixTest, Transpose) {
  S21Matrix matrix(2, 2);
  matrix.FillNumbers();
  S21Matrix matrix1 = matrix.Transpose();
  EXPECT_EQ(matrix1(0, 0), 1);
  EXPECT_EQ(matrix1(0, 1), 3);
  EXPECT_EQ(matrix1(1, 0), 2);
  EXPECT_EQ(matrix1(1, 1), 4);
}

TEST_F(S21MatrixTest, CalcComplements) {
  S21Matrix matrix1;
  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(0, 2) = 3;
  matrix1(1, 0) = 0;
  matrix1(1, 1) = 4;
  matrix1(1, 2) = 2;
  matrix1(2, 0) = 5;
  matrix1(2, 1) = 2;
  matrix1(2, 2) = 1;
  S21Matrix matrix2 = matrix1.CalcComplements();
  EXPECT_EQ(matrix2(0, 0), 0);
  EXPECT_EQ(matrix2(0, 1), 10);
  EXPECT_EQ(matrix2(0, 2), -20);
  EXPECT_EQ(matrix2(1, 0), 4);
  EXPECT_EQ(matrix2(1, 1), -14);
  EXPECT_EQ(matrix2(1, 2), 8);
  EXPECT_EQ(matrix2(2, 0), -8);
  EXPECT_EQ(matrix2(2, 1), -2);
  EXPECT_EQ(matrix2(2, 2), 4);

  //#####################################################

  S21Matrix matrix3(1, 1);
  S21Matrix matrix4 = matrix3.CalcComplements();
  EXPECT_EQ(matrix4.GetRows(), 1);
  EXPECT_EQ(matrix4.GetCols(), 1);
}

TEST_F(S21MatrixTest, Determinant) {
  S21Matrix matrix;
  matrix.FillNumbers();
  EXPECT_EQ(matrix.Determinant(), 0);
}

TEST_F(S21MatrixTest, InverseMatrix) {
  S21Matrix matrix1;
  matrix1(0, 0) = 2;
  matrix1(0, 1) = 5;
  matrix1(0, 2) = 7;
  matrix1(1, 0) = 6;
  matrix1(1, 1) = 3;
  matrix1(1, 2) = 4;
  matrix1(2, 0) = 5;
  matrix1(2, 1) = -2;
  matrix1(2, 2) = -3;
  matrix1 = matrix1.InverseMatrix();
  EXPECT_EQ(matrix1(0, 0), 1);
  EXPECT_EQ(matrix1(0, 1), -1);
  EXPECT_EQ(matrix1(0, 2), 1);
  EXPECT_EQ(matrix1(1, 0), -38);
  EXPECT_EQ(matrix1(1, 1), 41);
  EXPECT_EQ(matrix1(1, 2), -34);
  EXPECT_EQ(matrix1(2, 0), 27);
  EXPECT_EQ(matrix1(2, 1), -29);
  EXPECT_EQ(matrix1(2, 2), 24);
  matrix1.FillNumbers();
  EXPECT_THROW(matrix1.InverseMatrix(), std::invalid_argument);
}

TEST_F(S21MatrixTest, SetRows) {
  S21Matrix matrix1;
  matrix1.SetRows(4);
  EXPECT_EQ(matrix1.GetRows(), 4);
  //#####################################################
  S21Matrix matrix2;
  matrix2.SetRows(3);
  EXPECT_EQ(matrix2.GetRows(), 3);
}

TEST_F(S21MatrixTest, SetCols) {
  S21Matrix matrix1;
  matrix1.SetCols(4);
  EXPECT_EQ(matrix1.GetCols(), 4);
  //#####################################################
  S21Matrix matrix2;
  matrix2.SetCols(3);
  EXPECT_EQ(matrix2.GetCols(), 3);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}