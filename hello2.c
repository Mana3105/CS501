#include <stdio.h>
#include <cs50.h>


int main(void); { 

    int n;
    do
    {
        n = get_int("Ingrese un número entre 1 y 8: ");
    }
    while (n < 1 || n > 8);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }

        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }

        printf("\n");
    }

    return 0;
}
