#include <iostream>
int main()
{
    int tab[3][3] = {{0,0,0},{0,1,0},{0,0,0}};

    for (int i = 0; i < 3; i++)
    {
        std::cout << "-------------" << std::endl;
        for (int y = 0; y < 3; y++)
        {
            std::cout << "| " << tab[i][y] << " " ;
        }
        std::cout << "|" << std::endl;
    }
    std::cout << "-------------" << std::endl;

    return 0;
}
