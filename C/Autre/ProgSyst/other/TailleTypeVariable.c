#include <stdio.h>
#include <stdbool.h>

int main()
{
    printf("\nTaille d'un bool %d",sizeof(bool));
    printf("\nTaille d'un char %d",sizeof(char));
    printf("\nTaille d'un sig char %d",sizeof(signed char));
    printf("\nTaille d'un unsig char %d",sizeof(unsigned char));
    printf("\nTaille d'un short %d",sizeof(short));
    printf("\nTaille d'un unsig short %d",sizeof(unsigned short));
    printf("\nTaille d'un int %d",sizeof(int));
    printf("\nTaille d'un unsig int %d",sizeof(unsigned int));
    printf("\nTaille d'un long %d",sizeof(long));
    printf("\nTaille d'un unsig long %d",sizeof(unsigned long));
    printf("\nTaille d'un float %d",sizeof(float));
    printf("\nTaille d'un double %d",sizeof(double));
    //printf("\nTaille d'un unsig double %d",sizeof(unsigned long double));
    return 0;
}
