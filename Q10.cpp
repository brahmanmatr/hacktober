#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int coeff;
    int pow;
    struct node * nextptr;
}*stnode;

void Circularcreation(int n);
void displayList();

void main()
{
    int n;
    stnode = NULL;
    printf(" Input the number of nodes : ");
    scanf("%d", &n);
 
    Circularcreation(n); 
    displayList();
    
}

void Circularcreation(int n)
{
    int i, coeff,pow;
    struct node *preptr, *newnode;

    if(n >= 1)
    {
        stnode = (struct node *)malloc(sizeof(struct node));

        printf(" Enter coeffecient and power :\n ");
        scanf("%d %d", &coeff,&pow);
        stnode->coeff = coeff;
        stnode->pow = pow;
        stnode->nextptr = NULL;
        preptr = stnode;
        for(i=2; i<=n; i++)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            printf(" Enter coeffecient and power :\n ");
            scanf("%d %d", &coeff,&pow);
            newnode->coeff = coeff;
            newnode->pow = pow;
            newnode->nextptr = NULL;	
            preptr->nextptr = newnode;	
            preptr = newnode;   		
        }
        preptr->nextptr = stnode; 		
    }
}

void displayList()
{
    struct node *tmp;
    int n = 1;

    if(stnode == NULL)
    {
        printf(" No data found in the List yet.");
    }
    else
    {
        tmp = stnode;
        printf("The polynomial is :\n");

        do {
            printf("%dx^%d", tmp->coeff, tmp->pow);

            tmp = tmp->nextptr;
            if(tmp != stnode)
            printf(" + ");
            n++;
        }while(tmp != stnode);
    }
}

