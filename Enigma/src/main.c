#include <stdio.h>
#include <stdlib.h>
#include "enigma.h"
#include "encryption.h"

int main(void) {
    // if (argc != 4 && argc != 3) {
    //     printf("Неверное количество аргументов(a, b, c, <file>)");
    // }

    enigma_t *enigma = malloc(sizeof(enigma_t));
    int err = init_enigma(enigma, 2, 2, 3);

    for (int i = 0; i < ROWS_ROTORS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            printf("%c ", enigma->rotors[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < ROWS_REFLECT; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            printf("%c ", enigma->reflect[i][j]);
        }
        printf("\n");
    }

    char result = encryption_enigma(enigma, 'a');
    printf("Result: %c\n", result);

    result = encryption_enigma(enigma, result);
    printf("Result: %c\n", result);

    return err;
}
