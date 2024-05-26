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
*  Nom du fichier : main.c                                                    *
*                                                                             *
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cesar.h"
#include "vigenere.h"

// Fonction pour afficher le menu
void displayMenu() {
    printf("=========== Menu ===========\n");
    printf("1. Chiffrer avec Cesar\n");
    printf("2. Déchiffrer avec Cesar\n");
    printf("3. Chiffrer avec Vigenere\n");
    printf("4. Déchiffrer avec Vigenere\n");
    printf("5. Quitter\n");
    printf("============================\n");
    printf("Choisissez une option (1-5): ");
}

// Fonction main
int main() {
    char message[256];
    char key[256];
    int choice;

    // Boucle principale
    while (1) {
        //Affiche le menu et récupère le choix de l'utilisateur
        displayMenu();
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            //si l'utilisateur veux chiffrer avec césar
            case 1:
                printf("Entrez le message à chiffrer: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = '\0';
                int shift;
                printf("Entrez la cle pour le chiffrement de Cesar: ");
                scanf("%d", &shift);
                getchar();
                chiffrer_cesar(message, shift);
                printf("Message chiffre: %s\n", message);
                break;

            //si l'utilisateur veux déchiffrer avec césar
            case 2:
                printf("Entrez le message a déchiffrer: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = '\0';
                printf("Entrez la cle pour le dechiffrement de Cesar: ");
                scanf("%d", &shift);
                getchar();
                dechiffrer_cesar(message, shift);
                printf("Message déchiffre: %s\n", message);
                break;
            
            //si l'utilisateur veux chiffrer avec Vigenere
            case 3:
                printf("Entrez le message a chiffrer: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = '\0';
                printf("Entrez la cle pour le chiffrement de Vigenere: ");
                fgets(key, sizeof(key), stdin);
                key[strcspn(key, "\n")] = '\0';
                chiffrer_vigenere(message, key);
                printf("Message chiffre: %s\n", message);
                break;

            //si l'utilisateur veux déchiffre avec Vigenere
            case 4:
                printf("Entrez le message a dechiffrer: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = '\0';
                printf("Entrez la cle pour le déchiffrement de Vigenere: ");
                fgets(key, sizeof(key), stdin);
                key[strcspn(key, "\n")] = '\0';
                dechiffrer_vigenere(message, key);
                printf("Message déchiffre: %s\n\n", message);
                break;
            //si l'utilisateur veux quitter
            case 5:
                printf("Quitter...\n");
                exit(0);
            
            // si l'entrer n'est pas bonne
            default:
                printf("Option invalide. Veuillez reessayer.\n");
        }
    }

    return 0;
}
