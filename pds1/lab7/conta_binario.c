#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *file_name;
    scanf("%s", file_name);
    
    FILE *fptr = fopen(file_name, "rb");
    if (fptr == NULL)
        exit(1);
    
    int sum = 0;
    char buffer;
    while((buffer = fgetc(fptr)) != EOF)
    {
        if (buffer == 'a')
            sum++;
    }
    printf("%d\n", sum);
    return 0;
}