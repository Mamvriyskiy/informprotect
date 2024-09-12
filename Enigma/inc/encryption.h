#ifndef _ENCRYPTION_H_
#define _ENCRYPTION_H_

#include "enigma.h"

int search_symbol(char slice[COLUMNS], char symbol);
char encryption_enigma(enigma_t *enigma, char symbol);

#endif
