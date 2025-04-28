#include <stdio.h>
#include <string.h>

void modification(char* var){
    char* temp = " le monde";
    strncat(var,temp,strlen(temp));
    return;
}


int main()
{
    char str[18] = "Bonjour";   // augmenter la taille pour que strcat ajouter le nombre souhaiter
    modification(str);
    printf("%s\n",str);
    return 0;
}