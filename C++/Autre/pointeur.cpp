#include <iostream> // librairie basic en C++

bool function1(int *l, int *c){ // function avec retour booléen et modification des variables à leurs adresses
    std::cin >> *l >> *c;   // affectation et entrée des valeur
    return true;    // retour positif
}

int main() {
    int line;
    int column;
    if(function1(&line,&column)) // si la fonction donne un retour positif
        std::cout << line << " et " << column << std::endl; // affichage des valeur
    system("pause");    // mise en pause avant fermeture
    return 0;
}