#include <iostream>
#include "mtx.hpp"

int main()
{
  size_t m = 0, n = 0;
  std::cin >> m >> n;
  std::cout << m << " " << n << "\n";
  int ** t = ct(m,n);
  read(t, m, n);
  write(t, m, n)
  dt(t, m, n);
}
