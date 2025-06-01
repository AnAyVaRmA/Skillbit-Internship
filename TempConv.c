#include<stdio.h>
int main()
{
    double temp,C,F,res;
    char in,out;
    printf("Enter the temperature magnitude to be converted\n");
    scanf("%lf",&temp);
    printf("Enter type of conversion to be performed, first letter for input temp, and second letter for output (converted) temp\n");
    scanf(" %c",&in);
    switch (in)
    {
        case 'C':
        C=temp;
        break;
        case 'F':
        F=temp;
        break;
    }
    printf("Input:%lf %c\n", temp, in);
    scanf(" %c",&out);
    switch (out)
    {
        case 'C':
        if(in=='C')
        {
            printf("No need of conversion");
            res=C;
            break;
        }
        else if(in=='F')
        {
            C=((F-32)*5)/9;
            res=C;
            break;
        }
        case 'F':
        if(in=='F')
        {
            printf("No need of conversion");
            res=F;
            break;
        }
        else if(in=='C')
        {
            F=(C*1.8)+32;
            res=F;
            break;
        }
    }
    printf("Output:%lf %c\n", res, out);
}