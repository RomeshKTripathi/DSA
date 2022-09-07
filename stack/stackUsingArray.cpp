#include<iostream>
#include<vector>
using namespace std;

class stack{
    vector<int> s;
    int fill = 0;
    public:
    void push(int data){
        s.push_back(data);
        fill+=1;
    }
    void pop(){
        if(fill == 0){
            cout<<"Underflow";
            return;
        }
        s.resize(fill-1);
        fill-=1;
        
    }
    int top(){
        return s[fill-1];
    }
    int size(){
        return fill;
    }
    bool empty(){
        return fill;
    }
};

int main(){
    stack obj;
    obj.push(1);
    obj.push(2);
    obj.push(3);
    obj.push(4);
    obj.push(5);
    cout<<obj.top()<<endl;
    obj.pop();
    cout<<obj.top();
    cout<<obj.size();
    obj.push(14);
    cout<<obj.top();

}