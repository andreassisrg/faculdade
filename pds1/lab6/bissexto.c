#include <stdio.h>

int eh_bissexto(int ano);

int main(void)
{
    int buffer;
    while(scanf("%d", &buffer) != EOF)
    {
        printf("%d\n", eh_bissexto(buffer));
    }
}

int eh_bissexto(int ano)
{
    if (ano % 4 != 0)
        return 0;
    if (ano % 100 == 0 && ano % 400 != 0)
        return 0;
    return 1;
}