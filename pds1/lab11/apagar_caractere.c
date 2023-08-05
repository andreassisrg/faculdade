#include <stdio.h>
#include <string.h>

void *rm_char(char c, char *str);

int main(void)
{
    // Recebe string e caractere para ser removido
    char buffer[256];
    fgets(buffer, 256, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    char target;
    scanf("%c", &target);
    
    // Chama função e imprime resultado
    rm_char(target, buffer);
}

void *rm_char(char c, char *str)
{
    if (*str != '\0')
    {
        if (*str != c)
        {
            printf("%c", *str);
            rm_char(c, str + 1);
        }
        else
        {
            rm_char(c, str + 1);
        }
    }
}