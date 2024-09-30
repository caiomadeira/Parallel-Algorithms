#include "matrix.h"

int sizeofmatrix(Matrix* m) { return m->order->m * m->order->n; }

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
    //printf("Multiple of 12: %d", getfirstmultiple(m->order->m));
    int nEntriesPerTask = m->order->n / 4;
    if (m != NULL)
    {
        printf("\n");
        printf("Matrix %c\n", m->name);
        for(int i = 0; i < m->order->m; i++)
        {
            for(int j = 0; j < m->order->n; j++)
            {
                // if (i % nEntriesPerTask == 0 && i != 0)
                // {
                //     printf("\nTask: %d \n", i / nEntriesPerTask);
                // }
                printf("%d ", m->i[i][j]);
            }
            printf("\n");
        }
    } else { printf("matrix is null. Coudn't print the matrix.\n"); }
}

int * product(Matrix * a, int * b, int b_size, int show)
{
    int k = 1;
    int b_length = b_size;
    if (b_length == a->order->m)
    {
        int * y = (int*)malloc(a->order->m*sizeof(int));
        if (y == NULL) exit(-2);

        // Iniciando o vetor y
        for(int i = 0; i < a->order->m; i++)
            y[i] = 0;

        for(int i = 0; i < a->order->m; i++)
        {
            for(int j = 0; j < a->order->n; j++)
            {
                if (i != i - 1)
                {
                    y[i] += (a->i[i][j] * b[j]);
                    if (show == TRUE)
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
    /* 
    Se deseja criar uma matriz quadrada, 
    o valor de m e n deve ser a raiz quadrada do total de elementos.
    */
    int root = sqrt(total);
    double rootd = sqrt(total);
    if (root * root == total)
        return root;
    else
        perror("Error: Cannot create a quadratic matrix.\n");
        return -1;
}

void printvector(int * v, int n, char name, const char * format)
{
    if (v != NULL)
    {
        printf("\n");
        printf("Vector %c\n", name);
        for(int i = 0; i < n; i++)
        {
            if (strcmp(format, "vertical"))
                printf("|%d|", v[i]);
            else if (strcmp(format, "horizontal"))
                printf("|%d|\n", v[i]);
            else
                printf("You must choose a print format.\n");
        }
        printf("\n");
    }
}