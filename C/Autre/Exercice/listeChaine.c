#include <stdio.h>
#include <stdlib.h>


typedef struct maillon maillon;
struct maillon
{
    char val;
    maillon* next;
};

// typedef struct dimension{
//     int w;
//     int h;
// }dimension;

// typedef struct coord{
//     int x;
//     int y;
//     dimension dim;
// }coord;




void afficherListe(maillon* maille){
    maillon* curseur = maille;
    printf("%c",curseur->val);
    do
    {
        curseur = curseur->next;
        printf("%c",curseur->val);
    }
    while (curseur->next != NULL);
}
void ajouter(maillon* dest, maillon* maille)
{
    maillon* curseur = dest;
    while (curseur->next != NULL){curseur = curseur->next;}
    curseur->next = maille;

}
void supprimer(maillon* maille)
{
    *maille = *maille->next;
}


int main(int argc, char const *argv[])
{
    char* me[9] = "ueribr";
    mes[8] = "g"
    for(int i = 1; i <= 9)
    // coord position = (coord){9,9,(dimension){5,6}}
    // position.dim.h;
    maillon maillon1 = (maillon){'C',&(maillon){'A',NULL}};
    ajouter(&maillon1,&(maillon){'B',NULL});
    supprimer(&maillon1);
    afficherListe(&maillon1);
    return 0;
}