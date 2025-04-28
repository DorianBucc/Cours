#include <stdio.h>
#include <string.h>

int cascase(int l,int c)             //fonction vérifier si une case est gagnante ou perdante
{
    int cas = 1;                    // default case perdante
    if (c == l)                     // dans le cas ou la ligne est la colonne sont eq 
    {
        cas = 0;                    // cas case gagnant
    }
    else                            //  cas où la ligne est infèrieur ou superieur à la colonne
    {                   
        if (c%3 == l%3)              // vérifiant que ce sont des multiple de 3
        {
            cas = 0;                // cas case gagnante
        }
    }
    return cas;                     // retourne cas gagnant
}

int main(){

    int res = tamere( 4 , 7 );
    char *mot;
    if(res == 0) mot = "gagnante";
    else mot = "perdante";
    printf("case %s",mot);
}