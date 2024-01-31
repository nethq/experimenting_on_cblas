#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../configured_gsl_2.7.1/include/gsl/gsl_cblas.h"
#include <string.h>

#pragma comment(lib, "../configured_gsl_2.7.1/lib/libgsl.a")
//Тук ще направя опит за изчисляване на последователно изчисление на матрици, замервайки времето за изпълнение без и с CBLAS
long measured_time = NULL;
int val=100;
void measureTime(){
    if (measured_time == NULL){
        measured_time = clock();
    } else {
        measured_time = clock() - measured_time;
        printf("%ld,", measured_time);
        measured_time = NULL;
    }
}

void synth_matrix(int n, double *A){
    int i, j;
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            A[i*n + j] = (double)rand() / (double)RAND_MAX;
        }
    }
}

void test1(){
    int n = val;
    double *A = (double *)malloc(n*n*sizeof(double));
    double *B = (double *)malloc(n*n*sizeof(double));
    double *C = (double *)malloc(n*n*sizeof(double));
    synth_matrix(n, A);
    synth_matrix(n, B);
    synth_matrix(n, C);
    measureTime();
    int i, j, k;
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            double sum = 0;
            for (k = 0; k < n; k++){
                sum += A[i*n + k] * B[k*n + j];
            }
            C[i*n + j] = sum;
        }
    }
    measureTime();
    free(A);
    free(B);
    free(C);
}

void test2_through_cblas(){
    int n = val;
    double *A = (double *)malloc(n*n*sizeof(double));
    double *B = (double *)malloc(n*n*sizeof(double));
    double *C = (double *)malloc(n*n*sizeof(double));
    synth_matrix(n, A);
    synth_matrix(n, B);
    synth_matrix(n, C);
    measureTime();
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, n, n, n, 1, A, n, B, n, 0, C, n);
    measureTime();
    free(A);
    free(B);
    free(C);
}

main(int argc, char **argv){
    if (argc > 1){
        val = atoi(argv[1]);
    }
    test1();
    test2_through_cblas();   
	printf("%d\n",val);
return 0;
}
