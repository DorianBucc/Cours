#include <stdio.h> 
#include <stdlib.h>

int main(){

    int x, un;

    printf("Veuillez saisir la valeur de x pour obtenir ça suite : \n");
    scanf("%d", &x);

    un = 0;

    for (int i = 1; i <= x; i++)
    {
        un+=1;
        printf("%4d", un);
    }

    un = 0;

    printf("\n");

    for (int i = 1; i <= x; i++)
    {
        un+=2;
        printf("%4d", un);
    }

    un = 0;

    printf("\n");

    for (int i = 1; i <= x; i++)
    {
        un+=3;
        printf("%4d", un);
    }

    un = 0;

    printf("\n");

    for (int i = 1; i <= x; i++)
    {
        un+=4;
        printf("%4d", un);
    }

    un = 0;

    printf("\n");

    for (int i = 1; i <= x; i++)
    {
        un+=5;
        printf("%4d", un);
    }

    un = 0;

    printf("\n");

    for (int i = 1; i <= x; i++)
    {
        un+=6;
        printf("%4d", un);
    }

    un = 0;

    printf("\n");

    for (int i = 1; i <= x; i++)
    {
        un+=7;
        printf("%4d", un);
    }

    un = 0;

    printf("\n");

    for (int i = 1; i <= x; i++)
    {
        un+=8;
        printf("%4d", un);
    }

    un = 0;

    printf("\n");

    for (int i = 1; i <= x; i++)
    {
        un+=9;
        printf("%4d", un);
    }

    un = 0;

    printf("\n");

    for (int i = 1; i <= x; i++)
    {
        un+=10;
        printf("%4d", un);
    }

}