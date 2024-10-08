#include<iostream>
#include "omp.h"

using namespace std;

// to compile: g++ hello.cpp -o hellocplusplus -fopenmp
int main(void)
{
    int i = 5;
    #pragma omp parallel
    {
        cout << "E pur si muove:" << i << "\n" << endl;
    }
}