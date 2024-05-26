
# Mini Projet en C, sujet 3 : Chiffrement de message

https://github.com/D4kooo/mini_projet_C_sujet_3.git

## Description

Ce projet est un mini projet en C dans le cadre de l'apprentissage, il permet de chiffrer ou de déchiffrer un message en utilisant soit l'algorithme de César soit celui de Vigenere.


## Installation

Pour installer ce projet, suivez ces étapes :

1. Ouvrez un terminal (invite de commandes sur Windows).

2. Clonez le dépôt sur votre machine locale en utilisant la commande git :
```
git clone https://github.com/D4kooo/mini_projet_C_sujet_3.git
```

3. Naviguez jusqu'au répertoire du projet avec la commande :
```
cd mini_projet_C_sujet_3
```

4. Compilez les fichiers C à l'aide du fichier de la commande dans le makefile
```
make all
```

## Le makefile

Le makefile contient 5 commandes:

1.  `all` permet d'entièrement compiler le projet

2.  `main.o` permet de generer le fichier objet de main.c

3.  `cesar.o` permet de generer le fichier objet de cesar.c

4.  `vigenere.o` permet de generer le fichier objet de vigenere.c

5.  `clean` permet de supprimer tout les fichiers pouvant être génerer par le makefile

## Utilisation

Pour utiliser ce projet, après installation il faut exécuter le fichier exécutable `./chiffrement.exe`

## Crédits

Autret Pierrick & Giner Clément


## Licence

[MIT](https://choosealicense.com/licenses/mit/)
