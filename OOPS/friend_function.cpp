#include<iostream>
using namespace std;

class Base{
    private:
    int data = 123;
    public:
    friend void out_sider(Base obj);
    void personal_function(){
        cout << "Personal function : " << data << '\n';
    }

};

class Derived : private Base{
    public:
    friend void out_sider(Base obj);
};

void out_sider(Base obj){
        cout << "Out sider : " << obj.data << '\n';
}

int main(){
    Derived d;
    Base obj;
    out_sider(obj);
}