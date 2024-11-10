#include "mtx.hpp"
#include <iostream>
#include <stdexcept>

Matrix::Matrix(size_t m, size_t n) : num_rows_(m), num_columns_(n)
{
  mtx_ = sveshnikov::memory_alloc(num_rows_, num_columns_);
}

Matrix::Matrix(const Matrix &copiedMatrix) : num_rows_(copiedMatrix.num_rows_), num_columns_(copiedMatrix.num_columns_)
{
  mtx_ = new int *[num_rows_];
  for (size_t i = 0; i < num_rows_; i++)
  {
    mtx_[i] = new int[num_columns_];
    for (size_t j = 0; j < num_columns_; j++)
    {
      mtx_[i][j] = copiedMatrix.mtx_[i][j];
    }
  }
}

Matrix::~Matrix()
{
  sveshnikov::clean_matrix(mtx_, num_rows_);
}

size_t Matrix::getNumRows() const
{
  return num_rows_;
}

size_t Matrix::getNumColumns() const
{
  return num_columns_;
}

void Matrix::fillMatrix()
{
  sveshnikov::read_matrix(mtx_, num_rows_, num_columns_);
}

void Matrix::resizeMatrix(size_t newRows, size_t newColumns)
{
  if (newRows <= 0 || newColumns <= 0)
  {
    throw std::invalid_argument("ERROR: The new dimensions of the matrix are not positive");
  }
  int **newMtx = sveshnikov::memory_alloc(newRows, newColumns);
  for (int i = 0; i < num_rows_ && i < newRows; ++i)
  {
    for (int j = 0; j < num_columns_ && j < newColumns; ++j)
    {
      newMtx[i][j] = mtx_[i][j];
    }
  }
  sveshnikov::clean_matrix(mtx_, num_rows_);
  mtx_ = newMtx;
  num_rows_ = newRows;
  num_columns_ = newColumns;
}
