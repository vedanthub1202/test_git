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

struct node * searchIter(struct node* root, int key){
    while(root!=NULL){
        if(key == root->data){
            return root;
        } 
        else if(key<root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return NULL;
}

struct node* deleteIterative(struct node* root, int key)
{
    struct node* curr = root;
    struct node* prev = NULL;
 
    // Check if the key is actually
    // present in the BST.
    // the variable prev points to
    // the parent of the key to be deleted.
    while (curr != NULL && curr->data != key) {
        prev = curr;
        if (key < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }
 
    if (curr == NULL) {
        printf("%d is not found in provided BST\n",&key);
        return root;
    }
 
    // Check if the node to be
    // deleted has atmost one child.
    if (curr->left == NULL || curr->right == NULL) {
 
        // newCurr will replace
        // the node to be deleted.
        struct node* newCurr;
 
        // if the left child does not exist.
        if (curr->left == NULL)
            newCurr = curr->right;
        else
            newCurr = curr->left;
 
        // check if the node to
        // be deleted is the root.
        if (prev == NULL)
            return newCurr;
 
        // check if the node to be deleted
        // is prev's left or right child
        // and then replace this with newCurr
        if (curr == prev->left)
            prev->left = newCurr;
        else
            prev->right = newCurr;
 
        // free memory of the
        // node to be deleted.
        free(curr);
    }
 
    // node to be deleted has
    // two children.
    else {
        struct node* p = NULL;
        struct node* temp;
 
        // Compute the inorder successor
        temp = curr->right;
        while (temp->left != NULL) {
            p = temp;
            temp = temp->left;
        }
 
        // check if the parent of the inorder
        // successor is the curr or not(i.e. curr=
        // the node which has the same data as
        // the given data by the user to be
        // deleted). if it isn't, then make the
        // the left child of its parent equal to
        // the inorder successor'd right child.
        if (p != NULL)
            p->left = temp->right;
 
        // if the inorder successor was the
        // curr (i.e. curr = the node which has the
        // same data as the given data by the
        // user to be deleted), then make the
        // right child of the node to be
        // deleted equal to the right child of
        // the inorder successor.
        else
            curr->right = temp->right;
 
        curr->data = temp->data;
        free(temp);
    }
    return root;
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

    m:
    printf("-----OPTIONS-------\n");
    printf("1. Inorder Transversal\n");
    printf("2. Insert\n");
    printf("3. delete\n");
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
        deleteIterative(p, key);
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
