#include <stdio.h>
#include <stdbool.h>
int add(int a,int b)
{
    return(a+b);
}
int mul(int a,int b)
{
    return(a*b);
}
int sub(int a,int b)
{
    return(a-b);
}
int div(int a,int b)
{
    return(a/b);
}
int Calc(int a,int b)
{
    int op,calc=0;
    printf("Select which operation you want to perform \n");
    scanf("%d",&op);
    switch(op)
    {case 1:
        calc=add(a,b);
        break;
    case 2:
        calc=mul(a,b);
        break;
    case 3:
        calc=sub(a,b);
        break;
    case 4:
    if(b==0)
    {
        printf("Not valid \n");
        break;
    }
    else
    {
        calc=div(a,b);
        break;
    }
    }
    printf("Your result is %d \n",calc);
    return(calc);
}
int main ()
{
    int iter=0,res,Proceed,a,b;
    while(1)
    {
        printf("Enter the two input number(s) \n");
        if(iter==0)
        {
            printf("Enter the first number \n");
            scanf("%d",&a);
        }
        else
        a=res;
        printf("Enter the next number \n");
        scanf("%d",&b);
        res=Calc(a,b);
    printf("Proceed ? \n 1 for Yes \n 0 for No ");
    scanf("%d",&Proceed);
    if(Proceed==0) break;
    iter=iter+1;
    }
}