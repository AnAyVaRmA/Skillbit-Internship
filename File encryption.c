#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 1024
void encrypt(char filename[])
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("File retrieval error\n");
        return;
    }
    char buffer[LEN];
    int i = 0;
    char ch;
    while ((ch = fgetc(fp)) != EOF && i < LEN - 1)
    {
        buffer[i++] = ch;
    }
    buffer[i] = '\0';
    fclose(fp);
    printf("Enter key for encryption: ");
    int key;
    scanf("%d", &key);
    for (int j = 0; j < i; j++)
    {
        if (buffer[j] != '\n' && buffer[j] != ' ')
        {
            buffer[j] += key;
        }
    }
    fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("File writing error\n");
        return;
    }
    fputs(buffer, fp);
    fclose(fp);
    printf("Encryption complete\n");
}
void decrypt(char filename[])
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("File retrieval error\n");
        return;
    }
    char buffer[LEN];
    int i = 0;
    char ch;
    while ((ch = fgetc(fp)) != EOF && i < LEN - 1)
    {
        buffer[i++] = ch;
    }
    buffer[i] = '\0';
    fclose(fp);
    printf("Enter key for decryption: ");
    int key;
    scanf("%d", &key);
    for (int j = 0; j < i; j++)
    {
        if (buffer[j] != '\n' && buffer[j] != ' ')
        {
            buffer[j] -= key;
        }
    }
    fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("File writing error\n");
        return;
    }
    fputs(buffer, fp);
    fclose(fp);
    printf("Decryption complete\n");
}
int main()
{
    printf("Enter file name: ");
    char filename[100];
    fgets(filename, LEN, stdin);
    filename[strcspn(filename, "\n")] = '\0';
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("File does not exist.\nCreate file? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        getchar();
        if (choice == 'n')
        {
            return 0;
        }
        else if (choice == 'y')
        {
            fp = fopen(filename, "w");
            if (fp == NULL)
            {
                printf("Unable to create file.\n");
                return 1;
            }
            printf("Write the contents of the file:\n");
            char file_content[LEN];
            fgets(file_content, LEN, stdin);
            file_content[strcspn(file_content, "\n")] = '\0';
            fprintf(fp, "%s", file_content);
            fclose(fp);
        }
        else
        {
            printf("Invalid choice.\n");
            return 0;
        }
    }
    else
    {
        printf("File already exists.\n");
        fclose(fp);
    }
    printf("Enter 'e' for encryption or 'd' for decryption: ");
    char action;
    scanf(" %c", &action);
    switch (action)
    {
    case 'e':
        encrypt(filename);
        break;

    case 'd':
        decrypt(filename);
        break;

    default:
        printf("Invalid choice.\n");
        break;
    }
    return 0;
}
