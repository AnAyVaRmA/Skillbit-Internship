#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#define PATH_LEN 1024
void list_files(const char *path) 
{
    DIR *dir = opendir(path);
    if (dir == NULL) 
    {
        perror("Unable to open directory");
        return;
    }
    struct dirent *entry;
    printf("Files and Folders in %s:\n", path);
    while ((entry = readdir(dir)) != NULL) 
    {
        printf("  %s\n", entry->d_name);
    }
    closedir(dir);
}
void create_folder(const char *foldername) 
{
    if (mkdir(foldername) == 0)
        printf("Folder '%s' created successfully.\n", foldername);
    else
        perror("Failed to create folder");
}
void copy_file(const char *source, const char *destination) {
    FILE *src = fopen(source, "rb");
    if (!src) 
    {
        perror("Source file open failed");
        return;
    }
    FILE *dest = fopen(destination, "wb");
    if (!dest) 
    {
        perror("Destination file open failed");
        fclose(src);
        return;
    }
    char buffer[BUFSIZ];
    size_t n;
    while ((n = fread(buffer, 1, sizeof(buffer), src)) > 0) 
    {
        fwrite(buffer, 1, n, dest);
    }
    printf("File copied from '%s' to '%s'.\n", source, destination);
    fclose(src);
    fclose(dest);
}
void move_file(const char *source, const char *destination) 
{
    if (rename(source, destination) == 0)
        printf("File moved from '%s' to '%s'.\n", source, destination);
    else
        perror("File move failed");
}
void delete_file(const char *filename) 
{
    if (remove(filename) == 0)
        printf("File '%s' deleted successfully.\n", filename);
    else
        perror("File deletion failed");
}
int main() 
{
    char current_path[PATH_LEN];
    getcwd(current_path, sizeof(current_path));
    char command[PATH_LEN], arg1[PATH_LEN], arg2[PATH_LEN];
    while (1) 
    {
        printf("\nCurrent Directory: %s\n", current_path);
        printf("Commands: ls | cd <dir> | mkdir <name> | cp <src> <dest> | mv <src> <dest> | rm <file> | exit\n> ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';
        if (strcmp(command, "ls") == 0) 
        {
            list_files(current_path);
        } 
        else if (strncmp(command, "cd ", 3) == 0) 
        {
            sscanf(command + 3, "%s", arg1);
            if (chdir(arg1) == 0) 
            {
                getcwd(current_path, sizeof(current_path));
            } 
            else 
            {
                perror("cd failed");
            }
        } 
        else if (strncmp(command, "mkdir ", 6) == 0) 
        {
            sscanf(command + 6, "%s", arg1);
            create_folder(arg1);
        } 
        else if (strncmp(command, "cp ", 3) == 0) 
        {
            sscanf(command + 3, "%s %s", arg1, arg2);
            copy_file(arg1, arg2);
        } 
        else if (strncmp(command, "mv ", 3) == 0) 
        {
            sscanf(command + 3, "%s %s", arg1, arg2);
            move_file(arg1, arg2);
        } 
        else if (strncmp(command, "rm ", 3) == 0) 
        {
            sscanf(command + 3, "%s", arg1);
            delete_file(arg1);
        } 
        else if (strcmp(command, "exit") == 0) 
        {
            break;
        } 
        else 
        {
            printf("Unknown command.\n");
        }
    }
    return 0;
}