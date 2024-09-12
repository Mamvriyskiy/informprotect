#include <stdio.h>
#include "encryption.h"

int search_symbol(char slice[COLUMNS], char symbol) {
    for (int i = 0; i < COLUMNS; i++) {
        if (slice[i] == symbol) {
            return i;
        }
    }

    return -1;
}

void increnebt_index() {

}

char encryption_enigma(enigma_t *enigma, char symbol) {
    int indx;
    for (int i = 0; i < ROWS_ROTORS; i += 2) {
        indx = search_symbol(enigma->rotors[i], symbol);
        symbol = enigma->rotors[i + 1][indx];
    }

    indx = search_symbol(enigma->reflect[1], symbol);
    symbol = enigma->reflect[0][indx];

    for (int i = ROWS_ROTORS - 1; i > 0; i -= 2) {
        indx = search_symbol(enigma->rotors[i], symbol);
        symbol = enigma->rotors[i - 1][indx];
    }

    enigma->indexA++;
    if (enigma->indexA > COLUMNS) {
        enigma->indexA = 0;
        enigma->indexB++;
        if (enigma->indexB > COLUMNS) {
            enigma->indexB = 0;
            enigma->indexC++;
            if (enigma->indexC > COLUMNS) {
                enigma->indexC = 0;
            }
        }
    }

    return symbol;
}
