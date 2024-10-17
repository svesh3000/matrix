#ifndef MTX_HPP
#define MTX_HPP
#include <cstddef>
int ** ct(size_t m, size_t n); 
int dt(int ** t, size_t m, size_t n);
void read(int ** mtx, size_t m, size_t n);
void write(const int * const * mtx, size_t m, size_t n); 
#endif 
