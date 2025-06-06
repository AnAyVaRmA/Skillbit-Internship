#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 100
int main()
{
    int i,out=0,n=0,m;
    char buff1[LEN];
    char buff2[LEN];
    char buff3[LEN];
    char **contact_name=malloc(LEN*sizeof(char*));
    char **number1=malloc(LEN*sizeof(char*));
    char **number2=malloc(LEN*sizeof(char*));
    while(out==0)
    {
        printf("Enter 'a' to add contact,'e' to edit contact,'r' to remove contact,'v' to view all saved contacts and 'o' to exit\n");
        char choice;
        scanf(" %c",&choice);
        getchar();
        switch(choice)
        {
            case 'a':
            {
                printf("Enter contact name\n");
                fgets(buff1, LEN, stdin);
                buff1[strcspn(buff1, "\n")] = 0;
                contact_name[n]=strdup(buff1);
                printf("Enter contact number 1\n");
                fgets(buff2, LEN, stdin);
                buff2[strcspn(buff1, "\n")] = 0;
                number1[n]=strdup(buff2);
                printf("Enter contact number 2\n");
                fgets(buff3, LEN, stdin);
                buff3[strcspn(buff1, "\n")] = 0;
                number2[n]=strdup(buff3);
                n++;
                break;
            }
            case 'e':
            {
                printf("Enter contact number to be edited\n");
                scanf("%d",&m);
                getchar();
                free(contact_name[m]);
                free(number1[m]);
                free(number2[m]);
                printf("Enter contact name\n");
                fgets(buff1, LEN, stdin);
                buff1[strcspn(buff1, "\n")] = 0;
                contact_name[m]=strdup(buff1);
                printf("Enter contact number 1\n");
                fgets(buff2, LEN, stdin);
                buff2[strcspn(buff1, "\n")] = 0;
                number1[m]=strdup(buff2);
                printf("Enter contact number 2\n");
                fgets(buff3, LEN, stdin);
                buff3[strcspn(buff1, "\n")] = 0;
                number2[m]=strdup(buff3);
                break;
            }
            case 'r':
            {
                printf("Enter contact number to be removed\n");
                scanf("%d",&m);
                getchar();
                free(contact_name[m-1]);
                free(number1[m-1]);
                free(number2[m-1]);
                for(i=m-1;i<n-1;i++)
                {
                    contact_name[i]=contact_name[i+1];
                    number1[i]=number1[i+1];
                    number2[i]=number2[i+1];
                }
                n--;
                break;
            }
            case 'v':
            {
                printf("Contacts List:\n");
                for(i=0;i<n;i++)
                {
                    printf("%d:%s  %s  %s\n",(i+1) , contact_name[i], number1[i], number2[i]);
                }
                break;
            }
            case 'o':
            {
                out=1;
                break;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        free(contact_name[i]);
        free(number1[i]);
        free(number2[i]);
    }
    return 0;
}