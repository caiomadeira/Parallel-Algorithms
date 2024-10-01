#include "../../matrixlib/matrix.h"


static int * randvalues(int n)
{
    int * v = (int *)malloc(n*sizeof(int));
    if (v != NULL)
    {
        for(int i = 0; i < n; i++)
            v[i] = rand() % (1 + 1);
    }
    return v;
}

int main(int argc, char * argv[])
{
    printf("Sparse Matrix-Vector Multiplication - Introduction to Parallel Computing, 2th Edition.\n");
    
    if (argc == 2)
    {
        int * v;
        int total = atoi(argv[1]);
        int m = squareorder(total);
        if (m == -1) { exit(-1); }
        int n = m;
        v = randvalues(total);            

        printf("Order of square matrix: %dx%d\n", m, m);
        puts("");
        printf("Set of tasks = Matrix A;");
        Matrix* a = createMatrix(m, n, 'A', v);
        printmatrix(a);

        int * b = randvalues(m);
        
        printvector(b, m, 'B', "vertical");
        int * y = product(a, b, m, FALSE);

        printvector(y, m, 'Y', "vertical");

    } else { printf("Usage: <script_name> <total_of_elements> <m>.\n");}

    return 0;
}