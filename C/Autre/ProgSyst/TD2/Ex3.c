#include <stdio.h>
#include <stdlib.h>

void main(){
    int n;
    puts("Taille du tableau : ");
    scanf("%d", &n);
    int* tab = NULL;
    tab = malloc(sizeof(int) * n); //permet d'allouer de la mémoire

    if(tab == NULL){
        puts("Erreur lors de l'allocation de la mémoire");
    }
    else {
        int val, i = 0;
        do
        {
            puts("Valeurs a ajouter dans le tableau : ");
            scanf("%d", &val);
            tab[i] = val;
            i++;
        } while (i < n);

        puts("Valeurs se trouvant dans le tableau :");
        for (int i = 0; i < n; i++){
            printf("%d ", tab[i]);
        }

        free(tab); //permet de libérer la mémoire
    }
}