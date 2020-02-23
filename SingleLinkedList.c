#include<stdio.h>
#include<stdlib.h>


struct node
{
    int info;
    struct node *link;
};

void displaylist(struct node *start);
void displaycount(struct node *start);
void searchelement(struct node *start);
void addatend(struct node*start,int data);
struct node *addafter(struct node * start, int data);
struct node *addbefore(struct node * start,int data,int x);
struct node *addelementatbegining(struct node *start,int data);
struct node *addatposition(struct node *start,int data,int x);
struct node *createlist(struct node *start);
struct node *deletenode(struct node *start,int data);
void addlistatend(struct node *start, int data);
struct node *reverse(struct node *start);

void main()
{
    struct node *start = NULL;
    int choice,data,after,before;

    start = createlist(start);

    while(1)
    {
    printf("select the option\n");
    printf("1. quit\n");
    printf("2. display\n");
    printf("3. count\n");
    printf("4. search element\n");
    printf("5. addatbeginning\n");
    printf("6. addatend\n");
    printf("7. addafter\n");
    printf("8. addbefore\n");
    printf("9. addatposition\n");
    printf("10. deletenode\n");
    printf("11. reverse\n");
    printf("enter the option: ");
    scanf("%d",&choice);

    if(choice == 1)
    {
        break;
    }
    switch(choice)
    {
        case 2:
            displaylist(start);
            break;
        case 3:
            displaycount(start);
            break;
        case 4:
            searchelement(start);
            break;
        case 5:
            printf("enter the data to be added: ");
            scanf("%d",&data);
            start = addelementatbegining(start,data);
            break;
        case 6:
            printf("enter element to be added: ");
            scanf("%d",&data);
            addlistatend(start,data);
            break;
        case 7:
            printf("enter the element to be added: ");
            scanf("%d",&data);
            start = addafter(start,data);
            break;
        case 8:
            printf("enter the element to be added: ");
            scanf("%d",&data);
            printf("enter the element before which data to be added: ");
            scanf("%d",&before);
            start = addbefore(start,data,before);
            break;
        case 9:
            printf("enter the element to be added: ");
            scanf("%d",&data);
            printf("enter the position at which data to be added: ");
            scanf("%d",&before);
            start = addatposition(start,data,before);
            break;
        case 10:
            printf("enter the element to be deleted: ");
            scanf("%d",&data);
            start = deletenode(start,data);
            break;
        case 11:
            start = reverse(start);
            break;
        default:
            printf("invalid option selected\n");
            break;
    }
    }
}

struct node *createlist(struct node *start)
{
    int num,data,i;
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node *));
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

    return start;
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
}

void displaylist(struct node *start)
{
    struct node *p;
    p = start;
    printf("the elements in the list are: ");
    while(p!=NULL)
    {
        printf("%d ",p->info);
        p = p->link;
    }
    printf("\n\n");
}

void displaycount(struct node *start)
{
    struct node *p;
    int cou = 0;
    p = start;
    printf("the no. of elements in the list are: ");
    while(p!=NULL)
    {
        cou++;
        p = p->link;
    }
    printf("%d\n\n",cou);
}

void searchelement(struct node *start)
{
    struct node *p;
    int ele;
    int cou = 1;
    p = start;
    printf("enter the element to be searched: ");
    scanf("%d",&ele);
    while(p!=NULL)
    {
        if(p->info == ele)
        {
            break;
        }
        cou++;
        p = p->link;
    }
    if(p == NULL)
    {
        printf("element not found in list");
    }
    else
    {
        printf("%d is found at position %d",ele,cou);
    }
    printf("\n\n");
}

struct node *addelementatbegining(struct node *start,int data)
{
    int num,i;
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node *));
    
    temp->info = data;
    temp->link = start;
    start = temp;
    printf("\n");
    return start;
}

struct node *addafter(struct node * start,int data)
{
    int after;
    struct node *temp;
    struct node *p;
    p = start;
    temp = (struct node *)malloc(sizeof(struct node *));
    printf("enter the element after which data to be added: ");
    scanf("%d",&after);
    while(p!=NULL)
    {
        if(p->info == after)
            break;
        p = p->link;
    }
    if(p == NULL)
    {
        printf("element %d is not present in list\n\n",after);
    }
    else
    {
        temp->info = data;
        temp->link = p->link;
        p->link = temp;
    }
    return start;
}

struct node *addbefore(struct node * start,int data,int x)
{
    //int after;
    struct node *temp;
    struct node *p;
    p = start;
    temp = (struct node *)malloc(sizeof(struct node *));
    //printf("enter the element after which data to be added: ");
    //scanf("%d",&after);
    if(p->info == x)
    {
        start = addelementatbegining(start,data);
        return start;
    }
    while(p->link != NULL)
    {
        if(p->link->info == x)
            break;
        p=p->link;
    }
    if(p == NULL)
    {
        printf("element %d not present in list\n\n",x);
    }
    else
    {
        temp->info = data;
        temp->link = p->link;
        p->link = temp;
    }
    return start;
}

struct node *addatposition(struct node *start,int data,int x)
{
    int i;
    struct node *temp;
    struct node *p;
    p = start;
    temp = (struct node *)malloc(sizeof(struct node *));
    //printf("enter the element after which data to be added: ");
    //scanf("%d",&after);
    if(x == 1)
    {
        temp->info = data;
        temp->link = start;
        start = temp;
        return start;
    }
    for(i=1;i<x-1 & p!=NULL;i++)
    {
        p=p->link;
    }
    if(p == NULL)
    {
        printf("element %d not present in list\n\n",x);
    }
    else
    {
        temp->info = data;
        temp->link = p->link;
        p->link = temp;
    }
    return start;
}

struct node *deletenode(struct node *start,int data)
{
    struct node *temp, *p;
    p = start;
    if( p== NULL)
    {
        printf("list is empty\n");
        return start;
    }
    if(p->info == data)
    {
        temp = start;
        start = start->link;
        free(temp);
    }
    else
    {
        while(p->link != NULL)
        {
            if(p->link->info == data)
                break;
            p=p->link;
        }
        if(p==NULL)
        {
            printf("%d is not present in list\n",data);
        }
        else
        {
            temp = p->link;
            p->link = temp->link;
            free(temp);
        }  
    }
    return start;
}

struct node *reverse(struct node *start)
{
    struct node *prv,*ptr,*nxt;
    prv = NULL;
    ptr = start;

    while(ptr!=NULL)
    {
        nxt = ptr->link;
        ptr->link = prv;
        prv = ptr;
        ptr = nxt;
    }
    start = prv;
    return start;
}