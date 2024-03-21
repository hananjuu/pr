#include <stdio.h>
#include "header.h"

int main() {
    int choice;
    int displayMenu = 1;
    do {
        if (displayMenu) {
            printf("\nMenu Principal :\n");
            printf("1. Ajouter une t�che\n");
            printf("2. Modifier une t�che\n");
            printf("3. Supprimer une t�che\n");
            printf("4. Afficher toutes les t�ches\n");
            printf("5. Filtrer les t�ches par priorit�\n");
            printf("6. Marquer une t�che comme termin�e\n");
            printf("7. Quitter\n");
            printf("Entrez votre choix : ");
        }

        // V�rifier si la saisie est un entier
        if (scanf("%d", &choice) != 1) {
            printf("Choix invalide. Veuillez r�essayer.\n");
            while (getchar() != '\n'); // Vider le tampon d'entr�e
            displayMenu = 1;
            continue; // Revenir au d�but de la boucle
        }

        switch (choice) {
            case 1:
                addTask();
                displayMenu = 1;
                break;
            case 2:
                modifyTask();
                displayMenu = 1;
                break;
            case 3:
                deleteTask();
                displayMenu = 1;
                break;
            case 4:
                displayTasks();
                displayMenu = 0;
                break;
            case 5:
                filterTasksByPriority();
                displayMenu = 0;
                break;
            case 6:
                markTaskAsFinished();
                displayMenu = 1;
                break;
            case 7:
                printf("Fin du programme.\n");
                break;
            default:
                printf("Choix invalide. Veuillez r�essayer.\n");
                displayMenu = 1;
        }
    } while (choice <7 && choice>0);

    return 0;
}
