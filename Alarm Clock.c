#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
void ring_alarm(const char *message) 
{
    printf("\n\n⏰ ALARM! %s ⏰\n", message);
    for (int i = 0; i < 5; i++) 
    {
        printf("\a");
        fflush(stdout);
        sleep(1);
    }
}
int main() 
{
    int h, m;
    char msg[100];
    printf("Set alarm time (HH MM): ");
    scanf("%d %d", &h, &m);
    getchar(); 
    printf("Enter your alarm message: ");
    fgets(msg, sizeof(msg), stdin);
    msg[strcspn(msg, "\n")] = 0;
    printf("Alarm set for %02d:%02d with message: \"%s\"\n", h, m, msg);
    while (1) 
    {
        time_t now = time(NULL);
        struct tm *curr = localtime(&now);
        if (curr->tm_hour == h && curr->tm_min == m) 
        {
            ring_alarm(msg);
            break;
        }
        sleep(5);
    }
    return 0;
}