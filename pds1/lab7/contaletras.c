#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fptr = fopen(argv[1], "r");
    if (fptr == NULL)
        exit(1);

    char buffer;
    int sum = 0;
    while ((buffer = fgetc(fptr)) != EOF)
    {
        if (buffer == 'a')
        {
            sum++;
        }
    }   
    
    fclose(fptr);
    printf("%d\n", sum);
}