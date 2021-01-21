#include "../include/SpOps.h"

void spmv_csr(int *row_ptr, int *colind, int *val, int m, int n, int nnz, int *B_vec, int *out)
{
    /* This is the unscheduled SpMV */
    
    // int i, j;
    // int temp;
    // for(i = 0; i < m; i++)
    // {
    //     temp = out[i];
    //     for(j = row_ptr[i]; j < row_ptr[i+1]; j++){
    //         temp += val[j] * B_vec[colind[j]];
    //     }
    //     out[i] = temp;
    // }

    /* The position iterating SpMV */

    int i = 0, j, p;
    for (p = 0; p < nnz; p++) {
        j = colind[p];
        while (p == row_ptr[i + 1]) i++;
        out[i] += val[p] * B_vec[j];
    }
}

void spmm_csr(int *row_ptr, int *colind, int *val, int m, int N, int x, int nnz, int **B_mat, int **B_out)
{
    int i, j, k, p;
    int temp;

    /* Unscheduled SpMM */

    // for(k = 0; k < x; k++){ 
    //     for(i = 0; i < m; i++)
    //     {
    //         temp = 0;
    //         for(j = row_ptr[i]; j < row_ptr[i+1]; j++){
    //             temp += val[j] * B_mat[colind[j]][k];
    //         }
    //         B_out[i][k] = temp;
    //     }
    // }

    /* Position Iterating SpMM */ 

    i = 0;
    for (p = 0; p < nnz; p++) {
        j = colind[p];
        while (p == row_ptr[i + 1]) i++;
        for(k = 0;k < x; k++){
           B_out[i][k] += val[p] * B_mat[j][k];
        }
    }
}