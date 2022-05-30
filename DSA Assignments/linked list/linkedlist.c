#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void displaylinkedlist(struct node *ptr)
{
    while(ptr!=NULL)
    {
        printf("element: %d\n", ptr->data);
        ptr= ptr->next;
    }
}

struct node * delete_at_first(struct node *head)
{
    struct node * ptr = head;
    head=head->next;
    free(ptr);
    return head;
}

struct node * delete_at_end(struct node *head)
{
    struct node * p = head;
    struct node * q= head->next;
    while(q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
        free(q);
        return head;
}

struct node * insert_at_previous(struct node *head, int index, int data)
{
    struct node * ptr = (struct node *) malloc(sizeof(struct node));
    struct node * p = head;
    int i=0;

    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->data = data;
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
    struct node *p = (struct node *) malloc(sizeof(struct node));
    p->data = i;
    p->next = head;
    return p;
}

struct node * insert_end(struct node *head, int i)
{
    struct node *p= head;
    struct node *ptr = (struct node *) malloc(sizeof(struct node));
    ptr->data= i;
    while(p->next!=NULL)
    {
        p= p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

struct node * search(struct node *head, int i)
{
    struct node *ptr= head;
    while(ptr->next!=NULL)
    {
        if(ptr->data==i)
    {
        printf("The digit is in the list\n\n\n");
        break;
    }
    else
    {
        printf("The digit is not in the list\n");
    }
    ptr=ptr->next;
    }
    return head;
}
        

int main(int argc, char const *argv[])
{
    int n,s,i,m;
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

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
    fourth->next=NULL;

    displaylinkedlist(head);
    printf("\n");
    s:
    printf("Choose the actions you want to perform:\n");
    printf("1. insert at front\n");
    printf("2. insert at end\n");
    printf("3. insert at given position\n");
    printf("4. delete at front\n");
    printf("5. delete at end\n");
    printf("6. search\n");
    printf("7. display list\n");
    printf("8. exit\n");
    scanf("%d",&n);

    switch (n)
    {
    case 1:
        printf("enter the value you want to insert\n");
        scanf("%d",&i);
        head = insert_front(head, i);
        goto s;
        break;

    case 2:
        printf("enter the value you want to insert\n");
        scanf("%d",&i);
        head = insert_end(head, i);
        goto s;
        break;

    case 3:
        printf("enter the value you want to insert\n");
        scanf("%d",&i);
        printf("enter the position you want to insert\n");
        scanf("%d",&m);
        head= insert_at_previous(head, m, i);
        goto s;
        break;

    case 4:
        head = delete_at_first(head);
        goto s;
        break;

    case 5:
        head = delete_at_end(head);
        goto s;
        break;

    case 6:
        printf("enter the value you want to search\n");
        scanf("%d",&i);
        head = search(head,i);
        goto s;
        break;

    case 7:
        displaylinkedlist(head);
        goto s;
        break;

    case 8:
        break;

    default:
        break;
    }
    return 0;
}
