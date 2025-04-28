#include <stdio.h>
#include <time.h>
#include "lib.h"


void topcase(){
    for (int i = 1; i <= 3; i++)
    {
        printf("%c",H);
    }
    
}

void aff(int tab[30][30],int li,int co) //affichage du tableau
{

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
            if (tab[i][j] == 0)                             //affichage des cases à zero
            {
                printf("%c %d ",V,tab[i][j]);                    // ↑ écriture de l'emplacement des 0 du tableaux
            }
            else
                printf("%c %d ",V,tab[i][j]);               //affichage des colone sur la ligne
        }
        printf("%c\n",V);                                   //Pour une fin de ligne d'un millieu de pour les colone
    }

    printf("%c",LB);                                // ecrit une sur chaque début interligne le (├)
    for (int b = 1; b < co; b++)                    //boucle pour ecrire les 3 bar V (───) et la crois (┼)
    {
        topcase();                                  // ecrit les 3 bar ───
        printf("%c",BI);                             // ecrit l'intersection (┼)
    }
    topcase();                                      // ecrit les 3 bar ───
    printf("%c\n",RB);                              // ecrit une sur chaque fin interligne le (┤)
}


void init_tab(int tab[30][30],int li, int co)               //fonction pour initialiser les valeur du tableau
{
    for (int i = 0; i < li; i++)                            //boucle pour selectionner les ligne
    {
        for (int j = 0; j < co; j++)                        //boucle pour selectionner les colonnes
        {
            tab[i][j] = 0;                                  // affectation des valeur à 0
        }   
    }
}


int main(){

    int tabentier[30][30], li = 5, co = 5;

    init_tab(tabentier, li, co);
    aff(tabentier, li, co);

}