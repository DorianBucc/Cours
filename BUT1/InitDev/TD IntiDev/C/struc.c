#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct mo
{
    float n;
    int c;
}Tabnote;

typedef struct no
{
    int nbn;
    Tabnote notes[20];
}Notess;

typedef struct etude
{
    char nom[25];
    Notess note;
    float moy;
} Etudiant;

void lire_notes(char *nomfic, Etudiant *promo,int *n);
void affich_etudiant(Etudiant *promo,int *n);
float moys(Etudiant *p, int n);

int main()
{

    Etudiant promo[25];
    int n;
    int a = 1;
    lire_notes("notes.txt", promo, &n);
    affich_etudiant(promo, &a);
    moys(promo, n);
    return 0;
}

void lire_notes(char *nomfic, Etudiant *promo,int *n)
{
    FILE *f = fopen(nomfic,"r");
    int i,j,temp=0;
    fscanf(f, "%d", n);
    
    for (i = 0; i < *n; i++)
    {
        promo[i].moy = 0;
        fscanf(f,"%s %d",promo[i].nom, &promo[i].note.nbn);
        for(j=0; j < promo[i].note.nbn; j++)
        {
            fscanf(f,"%f %d", &promo[i].note.notes[j].n, &promo[i].note.notes[j].c);
            promo[i].moy += (promo[i].note.notes[j].n * promo[i].note.notes[j].c);  
            temp += promo[i].note.notes[j].c; 
        }
        promo[i].moy /= temp;
        temp = 0;
    }
}

void affich_etudiant(Etudiant *promo,int *n)
{
    int i, temp;
    printf("Nom de l'eleve : %s\n",promo[*n].nom);
    for (i = 0; i < promo[*n].note.nbn; i++)
    {
        printf("Notes n'%d de l'eleve : %.2f\n",i+1,promo[*n].note.notes[i].n); 

    }
    printf("Moyenne de l'eleve : %.2f\n",promo[*n].moy); 
}

float moys(Etudiant *p, int n)
{
    int i;
    float moy;
    for (i = 0; i < n; i++)
    {
        moy += p[i].moy;
    }
    moy/=n;
    printf("moyenne des moy : %.2f\n",moy);
    
    
}