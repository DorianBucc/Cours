#include <stdio.h>
#define NCOL 5
#define NLIG 5

int main()
{
    int tab1[][NCOL] = {
        {4,6,2,8,9},
        {23,56,89,34,21}};

    printf("%d\n",&tab1);

    int tab[] = {1,2,5,7,8};
    printf("%d\n",tab);
}