//Tri de Structures : Implémenter une fonction de tri qui trie un tableau d'étudiants en fonction de leur note.
#include <stdio.h>
#include <string.h>
//typedef struct Etudiant Etudiant;
typedef struct Etudiant {
   int matricule;
   char nom[100];
   int note;
}Etudiant;

void main(){
    int n;
    puts("Taille du tableau : ");
    scanf("%d", &n);
    struct Etudiant etu[2];
    etu[0] = (Etudiant){23,"Ferchach",0};
    etu[1] = (Etudiant){24,"Dagon",20};
    
    for (int y = 0; y < n; y++)
    {
        for(int i = 0; i < n; i++){
            if(etu[i+1].note > etu[i].note){
                struct Etudiant temp = etu[i];
                etu[i] = etu[i+1];
                etu[i+1] = temp;
            }
        }
    }
    
    

    for (int i = 0; i < n; i++)
    {
        printf("Matricule : %d, NOM : %s, Note : %d\n", etu[i].matricule, etu[i].nom, etu[i].note);
    }

}