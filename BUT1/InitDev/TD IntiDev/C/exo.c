#include <stdio.h>


int main(){
    	int N;
	int som = 0;
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
    	for (int i = 1; i <= N; i = i + 2)
	{
		som = som + i;
	}
	printf(" %d\n",som);
	som = 0;
	int c = 1;
	for (int i = 1;i <= N;i++)
	{
		c = c + 2;
	  	som = som + c;
	}
	printf("%d\n",som);
}
