#include<stdio.h>
#include<omp.h>

// to compile: gcc hello.c -o helloc -fopenmp

int main(void)
{
    int i = 5;
    #pragma omp parallel 
    {
        int c; // variable local or private to each thread
        c = omp_get_thread_num();
        printf("c = %d, E pur si muove: %d\n", c, i);
    }
}