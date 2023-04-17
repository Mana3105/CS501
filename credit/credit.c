
  
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Función para verificar si una cadena representa un número de tarjeta válido
int is_valid_card_number(const char *card_number)
{
    int sum = 0;
    int length = strlen(card_number);
    int parity = length % 2;

    for (int i = 0; i < length; i++)
    {
        int digit = card_number[i] - '0';

        if (i % 2 == parity)
        {
            digit *= 2;
            if (digit > 9)
            {
                digit -= 9;
            }
        }

        sum += digit;
    }

    return sum % 10 == 0;
}

// Función para determinar el tipo de tarjeta (Visa, Mastercard o American Express)
const char *get_card_type(const char *card_number)
{
    int length = strlen(card_number);

    if (length == 15 && strncmp(card_number, "34", 2) == 0 || strncmp(card_number, "37", 2) == 0)
    {
        return "AMEX";
    }
    else if (length == 16 && strncmp(card_number, "5", 1) == 0 && card_number[1] >= '1' && card_number[1] <= '5')
    {
        return "Mastercard";
    }
    else if ((length == 13 || length == 16) && strncmp(card_number, "4", 1) == 0)
    {
        return "Visa";
    }
    else
    {
        return "Desconocido";
    }
}

// Función para eliminar los guiones ("-") de una cadena
void remove_dashes(char *str)
{
    char *p = strchr(str, '-');
    while (p != NULL)
    {
        memmove(p, p + 1, strlen(p));
        p = strchr(p, '-');
    }
}

int main()
{
    char card_number[20];

    do
    {
        printf("Ingrese el número de su tarjeta de crédito: ");
        scanf("%s", card_number);

        // Eliminar los guiones ("-") del número de tarjeta (si los hay)
        remove_dashes(card_number);

        // Convertir todos los caracteres a números
        for (int i = 0; i < strlen(card_number); i++)
        {
            if (!isdigit(card_number[i]))
            {
                printf("El número de tarjeta ingresado no es válido.\n");
                goto end_program;
            }
        }

        // Verificar si el número de tarjeta es válido
        if (!is_valid_card_number(card_number))
        {
            printf("INVALID \n");
            goto end_program;
        }

        // Determinar el tipo de tarjeta
        const char *card_type = get_card_type(card_number);
        printf("%s.\n", card_type);

end_program:
        printf("=======================================\n");
    }
    while (1);

    return 0;
}