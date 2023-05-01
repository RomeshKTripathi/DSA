#include<iostream>
using namespace std;

int main(){

    int num = 5;

    auto square = [](int num){
        return num * num;
    };

    cout << "Square of " << num << " is : " << square(num);
    return 0;

}