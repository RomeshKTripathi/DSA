#include<iostream>
using namespace std;

typedef struct node{
    int data;
    struct node *prev;
    struct node *next;
    node(int val){
        data = val;
        prev = nullptr;
        next = nullptr;
    }
} node;

//createion of Doubly linked list,
//by adding newly created nodes at the end of the list.
void createList(int x,node* &head){
    node* temp = new node(x);
    node* ptr = head;
    if(head == nullptr){
        head = temp;
        return;
    }
    while(ptr->next){
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->prev = ptr;
    return;
}

//Print doubly linked list.

void printList(node* head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    return ;
}

//Print list in reverse order
void printReverseList(node* head){
    if(head == nullptr) return;

    while(head->next){
        head = head->next;
    }
    while(head){
        cout<<head->data<<" ";
        head = head->prev;
    }
}
//Insert a new node at beginning
void insertAtBegin(int x,node* &head){
    node* temp = new node(x);
    if(head == nullptr){
        head = temp;
        return;
    }
    temp->next = head;
    head->prev = temp;
    head = temp;
}
//Insert a new node at End of the list
void insertAtEnd(int x,node* &head){
    node* temp = new node(x);
    node* ptr = head;
    if(ptr == nullptr){
        head = temp;
        return;
    }
    while(ptr->next){
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->prev=ptr;
}

//Reverse List
void reverseList(node* &head){
   node* temp = nullptr;
   if(head == nullptr or head->next == nullptr )return;
   while(true){
        temp = head->next;
        head->next = head->prev;
        head->prev = temp;
        if(head->prev)
        head = head->prev;
        else return;
   }
}
//delete first node of list;
void deleteFirstNode(node* &head){
    if(head == nullptr)return ;
    if(head->next == nullptr){
        delete head;
        head = nullptr;
        return;
    }
    node* temp = head;
    head = head->next;
    delete temp;
    head->prev = nullptr;
}
//delete last node of list
void deleteLastNode(node* &head){
    if(head == nullptr)return;
    if(head->next == nullptr) {
        delete head;
        head = nullptr;
    }
    node* ptr = head;
    while(ptr->next){
        ptr = ptr->next;

    }
    ptr = ptr->prev;
    delete ptr->next;
    ptr->next = nullptr;
}


int main(){
    node* head = nullptr;
    int x;
    cout<<"No of elements:"<<endl;
    cin>>x;
    while(x--){
        int val;
        cin>>val;
        createList(val,head);
    }
    cout<<" List values :";
    printList(head);
    cout<<"\nList values Reverse:";
    printReverseList(head);
    cout<<"\nInsert at beginning:";
    insertAtBegin(8,head);
    printList(head);
    cout<<"\nInsert at End:";
    insertAtEnd(9,head);
    printList(head);
    cout<<"\nNow next ";
    reverseList(head);
    printList(head);
    deleteFirstNode(head);
    cout<<"\nDelete first node: ";
    printList(head);
    deleteFirstNode(head);
    cout<<"\nDelete first node: ";
    printList(head);
    cout<<"\ndelete last node :";
    deleteLastNode(head);
    printList(head);
}
