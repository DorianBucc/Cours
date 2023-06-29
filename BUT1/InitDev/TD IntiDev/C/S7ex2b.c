#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char phrase[101];
    char code[101];
    char zed, *p;
    int i, d = 3;

    printf("saisir une phrase : ");
    fgets(phrase, 101, stdin);
    p = strchr(phrase, '\n');
    if (p == NULL) while(getchar() != '\n');
    else *p = '\0';

    strcpy(code, phrase);

    for(i = 0; i < strlen(code); i++)
    {
        if (isalpha(code[i]) != 1) continue;
        zed = islower(code[i]) ? 'z' : 'Z';
        code[i] += d;
        if (code[i] > zed) code[i] -= 26;
    }
    



    printf("phrase saisie : [%s] [%s]\n",phrase,code);

    return 0;
}