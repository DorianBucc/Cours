#ifndef FRACTION
#define FRACTION

#include <stdio.h>
#include <stdlib.h>

typedef struct frac
{
    int num;
    int den;
}Frac;

Frac Creer_Frac(int a, int b);
void Affich_Frac(Frac F);
Frac Saisie1_Frac();
void Saisie2_Frac(Frac *F);
int pgcd(int a,int b);
void Reduire_Frac(Frac *F);
Frac Somme_Frac(Frac F1, Frac F2);
Frac Produit_Frac(Frac F1, Frac F2);
Frac Division_Frac(Frac F1, Frac F2);

#endif