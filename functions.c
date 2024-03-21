#include <stdio.h>
#include <string.h>
#include "header.h"



Task tasks[MAX_TASKS];
int numTasks = 0;

void addTask() {
    if (numTasks >= MAX_TASKS) {
        printf("La liste de t�ches est pleine.\n");
        return 0;
    }
    printf("Entrez la description de la t�che : ");
    scanf("%s", tasks[numTasks].description);
    printf("Entrez la priorit� de la t�che : ");
    scanf("%d", &tasks[numTasks].priority);
    printf("la tache est termine? ");
    scanf("%d",&tasks[numTasks].finished);


    numTasks++;
    printf("T�che ajout�e avec succ�s.\n");
}

void modifyTask() {
    int index;
    printf("Entrez l'indice de la t�che � modifier : ");
    scanf("%d", &index);

    if (index < 1 || index > numTasks) {
        printf("Indice de t�che invalide.\n");
        return;
    }
    printf("Entrez la nouvelle description de la t�che : ");
    scanf("%s", tasks[index - 1].description);
    printf("Entrez la nouvelle priorit� de la t�che : ");
    scanf("%d", &tasks[index - 1].priority);
    printf("T�che modifi�e avec succ�s.\n");
}

void deleteTask() {
    int index;
    printf("Entrez l'indice de la t�che � supprimer : ");
    scanf("%d", &index);
    if (index < 1 || index > numTasks) {
        printf("Indice de t�che invalide.\n");
        return 0;
    }
    for (int i = index - 1; i < numTasks - 1; i++) {
        strcpy(tasks[i].description, tasks[i + 1].description);
        tasks[i].priority = tasks[i + 1].priority;
        tasks[i].finished = tasks[i + 1].finished;
    }
    numTasks--;
    printf("T�che supprim�e avec succ�s.\n");
}

void displayTasks() {
    printf("Liste des t�ches :\n");
    for (int i = 0; i < numTasks; i++) {
    printf("%d. Description : %s | Priorit� : %d | Termin�e : %s\n", i + 1, tasks[i].description, tasks[i].priority,(tasks[i].finished == 1) ? "done" : "not yet" );

        }


}

void filterTasksByPriority() {
    printf("T�ches par ordre de priorit� :\n");

    for (int priority = 0; priority <= numTasks; priority++) {
        for (int i = 0; i < numTasks; i++) {
            if (tasks[i].priority == priority) {
                printf("%d. Description : %s | Priorit� : %d | Termin�e : %s\n", i + 1, tasks[i].description,
                       tasks[i].priority, (tasks[i].finished == 1) ? "done"  : "not yet");
            }
        }
    }
}

void markTaskAsFinished() {
    int index;
    printf("Entrez l'indice de la t�che termin�e : ");
    scanf("%d", &index);
    if (index < 1 || index > numTasks) {
        printf("Indice de t�che invalide.\n");
        return 0;
    }
    tasks[index - 1].finished = 1;
    printf("T�che marqu�e comme termin�e avec succ�s.\n");
}

