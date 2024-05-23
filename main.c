#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cesar.h"
#include "vigenere.h"

void displayMenu() {
    printf("===== Menu =====\n");
    printf("1. Chiffrer avec Cesar\n");
    printf("2. Déchiffrer avec Cesar\n");
    printf("3. Chiffrer avec Vigenere\n");
    printf("4. Déchiffrer avec Vigenere\n");
    printf("5. Quitter\n");
    printf("================\n");
    printf("Choisissez une option (1-5): ");
}

int main() {
    char message[256];
    char key[256];
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar();

        switch (choice) {
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

            case 5:
                printf("Quitter...\n");
                exit(0);

            default:
                printf("Option invalide. Veuillez reessayer.\n");
        }
    }

    return 0;
}
