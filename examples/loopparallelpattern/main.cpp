#include<iostream>
#include<omp.h>
extern "C"
{
    #include<stdlib.h>
    #include<stdio.h>
    #include<math.h>

    #define N 10000
}

int main(void)
{
    int i, j;
    double result = 0;
    double starttime, endtime, exectime;
    starttime = omp_get_wtime();

    #pragma omp parallel for reduction(+:result)
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            result += pow(2, 10) + pow(2, 10);
            result -= pow(2, 3) + pow(2, 3);
            result /= pow(2, 2) + pow(2, 2);
        }
    }
    
    endtime = omp_get_wtime();
    exectime = endtime - starttime;
    printf("\nTempo de execução: %f\n", exectime);
    printf("Result(cientific format): %e\n", result);
    printf("Result(double): %fs\n", result);

    return 0;
}