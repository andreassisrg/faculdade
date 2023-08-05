#include <stdio.h>

int main(void)
{
    int count = 228;

    do
    {
        if (count >= 300 && count <= 400)
        {
            count += 3;
        }
        else
        {
            count += 5;
        }
        printf("%i\n", count);
    }
    while (count < 457);

    return 0;
}