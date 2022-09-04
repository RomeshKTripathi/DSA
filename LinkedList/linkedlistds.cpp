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

//function to insert a node at given position 
//parameter-> data, position starting from 1, head node 

void insertAt(int data,int pos,node* &head){
    node* temp = new node(data);
        if(pos < 1) return ;
        if(pos == 1) {
            temp->next = head;
            head = temp;
            return;
        }
    node* ptr = head;
    int i = 1;
    while(ptr->next and i<pos-1){
        ptr = ptr->next;
        i++;
    }
    temp->next = ptr->next;
    ptr->next = temp;


}
//1->2->3->4->5

//function to search in a linked list

int searchList(int key,node* &head){
    node* ptr = head;
    int count = 0;
    while(ptr){
        count++;
        if(ptr->data == key){
            return count;
        }
        ptr = ptr->next;
    }
    return -1;
}

//function to search in list recursively
int searchListRecursive(int key,node* head){
    if(head == nullptr) return -1;
    if(head->data == key) return 1;
    int res = searchListRecursive(key,head->next);
    if(res == -1)
    return -1;
    else return res+1;
}

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
    insertAt(6,1,head);
    cout<<"After inserting at 3rd position\n";
    printList(head);
    cout<<"search in a list\nEnter key to search";
    int key;
    cin>>key;
    cout<<searchListRecursive (key,head);
    return 0;
}