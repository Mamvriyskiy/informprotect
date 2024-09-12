#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "enigma.h"

void shuffle(char *alphabet, int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = alphabet[i];
        alphabet[i] = alphabet[j];
        alphabet[j] = temp;
    }
}

void init_enigma_rotors(char matrix[ROWS_ROTORS][COLUMNS]) {
    char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < ROWS_ROTORS; i++) {
        shuffle(alphabet, COLUMNS);
        for (int j = 0; j < COLUMNS; j++) {
            matrix[i][j] = alphabet[j];
        }
    }
}

void init_enigma_reflect(char matrix[ROWS_REFLECT][COLUMNS]) {
    char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    shuffle(alphabet, COLUMNS);
    for (int j = 0; j < COLUMNS / 2; j++) {
        matrix[0][j] = alphabet[j];
        matrix[1][j] = alphabet[COLUMNS / 2 + j];
        matrix[0][COLUMNS / 2 + j] = alphabet[COLUMNS / 2 + j];
        matrix[1][COLUMNS / 2 + j] = alphabet[j];
    }
}

void right_rotate(char arr[COLUMNS], int k) {
    k = k % COLUMNS; 
    int temp[k];

    for (int i = 0; i < k; i++) {
        temp[i] = arr[COLUMNS - k + i];
    }

    for (int i = COLUMNS - 1; i >= k; i--) {
        arr[i] = arr[i - k];
    }

    for (int i = 0; i < k; i++) {
        arr[i] = temp[i];
    }
}

int init_enigma(enigma_t *enigma, int indexA, int indexB, int indexC) {
    init_enigma_rotors(enigma->rotors);     //инициализация роторов
    init_enigma_reflect(enigma->reflect);    //инициализация рефлектора

    enigma->indexA = indexA;
    enigma->indexB = indexB; 
    enigma->indexC = indexC;

    right_rotate(enigma->rotors[0], indexA);
    right_rotate(enigma->rotors[2], indexB);
    right_rotate(enigma->rotors[5], indexC);

    return 0;
}
