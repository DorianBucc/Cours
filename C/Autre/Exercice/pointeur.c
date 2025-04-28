#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int a = 57530;
    int* pa = &a;
    //printf("%i",*pa);

    pa = &a;

    pa == &a;
    *pa == a;
    *pa = 7500;
    a == 7500;
    printf("%d",a);
    //printf("%p",&b );

    // scanf("%i",&a);
    // int **tab;
    // tab[0] = &a;
    // printf("%i\n",tab[1][1]);
    // char *message = "Bonjour";
    // printf("%c",*(message+2));
    // int x = 2;
    // int y = 3;
    // int res = 57;

    // carre2(&x,&y,&res);

    char *tab = "rrezuivy";
    strcat(tab,"hjfd");
    printf("\n%s",tab);
}
int carre(int a, int b){
    return a*b;
}
void carre2(int *a, int *b, int *res){
    *res = *a * *b;
    *b = 0;
    *a = 0;
}