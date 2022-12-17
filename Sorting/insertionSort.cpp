#include <iostream>
#include <vector>
using namespace std;

void insertion_sort(vector<int> &data){
    const int size = data.size();

    for(int i = 1; i<size; i++){
        // Pick ith element and insert it at it's correct position.
        int key = data[i];
        int j = i-1;
        while(j >=0 && data[j] > key)
            data[j+1] = data[j--];
        data[j+1] = key; 
    }
}

int main(){
    vector<int> data = {5,2,3,6,1,7,9,21,8,4};
    insertion_sort(data);
    for( int item : data) cout << item << ' ';
}