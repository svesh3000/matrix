#include "mtx.hpp"
#include <iostream>
#include <stdexcept>

Matrix::Matrix(size_t m, size_t n) : num_rows(m), num_columns(n)
{
  sveshnikov::memory_alloc(num_rows, num_columns);
}

Matrix::Matrix(const Matrix &copiedMatrix) : num_rows(copiedMatrix.num_rows), num_columns(copiedMatrix.num_columns)
{
  mtx = new int *[num_rows];
  for (size_t i = 0; i < num_rows; i++)
  {
    mtx[i] = new int[num_columns];
    for (size_t j = 0; j < num_columns; j++)
    {
      mtx[i][j] = copiedMatrix.mtx[i][j];
    }
  }
}

Matrix::~Matrix()
{
  sveshnikov::clean_matrix(mtx, num_rows);
}

size_t Matrix::getNumRows() const
{
  return num_rows;
}

size_t Matrix::getNumColumns() const
{
  return num_columns;
}

size_t Matrix::fillMatrix()
{
  sveshnikov::read_matrix(mtx, num_rows, num_columns);
}

size_t Matrix::resizeMatrix(size_t newRows, size_t newColumns)
{
  if (newRows <= 0 || newColumns <= 0)
  {
    throw std::invalid_argument("ERROR: The new dimensions of the matrix are not positive");
  }
  int **newMtx = new int *[newRows];
  for (int i = 0; i < newRows; ++i)
  {
    newMtx[i] = new int[newColumns]{0};
  }
  for (int i = 0; i < num_rows || i < newRows; ++i)
  {
    for (int j = 0; j < num_columns || j < newColumns; ++j)
    {
      newMtx[i][j] = mtx[i][j];
    }
  }
  sveshnikov::clean_matrix(mtx, num_rows);
  mtx = newMtx;
  num_rows = newRows;
  num_columns = newColumns;
}