#include <stdio.h>

int inversion(int* nb1, int* nb2){
    int temp = *nb1;
    *nb1 = *nb2;
    *nb2 = temp;

    printf("Nouvelles valeurs : a = %d, b = %d", *nb1, *nb2);
    return 0;
}

void main(){
    int a = 10, b = 11;
    printf("Valeurs initiales : a = %d, b = %d\n", a, b);

    inversion(&a, &b);
}