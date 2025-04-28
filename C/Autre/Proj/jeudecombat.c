#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "lib.h"

typedef struct player
{
    char pseudo[30];
    char perso[30];
    int hp;
    int mp;
    int x;
    int y;
} player;

typedef struct perso
{
    char nom[30];
    int hp;
    int mp;
    int weapons;
} perso;

typedef struct weapons
{
    char arm1[10];
} armes;



void vidbuffer()
{
    while(getchar() != '\n'){}
}

void topcase(){

    int a;

    for (a = 1; a<=3; a++)
    {
        printf("%c", H);
    }
    
}

void regle(){

    printf("                                                                                                                        JEU DE COMBAT PLATEAU                          \n");
    printf("\n");
    printf("                                                                                        Bienvenue dans le jeu de combat de plateau, explication du concept du jeu : \n");
    printf("\n");
    printf("                                                            En debut de partie , chaque joueur et chacun son tour, va inscrire le nom de pseudo qu'il utilisera tout au long de la partie .\n");
    printf("\n");
    printf("        Une fois vos pseudo choisies, vous allez aÂªtre redirige vers le choix du personnage a incarner. Attention, le choix de votre personnage est tres important, le fait est qu'un personnage se joue differement en fonction des conditions du jeu.\n");
    printf("\n");
    printf("                                                                Plus les points de vie du personnage choisie son eleve, moins les degats commis aux autres joueurs seront important.\n");
    printf("\n");
}

void choix_perso(perso *j, int hp, int mp, int weapons, char nomj[30]){

    printf("Veuillez choisir le personnage a integrer : \n");

    printf("Le Magicien :    POINTS DE VIE = 150hp     POINTS D'ATTAQUES = 22mp.\n");
    printf("\n");

    printf("Le Barbare :     POINTS DE VIE = 200hp     POINTS D'ATTAQUES = 15mp");
    printf("\n");

    printf("La SorciaÂ¨re :    POINTS DE VIE = 130hp     POINTS D'ATTAQUES = 45mp.\n");
    printf("\n");

    printf("Le Druide :      POINTS DE VIE = 180hp     POINTS D'ATTAQUES = 20mp");
    printf("\n");
    
}

void create_player(player *p, perso *j, char nomj[30], int *rep){

    int hp; int mp; int weapons;

    printf("Veuillez saisir votre pseudo : \n");
    scanf("%s", nomj);
    vidbuffer();
    strcpy(p->pseudo, nomj);

    choix_perso(j, hp, mp, weapons, nomj);
    printf("Veuillez choisir votre personnage : (1/2/3/4)\n");
    scanf("%d", &*rep);
    switch (*rep)
    {
    case 1:
        strcpy(p->pseudo, nomj);
        strcpy(p->perso, "Magicien");
        p->hp = 150;
        p->mp = 22;
        break;

    case 2:
        strcpy(p->pseudo, nomj);
        strcpy(p->perso, "Barbare");
        p->hp = 200;
        p->mp = 15;
        break;

    case 3:
        strcpy(p->pseudo, nomj);
        strcpy(p->perso, "Sorciere");
        p->hp = 130;
        p->mp = 45;
    
        break;

    case 4:
        strcpy(p->pseudo, nomj);
        strcpy(p->perso, "Druide");
        p->hp = 180;
        p->mp = 20;
    
        break;
    
    default:
        break;
    }

    
}

void taille_tab(int *li, int *co){

    do
    {
        printf("Veuillez saisir le nombre de ligne pour la table du jeu : (les colonnes sont demandees juste apres)\n");
        scanf("%d", &*li);
        vidbuffer();

        if(*li < 5 || *li > 35)
        {
            printf("Erreur. Saisir entre 5 et 35.\n");
        }
    } while (*li < 5 && *li > 35);

    do
    {
        printf("Veuillez saisir le nombre de colonne pour la table du jeu :\n");
        scanf("%d", &*co);
        vidbuffer();

        if(*co < 5 || *co > 35)
        {
            printf("Erreur. Saisir entre 5 et 35.\n");
        }
    } while (*co < 5 || *co > 35);
    
}

