#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    int m,n;
} Order;

typedef struct {
    int **i;
    Order * order;
    char name;
} Matrix;

int squareorder(int total);
int * product(Matrix * a, int * b, int b_size, int show);
void printmatrix(Matrix* m);
int sizeofmatrix(Matrix* m);
void printvector(int * v, int n, char name, const char * format);
Matrix * createMatrix(int m, int n, char name, int * values);
