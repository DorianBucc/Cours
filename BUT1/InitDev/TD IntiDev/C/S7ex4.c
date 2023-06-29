#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char phrase[101];
    char mot[5] = "abas";
    int comp = 0;
    char *p;
    int i;

    printf("saisir une phrase : ");
    fgets(phrase, 101, stdin);
    p = strchr(phrase, '\n');
    if (p == NULL) while(getchar() != '\n');
    else *p = '\0';
    int min = 0, max = strlen(phrase)-1;

    for (int i = 0; i < strlen(phrase)-strlen(mot)+1; i++)
    {
        if(strncmp( phrase+i, mot, strlen(mot)) == 0) comp++;
    }
    printf("%d fois %s\n", comp, mot);
    

    

    return 0;
}