void affi_tab(player p1, player p2, int li, int co){

    printf("    ");

    for (int o = 1; o <= co; o++)
    {
        printf(" %2d ", o);
    }
    printf("\n");
    
    printf("    ");

    printf("%c", LT);

    for (int n = 1; n < co; n++)
    {
        topcase();
        printf("%c", TI);
    }
    topcase();
    printf("%c", RT);
    printf("\n");
    
    
    for (int i = 1; i <= li; i++)
    {
        
        
        if (i != 1 )
        {   
            printf("    ");
            printf("%c", LI);
            for (int k = 1; k < co; k++)
            {
                topcase();
                printf("%c", I);
            }
            topcase();
            printf("%c", RI);
            printf("\n");
        }
        
        printf(" %2d ", i);
        
        for (int j = 1; j <= co; j++)
        {
            printf("%c", V);
            if (p1.y == j && p1.x == i)
            {
                printf(" %c ", 241);
            }
            else if(p2.x == i && p2.y == j)
            {
                printf(" P ");
            }
            else 
            {
                printf("   ");
            }
            
        }
        printf("%c", V);
        printf("\n");
        
    }

    printf("    "); 
    printf("%c", LB);
    for (int m = 1; m < co; m++)
    {
        topcase();
        printf("%c", BI);
    }
    topcase();
    printf("%c", RB);
    
    printf("\n");
    
}

void deplacement_droitp1(player *p1, int li, int co){

    int d = 0;

    do
    {
    printf("Souhaitez vous vous deplacez de 1 ou 2 cases : \n");
    scanf("%d", &d);

    if (d == 1 && p1->y != co)
    {
        p1->y+=1;
    }
    else if (d == 2 && p1->y != co && p1->y != co - 1)
    {
        p1->y+=2;
    }

    if (d != 1 && d != 2)
    {
        printf("Impossible");
    }
    
    }while(d != 1 && d != 2);

}

void deplacement_gauchep1(player *p1, int li, int co){

    int g = 0;

    do
    {
    printf("Souhaitez vous vous deplacez de 1 ou 2 cases : \n");
    scanf("%d", &g);

    if (g == 1 && p1->y != (co - co) + 1)
    {
        p1->y-=1;
    }
    else if (g == 2 && p1->y != (co - co) + 1 && p1->y != (co - co) + 2)
    {
        p1->y-=2;
    }

    if (g != 1 && g != 2)
    {
        printf("Impossible");
    }
    
    }while(g != 1 && g != 2);
    
}

void deplacement_basp1(player *p1, int li, int co){

    int b = 0;

    do
    {
    printf("Souhaitez vous vous deplacez de 1 ou 2 cases : \n");
    scanf("%d", &b);

    if (b == 1 && p1->x != li)
    {
        p1->x+=1;
    }
    else if (b == 2 && p1->x != li && p1->x != li - 1)
    {
        p1->x+=2;
    }

    if (b != 1 && b != 2)
    {
        printf("Impossible");
    }
    
    }while(b != 1 && b != 2);
    
}

void deplacement_hautp1(player *p1, int li, int co){

    int h = 0;

    do
    {
    printf("Souhaitez vous vous deplacez de 1 ou 2 cases : \n");
    scanf("%d", &h);

    if (h == 1 && p1->x != (li - li) + 1)
    {
        p1->x-=1;
    }
    else if (h == 2 && p1->x != (li - li) + 1 && p1->x != (li - li) + 2)
    {
        p1->x-=2;
    }

    if (h != 1 && h != 2)
    {
        printf("Impossible");
    }
    
    }while(h != 1 && h != 2);
    
}
void deplacement_diagonale_haut_droitp1(player *p1, int li, int co){

    if (p1->x != ((li - li) + 1)  && p1->y != co) 
    {
        p1->x-=1;
        p1->y+=1;
    }
    
}

void deplacement_diagonale_haut_gauchep1(player *p1, int li, int co){

    if (p1->y != ((co - co) + 1) && p1->x != ((li - li) + 1)) 
    {
        p1->x-=1;
        p1->y-=1;
    }
    
}

void deplacement_diagonale_bas_droitp1(player *p1, int li, int co){

    if (p1->x != li && p1->y != co)  
    {
        p1->x+=1;
        p1->y+=1;
    }
    
}

void deplacement_diagonale_bas_gauchep1(player *p1, int li, int co){

    if (p1->y != ((co - co) + 1) && p1->x != li) 
    {
        p1->x+=1;
        p1->y-=1;
    }
    
}

void deplacement_diagonale_haut_droitp2(player *p2, int li, int co){

    if (p2->x != ((li - li) + 1)  && p2->y != co) 
    {
        p2->x-=1;
        p2->y+=1;
    }
    
}

void deplacement_diagonale_haut_gauchep2(player *p2, int li, int co){

    if (p2->y != ((co - co) + 1) && p2->x != ((li - li) + 1)) 
    {
        p2->x-=1;
        p2->y-=1;
    }
    
}

