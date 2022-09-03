#include<iostream>
using namespace std;
template<class T>
class LinkedList{
    public:
    T data;
    LinkedList *next;
    public:
    //constructor to create new node without data
    LinkedList(){
        this->next = nullptr;
    }
    //constructor to create new node of given type
    LinkedList(T data){
        this->data = data;
        this->next = nullptr;
    } 
    //constructor to create new node with given data and next node reference
    LinkedList(T data,T* next){
        this->data = data;
        this->next = next;
    }


    //=====================================================================

    void printList(T* head){
        if(head == nullptr) return;
        T *ptr = head;
        while(ptr){
            cout<<ptr->data<<endl;
            ptr = ptr->next;
        }
    }

};

int main(){
    LinkedList<int> *l1 = new LinkedList<int>();
    l1->next = new LinkedList<int>(10);
}