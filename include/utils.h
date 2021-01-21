#include <bits/stdc++.h>
#include <time.h>

//Generate 2 matrices and a vector 
int generate_val(int **A, int *B_vec, int **B_mat, int m, int n, int x);

//Convert matrix to CSR format
void convert_csr(int **A, int *row_ptr, int *colind, int *val, int m, int n, int nnz);

//Display all results
void display(int **A, int *B_vec, int **B_mat, int *row_ptr, int *colind, int *val, int *out, int **B_out, int m, int n, int x, int nnz);
