#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "color.h"

int main()
{
    Task tasks[MAX_TASKS];
    int numTasks = 0;
    int Choix;

    do
    {
        printf(BHGRN"*******************||TO DO LIST ||*******************\n");
        printf(UWHT"\e[1;34m Menu:\n");
        printf(UGRN"|1|. Ajouter \n");
        printf(UGRN"|2|. Afficher \n");
        printf(UGRN"|3|. Marquer une tâche comme terminée \n");
        printf(UGRN"|4|. Supprimer \n");
        printf(UGRN"|5|. Modifier \n");
        printf(UGRN"|6|. Filter\n");
        printf(UGRN"|0|. Quitter\n");
        printf(UWHT"\e[1;34mChoix: ");
        scanf("%d", &Choix);
        printf(BHGRN"*******************||TO DO LIST ||*******************\n");

        switch (Choix)
        {
        case 1:
            getchar();
            addTask(tasks, &numTasks);
            break;
        case 2:
            displayTasks(tasks, numTasks);
            break;
        case 3:
        {
            markTaskCompleted(tasks, numTasks);
            break;
        }
        case 4:
        {
            int index;
            printf("Saisissez l'index de la tâche à supprimer : ");
            scanf("%d", &index);
            deleteTask(tasks, &numTasks, index - 1);
            break;
        }
        case 5:
            int modifyIndex;
            printf("Enter the index of the task you want to modify: ");
            scanf("%d", &modifyIndex);
            getchar(); 
            modifyTask(tasks, numTasks, modifyIndex - 1);
            break;
        case 6:
            int filterPriority;
            printf("Enter priority to filter tasks: ");
            scanf("%d", &filterPriority);
            filterByPriority(tasks, numTasks, filterPriority);
            break;
        case 8:
            saveTasksToFile(tasks, numTasks, "fp.txt");
            printf("Tasks saved to file.\n");
            break;

        case 0:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please try again choice number 0-5.\n");
        }
    } while (Choix != 0);

    return 0;
}
