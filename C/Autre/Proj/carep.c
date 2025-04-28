#include <stdio.h>
#include "lib.h"

#define TMAX 30


struct car
{
    int l;
    int c;
    int val;
}car;

void topcase()          // fonction ecrivant les 3 bar ───
{
    for (int a = 1; a <= 3; a++)
    {
        printf("%c",H);
    }
}

void taille_tableau(int *ta)
{
    do
    {
        printf("Veuillez saisir les dimensions du tableau\n");
        scanf("%d",&*ta);

    } while ((*ta**ta)%2 == 0);
    printf("Merci\n");   
}

void initialisation(int (*tab)[TMAX])
{
    for (int j = 0; j < TMAX; j++)
    {
        for (int i = 0; i < TMAX; i++)
        {
            tab[j][i] = 0;
        }
    }
    printf("Initialiser\n");  
}

void prochaine_case(int (*tab)[TMAX],struct car *p,int *l,int *c,int ta)
{
    int S = 0;
    if (S == 0)
    {
        if (p->l == 0 && p->c == 0 && tab[ta-1][ta-1] == 0)
        {
            if (tab[ta][ta] == 0)
            {
                *l = ta-1;
                *c = ta-1;
            }
            else S = 1;  
        }
        else if (p->l == 0 && p->c == 0 && tab[ta-1][ta-1] != 0)
        {
            S = 1;
        }
        
        else if(p->l == 0)
        {
            if(tab[ta][p->c-1] == 0)
            {
                *l = ta-1;
                *c = p->c-1;
            }
            else S = 1;  
        }
        else if (p->c == 0)
        {
            if(tab[ta][p->c-2] == 0)
            {
                *l = p->l-1;
                *c = ta-1;
            }
            else S = 1;  
        }
        else
        {
            if (tab[p->l-1][p->c-1] == 0)
            {
                *l = p->l-1;
                *c = p->c-1;
            }
            else S = 1;        
        }
    }
    
    

    if (S == 1)
    {
        if (p->l == ta-1)
        {
            *l = 0;
        }
        else if (tab[p->l+1][p->c] == 0 )
        {
            *l += 1;
        }
        
        
    }

    


    
}

void aff(int li,int co,int tab[][TMAX])                         //affichage du tableau
{
    printf("\n%c",LT);                                      // ecrit une sur chaque début interligne le (┌)
    for (int b = 1; b < co; b++)                            //boucle pour ecrire les 3 bar V (───) et la crois (┼)
    {
        topcase();                                          // ecrit les 3 bar ───
        printf("%c",TI);                                    // ecrit l'intersection (┬)
    }
    
    topcase();                                              // ecrit les 3 bar ───
    printf("%c\n",RT);                                      // ecrit une sur chaque fin interligne le (┐)

    for (int i = 0; i < li; i++)                            // boucle pour les ligne
    {
        if (i != 0)
        {
            printf("%c",LI);                                // ecrit une sur chaque début interligne le (├)
            for (int b = 1; b < co; b++)                    //boucle pour ecrire les 3 bar V (───) et la crois (┼)
            {
                topcase();                                  // ecrit les 3 bar ───
                printf("%c",I);                             // ecrit l'intersection (┼)
            }
            topcase();                                      // ecrit les 3 bar ───
            printf("%c\n",RI);                              // ecrit une sur chaque fin interligne le (┤)
            
        }

        for (int j = 0; j < co; j++)                        // boucle pour les colonnes
        {
                printf("%c%2d ",V,tab[i][j]);                                          // ↑ écriture de l'emplacement des 0 du tableaux
        }
        printf("%c\n",V);                                   //Pour une fin de ligne d'un millieu de pour les colone
    }


    printf("%c",LB);                                        // ecrit une sur chaque début interligne le (└)
    for (int b = 1; b < co; b++)                            //boucle pour ecrire les 3 bar V (───) et la crois (┼)
    {
        topcase();                                          // ecrit les 3 bar ───
        printf("%c",BI);                                    // ecrit l'intersection (┴)
    }
    topcase();                                              // ecrit les 3 bar ───
    printf("%c\n\n",RB);                                      // ecrit une sur chaque fin interligne le (┘)

}


int main()
{
    int ta;
    int tab[TMAX][TMAX];
    
    taille_tableau(&ta);
    initialisation(tab);
    car.c = (ta/2);
    car.l = 0;
    car.val = 1;
    int l,c,finish = 0;
    tab[car.l][car.c] = car.val;
    car.val++;
    printf("E1\n");
    do
    {
        prochaine_case( tab, &car, &l, &c, ta);
        tab[l][c] = car.val;
        car.l = l;
        car.c = c;
        car.val++;
        printf("E2\n");

    } while ( car.val <= ta*ta);
    printf("E3\n");
    aff(ta,ta,tab);

}