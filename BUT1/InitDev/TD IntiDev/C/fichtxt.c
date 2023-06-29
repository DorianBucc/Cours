#include<stdio.h>
int main()
{
FILE * f;
char nom[20];
int i, n;
float snote, lenote, lanote;
f = fopen("notes.txt", "w"); // si le fichier n’existe pas, il est créé
printf("nombre d’elèves :");
scanf("%d", &n);
for(i=0; i<n; i++)
{
    printf("saisir un nom et une note :\n");
    scanf("%s %f %f %f", nom, &snote, &lenote, &lanote);
    fprintf(f,"%s %.1f %.1f %.1f\n", nom, snote, lenote, lanote);
}
fclose(f);
}