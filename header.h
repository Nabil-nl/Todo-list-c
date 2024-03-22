#ifndef HEADER_H
#define HEADER_H
#define MAX_TASKS 100
#define MAX_TITLE_LENGTH 50

typedef struct {
    char title[MAX_TITLE_LENGTH];
    int priority;
    int completed;
} Task;



void addTask(Task tasks[], int *numTasks);
void displayTasks(Task tasks[], int numTasks);
void markTaskCompleted(Task tasks[], int numTasks);
void deleteTask(Task tasks[], int *numTasks, int index);
void modifyTask(Task tasks[], int numTasks, int index);
void filterByPriority(Task tasks[], int numTasks, int priority);
void saveTasksToFile(Task tasks[], int numTasks, const char *filename);

#endif