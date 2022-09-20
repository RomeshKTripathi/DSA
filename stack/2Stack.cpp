#include<iostream>
using namespace std;

class stack_2{
    int n = 0;
    int *arr;
    int top1 = -1,top2 = n;
    public:
    stack_2(int n){
        arr = new int[n];
        this->n= n;
        top2 = n;
    }
    void push1(int data){
        if(top1+1 == top2) return;
        top1+=1;
        arr[top1] = data;
        return;
    }
    void push2(int data){
        if(top2-1 == top1) return;
        top2--;
        arr[top2] = data;
    }
    int peek1(){
        if(top1 >= 0)return arr[top1];
        else return -1;
    }
    int peek2(){
        if(top2<n) return arr[top2];
        else return -1;
    }
    void pop1(){
        if(top1>-1) top1--;
    }
    void pop2(){
        if(top2 < n)top2++;
    }

};

int main(){
    stack_2 *obj = new stack_2(10);
    obj->push1(1);
    obj->push1(2);
    obj->push1(3);
    obj->push1(4);
    obj->push2(5);
    obj->push2(6);
    obj->push2(7);
    obj->push2(8);
    cout<<obj->peek1()<<endl;
    obj->pop1();
    cout<<obj->peek1()<<endl;
    cout<<obj->peek2()<<endl;
    obj->pop2();
    cout<<obj->peek2()<<endl;
}