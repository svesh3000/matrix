#include "mtx.hpp"
int ** memory_alloc(size_t m, size_t n)
{
  int ** mtx = new int*[m];
  for (size_t i = 0; i < m; i++) {
    mtx[i] = new int[n];
  }
  return mtx;
}

void read(int ** mtx, size_t m, size_t n)
{
  int number = 0;
  for (size_t i = 0; i < m; i++) {
    for (size_t j = 0; j < n; i++) {
      std::cin >> number;
      mtx[i][j] = number;
    }
  }
  if (!std::cin) {
    std::cerr << "ERROR\n";
  }
}

void write(const int * const * mtx, size_t m, size_t n)
{

}

void clean(int ** t, size_t m)
{
  for (size_t i = 0; i < m; ++i) {
    delete [] t[i];
  }
  delete[] t;
}
