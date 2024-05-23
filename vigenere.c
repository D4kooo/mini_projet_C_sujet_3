#include "vigenere.h"
#include <string.h>

void vigenere_encrypt(char *message, char *key) {
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

void vigenere_decrypt(char *message, char *key) {
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
