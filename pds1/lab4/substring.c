#include <stdio.h>
#include <string.h>

int main(void)
{
    char s1[256];
    char s2[256];
    fgets(s1, 256, stdin);
    fgets(s2, 256, stdin);
    
    int count = 0;
    for (int i = 0, len1 = strlen(s1) - 1; i < len1; i++)
    {
        if (s1[i] == s2[0])
        {
            for (int j = 0, len2 = strlen(s2) - 1; j < len2; j++)
            {
                if (s1[j+i] == s2[j])
                {
                    count++;
                }
                else
                {
                    count = 0;
                    break;
                }
                if (count == len2)
                {
                    printf("É substring");
                    return 0;
                }
            }
        }
    }
    printf("Não é substring");
    return 1;
}