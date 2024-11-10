#ifndef MTX_HPP
#define MTX_HPP
#include <cstddef>
namespace sveshnikov
{
  int **memory_alloc(size_t m, size_t n);
  void read_matrix(int **mtx, size_t m, size_t n);
  void write_matrix(const int *const *mtx, size_t m, size_t n);
  void clean_matrix(int **t, size_t m);
}

struct Matrix
{
  public:
    Matrix(size_t m, size_t n);
    ~Matrix();
    Matrix(const Matrix &copiedMtx);
    size_t getNumRows() const;
    size_t getNumColumns() const;
    void fillMatrix();
    size_t resizeMatrix(size_t newRows, size_t newColumns);
    int **mtx_;

  private:
    size_t num_rows_;
    size_t num_columns_;
};
#endif
