#include <stdio.h>
#include <string.h>
 
struct Etudiant {
   int matricule;
   char nom[100];
   char prenom[100];
   int age;
};

struct Etudiant etu1 = {
    .matricule = 8428739,
    .nom = "Lafri",
    .prenom = "Jac",
    .age = 39,
};

struct Etudiant Modifier(struct Etudiant etu1)
{
    etu1.matricule = etu1.matricule + 2000;
    strcat(etu1.nom, "pouille");
    strcat(etu1.prenom, "ouille");
    etu1.age = etu1.age + 2;

    return etu1;
}
 
void main(){
    printf("Matricule : %d, NOM : %s, Prenom : %s, Age : %d\n", etu1.matricule, etu1.nom, etu1.prenom, etu1.age);
    etu1 = Modifier(etu1);
    printf("Matricule : %d, NOM : %s, Prenom : %s, Age : %d\n", etu1.matricule, etu1.nom, etu1.prenom, etu1.age);
}