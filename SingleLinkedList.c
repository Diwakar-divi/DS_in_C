#include<stdio.h>
#include<stdlib.h>


struct node
{
    int info;
    struct node *link;
};

void displaylist(struct node *start);
struct node *createlist(struct node *start);
void addlistatend(struct node *start, int data);

void main()
{
    struct node *start;
    start = NULL;

     start = createlist(start);
     displaylist(start);
}

struct node *createlist(struct node *start)
{
    int num,data,i;
    struct node *temp;

    printf("enter the no. of elements to be added to list = ");
    scanf("%d",&num);

    if(num == 0)
    {
        return start;
    }
    printf("enter first element value = ");
    scanf("%d",&data);
    temp->info = data;
    temp->link = NULL;
    start = temp;

    for(i=2;i<=num;i++)
    {
        printf("enter the next element value = ");
        scanf("%d",&data);
        addlistatend(start,data);
    }
}

void addlistatend(struct node *start, int data)
{
    struct node *p,*temp;
    temp = (struct node *)malloc(sizeof(struct node *));
    p = start;
    temp->info = data;
    temp->link = NULL;
    if(p->link == NULL)
    {
        temp->info = data;
        p->link = temp;
    }
    else
    {
        while(p->link!=NULL)
        {
            p=p->link;
        }
        temp->info = data;
        p->link = temp;
        /* code */
    }
    start = p;
}

void displaylist(struct node *start)
{
    struct node *p;
    p = start;
    while(p!=NULL)
    {
        printf("%d ",p->info);
    }
}