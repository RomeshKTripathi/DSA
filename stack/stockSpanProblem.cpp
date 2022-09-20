#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{

public:
    vector<int> stackSpan(vector<int> &v)
    {
        stack<int> s;
        vector<int> res;
        for (int i = 0; i < v.size(); i++)
        {
                while (s.size() and v[s.top()] < v[i])
                {
                    s.pop();
                }
                int span = (s.empty()?i+1:i-s.top());
                res.push_back(span);
                s.push(i);
        }
        return res;
    }
};
int main(){
    Solution *obj = new Solution();
    vector<int> vec = {60,10,20,40,35,30,50,70,65};
     vector<int> res = obj->stackSpan(vec);
     for(int x:res)cout<<x<<" ";
}