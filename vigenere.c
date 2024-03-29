#include "vigenere.h"
#include <stdio.h> 
#include <string.h>
#include <ctype.h>

/* Chiffrement Vigenère */
void chiffrement_vigenere(char message[], char cle[]) {
  int i, j;
  for(i = 0, j = 0; message[i] != '\0'; ++i, ++j) {
    if(j == strlen(cle)) {
      j = 0;
    }
    if(isalpha(message[i])) {
      if(islower(message[i])) {
        message[i] = (((message[i] - 97) + (cle[j] - 97)) % 26) + 97;
      } else {
        message[i] = (((message[i] - 65) + (cle[j] - 65)) % 26) + 65;
      }
    }
  }
  printf("Le message chiffré en utilisant la clé %s : %s\n", cle, message);
}

/* Déchiffrement Vigenère */
void dechiffrement_vigenere(char message[], char cle[]) {
  int i, j;
  for(i = 0, j = 0; message[i] != '\0'; ++i, ++j) {
    if(j == strlen(cle)) {
      j = 0;
    }
    if(isalpha(message[i])) {
      if(islower(message[i])) {
        message[i] = (((message[i] - 97) - (cle[j] - 97) + 26) % 26) + 97;
      } else {
        message[i] = (((message[i] - 65) - (cle[j] - 65) + 26) % 26) + 65;
      }
    }
  }
  printf("Le message déchiffré en utilisant la clé %s : %s\n", cle, message);
}