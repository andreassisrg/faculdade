#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[256];
    char c1;
    char c2;
    fgets(s, 256, stdin);
    scanf(" %c", &c1);
    scanf(" %c", &c2);
    
    for (int i = 0, len = strlen(s) - 1; i < len; i++)
    {
        if (s[i] == c1)
        {
            s[i] = c2;
            break;
        }
    }
    
    printf("%s", s);
}