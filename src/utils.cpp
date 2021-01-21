#include "../include/utils.h"

int generate_val(int **A, int *B_vec, int **B_mat, int m, int n, int x){
    int i, j, nnz = 0;
    srand(time(NULL));

    //For sparse matrix A
    /* Variable to determine sparsity of matrix */
    double sparsity = 0.2; 

    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            int isZero = rand() % 100;
            if(((double)isZero / 100) > sparsity)
                A[i][j] = 0;
            else{
                A[i][j] = rand() % 100;   
                nnz++;
            }
        }
    }
    //For vector B(SpMV)
    for(i = 0; i < n; i++)
        B_vec[i] = rand() % 100;
    
    // For matrix B(SpMM)
    for(i = 0; i < n; i++){
        for(j = 0; j < x; j++)
            B_mat[i][j] = rand() % 100;
    }
    return nnz;
}

void convert_csr(int **A, int *row_ptr, int *colind, int *val, int m, int n, int nnz){
    int i, j, point = 0;
    for(i = 0;i < m; i++){
        row_ptr[i] = point;
        for(j = 0; j < n; j++){
            if(A[i][j] != 0){
                val[point] = A[i][j];
                colind[point] = j;   
                point++;  
            }        
        }
    }
    row_ptr[m] = point;
}

void display(int **A, int *B_vec, int **B_mat, int *row_ptr, int *colind, int *val, int *out, int **B_out, int m, int n, int x, int nnz){
    int i, j, k;

    std::cout << "Sparse matrix  : " << std::endl;
    for(i = 0;i < m; i++){
        for(j = 0; j < n; j++)
            std::cout << A[i][j] << "\t";
        std::cout << std::endl;
    }

    std::cout << "CSR Format : " << std::endl;
    std::cout << std::endl << "Vector Row_ptr: " << std::endl;
    for(i = 0; i <= m; i++)
        std::cout << row_ptr[i] << "\t";

    std::cout << std::endl << "Vector col_ind " << std::endl;
    for(i = 0; i < nnz; i++)
        std::cout << colind[i] << "\t";

    std::cout << std::endl << "Vector val " << std::endl;
    for(i = 0; i < nnz; i++)
        std::cout << val[i] << "\t";

    std::cout << std::endl << "SpMV OUTPUT : " << std::endl;
    std::cout << std::endl << "Vector B: " << std::endl;
    for(i = 0; i < n; i++)
        std::cout << B_vec[i] << "\t";
        
    std::cout << std::endl << "Output vector: " << std::endl;
    for(i = 0; i < n; i++)
        std::cout << out[i] << "\t";

    std::cout << std::endl << "SpMM OUTPUT: " << std::endl;
    std::cout << "Dense matrix B : " << std::endl;
    for(i = 0;i < n; i++){
        for(j = 0; j < x; j++)
            std::cout << B_mat[i][j] << "\t";
        std::cout << std::endl;
    }
    std::cout << std::endl << "Output matrix B_out : " << std::endl;
    for(i = 0;i < m; i++){
        for(j = 0; j < x; j++)
            std::cout << B_out[i][j] << "\t";
        std::cout << std::endl;
    }
}