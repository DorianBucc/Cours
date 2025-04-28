#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void main()
{
    int get[4][4] = {{1,2,3,5}
                    ,{4,8,9,7}};
    // int g = **get;

    printf("Veuillez saisir\n\n");
    
    
    printf("%d\n",get[1][1]);

    printf("%d\n",*(*(get+1)+2));
    printf("\n");

    system("cls");

    int tab[][9] = {{1,2,3,4,5,6,7,8,9},{11,22,33,44,55,66,77,88,99}};
    int *g = &**tab;
    printf("%d\n",*(g+2));
    printf("%d\n",g[0]);
    printf("%d",*(g+1));
    system("pause");
}