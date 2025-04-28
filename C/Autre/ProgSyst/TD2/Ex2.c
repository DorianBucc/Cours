#include <stdio.h>
void main(){
    int c = 10;
    int* p = &c;
    *p = 11;
    printf("%d\n", c);
    printf("%d", *p);
    return;
}