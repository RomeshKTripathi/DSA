#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
    node(int x)
    {
        data = x;
        next = nullptr;
    }
} node;
// function to create List
void createList(int x, node *&head)
{
    node *tmp = new node(x);
    node *ptr = head;
    if (head == nullptr)
    {
        head = tmp;
        return;
    }
    while (ptr->next)
    {
        ptr = ptr->next;
    }
    ptr->next = tmp;
}
// function to print list
void printList(node *head)
{
    node *ptr = head;
    while (ptr)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}
// function to delete first node of linked list
void deleteFirstNode(node *&head)
{
    if (head)
    {
        head = head->next;
    }
}
// function to delete last node of linked list
void deleteLastNode(node *&head)
{
    node *tmp = head;
    if (tmp == nullptr)
        return;
    if (tmp->next == nullptr)
    {
        delete head;
        return;
    }
    while (tmp->next->next)
    {
        tmp = tmp->next;
    }
    node *deleteMe = tmp->next;
    tmp->next = nullptr;
    delete deleteMe;
}

// function to insert a node at given position
// parameter-> data, position starting from 1, head node

void insertAt(int data, int pos, node *&head)
{
    node *temp = new node(data);
    if (pos < 1)
        return;
    if (pos == 1)
    {
        temp->next = head;
        head = temp;
        return;
    }
    node *ptr = head;
    int i = 1;
    while (ptr->next and i < pos - 1)
    {
        ptr = ptr->next;
        i++;
    }
    temp->next = ptr->next;
    ptr->next = temp;
}
// 1->2->3->4->5

// function to search in a linked list

int searchList(int key, node *&head)
{
    node *ptr = head;
    int count = 0;
    while (ptr)
    {
        count++;
        if (ptr->data == key)
        {
            return count;
        }
        ptr = ptr->next;
    }
    return -1;
}

// function to search in list recursively
int searchListRecursive(int key, node *head)
{
    if (head == nullptr)
        return -1;
    if (head->data == key)
        return 1;
    int res = searchListRecursive(key, head->next);
    if (res == -1)
        return -1;
    else
        return res + 1;
}
// function to insert element in a sorted linked list
// assume list is sorted in non-decreasing order.
void insertInSortedList(int data, node *&head)
{
    node *temp = new node(data);
    if (head == nullptr)
    {
        head = temp;
        return;
    }
    node *ptr = head;
    if(ptr->data > data){
        temp->next = ptr;
        head = temp;
        return;
    }
    while(ptr->next and ptr->next->data < data){
        ptr = ptr->next;
    }
    if(ptr->next == nullptr)
        ptr->next = temp;
    else
        {
            temp->next = ptr->next;
            ptr->next = temp;
        }
}

// function to find middle of the linked list
void middleOfLinkedList(node *&head)
{
    if(head == nullptr)return;
    node *slow = head;
    node *fast = head;
    while(fast->next and fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast->next){
        cout<<slow->next->data;
    }
    else cout<<slow->data;
}
//function to reverse linked list : iterative solution
void reverseList(node *&head){
    node *ptr = nullptr;
    if(head == nullptr )return;
    while(head->next){
        node *temp = head;
        head = head->next;
        temp ->next = ptr;
        ptr = temp;
    }
    head->next = ptr;
}
//reverse list recursive
void reverseListRecursive(node *&head){
    
}

//evenOdd linked list
void evenOddList(node* &head){
    //assume 1st even and 2nd odd and so on.
    if(head == nullptr or head->next == nullptr) return;
    node *even_ptr = head;
    node* odd_ptr = head;
    node* ptr,*even,*odd;
    even = even_ptr;
    odd = odd_ptr;
    ptr = head;

    while(ptr->next){
        even->next = ptr;
        even = even->next;
        ptr = ptr->next;
        odd->next = ptr;
        odd = odd->next;
        if(ptr->next == nullptr)break;
        ptr = ptr->next;
    }   
    even_ptr = odd_ptr;
    head = even_ptr;
}


int main()
{
    int n, x;
    node *head = nullptr;
    cout << "No of elements you want to enter";
    cin >> n;
    while (n--)
    {
        cin >> x;
        insertInSortedList(x, head);
    }
    cout << "\nNow see your input " << endl;
    printList(head);
    cout<<"\nMiddle of the linked list :  ";
    middleOfLinkedList(head);
    cout<<"\nReverse List\n";
    reverseList(head);
    printList(head);
    cout<<"\nevenOdd list : ";
    evenOddList(head);
    printList(head);
}