#include<stdio.h>
#include<stdlib.h>

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

void insert(struct node *root, int key){
   struct node *prev = NULL;
   while(root!=NULL){
       prev = root;
       if(key==root->data){
           printf("Cannot insert %d, already in BST", key);
           return;
       }
       else if(key<root->data){
           root = root->left;
       }
       else{
           root = root->right;
       }
   }
   struct node* new = createnode(key);
   if(key<prev->data){
       prev->left = new;
   }
   else{
       prev->right = new;
   }
}

struct node *inOrderPredecessor(struct node* root){
    root = root->left;
    while (root->right!=NULL)
    {
        root = root->right;
    }
    return root;
}

struct node *deletenode(struct node * root, int value){

    struct node* iPre;
    if (root == NULL){
        return NULL;
    }
    if (root->left==NULL&&root->right==NULL){
        free(root);
        return NULL;
    }

    //searching for the node to be deleted
    if (value < root->data){
        root->left = deletenode(root->left,value);
    }
    else if (value > root->data){
        root->right = deletenode(root->right,value);
    }
    //deletion strategy when the node is found
    else{
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deletenode(root->left, iPre->data);
    }
    return root;
}

struct node * search(struct node * root, int key)
{
    if(root==NULL)
    return NULL;
    if(root->data==key)
    {
        return root;
    }
    else if(key<root->data)
    {
        return search(root->left,key);
    }
    else if(key>root->data)
    {
        return search(root->right, key);
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
    int o,m,key;
    struct node *p = createnode(5);
    struct node *p1= createnode(3);
    struct node *p2 = createnode(6);
    struct node *p3 = createnode(1);
    struct node *p4 = createnode(4);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    // if(isBST(p))
    // {
    //     printf("It is BST\n");
    // }
    // else
    // {
    //     printf("It is not BST\n");
    // }

    m:
    printf("-----OPTIONS-------\n");
    printf("1. Inorder Transversal\n");
    printf("2. Insert\n");
    printf("3. delete\n");
    printf("4. Search\n");
    scanf("%d",&o);

    switch (o)
    {
    case 1:
        printf("Inorder Transversal:");
        inOrder(p);
        printf("\n");
        goto m;
        break;

    case 2:
        printf("Enter the number you want to insert\n");
        scanf("%d",&key);
        insert(p, key);
        goto m;
        break;

    case 3:
        printf("Enter the value you want to delete\n");
        scanf("%d",&key);
        deletenode(p, key);
        printf("Inorder Transversal:");
        inOrder(p);
        printf("\n");
        goto m;
        break;

    case 4:
        printf("Enter the number you want to search\n");
        scanf("%d",&key);
        struct node *n =search(p,key);
        if(n!=NULL)
        printf("Found");
        else
        printf("Not found");
        goto m;
        break;
    
    default:
        break;
    }

    return 0;
}
