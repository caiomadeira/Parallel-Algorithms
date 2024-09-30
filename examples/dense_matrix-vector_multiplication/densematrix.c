#include "../../matrixlib/matrix.h"

/*

'computation' = calculo

Considere uma multiplicação de uma densa matriz A
nxn com um vetor B para produzir outro vector Y.
O i-ésimo elemento de y[i] do vetor produto é o produt
escalar (dot-product) da i-ésima linha de A com o vetor
entrada B.

Ou seja, o calculo de cada y[i] pode ser um considerado uma Task (tarefa).
Alternativamente, conforme mostrado mais adiante, o cálculo poderia ser decomposto
em ao menos, digamos quatro, tarefas onde cada tarefa calcula aproximadamente n/4 entradas
do vetor y.

*/

int * randvalues(int n)
{
    int * v = (int *)malloc(n*sizeof(int));
    if (v != NULL)
    {
        for(int i = 0; i < n; i++)
            v[i] = rand() % (n + 1);
    }
    return v;
}

void granularity(Matrix * m, int entrydivisor, int * y)
{
    int numOfTasks = m->order->m / entrydivisor;
    printf("Order of square matrix: %dx%d\n", m->order->m, m->order->n);
    printf("We got %d Tasks in total. Wich task has %d entries:\n", numOfTasks, entrydivisor);
    puts("");
    printf("Tasks are decomposed in Y vector\n");
    puts("");
    if (numOfTasks < entrydivisor)
        printf("Granularity type: COARSE-GRAINED (LARGER GRANULARITY).\nSmall number of large tasks.\n");
    else
        printf("Granularity type: FINE-GRAINED (SMALL GRANULARITY).\nLarge number of small tasks.\n");
}

// gcc seu_codigo.c -o seu_programa -lm: Usamos a FLAG -l para linkar a biblioteca matematica
int main(int argc, char * argv[])
{
    printf("Task Simulation - Introduction to Parallel Computing, 2th Edition.\n");
    
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

        printf("\n-------------------------------\n");
        printf("Analytics:\n");
        granularity(a, 3, y);

    } else { printf("Usage: <script_name> <total_of_elements> <m>.\n");}

    return 0;
}