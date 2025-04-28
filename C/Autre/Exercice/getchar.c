#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vidbuffer()
{
    while (getchar() != '\n'){}
}

void main()
{
    char get;
    printf("Veuillez saisir\n");
    get = getchar();
    vidbuffer();

    switch (get)
    {
    case 'T':
        printf("afficher le tableau\n");
        break;

    case 'O':
        printf("Rejouer\n");
        break;
    
    default:
        printf("no define\n");
        break;
    }

    printf("%c\n\n",get);

    get = getchar();
    vidbuffer();

    printf("%c\n\n",get);
}
