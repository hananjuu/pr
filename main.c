#include <stdio.h>
#include <stdlib.h>


#include <stdio.h>
#include "header.h"

int main() {
    int choice;
    int displayMenu = 1;
    do {
        if (displayMenu) {
            printf("\nMenu Principal :\n");
            printf("1. Ajouter une tâche\n");
            printf("2. Modifier une tâche\n");
            printf("3. Supprimer une tâche\n");
            printf("4. Afficher toutes les tâches\n");
            printf("5. Filtrer les tâches par priorité\n");
            printf("6. Marquer une tâche comme terminée\n");
            printf("7. Quitter\n");
            printf("Entrez votre choix : ");
        }
        scanf("%d", &choice);
        

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
                displayMenu = 0; // Ne pas réafficher le menu principal
                break;
            case 5:
                filterTasksByPriority();
                displayMenu = 0; // Ne pas réafficher le menu principal
                break;
            case 6:
                markTaskAsFinished();
                displayMenu = 1;

                break;
            case 7:
                printf("Fin du programme.\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                displayMenu = 1;
        }
    } while (choice <= 7&& choice >0);

    return 0;
}
