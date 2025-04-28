#include <stdio.h>
//suite avec x = 1 un1 = 0     un2 = 2     un3 = 4   un5 = 8 ...   unx = y avec raison r = 2

int suiteun(int x)  //method un1 à unx (calc un1 apres calc un2 apres calc un3 ... à calc un)
{
  int un = 0;
  for(int i = 1; i < x; i++)
  {
    un = un + (2 * i);
    
  }
  
  
  
}

int main(){
  printf("Veuillez saisir un entier : \n");
  scanf("%d", &x);
	printf("%d",suiteun(x));
}

