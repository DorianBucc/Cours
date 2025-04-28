#include <stdio.h>

struct Personne {
   char nom[100];
   char prenom[100];
   int age;
};

struct Personne pers = {
    .nom = "Pieu",
    .prenom = "Gerard",
    .age = 36,
};

void main(){
    printf("nom = %s, prenom = %s, age = %d ans\n", pers.nom, pers.prenom, pers.age);
}