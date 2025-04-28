#include <stdio.h>
#define PI 3.14


int fcarre(int x)
{
    return x*x;
}

void mcarre(int x,int *res)
{
    *res = x*x;
}


//suite un1 = 0     un2 = 2     un3 = 4    ...   unx = ?

int s1(int x)   //method un1 à unx (calc un1 apres calc un2 apres calc un3 ... à calc un)
{
    int un = 0;
    for(int i=2; i <= x; i++)
    {
        un += 2;
    }
    return un;
}

//ou//

int s11(int x)  //method un general
{
    int un = (x*2)-2;
    return un;
}

