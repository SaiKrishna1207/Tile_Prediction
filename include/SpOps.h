#include <bits/stdc++.h>
#include <time.h>

//SpMV Operation
void spmv_csr(int *row_ptr, int *colind, int *val, int m, int n, int nnz, int *B_vec, int *out);

//SpMM Operation
void spmm_csr(int *row_ptr, int *colind, int *val, int m, int N, int x, int nnz, int **B_mat, int **B_out);
