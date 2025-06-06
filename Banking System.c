#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN 10000
int main()
{
    int n=0,i=0,m=0,check=0,num,s,r,out=0;
    double amt;
    char **Acc_name=malloc(LEN*sizeof(char*));
    char buff1[LEN], *endptr;
    long *Acc_no=malloc(LEN*sizeof(long));
    Acc_no[0]=256619050;
    float *Acc_Bal=calloc(LEN, sizeof(float));
    while(out==0)
    {
    printf("Press '1' for account creation,'2' for cash withdrawal,'3' for cash deposition,'4' for account-to-account transaction,'5' to view details,'0' to exit interface");
    int choice;
    scanf("%d",&choice);
    getchar();
    switch(choice)
    {
        case 1:
        {
            printf("Enter Name on Account");
            fgets(buff1, LEN, stdin);
            num=strtol(buff1, &endptr, 10);
            buff1[strcspn(buff1, "\n")] = 0;
            Acc_name[n]=strdup(buff1);
            Acc_no[n]=Acc_no[0]+n;
            n++;
            break;
        }
        case 2:
        {
            printf("Enter Name on account or Account number");
            fgets(buff1, LEN, stdin);
            num=strtol(buff1, &endptr, 10);
            buff1[strcspn(buff1, "\n")] = 0;
            for(i=0;i<n;i++)
            {
                if(strcmp(buff1,Acc_name[i])==0)
                {
                    m=i;
                    check++;
                }
                else if(num==Acc_no[i])
                {
                    m=i;
                    check++;
                }
            }
            if(check==1)
            {
                printf("Enter amount of cash to be withdrawn");
                scanf("%lf",&amt);
                getchar();
                if(amt>Acc_Bal[m])
                printf("Insufficient Balance");
                else if(amt<=0)
                printf("Invalid Amount");
                else
                Acc_Bal[m]-=amt;
            }
            else
            printf("Invalid operation");
            break;
        }
        case 3:
        {
            printf("Enter Name on account or Account number");
            fgets(buff1, LEN, stdin);
            num=strtol(buff1, &endptr, 10);
            buff1[strcspn(buff1, "\n")] = 0;
            for(i=0;i<n;i++)
            {
                if(strcmp(buff1,Acc_name[i])==0)
                {
                    m=i;
                    check++;
                }
                else if(num==Acc_no[i])
                {
                    m=i;
                    check++;
                }
            }
            if(check==1)
            {
                printf("Enter amount of cash to be Deposited");
                scanf("%lf",&amt);
                getchar();
                Acc_Bal[m]+=amt;
            }
            else
            printf("Invalid operation");
            break;
        }
        case 4:
        {
            printf("Enter Name on account or Account number of Sender");
            fgets(buff1, LEN, stdin);
            num=strtol(buff1, &endptr, 10);
            buff1[strcspn(buff1, "\n")] = 0;
            for(i=0;i<n;i++)
            {
                if(strcmp(buff1,Acc_name[i])==0)
                {
                    s=i;
                    check++;
                }
                else if(num==Acc_no[i])
                {
                    s=i;
                    check++;
                }
            }
            if(check==1)
            {
                printf("Enter amount of cash to be Sent");
                scanf("%lf",&amt);
                getchar();
                if(amt>Acc_Bal[s])
                printf("Insufficient Balance");
                else if(amt<=0)
                printf("Invalid Amount");
                else
                Acc_Bal[s]-=amt;
            }
            else
            {
            printf("Invalid operation");
            break;
            }
            printf("Enter Name on account or Account number of receiver\n");
            fgets(buff1, LEN, stdin);
            num=strtol(buff1, &endptr, 10);
            check=0;
            for(i=0;i<n;i++)
            {
                if(strcmp(buff1,Acc_name[i])==0)
                {
                    m=i;
                    check++;
                }
                else if(num==Acc_no[i])
                {
                    m=i;
                    check++;
                }
            }
            if(check==1)
            {
                printf("Amount of cash transfered=%.2f\n",amt);
                Acc_Bal[m]+=amt;
            }
            else
            {
            printf("Invalid operation");
            Acc_Bal[s] += amt;
            }
            break;
        }
        case 5:
        {
            printf("Enter Name on account or Account number\n");
            fgets(buff1, LEN, stdin);
            num=strtol(buff1, &endptr, 10);
            buff1[strcspn(buff1, "\n")] = 0;
            for(i=0;i<n;i++)
            {
                if(strcmp(buff1,Acc_name[i])==0)
                {
                    m=i;
                    check++;
                }
                else if(num==Acc_no[i])
                {
                    m=i;
                    check++;
                }
            }
            if(check==1)
            {
                printf("Account Details\nName:%s Acc. No.:%ld Acc. Bal:%.2f",Acc_name[m],Acc_no[m],Acc_Bal[m]);
            }
            else
            printf("Invalid operation");
            break;
        }
        case 0:
        {
            out=1;
            break;
        }
    }
    check=0;
}
for (i = 0; i < n; i++) {
    free(Acc_name[i]);
}
free(Acc_name);
free(Acc_no);
free(Acc_Bal);
    return 0;
}