#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct joueur
{
    char pseudo[30];
    int hp;
    int mp;
}J;


int main()
{
    J *tab;
    tab = malloc(sizeof(J)*3);
    int i;

    for (i = 0; i < 3; i++)
    {
        printf("Entré\n");
        scanf("%s",tab[i].pseudo);
        scanf("%d",&tab[i].hp);
        scanf("%d",&tab[i].mp);
    }
    printf("quelle joueur souhhaitait vous avoir les info");
    scanf("%d",&i);
    printf("Le pseudo : %s \n les hp : %d \n les mp : %d\n",tab[i].pseudo,tab[i].hp,tab[i].mp);

}