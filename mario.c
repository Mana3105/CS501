#include <stdio.h>

int main(void) {
    int height;

    do {
        printf("Introduce una altura entre 1 y 8: ");
        scanf("%d", &height);
    } while (height < 1 || height > 8);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j <= i; j++) {
            printf("#");
        }
        printf("\n");
    }

    return 0;
}