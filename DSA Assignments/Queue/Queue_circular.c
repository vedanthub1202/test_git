#include<stdio.h>
#include<stdlib.h>

struct circularqueue
{
    int size,f,r;
    int *arr;
};

int isEmpty(struct circularqueue *q)
{
    if(q->r == q->f)
    return 1;
    return 0;
}

int isFull(struct circularqueue *q)
{
    if((q->r+1)%q->size == q->f)
    return 1;
    return 0;
}

void enqueue(struct circularqueue *q, int val){
    if(isFull(q)){
        printf("This Queue is full\n");
    }
    else{
        q->r = (q->r+1)%q->size;
        q->arr[q->r] = val;
        printf("Enqueued element: %d\n", val);
    }
}

int dequeue(struct circularqueue *q){
    int a=0;
    if(isEmpty(q)){
        printf("This Queue is empty\n");
    }
    else{
        q->f = (q->f+1)%q->size;
        a = q->arr[q->f];
        return a;
    }
    return 0;
}

void display(struct circularqueue *q)
{
    for(int i=q->f+1;i<q->r+1;i++)
    {
        printf("%d ->",q->arr[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    struct circularqueue q;
    int v,o,m;
    q.size = 10;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

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
        enqueue(&q ,v);
        goto m;
        break;

    case 2:
        v = dequeue(&q);
        printf("%d is deleted\n",v);
        goto m;
        break;

    case 3:
        display(&q);
        goto m;
        break;

    case 4:
        break;
    
    default:
        break;
    }
    return 0;
}
