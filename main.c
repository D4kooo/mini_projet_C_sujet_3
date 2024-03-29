#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Fonctions de chiffrement/déchiffrement */

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

/* Chiffrement Vigenère */
void chiffrement_vigenere(char message[], char cle2[]) {
  int i, j;
  for(i = 0, j = 0; message[i] != '\0'; ++i, ++j) {
    if(j == strlen(cle2)) {
      j = 0;
    }
    if(isalpha(message[i])) {
      if(islower(message[i])) {
        message[i] = (((message[i] - 97) + (cle2[j] - 97)) % 26) + 97;
      } else {
        message[i] = (((message[i] - 65) + (cle2[j] - 65)) % 26) + 65;
      }
    }
  }
  printf("Le message chiffré en utilisant la clé %s : %s\n", cle2, message);
}

/* Déchiffrement Vigenère */
void dechiffrement_vigenere(char message[], char cle2[]) {
  int i, j;
  for(i = 0, j = 0; message[i] != '\0'; ++i, ++j) {
    if(j == strlen(cle2)) {
      j = 0;
    }
    if(isalpha(message[i])) {
      if(islower(message[i])) {
        message[i] = (((message[i] - 97) - (cle2[j] - 97) + 26) % 26) + 97;
      } else {
        message[i] = (((message[i] - 65) - (cle2[j] - 65) + 26) % 26) + 65;
      }
    }
  }
  printf("Le message déchiffré en utilisant la clé %s : %s\n", cle2, message);
}

/* Fonctions de menu */
void menu_cesar() {
    char message[100];
    int cle;
    char cle2[100];
    int choix = 0;
    int ChoixTraitement;
    int ChoixClef;
    
  /* Ecriture du message a traiter */
  printf("Veuillez entrer le message à chiffrer/déchiffrer : ");
  fgets(message, sizeof(message), stdin);
  
  /* Choix du format de la clé, plusieures méthodes de chiffrement peuvent avoir des clés similaires */
  printf("Choississez le format de votre clé\n");
  printf("(1) : Clé avec chiffres\n");
  printf("(2) : Clé avec lettres\n ");
  scanf("%d", &ChoixClef);
  switch(ChoixClef) {
  case 1:
  /* Ici, on va entrer une clé avec des CHIFFRES, ce qui sous entend qu'elle sera compatible avec toutes les méthodes de chiffrement utilisant des CHIFFRES */
  printf("Veuillez entrer la clé de chiffrement : ");
  scanf("%d", &cle);
  break;
  case 2:
  /* Ici, on va entrer une clé avec des CHARACTERES, ce qui sous entend qu'elle sera compatible avec toutes les méthodes de chiffrement utilisant des CHARACTERES */
  printf("Veuillez entrer la clé de chiffrement : ");
  scanf("%s", &cle2);
  break;
  }
  
  
  /* Choix du type de chiffrement */
  printf("Que voulez-vous faire ?\n");
  if (ChoixClef == 1){
  printf("1. Cesar\n");
  printf("2. Nous avons detecté que votre clé ne correspondait pas a ce type de format\n");
  printf("3. Quitter\n");
  printf("Votre choix : ");
  }
  if (ChoixClef == 2){
  printf("1. Nous avons detecté que votre clé ne correspondait pas a ce type de format\n");
  printf("2. Vigenère\n");
  printf("3. Quitter\n");
  printf("Votre choix : ");
  }
  
  scanf("%d", &choix);
  switch(choix) {
    case 1:
      printf("Voulez vous dechiffrer ou chiffrer ?");
      ChoixTraitement = 0;
      scanf("%d", &ChoixTraitement);
      if (ChoixTraitement==1) {
      chiffrement_cesar(message, cle);
      }
      else
      {
      dechiffrement_cesar(message, cle);
      }
    break;
    case 2:
    printf("voulez vous chiffrer ou déchiffrer ?");
    ChoixTraitement = 0;
    scanf("%d", &ChoixTraitement);
    if (ChoixTraitement==1) {
        chiffrement_vigenere(message, cle2);
    }
    else
    {
        dechiffrement_vigenere(message, cle2);
    }
      break;
      case 3:
      printf("Au revoir !\n");
      break;
    }
}

void main() {
    menu_cesar();
}