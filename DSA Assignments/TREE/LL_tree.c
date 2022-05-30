#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

struct node
{
    int data;
    struct node * left;
    struct node * right;
};

struct node * createnode(int data)
{
    struct node *n;//creating node pointer
    n=(struct node *) malloc(sizeof(struct node));
    n->data=data;
    n->left = NULL;
    n->right = NULL;
}

void preOrder(struct node * root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct node * root)
{
    if(root!=NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
}

void inOrder(struct node * root)
{
    if(root!=NULL)
    {
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

int main(int argc, char const *argv[])
{
    int o,m;
    struct node *p = createnode(2);
    struct node *p1= createnode(1);
    struct node *p2 = createnode(4);
    struct node *p3 = createnode(6);
    struct node *p4 = createnode(9);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    m:
    printf("-----OPTIONS-------\n");
    printf("1. Preorder Transversal\n");
    printf("2. Postorder Transversal\n");
    printf("3. Inorder Transversal\n");
    scanf("%d",&o);

    switch (o)
    {
    case 1:
        printf("Preorder Transversal:");
        preOrder(p);
        printf("\n");
        goto m;
        break;

    case 2:
        printf("Postorder Transversal:");
        postOrder(p);
        printf("\n");
        goto m;
        break;

    case 3:
        printf("Inorder Transversal:");
        inOrder(p);
        printf("\n");
        goto m;
        break;
    
    default:
        break;
    }

    return 0;
}
