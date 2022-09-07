#include <iostream>
using namespace std;

// node definition.
typedef struct node
{
    int val;
    struct node *next;
    node(int data)
    {
        val = data;
        next = nullptr;
    }
    node(int data, node *ptr)
    {
        val = data;
        next = ptr;
    }
} node;

// class to handle list
class list
{
private:
    node *head = nullptr;

public:
    list() {} // to initialize the list
    list(int data)
    {
        head = new node(data);
    }

    void printList()
    {
        node *ptr = head;
        cout<<endl;
        while (ptr)
        {
            cout << ptr->val << " ";
            ptr = ptr->next;
        }
    }
    void addAtHead(int data)
    {
        node *temp = new node(data);
        temp->next = head;
        head = temp;
    }
    void addAtTail(int data)
    {
        node *temp = new node(data);
        if (head == nullptr)
        {
            head = temp;
            return;
        }

        node *ptr = head;
        while (ptr->next)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
    // return value of the given index, index starting from 0
    int get(int index)
    {
        if (head == nullptr)
            return -1; // invalid index
        if (index == 0)
            return head->val; // if first index is asked

        node *ptr = head;
        int count = 0;
        while (ptr)
        {
            if (count == index)
                return ptr->val;
            ptr = ptr ->next;
            count++;
        }
        return -1;
    }

    void addAtIndex(int index, int data)
    {
        if (index == 0)
        {
            head = new node(data, head);
            return;
        }
        node *curr = head->next;
        node *prev = head;
        int count = 0;
        while(curr){
            count++;
            if(count  == index){
                prev->next = new node(data,curr);
                return;
            }
            count++;
            prev = curr;
            curr = curr->next;
        } 
    }
    void deleteAtIndex(int index){
        if(head == nullptr)return;
        int count = 0;
        node *temp = nullptr;
        node *prev = head;
        node *curr = head->next;
        if(index == 0)
            {
                head = curr;
                return;
            }

        while(curr){
            count++;
            if(count == index){
                prev->next = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }

    }

    // Reverse the list;
    void reverse()
    {
        if (head == nullptr or head->next == nullptr)
            return;
        node *curr = head;
        node *next = head;
        node *temp = nullptr;
        node *rev = nullptr;
        while (curr)
        {
            temp = curr;
            curr = curr->next;
            temp->next = rev;
            rev = temp;
        }
        head = rev;
    }
};

int main()
{
    list *obj = new list();
    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(1,2);
    obj->printList();
    cout<<endl<<obj->get(1);
    obj->printList();
    obj->deleteAtIndex(1);
    obj->printList();
    cout<<endl<<obj->get(1)<<endl;
    obj->printList();

}