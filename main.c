/******************************************************************************
*  ASR => 4R2.04                                                              *
*******************************************************************************
*                                                                             *
*  N° de Sujet :             Sujet 3                                          *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Intitulé :             Chiffrement de Message                              *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom-prénom1 :          Giner Clément                                       *
*                                                                             *
*  Nom-prénom2 :          Autret Pierrick                                     *
*                                                                             *
*  Nom-prénom3 :                                                              *
*                                                                             *
*  Nom-prénom4 :                                                              *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom du fichier :       main.c                                              *
*                                                                             *
******************************************************************************/

#include "cesar.h"
#include "vigenere.h"
#include <stdio.h>
#include <string.h>

int main() {
    int choix, cleCesar;
    char message[1024], cleVigenere[256];
    
    printf("Choisissez l'opération :\n");
    printf("1. Chiffrement\n");
    printf("2. Déchiffrement\n");
    scanf("%d", &choix);
    getchar(); // Pour consommer le caractère de nouvelle ligne après le nombre

    printf("Entrez le message : ");
    gets(message); // Attention à la sécurité de gets dans un vrai programme

    if (choix == 1 || choix == 2) {
        printf("Choisissez le type de chiffrement :\n");
        printf("1. César\n");
        printf("2. Vigenère\n");
        scanf("%d", &choix);
        getchar(); // Pour consommer le caractère de nouvelle ligne

        if (choix == 1) { // Chiffrement César
            printf("Entrez la clé (nombre) : ");
            scanf("%d", &cleCesar);
            getchar(); // Pour consommer le caractère de nouvelle ligne
            if (choix == 1) chiffrement_cesar(message, cleCesar);
            else dechiffrement_cesar(message, cleCesar);
        } else if (choix == 2) { // Chiffrement Vigenère
            printf("Entrez la clé (texte) : ");
            gets(cleVigenere); // Attention à la sécurité de gets dans un vrai programme
            if (choix == 1) chiffrement_vigenere(message, cleVigenere);
            else dechiffrement_vigenere(message, cleVigenere);
        }
    } else {
        printf("Choix non valide.\n");
        return 1; // Fin prématurée du programme
    }

    printf("Résultat : %s\n", message);
    return 0;
}
