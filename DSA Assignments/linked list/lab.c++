#include <iostream> 
using namespace std; 

class Node 
{ 
public: 
int data; 
Node *next; 
}; 

class linkedList 
{ 
private: 
Node *first; 
public: 
linkedList() 
{ 
first = NULL; 
 } 

linkedList(int A[], int n); 
~linkedList(); 
void display(); 
int count(); 
int Delete(int pos); 
void insert(int index, int x); 
}; 

 linkedList::linkedList(int A[], int n) 

{ 
Node *last, *t; 

 first = new Node; 
 first->data = A[0]; 
 first->next = NULL; 
 last = first; 

 for (int i = 1; i < n; i++) 

{ 
t = new Node; 
t->data = A[i]; 
t->next = NULL; 
last->next = t; 
last = t; 

 } 

} 

linkedList::~linkedList() 

{ 

Node *p = first; 
 while (first) 

{ 
first = first->next; 

delete p; 

 p = first; 

} 

} 

 

void linkedList::display() 

{ 
 Node *p = first; 

while (p) 

{ 

cout << p->data << " "; 

 p = p->next; 
 } 

} 

int linkedList::count() 

{ 
 Node *p = first; 

 int c = 0;
 while (p) 

{ 

 c++; 

 p = p->next; 

 } 

 return c; 

} 

 

int linkedList::Delete(int pos) 

{ 

 Node *p = first; 

 Node *q = NULL; 

 int x = -1; 

if (pos < 1 || pos > count()) 

{ return x; 

 } 

 
 if (pos == 1) 

{ 

 q = first; 

 first = first->next; 

 x = first->data;
 delete q; 

 return x; 

} 
 else 

 { 

 for (int i = 0; i < pos - 1; i++) 

 { 

  q = p; 

 p = p->next; 

 } 

 

 q->next = p->next; 

 x = p->data; 
delete p; 

 

 return x; 

 } 

} 

 

void linkedList::insert(int index, int x) 

{ 

 Node *p = first; 

 Node *t; 

 t = new Node; 

 

 t->data = x; 

 

 if (index < 0 || index > count()) 

 { 

 cout << "invalid input" << endl; 

 } 

else if (index == 0) 

 { 

 t->next = first; 

  first = t; 

 } 

 else 

{ 

 

for (int i = 0; i < index - 1; i++) 

{ 

p = p->next; 

} 

 

t->next = p->next; 

p->next = t; 

} 

} 

 

int main() 

{ 

 int a[] = {46, 9, 4, 32, 34, 76, 47, 3}; 

 linkedList l(a, 8); 

 

 printf("Displaying the element\n"); 

 l.display(); 

 cout << "\n"; 

 

 printf("Inserting the element\n"); 

 l.insert(5, 43); 

 l.display(); 

 

 cout << "\n"; 

printf("Deleting an element\n"); 

 l.Delete(4); 

 l.display(); 

 

 return 0; 

}