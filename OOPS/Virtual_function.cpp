#include<iostream>
using namespace std;

class Base{
    public:
    void inbase(){
        cout << " in base ";
    }
};

class Derived : public Base{
    public:
    virtual void vrt() = 0;
};

class dd : public Derived{
    public:
    void vrt(){
        cout << "Definition";
    }
};

int main(){
    Derived *d = new dd();
    d->vrt();
}