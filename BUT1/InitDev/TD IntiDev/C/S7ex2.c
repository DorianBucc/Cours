#include <stdio.h>
#include <string.h>

int main()
{
    char mot[6];
    char mot2[6];
    printf("saisir un mot : ");
    scanf("%5s", mot);
    while(getchar() != '\n');
    
    printf("mot saisi : %s %d\n", mot, (int)strlen(mot));
    strcpy(mot2,mot);

    for (int i = 0; i < strlen(mot) ; i++)
    {
        switch (mot2[i])
        {
        case 'z':
        case 'y':
        case 'x':
        case 'Z':
        case 'Y':
        case 'X':mot2[i] = mot2[i]-23; break; 
        default: mot2[i] = mot2[i]+3; break;
        }
    }
    
    printf("%s = %s",mot,mot2);
    return 0;
}