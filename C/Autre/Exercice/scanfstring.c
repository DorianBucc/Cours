#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vidbuffer()
{
    while (getchar() != '\n'){}
}

void main()
{
    char *get;
    printf("Veuillez saisir\n");
    scanf("%s",get);

    printf("%s\n\n",get);
    printf("%c\n\n",get[1]);
}