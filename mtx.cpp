#include "mtx.hpp"
#include <iostream>

int **sveshnikov::memory_alloc(size_t m, size_t n)
{
  int **mtx = new int *[m];
  for (size_t i = 0; i < m; i++)
  {
    mtx[i] = new int[n];
  }
  return mtx;
}

void sveshnikov::read_matrix(int **mtx, size_t m, size_t n)
{
  int number = 0;
  for (size_t i = 0; i < m; i++)
  {
    for (size_t j = 0; j < n; j++)
    {
      std::cin >> number;
      mtx[i][j] = number;
    }
  }
  if (!std::cin)
  {
    std::cerr << "ERROR\n";
    throw std::invalid_argument("ERROR: Not a number");
  }
}

void sveshnikov::write_matrix(const int *const *mtx, size_t m, size_t n)
{
  for (size_t i = 0; i < m; i++)
  {
    for (size_t j = 0; j < n; j++)
    {
      if (j != n - 1)
      {
        std::cout << mtx[i][j] << " ";
      }
      else
      {
        std::cout << mtx[i][j];
      }
    }
    std::cout << "\n";
  }
}

void sveshnikov::clean_matrix(int **t, size_t m)
{
  for (size_t i = 0; i < m; ++i)
  {
    delete[] t[i];
  }
  delete[] t;
}
