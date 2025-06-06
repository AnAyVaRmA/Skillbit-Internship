#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 100
int main()
{
    printf("Enter number of items to be entered \n");
    int i,n,m,qty_sld;  
    scanf("%d",&n);
    getchar();
    char **item=malloc(n*sizeof(char*)),choice;
    char buff[LEN];
    int *price=malloc(n*sizeof(int));
    int *quantity=malloc(n*sizeof(int));
    int *sold_quantity=calloc(n,sizeof(int));
    for(i=0;i<n;i++)
    {
        printf("Enter item no. %d \n",i);
        fgets(buff, LEN, stdin);
        buff[strcspn(buff, "\n")] = 0;
        item[i]=strdup(buff);
        printf("Enter price of item no. %d \n",i);
        scanf("%d",&price[i]);
        printf("Enter quantity of item no. %d \n",i);
        scanf("%d",&quantity[i]);
        getchar();
    }
    int out=1;
    while(out==1)
    {
        printf("Press 'a' to add,'r' to remove,'q' to view stock,'t' to add sold items,'s' to calculate total sale,'e' to exit \n");
        scanf(" %c",&choice);
        switch(choice)
        {
            case 'a':
            {
                printf("Enter number of items to be added \n");
                scanf("%d",&m);
                item=realloc(item, (n+m)*sizeof(char*));
                price=realloc(price, (n+m)*sizeof(int));
                quantity=realloc(quantity, (n+m)*sizeof(int));
                sold_quantity = realloc(sold_quantity, (n + m) * sizeof(int));
                for (i = n; i < n + m; i++) 
                sold_quantity[i] = 0;
                for(i=n;i<(n+m);i++)
                {
                    printf("Enter item no. %d \n",i);
                    fgets(buff, LEN, stdin);
                    buff[strcspn(buff, "\n")] = 0;
                    item[i]=strdup(buff);
                    printf("Enter price of item no. %d \n",i);
                    scanf("%d",&price[i]);
                    printf("Enter quantity of item no. %d \n",i);
                    scanf("%d",&quantity[i]);
                    getchar();
                }
                n+=m;
                break;
            }
            case 'r':
            {
                printf("Enter item number to be removed \n");
                scanf("%d",&m);
                getchar();
                free(item[m]);
                for(i=m;i<n-1;i++)
                {
                    item[i]=item[i+1];
                    price[i]=price[i+1];
                    quantity[i]=quantity[i+1];
                    sold_quantity[i] = sold_quantity[i+1];
                }
                item=realloc(item, (n-1)*sizeof(char*));
                price=realloc(price, (n-1)*sizeof(int));
                quantity=realloc(quantity, (n-1)*sizeof(int));
                sold_quantity = realloc(sold_quantity, (n - 1) * sizeof(int));
                n--;
                break;
            }
            case 'q':
            {
                for(i=0;i<n;i++)
                {
                    printf("%d: %s Rs %d %d\n", i, item[i], price[i], quantity[i]);
                }
                break;
            }
            case 't':
            {
                printf("Enter item number sold \n");
                scanf("%d",&m);
                getchar();
                if(m<0 || m>=n)
                printf("Invalid item number \n");
                else 
                {
                printf("Enter quantity sold \n");
                scanf("%d",&qty_sld);
                getchar();
                if(qty_sld<=quantity[m] && qty_sld>0)
                {
                    quantity[m]-=qty_sld;
                    sold_quantity[m]+=qty_sld;
                }
                else
                printf("Invalid quantity \n");
                }
                break;
            }
            case 's':
            {
                int total_sale=0;
                for(i=0;i<n;i++)
                {
                    total_sale+=price[i]*sold_quantity[i];
                }
                printf("Total sale = Rs %d \n",total_sale);
                break;
            }
            case 'e':
            {
                out=0;
                break;
            }
        }
    }
    for (i = 0; i < n; i++)
    free(item[i]);
    free(item);
    free(quantity);
    free(price);
    free(sold_quantity);
    return 0;
}