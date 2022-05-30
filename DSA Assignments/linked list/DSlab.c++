#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
};


void append(node** head, int data){
    node* new_node = new node();
    node* last = *head;
    new_node->data = data;
    if(*head == NULL){
        *head = new_node;
        return;
    }
    while(last->next != NULL){
        last = last->next;
    }
    last->next = new_node;
    return;
}

void insertToNext(node* prev_node, int data){
    if(prev_node == NULL){
        cout << "No previous node";
    }
    node* new_node = new node();
    new_node->data = data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void deleteNode(node** head, int data){
    node* temp = *head;
    node* prev = NULL;

    if(temp != NULL && (temp->data == data)){
        *head = temp->next;
        delete temp;
        return;
    }
    else{
        while(temp != NULL && temp->data != data){
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        delete temp;
    }
}

bool search(node* head, int data){
    while(head !=NULL){
        if(data == head->data){
            return true;
        }
        head = head->next;
    }
    return false;
}

void display(node* head){
    while(head != NULL){
        cout << head->data << "->";
        head = head->next;
    }
    return;
} 


int main(){
    
    node* head = NULL;
    append(&head , 9);
    append(&head , 3);
    append(&head , 8);
    append(&head , 1);
    append(&head , 7);

    display(head);
    cout << endl << endl;

    insertToNext(head->next->next , 27);

    display(head);
    cout << endl << endl;

    deleteNode(&head , 3);

    display(head);
    cout << endl << endl;

    bool val = search(head, 8);
    cout << val;


    return 0;
}