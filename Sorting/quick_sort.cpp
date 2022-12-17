#include<iostream>
#include<vector>
using namespace std;
int hoare_partition(vector<int> &data, int l, int r){
    int pivot = data[l];
    int i = l-1, j = r+1;
    while(i <= j){
        do{
            i++;
        }while(data[i] < pivot);
        do{
            j--;
        }while(data[j]>pivot);
        if(i >= j) return j;
        swap(data[i], data[j]);
    }
}

int lomuto_partition(vector<int> &A, int l, int r){
    // consider last element as pivot.
    int pivot = A[r];
    int i = l-1, j = l;
    for(int j = l; j < r; j++){
        if(A[j] < pivot){
            swap(A[i+1], A[j]);
            i++;
        }
    }
    swap(A[i+1], A[r]);
    return i+1;
}
void quick_sort(vector<int> &data, int l, int r){
    begin:
    if(l < r){
        int pivot = hoare_partition(data, l, r);
        quick_sort(data, l, pivot);
        l = pivot + 1;
        goto begin;
    }
}

int main(){
    vector<int> data = {8,3,1,6,3,4,9,0,80,34,12,13,2,4,3,33,34,35,67};
    quick_sort(data, 0, data.size()-1);
    for(int item : data) cout << item << "  ";
}