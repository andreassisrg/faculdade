#include <stdio.h>

int main()
{
    long int x;
    scanf("%li\n", &x);
    long int y;
    scanf("%li\n", &y);
    long int z;
    scanf("%li\n", &z);

    if (x % y == 0 && x % z == 0)
    {
        printf("O número é divisível\n");
    }
    else
    {
        printf("O número não é divisível\n");
    }

    return 0;
}