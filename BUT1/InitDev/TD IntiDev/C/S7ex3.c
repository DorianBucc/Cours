#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char phrase[101];
    char *p;
    int i;

    printf("saisir une phrase : ");
    fgets(phrase, 101, stdin);
    p = strchr(phrase, '\n');
    if (p == NULL) while(getchar() != '\n');
    else *p = '\0';
    int min = 0, max = strlen(phrase)-1;

    for(i = 0; i < strlen(phrase)/2; i++)
    {
        if(phrase[min] == phrase[max]) {min++;max--;}
        else {printf("%s n'est pas un palindrome\n",phrase); break;}
    }
    

    return 0;
}