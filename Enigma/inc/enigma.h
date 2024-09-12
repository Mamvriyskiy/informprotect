#ifndef _ENIGMA_H_
#define _ENIGMA_H_

#define ROWS_ROTORS     6
#define ROWS_REFLECT    2
#define COLUMNS         52

typedef struct
{
    char rotors[ROWS_ROTORS][COLUMNS];
    char reflect[ROWS_REFLECT][COLUMNS];
    int indexA;
    int indexB;
    int indexC;
} enigma_t;



void init_enigma_rotors(char matrix[ROWS_ROTORS][COLUMNS]);
void init_enigma_reflect(char matrix[ROWS_REFLECT][COLUMNS]);
int init_enigma(enigma_t *enigma, int indexA, int indexB, int indexC);

#endif
