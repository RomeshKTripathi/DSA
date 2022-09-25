#include<iostream>
#include<queue>
using namespace std;

void generateNumbers(int n){
    queue<string> q;
    string curr = "";
    q.push("5");
    q.push("6");
    while(n--){
        curr = q.front();
        q.pop();
        cout<<curr<<endl;
        q.push(curr+"5");
        q.push(curr+"6");
    }
    return ;
}
int main(){
    generateNumbers(10);
}