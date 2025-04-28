/*
Structures Emboîtées : Créer une structure "Adresse" avec des 
champs tels que rue, ville, code postal, etc. 
Ensuite, incorporer cette structure dans la structure "Personne" 
pour représenter l'adresse d'une personne.
*/
#include <stdio.h>
#include <string.h>

typedef struct Adresse{
    char rue[100];
    int numero;
    char ville[100];
    int codepostal;
} Adresse;

struct Personne {
   char nom[100];
   char prenom[100];
   int age;
   Adresse adresse;
};

struct Personne pers = {
.nom = "Pieu",
.prenom = "Gerard",
.age = 36,
.adresse = (Adresse){"rue de metz",26,"Metz",57000},
};

int main(int argc, char const *argv[])
{ 
    printf("nom = %s, prenom = %s, age = %d ans\nadresse : %d %s %d dans %s", pers.nom, pers.prenom, pers.age,pers.adresse.numero,pers.adresse.rue,pers.adresse.codepostal,pers.adresse.ville);
    return 0;
}
