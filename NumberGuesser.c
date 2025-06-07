#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int min,max,guess,tries,r,i;
    printf("Enter the upper limit\n");
    scanf("%d",&max);
    printf("Enter the lower limit\n");
    scanf("%d",&min);
    srand(time(NULL));
    r=rand()%(max-min+1)+min;
    printf("Enter number of tries you want to have\n");
    scanf("%d",&tries);
    for(i=tries;i>0;i--)
    {
        printf("Try number:%d\n",i);
        scanf("%d",&guess);
        if(guess==r)
        {
            printf("Correct Guess!!\n");
            break;
        }
        else
        printf("wrong guess\n");
    }
    return 0;
}