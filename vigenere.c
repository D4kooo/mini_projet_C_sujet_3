/******************************************************************************
*  ASR => 4R2.04                                                              *
*******************************************************************************
*                                                                             *
*  N° de Sujet : 3                                                            *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Intitulé :   Chiffrement de messages                                       *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom-prénom1 : AUTRET Pierrick                                              *
*                                                                             *
*  Nom-prénom2 : GINER Clement                                                *
*                                                                             *
*  Nom-prénom3 :                                                              *
*                                                                             *
*  Nom-prénom4 :                                                              *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom du fichier : vigenere.c                                                *
*                                                                             *
******************************************************************************/

#include "vigenere.h"
#include <string.h>

void chiffrer_vigenere(char *message, char *key) {
    int msgLen = strlen(message), keyLen = strlen(key), i, j;
    for (i = 0, j = 0; i < msgLen; ++i, ++j) {
        if (j == keyLen) j = 0;
        char c = message[i];
        if (c >= 'a' && c <= 'z') {
            c = (c - 'a' + (key[j] - 'a')) % 26 + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            c = (c - 'A' + (key[j] - 'A')) % 26 + 'A';
        }
        message[i] = c;
    }
}

void dechiffrer_vigenere(char *message, char *key) {
    int msgLen = strlen(message), keyLen = strlen(key), i, j;
    for (i = 0, j = 0; i < msgLen; ++i, ++j) {
        if (j == keyLen) j = 0;
        char c = message[i];
        if (c >= 'a' && c <= 'z') {
            c = (c - 'a' - (key[j] - 'a') + 26) % 26 + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            c = (c - 'A' - (key[j] - 'A') + 26) % 26 + 'A';
        }
        message[i] = c;
    }
}
