#include <stdio.h>

int main()
{
    char c;
    int nb_car = 0, nb_voy = 0;
    while ((c=getchar()) != '\n')
    {
        // putchar(c);
        switch (c)
        {
        case 'a':
        case 'i':
        case 'e':
        case 'o':
        case 'u':
        case 'y': nb_voy++;
        default: nb_car++;
        }
    }
    printf("\n%d,,%d\n",nb_car,nb_voy);
    return 0;
}

/*
#include <stdio.h>
int main()
{
    char c;
    int nb_car = 0, nb_voy = 0, nb_lig = 0;
    while ((c=getchar()) != ',')
    {
        switch (c)
        {
        case '\n': nb_lig++; break;
        case 'a':
        case 'i':
        case 'e':
        case 'o':
        case 'u':
        case 'y': nb_voy++;
        default: nb_car++;
        }

    }
    printf("\n%d,,%d,,%d\n",nb_car,nb_voy,nb_lig);
    return 0;

}
*/