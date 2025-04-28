#include <iostream> // librairie basic en C++
int main() {
    int ph;
    std::cout << "Ecriver " << std::endl ;  // indique un message
    std::cin >> ph >> ph;                   // scan en C++
    std::cout << "Message : " << ph << std::endl << "Fin" << std::endl; // ecrit 
    system("pause");    // mise en pause avant fermeture
    
      int num;

    std::cout << "Hello world" << std::endl;
    std::cin >> num;
    std::cout << "Valeur " << num << std::endl;

    printf("Hello world\n");
    scanf("%i",&num);
    printf("Valeur %i \n",num);
    
    return 0;
}