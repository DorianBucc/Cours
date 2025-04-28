#include <iostream> // librairie basic en C++
#include <cstdio>   // librairie C dans C++ (stdio = en C++ cstdio)

int main() {
    float f = 2.2;
    int i = f;
    std::cout << f << std::endl;    // ecrit
    std::cout << i << std::endl;    // ecrit
    std::string a = "1" ;
    puts("");   // print simple string
    int b = std::stoi(a);
    std::cout << a+a << std::endl;  // ecrit
    std::cout << b+b << std::endl;  // ecrit
    system("pause");    // mise en pause avant fermeture
    return 0;
}