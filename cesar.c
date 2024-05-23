#include "cesar.h"

void cesar_encrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; ++i) {
        char c = message[i];
        if (c >= 'a' && c <= 'z') {
            c = (c - 'a' + shift) % 26 + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            c = (c - 'A' + shift) % 26 + 'A';
        }
        message[i] = c;
    }
}

void cesar_decrypt(char *message, int shift) {
    cesar_encrypt(message, 26 - shift);
}
