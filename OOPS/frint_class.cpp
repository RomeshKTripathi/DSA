#include<iostream>
using namespace std;

class Base{
    private:
    int data = 123;
    public:
    Base(){
        cout << "From Base Class!\n";
    }
    friend class Derived;
};

class Derived : private Base{
    public:
    void print_friend_class_data(){
        cout << "Friend's private data is :" << data;
    }
};

int main(){
    Derived d;
    d.print_friend_class_data();
}