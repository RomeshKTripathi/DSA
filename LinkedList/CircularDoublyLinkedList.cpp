#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
    node(int x)
    {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
} node;

// function to create List
void createList(int data, node *&head)
{
    node *temp = new node(data);
    if (head == nullptr)
    {
        temp->next = temp;
        temp->prev = temp;
        head = temp;
        
        return;
    }
    node *ptr = head;
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }

    ptr->next = temp;
    temp->prev = ptr;
    temp->next = head;
    head->prev = temp;
}

// function to print all nodes of circular doubly linked list

void printList(node *&head)
{
    node *ptr = head;
    do
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    } while (ptr != head);
}

int main()
{
    node *head = nullptr;
    int n;
    cin >> n;
    while (n--)
    {
        createList(n, head);
    }
    printList(head);
}