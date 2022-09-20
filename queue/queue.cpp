#include<iostream>
using namespace std;
class queue{
    int *que = nullptr;
    int capacity;
    int front = -1;
    int rear = -1;
    public:
    queue(int size){
        que = new int[size];
        capacity = size;
        rear = capacity;
    }
};