void deplacement_diagonale_bas_droitp2(player *p2, int li, int co){

    if (p2->x != li && p2->y != co)  
    {
        p2->x+=1;
        p2->y+=1;
    }
    
}

void deplacement_diagonale_bas_gauchep2(player *p2, int li, int co){

    if (p2->y != ((co - co) + 1) && p2->x != li) 
    {
        p2->x+=1;
        p2->y-=1;
    }
    
}

void deplacement_droitp2(player *p2, int li, int co){

    int d = 0;

    do
    {
    printf("Souhaitez vous vous deplacez de 1 ou 2 cases : \n");
    scanf("%d", &d);

    if (d == 1 && p2->y != co)
    {
        p2->y+=1;
    }
    else if (d == 2 && p2->y != co && p2->y != co - 1)
    {
        p2->y+=2;
    }

    if (d != 1 && d != 2)
    {
        printf("Impossible");
    }
    
    }while(d != 1 && d != 2);

}

void deplacement_gauchep2(player *p2, int li, int co){

    int g = 0;

    do
    {
    printf("Souhaitez vous vous deplacez de 1 ou 2 cases : \n");
    scanf("%d", &g);

    if (g == 1 && p2->y != (co - co) + 1)
    {
        p2->y-=1;
    }
    else if (g == 2 && p2->y != (co - co) + 1 && p2->y != (co - co) + 2)
    {
        p2->y-=2;
    }

    if (g != 1 && g != 2)
    {
        printf("Impossible");
    }
    
    }while(g != 1 && g != 2);
    
}

void deplacement_basp2(player *p2, int li, int co){

    int b = 0;

    do
    {
    printf("Souhaitez vous vous deplacez de 1 ou 2 cases : \n");
    scanf("%d", &b);

    if (b == 1 && p2->x != li)
    {
        p2->x+=1;
    }
    else if (b == 2 && p2->x != li && p2->x != li - 1)
    {
        p2->x+=2;
    }

    if (b != 1 && b != 2)
    {
        printf("Impossible");
    }
    
    }while(b != 1 && b != 2);
    
}

void deplacement_hautp2(player *p2, int li, int co){

    int h = 0;

    do
    {
    printf("Souhaitez vous vous deplacez de 1 ou 2 cases : \n");
    scanf("%d", &h);

    if (h == 1 && p2->x != (li - li) + 1)
    {
        p2->x-=1;
    }
    else if (h == 2 && p2->x != (li - li) + 1 && p2->x != (li - li) + 2)
    {
        p2->x-=2;
    }

    if (h != 1 && h != 2)
    {
        printf("Impossible");
    }
    
    }while(h != 1 && h != 2);
    
}

