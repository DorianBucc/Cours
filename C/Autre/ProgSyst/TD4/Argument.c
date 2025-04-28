#include <stdio.h>
#include <libgen.h>

int main(int argc, char * argv[])
{
    printf("chemin : %s\n",argv[0]);
    if(argc > 1) printf("nom du programme : %s\n", basename(argv[0]));
    if(argc > 1) printf("nom du dir : %s\n", dirname(argv[0]));
    for (int i = 1; i < argc; i++)
    {
        printf("Argv[%i] = %s\n",i,argv[i]);
    }
    return 0;
}
