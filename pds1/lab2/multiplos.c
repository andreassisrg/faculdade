#include <stdio.h>

int main (void)
{
    int X;
    scanf("%i", &X);

    printf("Múltiplos de 2: %i\n", X/2);
    printf("Múltiplos de 3: %i\n", X/3);
    printf("Múltiplos de 5: %i\n", X/5);
    printf("Múltiplos de todos: %i\n", X/2/3/5);

}