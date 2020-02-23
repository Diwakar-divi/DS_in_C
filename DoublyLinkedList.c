#include<stdio.h>
#include<stdlib.h>


struct node
{
    struct node *prev;
    int info;
    struct node *next;
};

struct node *createlist(struct node *start);
void addlistatend(struct node *start, int data);
struct node * addinemptylist(struct node *start, int data);
void displaylist(struct node *start);

struct node *createlist(struct node *start)
{
    int num,data,i;
    printf("enter the no. of elements to be added to list = ");
    scanf("%d",&num);
    start = NULL;

    if(num == 0)
    {
        return start;
    }
    printf("enter first element value = ");
    scanf("%d",&data);
    start = addinemptylist(start,data);

    for(i=2;i<=num;i++)
    {
        printf("enter the next element value = ");
        scanf("%d",&data);
        addlistatend(start,data);
    }
    return start;
}

void addlistatend(struct node *start, int data)
{
    struct node *p,*temp;
    temp = (struct node *)malloc(sizeof(struct node *));
    p = start;
        while(p->next != NULL)
        {
            p = p->next;
        }    
        temp->info = data;
        p->next = temp;
        temp->next = NULL;
        temp->prev = p;
}

struct node * addinemptylist(struct node *start, int data)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node *));
    temp->info = data;
    temp->next = NULL;
    temp->prev = NULL;
    start = temp;
    return start;
}

void displaylist(struct node *start)
{
    struct node *p;
    p = start;
    printf("the elements in the list are: ");
    while(p!=NULL)
    {
        printf("%d ",p->info);
        p = p->next;
    }
    printf("\n\n");
}

void main()
{
    struct node *start = NULL;
    int choice,data,after,before;

    start = createlist(start);

    while(1)
    {
    printf("select the option\n");
    printf("1. display\n");
    printf("2. addatbeginning\n");
    printf("3. addatend\n");
    printf("4. addafter\n");
    printf("5. addbefore\n");
    printf("6. deletenode\n");
    printf("7. reverse\n");
    printf("8. addinemptylist\n");
    printf("9. quit\n");
    printf("enter the option: ");
    scanf("%d",&choice);

    if(choice == 9)
    {
        break;
    }
    switch(choice)
    {
        case 1:
            displaylist(start);
            break;
        case 5:
            printf("enter the data to be added: ");
            scanf("%d",&data);
            //start = addelementatbegining(start,data);
            break;
        case 6:
            printf("enter element to be added: ");
            scanf("%d",&data);
            //addlistatend(start,data);
            break;
        case 7:
            printf("enter the element to be added: ");
            scanf("%d",&data);
            //start = addafter(start,data);
            break;
        case 8:
            printf("enter the element to be added: ");
            scanf("%d",&data);
            printf("enter the element before which data to be added: ");
            scanf("%d",&before);
            //start = addbefore(start,data,before);
            break;
        case 9:
            printf("enter the element to be added: ");
            scanf("%d",&data);
            printf("enter the position at which data to be added: ");
            scanf("%d",&before);
            //start = addatposition(start,data,before);
            break;
        case 10:
            printf("enter the element to be deleted: ");
            scanf("%d",&data);
            //start = deletenode(start,data);
            break;
        case 11:
            //start = reverse(start);
            break;
        default:
            printf("invalid option selected\n");
            break;
    }
    }
}