#include "include/SpOps.h"
#include "include/utils.h"

int main(){
    
    int i, j, k, n, m, x;
    std::cout << "Enter the dimensions of sparse matrix A : m and n : " << std::endl;
    std::cin >> m >> n;
    std::cout << "Enter the dimensions of matrix B : n and x.(n is already there, only enter x)" << std::endl;
    std::cin >> x;
    int  *B_vec = new int[n];
    int **A, **B_mat, **B_out;
    A = new int *[m], B_mat = new int *[n], B_out = new int *[m];
    for(i = 0; i < n; i++){
        A[i] = new int[n];
        B_mat[i] = new int[x];
        B_out[i] = new int[x];
    }
    
    int nnz = generate_val(A, B_vec, B_mat, m, n, x);

    //For CSR format
    int *row_ptr = new int[m + 1], *colind = new int[nnz], *val = new int[nnz];
    
    // Converting sparse matrix into Compressed Sparse Row form
    convert_csr(A, row_ptr, colind, val, m, n, nnz);

    int* out = new int[10];
    // Sparse Matrix-Vector multiplication
    spmv_csr(row_ptr, colind, val, m, n, nnz, B_vec, out);

    //Sparse Matrix-Dense Matrix multiplication
    spmm_csr(row_ptr, colind, val, m, n, x, nnz, B_mat, B_out);

    //Display output
    display(A, B_vec, B_mat, row_ptr, colind, val, out, B_out, m, n, x, nnz);

    return 0;
}