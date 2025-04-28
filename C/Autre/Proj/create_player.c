// OLD



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vidbuffer(){

    while(getchar() != '\n');
}

typedef struct player
{
    char pseudo[20];
    int hp;
    int mp;
} player;

void create_player(player *p, char psdo[20]){

    printf("Veuillez saisir le pseudo que vous souhaitez utiliser : \n");
    scanf("%s", psdo);
    vidbuffer();
    strcpy(p->pseudo, psdo);

    p->hp = 0;
    p->mp = 0;
}

int main(void){

    char psdo[20]; int nombre_joeurs = 0; int i;

    player p = {"", 0, 0};
    player *tabplayer = NULL;

    printf("Veuillez saisir le nombre de joueurs : \n");
    scanf("%d", &nombre_joeurs);
    vidbuffer();
    

    tabplayer = malloc(sizeof(int) * nombre_joeurs);

    if (tabplayer == NULL)
    {
        exit (1);
    }

    for (i = 0; i < nombre_joeurs; i++)
    {
        create_player(&tabplayer[i], psdo);
    }

    for (i = 0; i < nombre_joeurs; i++)
    {
        printf("%s\n", tabplayer[i].pseudo);
        printf("%d\n", tabplayer[i].hp);
        printf("%d\n", tabplayer[i].mp);
    }

    free(tabplayer);
    
}