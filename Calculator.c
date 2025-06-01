#include <stdio.h>
#include <string.h>
int main() 
{
    int iter = 0, a, b, res;
    char op[2];
    printf("Start calculating\nPress '=' to stop calculating\n");
    scanf("%d", &a);
    getchar();
    while (iter == 0) 
    {
        fgets(op, sizeof(op), stdin);
        op[strcspn(op, "\n")] = '\0';
        if (strcmp(op, "=") == 0) {
            printf("Final result: %d\n", a);
            iter = 1;
            break;
        }
        scanf("%d", &b);
        getchar();
        if (strcmp(op, "+") == 0) 
        {
            res = a + b;
        } 
        else if (strcmp(op, "-") == 0) 
        {
            res = a - b;
        } 
        else if (strcmp(op, "*") == 0) 
        {
            res = a * b;
        } 
        else if (strcmp(op, "/") == 0) 
        {
            if (b == 0) 
            {
                printf("Error: Division by zero\n");
                continue;
            }
            res = a / b;
        } 
        else 
        {
            printf("Invalid operator\n");
            continue;
        }
        printf("= %d\n", res);
        a = res;
    }
    return 0;
}