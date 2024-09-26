#include<stdio.h>
#include<stdlib.h>

#define RRAND_MAX 9

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

typedef struct {
    int m,n;
} Order;

typedef struct {
    int **i;
    Order * order;
} Matrix;


Matrix * createMatrix(int m, int n, int * values)
{
    Matrix * mat = (Matrix*)malloc(sizeof(Matrix));
    if (mat != NULL)
    {
        mat->order = (Order*)malloc(sizeof(Order));
        if (mat->order != NULL)
        {
            mat->order->m = m;
            mat->order->n = n;
            
            mat->i = (int**)malloc(m*sizeof(int));
            if (mat->i != NULL)
            {
                for(int i = 0; i < m; i++)
                {
                    mat->i[i] = (int*)malloc(n*(sizeof(int)));
                    if (mat->i[i] != NULL)
                    {
                        for(int j = 0; j < n; j++)
                        {
                            mat->i[i][j] = values[j];
                        }
                    }
                }
            }
        }
        return mat;
    }
    return NULL;
}

void printmatrix(Matrix* m)
{
    for(int i = 0; i < m->order->m; i++)
    {
        for(int j = 0; j < m->order->n; j++)
        {
            printf("%d ", m->i[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    int v[] = {3, 2, 1, 4, 8, 6, 1, 3, 4};

    Matrix* matrix = createMatrix(3, 3, v);
    printmatrix(matrix);

    return 0;
}