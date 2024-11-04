#include <iostream>
#include <new>
#include <stdexcept>
#include "mtx.hpp"

int main()
{
  size_t m = 0, n = 0;
  std::cin >> m >> n;
  if (!std::cin)
  {
    std::cerr << "ERROR\n";
    return 1;
  }
  try
  {
    Matrix matrix(m, n);
    matrix.fillMatrix();
    sveshnikov::write_matrix(matrix.mtx, m, n);
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << "Memory Allocation Error: " << e.what() << "n";
  }
  catch (const std::invalid_argument &e)
  {
    std::cerr << "Invalid Argument: " << e.what() << "n";
  }
}