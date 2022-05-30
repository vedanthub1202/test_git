#include<stdio.h>
#include<stdlib.h>

struct node * f = NULL;
struct node * r = NULL;

struct node
{
    int data;
    struct node * next;
};

void display(struct node *ptr)
{
    while(ptr!= NULL)
    {
        printf("%d -> ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void enqueue(int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if(n==NULL)
    printf("Queue is Full\n");
    else{
        n->data = val;
        n->next = NULL;
        if(f==NULL)
        {
            f=r=n;
        }
        else{
            r->next= n;
            r = n;
        }
    }
}

int dequeue()
{
    int val = -1;
    struct node * ptr;
    if(f==NULL)
    printf("Queue is Empty\n");
    else{
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}

int main(int argc, char const *argv[])
{
    int o,v,m;

    m:

    printf("------------OPTIONS------------\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    printf("Enter the option you want : ");
    scanf("%d",&o);

    switch (o)
    {
    case 1:
        printf("enter the value you want to enqueue\n");
        scanf("%d",&v);
        enqueue(v);
        goto m;
        break;

    case 2:
        v = dequeue();
        goto m;
        break;

    case 3:
        display(f);
        goto m;
        break;

    case 4:
        break;
    
    default:
        break;
    }
    return 0;
}
