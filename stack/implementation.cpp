#include<iostream>
using namespace std;

class Stack{
private:
    int *stk = nullptr;
    int top = -1;
    int capacity = 0;
public:
    Stack(int size){
        stk = new int[size];
        this->capacity = size;
    }
    void push(int data){
        if(top == capacity - 1) {
            cout << "Stack Overflow !";
            return;
        }

        top = top + 1;

        stk[top] = data;
    }

    int pop(){
        if(top == -1){
            cout << "Stack Underflow !";
            return -1;
        }

        int top_data = this->stk[top];
        top = top - 1;
        return top_data;
    }

    int peek(){
        if(top == -1) {
            cout << "Empty stack !";
            return -1;
        }

        return this->stk[top];
    }

    bool isEmpty(){
        return top == -1;
    }

};


int main(){
    Stack stk = Stack(4);
    // usecase of stack.

    stk.push(1);
    stk.push(2);
    cout << stk.peek() << endl;
    stk.pop();
    cout<< stk.peek();
    
}