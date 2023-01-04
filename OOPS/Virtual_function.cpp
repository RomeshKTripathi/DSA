#include<iostream>
using namespace std;

class Base{
    public:
    virtual void print()= 0;
};

class Derived : public Base{
    public:
    void print(){
        cout << "Derived Class";
    }
};

int main(){
    Derived d;
    d.print();
}