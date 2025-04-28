//g++ -std=c++11 -pthread mon_programme.cpp -o mon_programme
#include <iostream>
#include <windows.h>

bool isPremierRec(int var,int diviseur){
    if(diviseur >= var) return true;
    else if(var % diviseur == 0) return false;
    return isPremierRec(var, diviseur+2);
}

bool isPremier(int var){
    if(var % 2 == 0) return false;
    return isPremierRec(var,3);
}

// Fonction à exécuter dans le thread
DWORD WINAPI maFonction(PVOID parametre) {


    std::cout << "Entrée les nombres du tableau, pour terminer taper 0" << std::endl;
    unsigned short tab[256];
    unsigned short i = 0;
    for (i; i < 256; i++)
    {
        int var;
        scanf("%i",&var);
        if(var <= 0 ||  var > 65535)
            break;
        tab[i] = var;
        
    }
    for (int y = 0; y < i; y++) {
        if(isPremier(tab[y]))
            std::cout << "C'est un nombre premier : " << tab[y] << std::endl;
        else
            std::cout << "Ce n'est pas un nombre premier : " << tab[y] << std::endl;
    }

    return 0;
}


int main() {
    
    HANDLE monThread1 = CreateThread(nullptr, 0, maFonction, NULL, 0, nullptr);

    int i = 0;
    DWORD exitCode;
    do{
        GetExitCodeThread(monThread1, &exitCode);
        i++;
        Sleep(500);
    }while(exitCode == STILL_ACTIVE);

    WaitForSingleObject(monThread1, INFINITE);
    
    CloseHandle(monThread1);
    std::cout << "Temps d'execution : " << i/2 << " seconde" << std::endl;
    std::cout << "Fin du programme" << std::endl;

    return 0;
}