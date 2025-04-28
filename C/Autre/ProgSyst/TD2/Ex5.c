//Liste Chaînée Simple :
//Implémenter une liste chaînée simple (5 éléments)
// en utilisant des structures et des pointeurs.
//Ajouter des fonctions pour ajouter, supprimer et afficher des éléments de la liste.*/
#include <stdio.h>

typedef struct maillon maillon;
struct maillon
{
    char val;
    maillon* next;
};


void afficherListe(maillon* maille){
    maillon* curseur = maille;
    printf("%c",(*curseur).val); // curseur->val == (*curseur).val
    if(curseur->next == NULL){puts(""); return;}
    do
    {
        curseur = curseur->next;
        printf("%c",curseur->val);
    }
    while (curseur->next != NULL);

    puts(""); // == printf("\n");
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


int main()
{
    //maillon maillon1 = (maillon){'C',&(maillon){'A',NULL}};
    // maillon maillon1;
    // maillon1.next = NULL;
    // maillon1.val = 'S';
    maillon maillon1 = { .next = NULL, .val = 'S'};
    afficherListe(&maillon1);
    ajouter(&maillon1,&(maillon){'A',NULL});
    ajouter(&maillon1,&(maillon){'L',NULL});
    ajouter(&maillon1,&(maillon){'U',NULL});
    ajouter(&maillon1,&(maillon){'T',NULL});
    afficherListe(&maillon1);
    supprimer((&maillon1)->next);
    afficherListe(&maillon1);
    return 0;
}