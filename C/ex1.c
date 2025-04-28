#include <stdio.h>
int main()
{
    int tab[3][3] = {{0,0,0},{0,1,0},{0,0,0}};
    int i = 0;
    int y = 0;
    for (i; i < 3; i++)
    {
        puts("-------------");
        y = 0;
        for (y; y < 3; y++)
        {
            printf("| %i ",tab[i][y]);
        }
        puts("|");
    }
    puts("-------------");
    return 0;
}
