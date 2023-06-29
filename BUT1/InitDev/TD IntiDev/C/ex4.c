#include <stdio.h>


int main(){
    int N;
    do{
        printf("Saisir un entier positif\n");
        scanf("%d",&N);
    }
    while (N < 1);
    printf("Les nombres pair sont : \n");
    for (int i = 0; i <= N; i=i+2)
    {
        printf("%d ",i);
    }

 
}