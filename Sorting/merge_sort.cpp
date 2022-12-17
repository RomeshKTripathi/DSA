#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int> &data, int l, int m, int r){
    int temp[r-l+1] = {0};
    int i = l, j = m, k = 0, invs = 0;
    while(i < m && j <= r){
        if(data[i] <= data[j]){
            temp[k++] = data[i++];
        }else{
            temp[k++] = data[j++];
            invs += m-i;
        }
    }
    while(i < m)
        temp[k++] = data[i++];
    while(j <= r){
        temp[k++] = data[j++];
        invs += m-i;
    }
    // copy data in original vector.
    for(int i = l; i<= r; i++){
        data[i] = temp[i-l];
    }
    return invs;
}

int merge_sort(vector<int> &data, int l, int r){
    int res = 0;
    if(l<r){
        int m = (l+r)/2;
        res += merge_sort(data, l, m);
        res += merge_sort(data, m+1, r);
        res += merge(data, l, m+1, r);
    }
    return res;
}


int main(){
    vector<int> data = {2,4,1,6,8,2,3,4,90,8,7,7,8,78};
    int invs = merge_sort(data, 0, data.size()-1);
    for(int item : data) cout << item << ", ";
    cout << "\nINVERSIONS : " << invs; 

}