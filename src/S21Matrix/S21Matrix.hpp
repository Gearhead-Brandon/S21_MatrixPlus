#ifndef __S21MATRIX_H__
#define __S21MATRIX_H__

#include <cmath>
#include <iostream>

#define IncorrectValuesRowsOrColumns                                           \
  "Incorrect values for initialization, rows and cols should be > 0 "
#define IncorrectValuesRowsOrColumnsResize                                     \
  "Incorrect values for resize, rows and cols should be > 0 "
#define DiffSizesMatrices "Different matrix dimensions"
#define DiffSizesMatrices "Different matrix dimensions"
#define NumColsNotEqNumRows                                                    \
  "The number of columns of the first matrix is not equal to the number of "   \
  "rows of the second matrix"
#define MatrixNotSquare "The matrix is not square."
#define DetIsZero "The determinant of the matrix is zero"
#define IndexesOutOfRange "Indexes is out of range"

class S21Matrix {

private:
  // attributes
  int rows_, cols_; // rows and columns attributes
  double **matrix_; // pointer to the memory where the matrix will be allocated

  void CreateMatrix();
  bool CheckSameSize(int other_rows, int other_cols);
  void CheckMatrixQuadraticity();
  void CheckMatrixSize(int row, int col);
  bool EqColsToRows(int other_rows);

  void RemoveMatrix();
  void CopyMatrix(const S21Matrix &other);
  double FindDet();
  void CreateMinor(S21Matrix &temp, int skip_row, int skip_col);

public:
  S21Matrix();                       // default constructor
  S21Matrix(int rows, int cols);     // parameterized constructor
  S21Matrix(const S21Matrix &other); // copy cnstructor
  S21Matrix(S21Matrix &&other);      // move cnstructor
  ~S21Matrix();                      // destructor

  // accessors
  int GetRows() const;
  int GetCols() const;

  // mutators
  void SetRows(int newRows);
  void SetCols(int newCols);
  void Resize(int new_rows, int new_cols);

  // some operators overloads
  S21Matrix operator+(const S21Matrix &other);
  S21Matrix operator-(const S21Matrix &other);
  S21Matrix operator*(const S21Matrix &other);
  S21Matrix operator*(const double &value);
  S21Matrix &operator=(const S21Matrix &other);
  bool operator==(const S21Matrix &other);
  S21Matrix &operator+=(const S21Matrix &other);
  S21Matrix &operator-=(const S21Matrix &other);
  S21Matrix &operator*=(const S21Matrix &other);
  S21Matrix &operator*=(const double &value);
  double &operator()(int row, int col);

  // some public methods
  bool EqMatrix(const S21Matrix &other);
  void SumMatrix(const S21Matrix &other);
  void SubMatrix(const S21Matrix &other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix &other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  void FillNumbers();
  bool PrintMatrix() const;
};

#endif
