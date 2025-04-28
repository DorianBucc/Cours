#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void main()
{
    int res,nbp = 0,nbf = 0;
    int nb;
    float f = 1;
    srand((unsigned int) time( NULL ));

    printf("Combien de partis voulez vous jouer\n");
    scanf("%d",&nb);
    while (getchar() != '\n'){}
    printf("\n");
    
    for(int i = 0 ;i < nb; i++)
    {
        res = rand()%2;
        (res == 0) ? nbp++ : nbf++ ;

    }
    printf("Sur %d partis de jeu il y a :\n\n",nb);
    printf("Le pourcentage de face qui est de %.2f %%\n",f*nbf/nb*100);
    printf("Le pourcentage de pile qui est de %.2f %%\n\n",f*nbp/nb*100);
}