void deplacement_tab(player p, player p1, player p2, int li, int co){

    char choix; char choix1; char rep; char rep1; char rep2; char rep3; char rep4; char rep5;
    
    do
    {
        vidbuffer();

        printf("Tour du joueur 1 : \n");

        printf("Souhaitez-vous vous deplacer vers la droite (d/d), vers la gauche (g/G), vers le bas (b/B/), vers le haut (h/H), en diagonale (r/R) ? \n");
        choix = getchar();
        vidbuffer();

        switch (choix)
        {
        case 'd': case 'D':
            deplacement_droitp1(&p1, li, co);
            affi_tab(p1, p2, li, co);
            break;
        
        case 'g': case 'G':
            deplacement_gauchep1(&p1, li, co);
            affi_tab(p1, p2, li, co);
            break;
        
        case 'b': case 'B':
            deplacement_basp1(&p1, li, co);
            affi_tab(p1, p2, li, co);
            break;
        
        case 'h': case 'H':
            deplacement_hautp1(&p1, li, co);
            affi_tab(p1, p2, li, co);
            break;

        case 'r': case 'R':
        printf("Souhaitez-vous vous dÃ©placer vers la diagonale du haut ou du bas ? (h/H/b/B)\n");
            rep = getchar();
            vidbuffer();
            switch (rep)
            {
                case 'h': case 'H':
                    printf("Souhaitez-vous vous dÃ©placer vers la diagonale haut DROIT ou GAUCHE ? (d/D/g/G)\n");
                    rep1 = getchar();
                    switch (rep1)
                    {
                    case 'd': case 'D':
                        deplacement_diagonale_haut_droitp1(&p1, li, co);
                        affi_tab(p1, p2, li, co);
                        break;

                    case 'g': case 'G':
                        deplacement_diagonale_haut_gauchep1(&p1, li, co);
                        affi_tab(p1, p2, li, co);
                        default:
                        break;
                    }
                   

                case 'b': case 'B':
                    printf("Souhaitez-vous vous dÃ©placer vers la diagonale bas DROIT ou GAUCHE ? (d/D/g/G)");
                    rep2 = getchar();
                    switch (rep2)
                    {
                    case 'd': case 'D':
                        deplacement_diagonale_bas_droitp1(&p1, li, co);
                        affi_tab(p1, p2, li, co);
                        break;
                    
                    case 'g': case 'G': 
                        deplacement_diagonale_bas_gauchep1(&p1, li, co);
                        affi_tab(p1, p2, li, co);
                        default:
                        break;
                    }
                    
                default:
                break;
            
            }
            break;
            vidbuffer();
        }
    
        vidbuffer();

        printf("Tour du joueur 2 : \n");

        printf("Souhaitez-vous vous deplacer vers la droite (d/d), vers la gauche (g/G), vers le bas (b/B/), vers le haut (h/H), en diagonale (r/R) ? \n");
        choix1 = getchar();
        vidbuffer();

        switch (choix1)
        {
        case 'd': case 'D':
            deplacement_droitp2(&p2, li, co);
            affi_tab(p1, p2, li, co);
            break;
        
        case 'g': case 'G':
            deplacement_gauchep2(&p2, li, co);
            affi_tab(p1, p2, li, co);
            break;
        
        case 'b': case 'B':
            deplacement_basp2(&p2, li, co);
            affi_tab(p1, p2, li, co);
            break;
        
        case 'h': case 'H':
            deplacement_hautp2(&p2, li, co);
            affi_tab(p1, p2, li, co);
            break;

        case 'r': case 'R':
        printf("Souhaitez-vous vous dÃ©placer vers la diagonale du haut ou du bas ? (h/H/b/B)\n");
            rep3 = getchar();
            vidbuffer();

            switch (rep3)
            {
                case 'h': case 'H':
                    printf("Souhaitez-vous vous dÃ©placer vers la diagonale haut DROIT ou GAUCHE ? (d/D/g/G)");
                    rep4 = getchar();
                    switch (rep4)
                    {
                    case 'd': case 'D':
                        deplacement_diagonale_haut_droitp2(&p2, li, co);
                        affi_tab(p1, p2, li, co);
                        break;

                    case 'g': case 'G':
                        deplacement_diagonale_haut_gauchep2(&p2, li, co);
                        affi_tab(p1, p2, li, co);
                        default:
                        break;
                    }

                case 'b': case 'B':
                    printf("Souhaitez-vous vous dÃ©placer vers la diagonale bas DROIT ou GAUCHE ? (d/D/g/G)");
                    rep5 = getchar();
                    switch (rep5)
                    {
                    case 'd': case 'D':
                        deplacement_diagonale_bas_droitp2(&p2, li, co);
                        affi_tab(p1, p2, li, co);
                        break;
                    
                    case 'g': case 'G': 
                        deplacement_diagonale_bas_gauchep2(&p2, li, co);
                        affi_tab(p1, p2, li, co);
                        default:
                        break;
                    }
                    default:
                break;
                vidbuffer();
            }
            break;
            
            vidbuffer();
        }
    } while (1);
    
}

int main(void){

    player p = {"","", 0, 0}; player p1 = {"","",0, 0}; player p2 = {"","",0, 0}; 
    perso j = {"", 0, 0, 0};
    int rep; char nomjoueur[30]; int nb_joueur; 
    player *tabplayer = NULL;
    int li; int co;

    regle();
    
    printf("Veuillez saisir le nombre de joueurs : \n");
    scanf("%d", &nb_joueur);

    tabplayer = malloc(sizeof(int) * nb_joueur);

    if (tabplayer == NULL)
    {
        exit(1);
    }

    for (int i = 0; i < nb_joueur; i++)
    {
        create_player(&tabplayer[i], &j, nomjoueur, &rep);
    }

    for (int i = 0; i < nb_joueur; i++)
    {
        printf("PSEUDO = %s   ||    PERSO = %s    ||    POINTS DE VIE = %d    ||    POINTS D'ATTAQUE =  %d    \n", tabplayer[i].pseudo, tabplayer[i].perso, tabplayer[i].hp, tabplayer[i].mp);

        printf("\n");
    }

    printf("Personnage enregistre avec succes !");

    printf("Enregistrement de la taille de la table du jeu : \n");

    taille_tab(&li, &co);

    p1.x = 1; p1.y = 1; p2.x = li; p2.y = co;

    affi_tab(p1, p2, li, co);
    deplacement_tab(p, p1, p2, li, co);

    free(tabplayer);

}