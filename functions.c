#include <stdio.h>
#include <string.h>
#include "header.h"



Task tasks[MAX_TASKS];
int numTasks = 0;

void addTask() {
    if (numTasks >= MAX_TASKS) {
        printf("La liste de tâches est pleine.\n");
        return 0;
    }
    printf("Entrez la description de la tâche : ");
    scanf("%s", tasks[numTasks].description);
    printf("Entrez la priorité de la tâche : ");
    scanf("%d", &tasks[numTasks].priority);
    printf("la tache est termine? ");
    scanf("%d",&tasks[numTasks].finished);


    numTasks++;
    printf("Tâche ajoutée avec succès.\n");
}

void modifyTask() {
    int index;
    printf("Entrez l'indice de la tâche à modifier : ");
    scanf("%d", &index);

    if (index < 1 || index > numTasks) {
        printf("Indice de tâche invalide.\n");
        return;
    }
    printf("Entrez la nouvelle description de la tâche : ");
    scanf("%s", tasks[index - 1].description);
    printf("Entrez la nouvelle priorité de la tâche : ");
    scanf("%d", &tasks[index - 1].priority);
    printf("Tâche modifiée avec succès.\n");
}

void deleteTask() {
    int index;
    printf("Entrez l'indice de la tâche à supprimer : ");
    scanf("%d", &index);
    if (index < 1 || index > numTasks) {
        printf("Indice de tâche invalide.\n");
        return 0;
    }
    for (int i = index - 1; i < numTasks - 1; i++) {
        strcpy(tasks[i].description, tasks[i + 1].description);
        tasks[i].priority = tasks[i + 1].priority;
        tasks[i].finished = tasks[i + 1].finished;
    }
    numTasks--;
    printf("Tâche supprimée avec succès.\n");
}

void displayTasks() {
    printf("Liste des tâches :\n");
    for (int i = 0; i < numTasks; i++) {
    printf("%d. Description : %s | Priorité : %d | Terminée : %s\n", i + 1, tasks[i].description, tasks[i].priority,(tasks[i].finished == 1) ? "done" : "not yet" );

        }


}

void filterTasksByPriority() {
    printf("Tâches par ordre de priorité :\n");

    for (int priority = 0; priority <= numTasks; priority++) {
        for (int i = 0; i < numTasks; i++) {
            if (tasks[i].priority == priority) {
                printf("%d. Description : %s | Priorité : %d | Terminée : %s\n", i + 1, tasks[i].description,
                       tasks[i].priority, (tasks[i].finished == 1) ? "done"  : "not yet");
            }
        }
    }
}

void markTaskAsFinished() {
    int index;
    printf("Entrez l'indice de la tâche terminée : ");
    scanf("%d", &index);
    if (index < 1 || index > numTasks) {
        printf("Indice de tâche invalide.\n");
        return 0;
    }
    tasks[index - 1].finished = 1;
    printf("Tâche marquée comme terminée avec succès.\n");
}

