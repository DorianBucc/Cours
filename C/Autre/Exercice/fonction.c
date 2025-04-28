#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ecrire(char fich[25])
{
    char ch;
    FILE *fi;

    fi = fopen(fich, "w");

    do
    {
        ch = getchar();
        fputc(ch, fi);
    }while(ch != '0');

    fclose(fi);

}

void lire(char fich[25])
{
    char ch;
    FILE *f;

    printf("\nLe fichier %s contient :\n",fich);
    f = fopen(fich, "r");
    do
    {
        ch = fgetc(f);
        printf("%c",ch);
    }while (ch!='0');

    fclose(f);
}

void ecrires(char fich[25])
{
    char ch[25];
    FILE *fi;

    fi = fopen(fich, "w");
    do
    {
        scanf("%s",ch);
        fputs(ch, fi);
    }while(ch[0] != '0');

    fclose(fi);
}

void lires(char fich[25])
{
    char ch[20];
    FILE *f;
    int in;

    printf("\nLe fichier %s contient :\n",fich);
    f = fopen(fich, "r");
    scanf("%i",&in);
    fgets(ch,in+1,f);
    printf("--> %s\n",ch);

    fclose(f);
}

void LireString(char fich[25])
{
    char ch[20];
    FILE *f;
    int in;

    f = fopen(fich, "w");
    scanf("%s",ch);
    fprintf(f,"Nom : %s",ch);


    fclose(f);
}

void EcrireString(char fich[25])
{
    char ch[20],ch1[20];
    FILE *f;
    int in;

    f = fopen(fich, "r+w");

    scanf("%s",ch1);
    fprintf(f,"Nom : %s",ch1);

    fscanf(f,"%10s",ch);
    printf("%s",ch);


    fclose(f);
}