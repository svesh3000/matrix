#include <iostream>
#include <new>
#include "mtx.hpp"

int main()
{
  size_t m = 0, n = 0;
  std::cin >> m >> n;
  if (!std::cin) {
    std::cerr << "ERROR\n";
    return 1;
  }
  try {
    int ** t = memory_alloc(m,n);
  }
  catch (const std::bad_alloc& e) {
    std::cerr << "Memory Allocation Error: " << e.what() << "\n";
  }
  read(t, m, n);
  write(t, m, n)
  clean(t, m);
}
