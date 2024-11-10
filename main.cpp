#include <iostream>
#include <new>
#include <stdexcept>
#include "mtx.hpp"

int main()
{
  size_t m = 0, n = 0, new_m, new_n;
  std::cin >> m >> n;
  if (!std::cin || m <= 0 || n <= 0)
  {
    std::cerr << "ERROR\n";
    return 1;
  }
  try
  {
    Matrix matrix(m, n);
    matrix.fillMatrix();
    sveshnikov::write_matrix(matrix.mtx_, m, n);
    std::cout << "Введи новые размеры матрицы\n";
    std::cin >> new_m >> new_n;
    if (!std::cin)
    {
      std::cerr << "ERROR\n";
      return 1;
    }
    matrix.resizeMatrix(new_m, new_n);
    sveshnikov::write_matrix(matrix.mtx_, new_m, new_n);
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << "Memory Allocation Error: " << e.what() << "\n";
    return 1;
  }
  catch (const std::invalid_argument &e)
  {
    std::cerr << "Invalid Argument: " << e.what() << "\n";
    return 1;
  }
}
