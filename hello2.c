#include <cs50.h>
#include <stdio.h>

int main(void)

{
    int numbers[] = {20, 50, 10, 5};

    int n = get_int("Number: ");
    for (int i = 0; i < 4: i++)     
    {
        if(numbers[i] == n)
        {
            printf("Found\n");
            return 0;
        }
    } 
    printf("Not Found\n")   
    return 1;
}