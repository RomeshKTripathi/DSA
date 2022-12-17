#include<iostream>
using namespace std;

void intersection(int A[], int B[], int m, int n){
    int i = 0, j = 0;
    while(i < m && j < n){
        if(A[i] < B[j]) i++;
        else if(A[i] > B[j]) j++;
        else{
            if(A[i] == A[i-1]) continue;
            cout << A[i] << "  ";
            i++;j++;
        }
    }
}

int main(){
    int A[] = {1,2,3,4,5,6,7,8,9};
    int B[] = {2,2,3,3,4,4,6,6,7,7,7,8,9,10};
    intersection(A, B, 9, 14);
}