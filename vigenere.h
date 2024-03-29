#ifndef VIGENERE_H
#define VIGENERE_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void chiffrement_vigenere(char message[], char cle[]);
void dechiffrement_vigenere(char message[], char cle[]);

#endif // VIGENERE_H