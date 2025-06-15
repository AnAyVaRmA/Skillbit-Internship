#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#define LEN 1024
int main()
{
    char choice_out, choice_in;
    int out = 0;
    char questions[LEN], answers[LEN], givenans[LEN],modified[LEN];
    while (out == 0)
    {
        printf("Enter 'p' to play game, 'w' to write/add questions, 'e' to exit\n");
        scanf(" %c", &choice_out);
        getchar();
        switch (choice_out)
        {
        case 'w':
        {
            FILE *fp = fopen("Quiz.txt", "r");
            int ques_total = 0;
            char line[LEN];
            if (fp != NULL)
            {
                while (fgets(line, LEN, fp))
                {
                    if (strncmp(line, "Q", 1) == 0)
                        ques_total++;
                }
                fclose(fp);
            }
            printf("Currently there are %d question(s).\n", ques_total);
            printf("Do you want to add a question? (y/n): ");
            scanf(" %c", &choice_in);
            getchar();
            if (choice_in == 'y')
            {
                fp = fopen("Quiz.txt", "a");
                if (fp == NULL)
                {
                    printf("Error opening file for writing.\n");
                    break;
                }
                printf("Enter the question:\n");
                fgets(questions, LEN, stdin);
                questions[strcspn(questions, "\n")] = '\0';
                printf("Enter the answer:\n");
                fgets(answers, LEN, stdin);
                answers[strcspn(answers, "\n")] = '\0';
                fprintf(fp, "Q%d: %s\n", ques_total + 1, questions);
                fprintf(fp, "Ans%d: %s\n", ques_total + 1, answers);
                fclose(fp);
                printf("Question added successfully.\n");
            }
            break;
        }
        case 'p':
        {
            FILE *fp = fopen("Quiz.txt", "r");
            if (fp == NULL)
            {
                printf("No quiz file found. Add a question first.\n");
                break;
            }
            int ques_total = 0;
            char line[LEN];
            while (fgets(line, LEN, fp))
            {
                if (strncmp(line, "Q", 1) == 0)
                    ques_total++;
            }
            fclose(fp);
            if (ques_total == 0)
            {
                printf("No questions available.\n");
                break;
            }
            srand(time(NULL));
            int r = (rand() % ques_total) + 1;
            fp = fopen("Quiz.txt", "r");
            if (fp == NULL)
            {
                printf("Error reading quiz file.\n");
                break;
            }
            int current = 0;
            while (fgets(line, LEN, fp))
            {
                if (sscanf(line, "Q%d:", &current) == 1 && current == r)
                {
                    char *qtext = strchr(line, ':');
                    if (qtext != NULL)
                    {
                        printf("\nQuestion %d: %s\n", current, qtext + 1);
                    }
                    printf("Your Answer: ");
                    fgets(givenans, LEN, stdin);
                    givenans[strcspn(givenans, "\n")] = '\0';
                    modified[0]=' ';
                    strcpy(modified+1,givenans);
                    strcpy(givenans,modified);
                    if (fgets(line, LEN, fp))
                    {
                        char *ans_text = strchr(line, ':');
                        if (ans_text != NULL)
                        {
                            ans_text++;
                            ans_text[strcspn(ans_text, "\n")] = '\0';
                            if (strcmp(givenans, ans_text) == 0)
                            {
                                printf("Correct Answer!\n");
                            }
                            else
                            {
                                printf("Wrong Answer. Correct answer was: '%s';\nYour answer was: '%s'\n", ans_text,givenans);
                            }
                        }
                    }
                    break;
                }
            }
            fclose(fp);
            break;
        }
        case 'e':
        {
            out = 1;
            break;
        }

        default:
        {
            printf("Invalid choice\n");
            break;
        }
        }
    }

    return 0;
}