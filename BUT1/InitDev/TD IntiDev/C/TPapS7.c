#include "fraction.h"

Frac Creer_Frac(int a, int b)
{
    Frac F;
    F.num = a;
    F.den = b;
    return F;
}

Frac Saisie1_Frac()
{
    Frac F;
    scanf("%d %d",&F.num,&F.den);
    return F;
}

void Affich_Frac(Frac F)
{
    printf("%-5d/%5d\n",F.num,F.den);
}

void Saisie2_Frac(Frac *F)
{
    scanf("%d %d",&F->num,&F->den);
}

int pgcd(int a,int b)
{
    a = abs(a);
    b = abs(b);
    while(a != b)
    {
        if(a > b) a = a - b;
        else b -= a;
    }
    return a;
}

void Reduire_Frac(Frac *F)
{
    int m = pgcd(F->num, F->den);
    F->num = F->num / m;
    F->den = F->den / m;
}

Frac Somme_Frac(Frac F1, Frac F2)
{
    Frac S = {F1.num * F2.den, F1.den * F2.den};
    Reduire_Frac(&S);
    return S;
}

Frac Produit_Frac(Frac F1, Frac F2)
{
    Frac P = {F1.num * F2.num, F1.den * F2.den};
    Reduire_Frac(&P);
    return P;
}

Frac Division_Frac(Frac F1, Frac F2)
{
    Frac D = {F1.num * F2.num, F1.den * F2.den};    //Faux
    Reduire_Frac(&D);
    return D;
}