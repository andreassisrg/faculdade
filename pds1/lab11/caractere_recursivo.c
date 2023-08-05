#include <stdio.h>
#include <string.h>

int n_chars(char c, char *str);

int main(void)
{
    // Recebe string e caractere para ser contabilizado
    char buffer[256];
    fgets(buffer, 256, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    char target;
    scanf("%c", &target);
    
    // Chama função e imprime resultado
    int res = n_chars(target, buffer);
    printf("%d\n", res);
}

int n_chars(char c, char *str)
{
    if (*str != '\0')
    {
        if (*str == c)
        {
            return 1 + n_chars(c, str + 1);
        }
        else
        {
            return n_chars(c, str + 1);
        }
    }
    else
    {
        return 0;
    }
}