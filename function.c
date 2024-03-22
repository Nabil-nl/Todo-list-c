#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void addTask(Task tasks[], int *numTasks) {
    if (*numTasks >= MAX_TASKS) {
        printf("Maximum number of tasks reached.\n");
        return;
    }

    Task newTask;

    printf("Nom Task : ");
    fgets(newTask.title, MAX_TITLE_LENGTH, stdin);
    newTask.title[strcspn(newTask.title, "\n")] = 0; 

    printf("Priority (1-3): ");
    scanf("%d", &newTask.priority);

    

    newTask.completed = 0;

    tasks[(*numTasks)++] = newTask;

    printf("Task added successfully.\n");
}

void displayTasks(Task tasks[], int numTasks) {
    printf("afficher:\n");
    for (int i = 0; i < numTasks; i++) {
        printf("|%d.| | %s | [Priority: %d,  %s]\n", i + 1, tasks[i].title, tasks[i].priority, tasks[i].completed ? "Completed" : "Not completed");
    }
}

void markTaskCompleted(Task tasks[], int numTasks) {
    int taskIndex;
    printf("Enter the index of the task you want to mark as completed: ");
    scanf("%d", &taskIndex);
    if (taskIndex >= 1 && taskIndex <= numTasks) {
        tasks[taskIndex - 1].completed = 1;
        printf("Task marked as completed.\n");
    } else {
        printf("Invalid task index.\n");
    }
}

// save 3ndi error
 void saveTasksToFile(Task tasks[], int numTasks, const char *fp) {
    FILE *fileop ;
    fileop = fopen("fp.txt", "wb");
    if (fileop == NULL) {
        printf("Error opening file for writing.\n");
        return;
     }
     fwrite(&numTasks, sizeof(int), 1, fileop); 

    for (int i = 0; i < numTasks; i++) {
        fwrite(&tasks[i], sizeof(Task), 1, fileop);  }

    fclose(fileop);
}
//supprimer
void deleteTask(Task tasks[], int *numTasks, int index) {
    if (index < 0 || index >= *numTasks) {
        printf("Invalid task index.\n");
        return;
    }

    for (int i = index; i < *numTasks - 1; i++) {
        tasks[i] = tasks[i + 1];
    }

    (*numTasks)--;
    printf("Task deleted successfully.\n");
}
//modifier
void modifyTask(Task tasks[], int numTasks, int index) {
    if (index < 0 || index >= numTasks) {
        printf("Invalid task index.\n");
        return;
    }

    Task *task = &tasks[index];

    printf("Enter new title for the task: ");
    fgets(task->title, MAX_TITLE_LENGTH, stdin);
    task->title[strcspn(task->title, "\n")] = '\0';

    printf("Enter new priority for the task (1-3): ");
    scanf("%d", &task->priority);

    printf("Task modified successfully.\n");
}
//filter pr
void filterByPriority(Task tasks[], int numTasks, int priority) {
    printf("Tasks with priority %d:\n", priority);
    for (int i = 0; i < numTasks; i++) {
        if (tasks[i].priority == priority) {
            printf("%s [Priority: %d, %s]\n", tasks[i].title, tasks[i].priority, tasks[i].completed ? "Completed" : "Not completed");
        }
    }
}



