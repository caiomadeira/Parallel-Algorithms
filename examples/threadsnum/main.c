#include<stdio.h>
#include<omp.h>

int main(void)
{
    int i = 5; // a shared variable 
    #pragma omp parallel num_threads(3)
    {
        int c;
        c = omp_get_thread_num(); // a variable local or private to each thread
        //printf("c = %d, i = %d\n", c, i);
        switch (c)
        {
        case 0:
            printf("Thread %d\n", c);
            break;
        case 1:
            printf("Thread %d\n", c);
            break;
        case 2:
            printf("Thread %d\n", c);
            break;
        case 3:
            printf("Thread %d\n", c);
            break;
        
        default:
            printf("Thread nao mapeada.\n");
            break;
        }
    }
}

