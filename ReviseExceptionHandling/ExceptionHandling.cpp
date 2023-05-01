#include<iostream>
using namespace std;

class Exception{
    string msg = "";
    public:
    Exception(string msg){
        this->msg = msg;
    }

    string what(){
        return this->msg;
    }
};


int main(){
    int a, b;
    int result = 0;
    cin >> a >> b;

    try{
        if(b == 0) throw Exception("Divisor should not be 0");
        result = a/b;
        cout << result;
    }catch(Exception &e){
        cout << e.what();
    }
}