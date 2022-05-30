#include<stdio.h>
#include<stdlib.h>

struct node *top = NULL;
struct node
{
    int data;
    struct node *next;
};

int isEmpty(struct node *top)
{
    if(top==NULL)
    return 1;
    else
    return 0;
}

int isFull(struct node *top)
{
    struct node *p= (struct node *)malloc(sizeof(struct node));
    if(p==NULL)
    return 1;
    else
    return 0;
}

struct node * push(struct node *top, int val)
{
    if(isFull(top))
    {printf("stack overflow\n");}
    else
    {
    struct node * p = (struct node *)malloc(sizeof(struct node));
    p->data = val;
    p->next = top;
    top = p;
    }
    return top;
}

int pop(struct node * top)
{
    if(isEmpty(top))
    printf("Stack underflow\n");
    else
    {
        struct node *p = top;
        top = top->next;
        int x= p->data;
        free(p);
        return x;
    }
}

int peek(int n)
{
    struct node * p= top;
    for(int i=0;(i<n-1 && p!=NULL);i++)
    {
        p = p->next;
    }
    if(p!=NULL)
    return p->data;
    else 
    return -1;
}

void displaylinkedlist(struct node *ptr)
{
    while(ptr!=NULL)
    {
        printf("element: %d\n", ptr->data);
        ptr= ptr->next;
    }
}

int main(int argc, char const *argv[])
{
    int o,m,n,e;
    
    m:
    printf("Choose from the option\n");
    printf("1. push\n");
    printf("2. pop\n");
    printf("3. peek\n");
    printf("4. isEmpty\n");
    printf("5. isFull\n");
    printf("6. display\n");
    printf("7. exit\n");
    scanf("%d",&o);

    switch (o)
    {
    case 1:
        printf("enter the no. you want to push\n");
        scanf("%d",&n);
        top = push(top, n);
        goto m;
        break;

    case 2:
        e = pop(top);
        printf("popped element is %d",&e);
        goto m;
        break;

    case 3:
        printf("enter the position you want\n");
        scanf("%d",&n);
        int y =peek( n);
        printf("the element you want to peek is %d",y);
        goto m;
        break;

    case 4:
        if(isEmpty(top))
        printf("the stack is empty");
        else
        printf("the stack is not empty");
        goto m;
        break;

    case 5:
        if(isFull(top))
        printf("the stack is Full");
        else
        printf("the stack is full");
        goto m;
        break;

    case 6:
        displaylinkedlist(top);
        goto m;
        break;

    case 7:
        break;
    
    default:
        break;
    }
    return 0;
}
