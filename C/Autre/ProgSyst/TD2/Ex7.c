#include <stdio.h>
#include <string.h>

struct Etudiant {
   unsigned int matricule;
   char nom[100];
   char prenom[100];
   short note[100];
};

void main(){
    int i = 0, n;
    puts("Taille du tableau : ");
    scanf("%d", &n);
    struct Etudiant etu[n];

    for(int i = 0; i < n; i++){
        puts("Entrez le matricule de l'etudiant : ");
        scanf("%d", &etu[i].matricule);
        puts("Entrez le nom de l'etudiant : ");
        scanf("%s", &etu[i].nom);
        puts("Entrez le prenom de l'etudiant : ");
        scanf("%s", &etu[i].prenom);
        puts("Entrez la note de l'etudiant : ");
        scanf("%d", &etu[i].note[0]);
        puts("\n");
    }

    puts("Tableau d'etudiants : ");
    for (int i = 0; i < n; i++)
    {
        printf("Matricule : %d, NOM : %s, Prenom : %s, Note : %d\n", etu[i].matricule, etu[i].nom, etu[i].prenom, etu[i].note[0]);
    }
}