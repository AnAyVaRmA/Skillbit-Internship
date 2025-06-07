#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
struct expenses {
    char name[100];
    char category[100];
    float amount;
};
int main() {
    struct expenses expense[MAX];
    int n, i, j, found, cat_count = 0;
    printf("Enter number of expenses: ");
    scanf("%d", &n);
    getchar();
    for (i = 0; i < n; i++) 
    {
        printf("\nEnter expense name: ");
        fgets(expense[i].name, sizeof(expense[i].name), stdin);
        expense[i].name[strcspn(expense[i].name, "\n")] = 0;
        printf("Enter expense category: ");
        fgets(expense[i].category, sizeof(expense[i].category), stdin);
        expense[i].category[strcspn(expense[i].category, "\n")] = 0;
        printf("Enter amount: ");
        scanf("%f", &expense[i].amount);
        getchar();
    }
    char **categories = malloc(n * sizeof(char*));
    float *total = calloc(n, sizeof(float));
    for (i = 0; i < n; i++) {
        found = 0;
        for (j = 0; j < cat_count; j++) {
            if (strcmp(categories[j], expense[i].category) == 0) 
            {
                total[j] += expense[i].amount;
                found = 1;
                break;
            }
        }
        if (!found && cat_count < MAX) 
        {
            categories[cat_count] = malloc(strlen(expense[i].category) + 1);
            strcpy(categories[cat_count], expense[i].category);
            total[cat_count] = expense[i].amount;
            cat_count++;
        }
    }
    int out = 0;
    while (!out) {
        printf("\nEnter '1' to view all, '2' for category-wise, '3' to exit: ");
        int choice;
        scanf("%d", &choice);
        getchar();
        switch (choice) 
        {
            case 1:
            {
                printf("\n======== All Expenses ========\n");
                for (i = 0; i < n; i++) {
                    printf("%d. %s | %s | ₹%.2f\n", i + 1, expense[i].name, expense[i].category, expense[i].amount);
                }
                break;
            }
            case 2:
            {
                printf("\n======= Category-wise Summary =======\n");
                for (i = 0; i < cat_count; i++) {
                    printf("\n-- %s (Total: ₹%.2f) --\n", categories[i], total[i]);
                    for (j = 0; j < n; j++) {
                        if (strcmp(expense[j].category, categories[i]) == 0) {
                            printf("  %s - ₹%.2f\n", expense[j].name, expense[j].amount);
                        }
                    }
                }
                break;
            }
            case 3:
            {
                out = 1;
                break;
            }
            default:
            printf("Invalid choice. Try again.\n");
        }
    }
    for (i = 0; i < cat_count; i++) 
    {
        free(categories[i]);
    }
    free(categories);
    free(total);
    return 0;
}