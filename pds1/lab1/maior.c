#include <stdio.h>

int main()
{
    // Prompting usuário por 3 valores
    long int valor_1;
    scanf("%li\n", &valor_1);
    long int valor_2;
    scanf("%li\n", &valor_2);
    long int valor_3;
    scanf("%li\n", &valor_3);

    // Printando o maior
    if (valor_1 >= valor_2 && valor_1 >= valor_3)
    {
        printf("%li\n", valor_1);
    }
    else if (valor_1 >= valor_2 && valor_1 <= valor_3)
    {
        printf("%li\n", valor_3);
    }
    else if (valor_1 <= valor_2 && valor_2 >= valor_3)
    {
        printf("%li\n", valor_2);
    }
    else if (valor_1 <= valor_2 && valor_2 <= valor_3)
    {
        printf("%li\n", valor_3);
    }

    return 0;
}