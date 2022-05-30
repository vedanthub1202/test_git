/*Write a C program of circular linked list and perform insertion deletion and search operations
NAME: VEDANT ABHAY JOSHI
PRN: 2020BTEIT00045
BATCH: S3
DSA LAB*/
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void displaylinkedlist(struct node *head)
{
    struct node * ptr = head;
    do
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    } while (ptr!=head);
}

struct node * delete_at_first(struct node *head)
{
    struct node * p = head;
    int i=0,index=1;

    while (i!=index)
    {
        p=p->next;
        i++;
    }
    struct node * ptr = p->next;
    p->next = ptr->next;
    free(ptr); 
    return head;
}

void  delete_at_end(struct node *head)
{
    struct node * p = head;
    struct node * q= head->next;
    while(q->next!=head)
    {
        p=p->next;
        q=q->next;
    }
    p->next =head;
}

struct node * insert_at_previous(struct node *head, int m, int i)
{
    struct node * ptr = (struct node *) malloc(sizeof(struct node));
    struct node * p = head;
    int x=0;

    while(x!=m-1)
    {
        p=p->next;
        x++;
    }
    ptr->data = i;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct node* deleteatindex(struct node *head, int index)
{
    struct node * p = head;
    int i=0;

    while (i!=index-1)
    {
        p=p->next;
        i++;
    }
    struct node * ptr = p->next;
    p->next = ptr->next;
    free(ptr); 
    return head;
}

struct node * insert_front(struct node *head, int i)
{
    struct node *p = head;
	struct node *a =(struct node *)malloc(sizeof(node));
	a->data=i;
    while(p->next!=head)
    {
        p= p->next;
    }
    p->next = a;
    a->next = head;
    return a;
}

struct node * insert_end(struct node *head, int i)
{
    struct node *p = head;
	struct node *a =(struct node *)malloc(sizeof(node));
	a->data=i;
    while(p->next!=head)
    {
        p= p->next;
    }
    p->next = a;
    a->next = head;
    return head;
}

struct node * delete_previous(struct node *head, int i)
{
    struct node * p = head;
    struct node * ptr = head->next;
    int x=1;
    while(x!=i-1)
    {
        p= p->next;
        ptr = p->next;
        x++;
    }
    p->next = ptr->next;
    return head;
}

void search(struct node *head, int i)
{
    struct node * p = head;
    while(p->next!=head)
    {
        if(p->data==i)
        {
        printf("The digit is in the list\n");
        break;
        }
        else
        printf("The given digit is not in the list\n");
        p= p->next;
    }
}

int main(int argc, char const *argv[])
{
    int n,i,s,m;
    struct node * head;
    struct node * second;
    struct node * third;
    struct node * fourth;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    head->data=12;
    head->next=second;

    second->data=122;
    second->next=third;

    third->data=129;
    third->next=fourth;

    fourth->data=1212;
    fourth->next=head;

    displaylinkedlist(head);
    printf("\n");
    s:
    printf("Choose the actions you want to perform:\n");
    printf("1. insert at front\n");
    printf("2. insert at end\n");
    printf("3. insert at given position\n");
    printf("4. delete at front\n");
    printf("5. delete at end\n");
    printf("6. delete at given position\n");
    printf("7. search the given no.\n");
    printf("8. display list\n");
    printf("9. exit\n");
    scanf("%d",&n);

    switch (n)
    {
    case 1:
        printf("Enter the value you want to insert\n");
        scanf("%d",&i);
        head = insert_front(head, i);
        goto s;
        break;

    case 2:
        printf("Enter the value you want to insert\n");
        scanf("%d",&i);
        head = insert_end(head, i);
        goto s;
        break;

    case 3:
        printf("Enter the value you want to insert\n");
        scanf("%d",&i);
        printf("Enter the position you want to insert\n");
        scanf("%d",&m);
        head = insert_at_previous(head, m, i);
        goto s;
        break;

    case 4:
        head = delete_at_first(head);
        goto s;
        break;

    case 5:
        delete_at_end(head);
        goto s;
        break;

    case 6:
        printf("Enter the position you want to delete\n");
        scanf("%d",&i);
        head = delete_previous(head, i);
        goto s;
        break;

    case 7:
        printf("Enter the no. you want to search in the list\n");
        scanf("%d",&i);
        search(head, i);
        goto s;
        break;
               
    case 8:
        displaylinkedlist(head);
        goto s;
        break;

    case 9:
        break;
    
    default:
        break;
    }
    return 0;
}
