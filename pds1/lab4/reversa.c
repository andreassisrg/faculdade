#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[256];
    scanf("%[^\n]", s); // Usado para coletar string com espaço
    
    for (int i = strlen(s) - 1 ; i >= 0; i--)
    {
        printf("%c", s[i]);
    }
}