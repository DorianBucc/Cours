#include<stdio.h>

typedef struct e{
    int x;
    int y;
}E;

typedef struct a{
    E t[20];
    char nom [20];
}A;




int main()
{
A promo[200];
FILE * f;
char nom[10];
float note;
f = fopen("notes.txt", "r");
while (fscanf(f,"%s %f", nom, &note) != EOF)
    printf("%s %.1f\n", nom, note);
}
