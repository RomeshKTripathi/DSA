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

void createList(int x,node* &head){
    node* tmp = new node(x);
    node* ptr = head;
    if(head == nullptr)
    {
        head = tmp;
        return;
    }
    while(ptr->next){
        ptr = ptr->next;
    }
    ptr->next = tmp;
}

void printList(node* head){
    node* ptr = head;
    while(ptr){
        cout<<ptr->data<<endl;
        ptr = ptr->next;
    }
}

void deleteFirstNode(node* &head){
    if(head){
        head = head->next;
    }
}
void deleteLastNode(node* &head){
    node* tmp = head;
    if(tmp == nullptr) return;
    if(tmp->next == nullptr) {
        delete head;
        return;
    }
    while(tmp->next->next){
        tmp = tmp->next;
    }
    node* deleteMe = tmp->next;
    tmp->next = nullptr;
    delete deleteMe;
}
//1->2->3->4->5
int main(){
    int n,x;
    node* head = nullptr;
    cout<<"No of elements you want to enter";
    cin>>n;
    while(n--){
        cin>>x;
        createList(x,head);
    }
    cout<<"\nNow see your input "<<endl;
    printList(head);
    deleteFirstNode(head);
    cout<<"After deleting first node of your list:\n";
    printList(head);
    deleteLastNode(head);
    cout<<"After deleting last node of your list:\n";
    printList(head);
    return 0;
}