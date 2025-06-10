#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define LEN 100
struct student {
    char name[LEN];
    float maths;
    float physics;
    float chemistry;
    float english;
    float sec_lang;
    float prev;
};
int main()
{
    struct student students[LEN];
    char choice;
    char buff[LEN];
    int n,i;
    int count=0;
    int out=0;
    while(out==0)
    {
        printf("Enter 'a' to add new student,'v' to view all current records,'i' to view individual record,'u' to update previous record and ,'e' to exit\n");
        scanf(" %c",&choice);
        getchar();
        switch(choice)
        {
            case 'a':
            {
                printf("Enter number of students to be added\n");
                scanf("%d",&n);
                n+=count;
                getchar();
                for(i=count;i<n;i++)
                {
                    printf("Enter name of student number %d\n",i+1);
                    fgets(buff,LEN,stdin);
                    buff[strcspn(buff, "\n")] = 0;
                    strcpy(students[i].name,buff);
                    printf("Enter marks in Maths of student number %d\n",i+1);
                    scanf("%f",&students[i].maths);
                    getchar();
                    printf("Enter marks in Physics of student number %d\n",i+1);
                    scanf("%f",&students[i].physics);
                    getchar();
                    printf("Enter marks in Chemistry of student number %d\n",i+1);
                    scanf("%f",&students[i].chemistry);
                    getchar();
                    printf("Enter marks in English of student number %d\n",i+1);
                    scanf("%f",&students[i].english);
                    getchar();
                    printf("Enter marks in Second Language of student number %d\n",i+1);
                    scanf("%f",&students[i].sec_lang);
                    getchar();
                    printf("Enter previous Average of student number %d, if any\n",i+1);
                    scanf("%f",&students[i].prev);
                    getchar();
                    if(students[i].prev==0)
                    students[i].prev=(students[i].maths+students[i].physics+students[i].chemistry+students[i].english+students[i].sec_lang)/5;
                    else
                    students[i].prev=(((students[i].maths+students[i].physics+students[i].chemistry+students[i].english+students[i].sec_lang)/5)+students[i].prev)/2;
                    count++;
                }
                break;
            }
            case 'v':
            {
                printf("=========Student Records=========\n");
                for(i=0;i<count;i++)
                {
                    printf("%d:Name %s Maths:%.2f Physics:%.2f Chemistry:%.2f English:%.2f 2nd Language:%.2f Average:%.2f\n",i+1,students[i].name,students[i].maths,students[i].physics,students[i].chemistry,students[i].english,students[i].sec_lang,students[i].prev);
                }
                break;
            }
            case 'i':
            {
                printf("Enter the student number\n");
                scanf("%d",&i);
                getchar();
                i--;
                printf("Name %s Maths:%.2f Physics:%.2f Chemistry:%.2f English:%.2f 2nd Language:%.2f Average:%.2f\n",students[i].name,students[i].maths,students[i].physics,students[i].chemistry,students[i].english,students[i].sec_lang,students[i].prev);
                break;
            }
            case 'u':
            {
                printf("Enter student number to be updated\n");
                scanf("%d",&i);
                getchar();
                i--;
                printf("Current Details::Name %s Maths:%.2f Physics:%.2f Chemistry:%.2f English:%.2f 2nd Language:%.2f Average:%.2f\n",students[i].name,students[i].maths,students[i].physics,students[i].chemistry,students[i].english,students[i].sec_lang,students[i].prev);
                printf("Enter updated name of student number %d\n",i);
                    fgets(buff,LEN,stdin);
                    buff[strcspn(buff, "\n")] = 0;
                    strcpy(students[i].name,buff);
                    printf("Enter updated marks in Maths of student number %d\n",i+1);
                    scanf("%f",&students[i].maths);
                    getchar();
                    printf("Enter updated marks in Physics of student number %d\n",i+1);
                    scanf("%f",&students[i].physics);
                    getchar();
                    printf("Enter updated marks in Chemistry of student number %d\n",i+1);
                    scanf("%f",&students[i].chemistry);
                    getchar();
                    printf("Enter updated marks in English of student number %d\n",i+1);
                    scanf("%f",&students[i].english);
                    getchar();
                    printf("Enter updated marks in Second Language of student number %d\n",i+1);
                    scanf("%f",&students[i].sec_lang);
                    getchar();
                    printf("Enter updated previous Average of student number %d, if any\n",i+1);
                    scanf("%f",&students[i].prev);
                    getchar();
                    if(students[i].prev==0)
                    students[i].prev=(students[i].maths+students[i].physics+students[i].chemistry+students[i].english+students[i].sec_lang)/5;
                    else
                    students[i].prev=(((students[i].maths+students[i].physics+students[i].chemistry+students[i].english+students[i].sec_lang)/5)+students[i].prev)/2;
                break;
            }
            case 'e':
            {
                out=1;
                break;
            }
        }
    }
}