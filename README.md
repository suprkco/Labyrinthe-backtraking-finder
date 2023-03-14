# Labyrinthe-backtraking-finder

Le code est un programme en langage C qui permet de lire un fichier texte contenant un labyrinthe, puis de trouver & de visualiser un chemin pour traverser le labyrinthe en utilisant du backtracking.

## Concept de backtracking

Le concept de backtracking est un algorithme qui permet de trouver une solution à un problème en utilisant une méthode récursive. Le principe est de tester toutes les possibilités jusqu'à ce qu'une solution soit trouvée. Si aucune solution n'est trouvée, le programme revient en arrière et teste une autre possibilité. Le programme continue à tester toutes les possibilités jusqu'à ce qu'une solution soit trouvée ou que toutes les possibilités aient été testées.

## Fonctionement du programme

Le programme lit un fichier texte contenant un labyrinthe, puis il trouve un chemin pour traverser le labyrinthe en utilisant du backtracking. Le programme affiche le labyrinthe en cours de résolution, puis il affiche le labyrinthe avec le chemin trouvé.
Le bot cherche le chemin en utilisant la méthode suivante:
- le bot commence par se déplacer vers la droite
- si le bot ne peut pas se déplacer vers la droite, il se déplace vers le bas
- si le bot ne peut pas se déplacer vers le bas, il se déplace vers la gauche
- si le bot ne peut pas se déplacer vers la gauche, il se déplace vers le haut
- si le bot ne peut pas se déplacer vers le haut, il revient en arrière et teste une autre possibilité

## Choix & creation de labirynthes

Le programme peut être utilisé avec n'importe quel labyrinthe, mais il est préférable d'utiliser un labyrinthe avec un chemin unique. Le programme peut être utilisé avec un labyrinthe de n'importe quelle taille, mais il doit respecter les règles suivantes:
- le point de départ doit être representé par le caractère `A`
- le point d'arrivée doit être representé par le caractère `B`
- les murs et les délimitations doivent être représentés par le caractère `+`

## Exemple

Voici un exemple de labyrinth:
    +++++++++
    +A      +
    + +++++++
    +    +  +
    +  +   B+
    +++++++++

## Installation

Pour compiler le programme, il faut utiliser la commande suivante:
    
        gcc -o labyrint labyrint.c

Pour exécuter le programme, il faut utiliser la commande suivante:
        
            ./labyrint
