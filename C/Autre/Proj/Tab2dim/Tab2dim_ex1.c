#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define NCOL 5
#define NLIG 5



void tabu(int tab[][NCOL])
{
    for (int i = 0; i < NLIG; i++)
    {
        for (int j = 0; j < NCOL; j++)
        {
            tab[i][j] = rand()%100;
        }
    }
}

void remplir(int *tab, int *t, int val)
{
    tab[*t] = val;
    *t+=1;
}

int main()
{
    srand(time(NULL));
    int tab[NLIG][NCOL];
    tabu(tab);
    int res[100];
    int min = tab[0][0], min1, min2,t = 0,m1,m2,m3;
    for (int i = 0; i < NLIG; i++)
    {
        for (int j = 0; j < NCOL; j++)
        {
            if (min > tab[i][j])   min = tab[i][j];
        }
        
    }
    remplir(res,&t,min);

    for (int i = 0; i < NLIG; i++)
    {
        min1 = tab[i][0];
        for (int j = 0; j < NCOL; j++)
        {
            if (min1 > tab[i][j])
            {
                min1 = tab[i][j];
            }
        }
        remplir(res,&t,min1);
        m2 = t; 
    }    

    for (int i = 0; i < NCOL; i++)
    {
        min2 = tab[0][i];
        for (int j = 0; j < NLIG; j++)
        {
            if (min2 > tab[j][i]) 
            {
                min2 = tab[j][i];
                
            }
            
        }
        remplir(res,&t,min2);
        m3 = t;
    }
    printf("La valeur min est %d\n",res[0]);
    int c = 1;
    for (int i = 1; i < m2; ++i)
    {
        printf("La valeur min par colonne %d est de %d\n",c,res[i]);
        c++;
    }
    c = 1;
    for (int i = m2; i < m3; ++i)
    {
        printf("La valeur min par ligne %d est de %d\n",c,res[i]);
        c++;
    }
    c = 1;
    int temp;
    for (int i = 1; i <= 2; ++i)
    {
        for (int j = c; j < NCOL+c; ++j)
        {
            printf("%d |",res[j]);
            temp = j;
        }
        c = temp;
        printf("\n");
    }
    
}