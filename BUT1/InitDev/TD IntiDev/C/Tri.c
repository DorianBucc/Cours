#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int TrouverMin(int *tab,int N, int borneMin)
{
    int i, min = tab[0], posmin;
    for (i = borneMin; i < N; i++){
        if(tab[i] < min){
            min = tab[i];
            posmin = i;
        }
    }
    return posmin;
}

void affichage(int *tab,int n)
{
    for (int i=0; i < n; i++)
    {
        printf("%d,",tab[i]);
    }
    printf("\n");
}

void echange(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int trie(int *tab,int n){
    for(int i = 0; i < n; i++)
    {
        if(tab[i] > tab[i+1])   return 0;
    }
    return 1;
}

void tri_b(int *tab,int n){
    do
    {
        for (int i=0; i < n-1; i++)
        {
            if (tab[i]>tab[i+1])    echange(&tab[i],&tab[i+1]);
        }
    } while (trie(tab,n) != 1);
}



void tri_insertion(int *tab,int n)
{                                        // à revoir
    for (size_t y = 0; y < n*2; y++)
    {
        for (int i = 0;i < n; i++)
        {
            echange(&tab[i],&tab[TrouverMin(tab,n,i)]);
        }
    }
    int temp = tab[0];
    for (int y = 0; y < n-1; y++)
    {
        echange(&tab[y],&tab[y+1]);
    }
    tab[n-1] = temp;
}

int rech_sequentielle(int *tab,int n,int val){

    for (int i = 0; i < n ; i++ )
    {
        if (tab[i] ==  val)
        {
            printf("La position de la valeur val dans le tableau est : %d \n",i+1);
            return i+1;
        }
    }
    printf("La valeur n'est pas dans le tableau");
    return 0;
}


int rech_dichotomique( int *tab, int n, int val){
    int min, max, m, b, a;
    min=1;
    max=n;
    do
    {
        m=(max+min)/2;
        if (tab[m] == val)
        {
            printf("La valeur recherché est à la position : %d \n",m+1);
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


int main()
{
    srand(time(NULL));
    int n=3000;
    int val=0;
    int tab[n];
    for (int i = 0; i < n; i++)
    {
        tab[i] = rand()%100;
    }
    // affichage(tab,n);
    

    printf("%d\n",TrouverMin(tab, n, val));
    // echange(&tab[2],&tab[4]);
    printf("%d\n",trie(tab,n));
    
    // tri_b(tab,n);
    // tri_insertion(tab,n);
    // rech_sequentielle(tab,n,34);
    rech_dichotomique(tab,n,34);

    // affichage(tab,n);
    printf("%d\n",trie(tab,n));
    printf("\n");
}

