#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

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
    char name;
} Matrix;

int lengthofvector(int * v) { return sizeof(v) / sizeof(v[0]); }
int sizeofmatrix(Matrix* m) { return m->order->m * m->order->n; }

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

Matrix * createMatrix(int m, int n, char name, int * values)
{
    Matrix * mat = (Matrix*)malloc(sizeof(Matrix));
    if (mat != NULL)
    {
        mat->order = (Order*)malloc(sizeof(Order));
        if (mat->order != NULL)
        {
            mat->order->m = m;
            mat->order->n = n;
            mat->name = toupper(name);
            
            mat->i = (int**)malloc(m*sizeof(int*));
            if (mat->i != NULL)
            {
                for(int i = 0; i < m; i++)
                {
                    mat->i[i] = (int*)malloc(n*(sizeof(int)));
                    if (mat->i[i] != NULL)
                    {
                        for(int j = 0; j < n; j++)
                        {
                            mat->i[i][j] = values[i * n + j];
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
    if (m != NULL)
    {
        printf("\n");
        printf("Matrix %c\n", m->name);
        for(int i = 0; i < m->order->m; i++)
        {
            for(int j = 0; j < m->order->n; j++)
            {
                printf("%d ", m->i[i][j]);
            }
            printf("\n");
        }
    } else { printf("matrix is null. Coudn't print the matrix.\n"); }
}

void printvector(int * v, char name, const char * format)
{
    if (v != NULL)
    {
        printf("\n");
        printf("Vector %c\n", name);
        for(int i = 0; i < lengthofvector(v) + 1; i++)
        {
            if (strcmp(format, "vertical"))
                printf("%d ", v[i]);
            else if (strcmp(format, "horizontal"))
                printf("%d\n", v[i]);
            else
                printf("You must choose a print format.\n");
        }
        printf("\n");
    }
}

int * product(Matrix * a, int * b)
{
    int k = 1;
    int b_length = lengthofvector(b) + 1;
    if (b_length == a->order->m)
    {
        int * y = (int*)malloc(a->order->m*sizeof(int));
        if (y == NULL) exit(-2);

        for(int i = 0; i < a->order->m; i++)
        {
            for(int j = 0; j < a->order->n; j++)
            {
                if (i != i - 1)
                {
                    y[i] += (a->i[i][j] * b[j]);
                    printf("y[%d] = (%d * %d) = %d\n", i, a->i[i][j], b[j], y[i]);
                    k++;
                }
            }
        }
        return y;
    }
}

int squareorder(int total) 
{ 
    int i;
    for(i = 1; i < total; i++)
    {
        if (total % i == 0 && i != 1)
            return total / i;
    } 
}

int main(int argc, char * argv[])
{

    // int qtvalues = atoi(argv[1]);
    // int * v = randvalues(qtvalues);
    // int m = squareorder(qtvalues);
    // int n = m;
    int total = 324;
    int * v = randvalues(total);
    int m = 18;
    int n = 18;
    printf("Order of square matrix: %dx%d\n", m, m);

    Matrix* a = createMatrix(m, n, 'A', v);
    printmatrix(a);

    int * b = randvalues(m);
    
    printvector(b, 'B', "vertical");
    int * y = product(a, b);

    printvector(y, 'Y', "vertical");

    return 0;
}