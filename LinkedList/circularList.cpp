#include<iostream>
using namespace std;

typedef struct node{
    int data;
    struct node *next;
    node(int x){
        data = x;
        next = nullptr;
    }
} node;

//create list funcion 
void createList(int data,node* &head){
    node* tmp = new node(data);
    if(head == nullptr){
        head = tmp;
        tmp->next = head;
    }
    node* ptr = head;
    while(ptr->next!= head){
        ptr = ptr->next;
    }
    ptr->next = tmp;
    tmp->next = head;
    
}
void printList(node* &head){
    node* ptr = head;
    if(head == nullptr) return;
   do{
    cout<<ptr->data<<" ";
    ptr = ptr->next;
   }while(ptr!=head);
}
//insert at beginning
void insertAtBegin(int x,node* &head){
    node* temp = new node(x);
    node* ptr = head;
    if(head == nullptr){
        head = temp;
        temp->next = head;
        return;
    }
    while(ptr->next!=head){
        ptr = ptr->next;
    }
    temp ->next = head;
    head = temp;
    ptr->next = head;
}
//delete head of circular list;
void deleteHead(node* &head){
    node* ptr = head;
    if(ptr == nullptr) return;
    if(ptr->next == head){
       delete ptr;
       head = nullptr;
        return;
    }
    node* target_node = head;
    head = head->next;
    while(ptr->next != target_node){
        ptr = ptr->next;
    }
    ptr->next = head;
    delete target_node;
}

//delete kth node from circular linked list
void deleteKthNode(int k,node* &head){
    if(k==1) {
        deleteHead(head);
        return;
    }
    int count = 1;
    node* ptr = head;
    while(ptr->next!=head){
        if(count == k-1){
            node* temp = ptr->next;
            ptr->next = ptr->next->next;
            delete temp;
            return;
        }
        ptr = ptr->next;
        count++;
    }
}

int main(){
    node* head=nullptr;
    int x;
    cin>>x;
    while(x--){
        int val;
        cin>>val;
        createList(val,head);

    }
    cout<<"Delete kth node k = ";
    int k;
    cin>>k;
    deleteKthNode(k,head);
    cout<<"\n List : ";
    printList(head);
}