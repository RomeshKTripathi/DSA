#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

class Solution{
    public:
    int removeDuplicates(vector<int> &nums){
        unordered_set<int> s;
        int index;
        for(int i = 0; i<nums.size(); i++){
            if(s.find(nums[i]) == s.end()){
                s.insert(nums[i]);
                nums[index++] = nums[i];
            }
        }
        return index;
        
    }
};
int main(){
    Solution *obj = new Solution();
    vector<int> arr({1,4,2,6,7,8,7,3,4,5,9,5});
    int n = obj->removeDuplicates(arr);
    for(int i = 0; i<n; i++) cout << arr[i] << " ";
}