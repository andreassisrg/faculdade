#include <stdio.h>

int main()
{
    long int valor;
    scanf("%li\n", &valor);

    printf("100: %li\n", valor/100);
    valor = valor%100;

    printf("50: %li\n", valor/50);
    valor = valor%50;

    printf("20: %li\n", valor/20);
    valor = valor%20;

    printf("10: %li\n", valor/10);
    valor = valor%10;

    printf("5: %li\n", valor/5);
    valor = valor%5;

    printf("2: %li\n", valor/2);
    valor = valor%2;

    printf("1: %li\n", valor/1);

    return 0;
}