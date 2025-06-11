#include <stdio.h>
#include <string.h>
#define LEN 1024
#define MAX_TASKS 100
int main()
{
    char choice,task[LEN];
    int task_count=0;
    int out = 0;
    int num;
    char number[10];
    char *pos;
    while(out == 0)
    {
        printf("Enter 'a' to add tasks,'v' to view all current tasks,'u' to update a task,'r' to remove a task and 'e' to exit\n");
        scanf(" %c",&choice);
        getchar();
        switch(choice)
        {
        case 'a':
        {
            FILE *fp_read = fopen("Tasks.txt", "r");
            int lines = 0;
            char temp[LEN];
            if (fp_read) 
            {
                while (fgets(temp, LEN, fp_read)) 
                {
                    lines++;
                }
                fclose(fp_read);
            }
            printf("Enter tasks to be added\n");
            FILE *fp1 = fopen("Tasks.txt", "a");
            fgets(task, LEN, stdin);
            task[strcspn(task, "\n")] = 0;
            fprintf(fp1, "%d. %s\n",task_count+1, task);
            fclose(fp1);
            task_count++;
            break;
        }
        case 'v':
        {
            FILE *fp2 = fopen("Tasks.txt", "r");
            while (fgets(task, 100, fp2) != NULL)
            {
                printf("%s", task);
            }
            fclose(fp2);
            break;
        }
        case 'u': {
            printf("Enter task number to update: ");
            int num;
            scanf("%d", &num);
            getchar();
            printf("Enter updated task: ");
            char new_task[LEN];
            fgets(new_task, LEN, stdin);
            new_task[strcspn(new_task, "\n")] = 0;
            FILE *fp = fopen("Tasks.txt", "r");
            char lines[MAX_TASKS][LEN];
            int i = 0;
            while (fgets(lines[i], LEN, fp))
            {
                i++;
            }
            fclose(fp);
            if (num >= 1 && num <= i) {
                snprintf(lines[num - 1], LEN, "%d. %s\n", num, new_task);
            } else {
                printf("Invalid task number.\n");
                break;
            }
            fp = fopen("Tasks.txt", "w");
            for (int j = 0; j < i; j++) 
            {
                fputs(lines[j], fp);
            }
            fclose(fp);
            printf("Task updated.\n");
            break;
        }
        case 'r': {
            printf("Enter task number to remove: ");
            int num;
            scanf("%d", &num);
            getchar();

            FILE *fp = fopen("Tasks.txt", "r");
            char lines[MAX_TASKS][LEN];
            int i = 0;

            while (fgets(lines[i], LEN, fp)) {
                i++;
            }
            fclose(fp);

            if (num < 1 || num > i) {
                printf("Invalid task number.\n");
                break;
            }

            fp = fopen("Tasks.txt", "w");
            int new_count = 1;
            for (int j = 0; j < i; j++) {
                if (j == num - 1) continue;
                fprintf(fp, "%d. %s", new_count++, strchr(lines[j], '.') + 1);
            }
            fclose(fp);
            printf("Task removed.\n");
            break;
        }
        case 'e':
        {
            out=1;
            break;
        }
        }
    }
    return 0;
}