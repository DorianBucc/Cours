#include <stdio.h>
#include <stdlib.h>

int fon(int n,int t)
{
    int i = n;
    printf("%d\n",i);
    if(i > -40000 && t == 0) i = fon(i-10,t);
    else if (i < 1000)
    { 
    t = 1;
    i = fon(i+10,t); 
    if (i = 0) t = 0;
    }
}


int main()
{
    int n = 10000;
    fon(n, 0);
}