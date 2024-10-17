#include "mtx.hpp"
void dt (int ** t, size_t m)
{
  for (size_t i = 0; i < m; ++i){
    delete [] t[i];
  }
  delete[] t;
}
