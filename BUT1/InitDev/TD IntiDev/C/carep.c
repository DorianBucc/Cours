#include <stdio.h>
#define TMAX 30


struct car
{
    int l;
    int c;
    int val;
}car;


taille_tableau(int *ta)
{
    do
    {
        printf("Veuillez saisir les dimensions du tableau\n");
        scanf("%d",&*ta);

    } while ((*ta**ta)%2);   
}

initialisation(int (*tab)[TMAX])
{
    for (int j = 0; j < TMAX; j++)
    {
        for (int i = 0; i < TMAX; i++)
        {
            tab[j][i] = 0;
        }
    }
}

prochaine_case(int (*tab)[TMAX],struct car *p,int *l,int *c,int ta)
{
    int S = 0;
    if (p->l == 1 && p->c == 1)
    {
        if (tab[ta][ta] == 0)
        {
            *l = ta;
            *c = ta;
        }
        else S = 1;  
    }
    else if(p->l == 1)
    {
        if(tab[ta][p->c-2] == 0)
        {
            *l = ta;
            *c = p->c-2;
        }
        else S = 1;  
    }
    else if (p->c == 1)
    {
        if(tab[ta][p->c-2] == 0)
        {
            *l = p->l-2;
            *c = ta;
        }
        else S = 1;  
    }
    else
    {
        if (tab[p->l-2][p->c-2])
        {
            *l = p->l-2;
            *c = p->c-2;
        }
        else S = 1;        
    }

    if (S == 1)
    {
        if (p->l == ta)
        {
            *l = 0;
        }
        
    }
    


    
}



int main()
{
    int ta;
    int tab[TMAX][TMAX];
    
    taille_tableau(&ta);
    car.c = (co/2)+1;
    car.l = 1;
    car.val = 1;


    int l,c,finish = 0;
    tab[car.l-1][car.c-1] = car.val;
    car.val++;
    do
    {
        
        prochaine_case( tab, &car, l, c, ta);
        tab[l-1][c-1] = car.val;
        car.val++;
    } while (finish == 0);

}