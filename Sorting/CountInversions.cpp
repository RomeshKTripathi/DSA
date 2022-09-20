#include<iostream>
#include<vector>
using namespace std;

int inversion(vector<int>& v,int l,int m,int r){
    int count=0;
    vector<int> left;
    vector<int> right;
    for(int i = l;i<m;i++){
        left.push_back(v[i]);
    }
    for(int i = m;i<=r;i++){
        right.push_back(v[i]);
    }

    int i = 0;
    int j = 0;
    int k = l;
    while(i<left.size() and j<right.size()){
        if(left[i]<=right[j]){
            v[k] = left[i];
            i++;
        }
        else{
            v[k] = right[j];
            j++;
            count+= left.size()-i;
        }
        k++;
    }
    while(i<left.size()){
        v[k] = left[i];
        i++;
        k++;
    }
    while(j<right.size()){
        v[k] = right[j];
        k++;
        j++;
    }
    return count;
}

int countInversions(vector<int> &vec,int l,int r){
    int count = 0;
    if(l<r){
        int m = (l+r)/2;
        count+=countInversions(vec,l,m);
        count+=countInversions(vec,m+1,r);
        count += inversion(vec,l,m+1,r);
    }
    return count;
}
int main(){
    vector<int> v = {5,6,3,2,5,4,8,9,1};
    cout<<countInversions(v,0,v.size()-1);
}