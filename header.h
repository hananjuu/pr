#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#ifndef TASKS_H
#define TASKS_H

#define MAX_TASKS 100

typedef struct {
    char description[100];
    int priority;
    int finished;
} Task;

void addTask();
void modifyTask();
void deleteTask();
void displayTasks();
void filterTasksByPriority();
void markTaskAsFinished();

#endif /* TASKS_H */


#endif // HEADER_H_INCLUDED
