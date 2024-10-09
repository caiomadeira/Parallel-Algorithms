#include<iostream>
#include<omp.h>
extern "C"
{
    #include<stdlib.h>
    #include<stdio.h>
    #include<math.h>

    #define N 1000
}

// Function for example
// We've assumed the combine() function is simple and doesn't take much time.
/*
This function must be called in the same order as in the sequential
program. This characteristic is fundamental to make the loop iterations
independent.

It should be acceptable to run calls to combine() outside the parallel region.
We do this by placing each intermediate result computed by big_comp() into
an element of an array. Then the array elements can be passed to the combine()
function in the sequential order in a separate loop. This
code transformation preserver the meaning of the original program.


*/
void combine(double *anwser, double res) { *anwser += res; }

// Intermediare function for example
double big_comp(int i) { return pow(2, i); }

int main(void)
{
    int i;
    double anwser, res[N];
    anwser = 0.0;

    double starttime, endtime, exectime;
    starttime = omp_get_wtime();

    #pragma omp parallel
    {
        #pragma omp for
        for(i = 0; i < N; i++)
            res[i] = big_comp(i); //printf("%f\n", res[i]);
    }

    for(i=0;i<N;i++)
        combine(&anwser, res[i]);
    
    endtime = omp_get_wtime();
    exectime = endtime - starttime;
    printf("\nTempo de execução: %f\n", exectime);
    printf("Result(cientific format): %e\n", anwser);
    printf("Result(double): %f\n", anwser);

    return 0;
}