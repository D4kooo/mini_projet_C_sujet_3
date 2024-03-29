#include "cesar.h"
#include <stdio.h>
#include <ctype.h>

/* Chiffrement César */
void chiffrement_cesar(char message[], int cle) {
  int i;
  for(i = 0; message[i] != '\0'; ++i) {
    if(isalpha(message[i])) {
      if(islower(message[i])) {
        message[i] = (((message[i] - 97) + cle) % 26) + 97;
      } else {
        message[i] = (((message[i] - 65) + cle) % 26) + 65;
      }
    }
  }
  printf("Le message chiffré en utilisant la clé %d : %s\n", cle, message);
}

/* Déchiffrement César */
void dechiffrement_cesar(char message[], int cle) {
  chiffrement_cesar(message, 26 - cle);
}
