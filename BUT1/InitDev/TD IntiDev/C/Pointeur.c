#include <stdio.h>
#include <stdlib.h>
#define N 10

void function(int *p,int n)
{
    int *i;
    for (i = p; i < p+n; i++)
    {
        if(*i == 0) printf("en indice : %d\n",i-p);
    }
}

int main()
{
    int p[N] = {0,1,2,3,0,5,0,7,8,9};
    function(p,N);    
}

