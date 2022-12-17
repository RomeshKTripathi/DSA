#include <bits/stdc++.h>
using namespace std;

int merge(long long *arr, int i, int m, int j){
    if(i == j) return 0 ;
    int inversion = 0;
    int temp[j-i+1], index = 0, k = i, l = m+1;
    while(k <= m && l <= j){
        if(arr[k] <= arr[l]){
            temp[index++] = arr[k++];
        }else{
            inversion += (m-k)+1;
            temp[index++] = arr[l++];
        }
    }
    while(k <= m){
        temp[index++] = arr[k++];
    }
    while(l <= j){
        inversion += (m-k)+1;
        temp[index++] = arr[l++];
    }
    
    for(k = i; k<=j; k++){
        arr[k] = temp[k-i];
    }
    return inversion;
}

int mergeSort(long long *arr, int i, int j){
        int invs = 0;
    if(i<j){
        int p = (j-i)/2 + i;
        invs += mergeSort(arr, i, p);
        invs += mergeSort(arr, p+1, j);
        invs += merge(arr, i, p, j);
    }
    return invs;
}

long long getInversions(long long *arr, int n){
    return mergeSort(arr, 0, n-1);
}

int main(){
    long long arr[] = {6,2,7,9,3,4,6,1,9};
    cout << getInversions(arr, 9);
    for(int i = 0; i<9; i++) cout << arr[i] << ' ';
    
}