#include <stdio.h>
#include <stdlib.h>

int isFull(struct queue *);
int isEmpty(struct queue *);

struct queue{
    int size,f,r;
    int *arr;
};

void enqueue(struct queue *q, int val){
    if(isFull(q)){
        printf("This Queue is full\n");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
        printf("Enqueued element: %d\n", val);
    }
}

int dequeue(struct queue *q){
    int a = 0;
    if(isEmpty(q)){
        printf("This Queue is empty\n");
    }
    else{
        q->f++;
        a = q->arr[q->f]; 
    }
    return a;
}

void display(struct queue *q)
{
    for(int i=q->f+1;i<q->r+1;i++)
    {
        printf("%d ->",q->arr[i]);
    }
    printf("\n");
}

int isEmpty(struct queue *q)
{
    if(q->r == q->f)
    return 1;
    return 0;
}

int isFull(struct queue *q)
{
    if(q->r == q->size-1)
    return 1;
    return 0;
}

int main(int argc, char const *argv[])
{
    struct queue q;
    int v,o,m;
    q.size = 10;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    m:

    printf("-------------OPTIONS------------\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    printf("Enter the option you want : \n");
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
