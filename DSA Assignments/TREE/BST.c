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

struct node *inOrderPredecessor(struct node* root)
{
    root = root->left;
    while (root->right!=NULL)
    {
        root = root->right;
    }
    return root;
}

struct node *deletenode(struct node * root, int value)
{
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


// struct node * searchIter(struct node* root, int key){
//     while(root!=NULL){
//         if(key == root->data){
//             return root;
//         } 
//         else if(key<root->data){
//             root = root->left;
//         }
//         else{
//             root = root->right;
//         }
//     }
//     return NULL;
// }

int isBST(struct  node* root){
    static struct node *prev = NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
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

void insert(struct node * root, int key)
{
    struct node * prev = NULL;
    while(root!=NULL)
    {
        prev =root;
        if(key==root->data)
        printf("The digit is already in BST\n");
        return ;
        if(key<root->data)
        {
            root = root->left;
        }
        else
        root = root->right;
    }
    struct node * new = createnode(key);
    if(key<prev->data)
    prev->left = new;
    prev->right = new;
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

    if(isBST(p))
    {
        printf("It is BST\n");
    }
    else
    {
        printf("It is not BST\n");
    }

    m:
    printf("-----OPTIONS-------\n");
    printf("1. Preorder Transversal\n");
    printf("2. Postorder Transversal\n");
    printf("3. Inorder Transversal\n");
    printf("4. Search\n");
    printf("5. delete\n");
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

    case 5:
        printf("Enter the value you want to delete\n");
        scanf("%d",&key);
        deletenode(p, key);
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
