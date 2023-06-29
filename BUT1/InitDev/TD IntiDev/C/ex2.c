#include <stdio.h>

int minTabBorne(int bi, int bs, int tab[]);
void echange(int* a, int* b);
// a est de type int* <==> adresse d'un entier 
void tri_b(int tab[], int n);
void affichage(int tab[],int n);
int trie(int tab[],int n);
void tri_insertion(int tab[],int n);
int TrouverMin(int tab[],int N, int borneMin);
int rech_sequentielle(int tab[],int n,int val);
int rech_dichotomique(int tab[],int n, int val);
void supprime(int tab[], int n, int val);

int main(){
    int n=5;
    int val=15;
    int tab[] = {15,15,16,21,58};
    supprime(tab, n, val);
}

int TrouverMin(int tab[],int N, int borneMin){
    int i, min = 1001, posmin;
    for (i = borneMin; 1 < N; i++){
        if(tab[i] < min){
            min = tab[i];
            posmin = i;
        }
    }
}

void echange(int* a, int* b){
    int temp = *a;
    // * = opérateur d'adressage indirect
    // *a (adressage indirect)
    // la mémoire d'adresse a
    *a = *b;
    *b = temp;
}

void affichage(int tab[],int n){
    int i;
    for (i=0; i<n; i++)
    {
        printf("%d,",tab[i]);
    }
}

int trie(int tab[],int n){
    int i=0;
    while (i < n-1)
    {
        if(tab[i] > tab[i+1])
            return 0;
        i++;
    }
    return 1;
}

void tri_b(int tab[],int n){
    int i;
    do
    {
        for (i=0; i < n-1; i++)
        {
        if (tab[i]>tab[i+1]){
            echange(&tab[i],&tab[i+1]);
        }
        }
    } while (trie(tab,n) != 1);
}

void tri_insertion(int tab[],int n){
    int i;
    for (i=0;i<n-1; i++)
    {
        echange(&tab[i],&tab[TrouverMin(tab,n,i)]);
    }
}

int rech_sequentielle(int tab[],int n,int val){
    int i;
    for (i=0;i<n;i++)
    {
        if (tab[i] ==  val)
        {
            printf("La position de la valeur val dans le tableau est : %d",i+1);
            return i+1;
        }
            printf("La valeur n'est pas dans le tableau");
            return 0;
    }
}

int rech_dichotomique(int tab[],int n, int val){
    int min, max, m, b, a;
    min=1;
    max=n;
    do
    {
        m=(max+min)/2;
        if (tab[m] == val)
        {
            printf("La valeur recherché est à la position : %d",m+1);
            return m+1;
        }
        else if (tab[m] < val)
        {
            min=m+1;
        }
        else
        {
            max=m-1;
        }   
    } while (min<=max);
}

void supprime(int tab[], int n, int val)
{
    for (int i = 0; i < n; i++)
    {
        if (val == tab[i])
        {
             if (tab[i] == tab[i + 1])
            {
                echange(tab[i], tab[i + 1]);
            }
            do
            {
                /* code */
            } while (tab[i + 1]);
            
        }
    }
    affichage(tab, n-1);
}