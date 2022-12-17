#include<iostream>
#include<vector>
using namespace std;

void sort_colors(vector<int> &colors){
    int hi = colors.size();
    int i = -1, j = 0;
   while(j < hi){
        if(colors[j] == 0){
            i++;
            swap(colors[i], colors[j]);
        }
        else if(colors[j] == 2){
            hi--;
            swap(colors[j--], colors[hi]);
        }
        j++;
    }
}

int main(){
    vector<int> colors = {0,1,2,2,1,2,0,1,0,2,2,0,0,1,1,1,1,2,1,2,0};
    sort_colors(colors);
    for(int color : colors) cout << color << "  ";
}