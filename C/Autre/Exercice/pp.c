#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    char* tabb[10];
    char tab[] = "Test";
    char* tableau;
    tableau = (char *)malloc(4 * sizeof(char));
    tableau[0] = 'D';
    tableau[1] = '2';
    tableau[2] = 'G';
    tableau[3] = 'I';
    // if (tableau == NULL)  printf("Erreur d'allocation de mémoire.\n");
    tabb[0] = tab;
    tabb[1] = tableau;
    
    
    printf(tabb[0]);
    printf("\n");
    printf("%c",tableau[0]);
    printf("\n");
    printf(tableau);
    printf("\n");
    free(tableau);
    printf(tableau);
}