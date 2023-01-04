#include<iostream>
using namespace std;

class A{
    public:
    void BX(){
        cout << "A called !\n";
    }
};

class B:public A{
    public:
    void BX(){
        cout << "B called !\n";
    }
};

class C:public B{
    public:
    void CX(){
        cout << "C called !\n";
    }
};

int main(){
    C obj;
    obj.BX();
    // A *obj = new C();
}
