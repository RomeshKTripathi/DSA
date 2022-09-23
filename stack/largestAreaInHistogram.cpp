// Naive approach to solve largest Area in Histogram problem
// Complexity of the solution is O(n^2);

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// this approach will use single traversal with single stack 
int LAIH(vector<int> &histogram){
    stack<int> st;
    int res = 0;
    int curr = 0;
    for(int i = 0;i<histogram.size();i++){
        while(st.size() and histogram[st.top()]>=histogram[i])
            {
                //calculate area associated with this element previous greater element under this element and next greater is i.
                int tp = st.top();
                st.pop();
                //top pointer 'tp' is larger than ith element.
                curr = histogram[tp]*((st.size())?(i-st.top()-1):i);
                res = max(curr,res);
            }
            st.push(i);
    }
    while(st.size()){
        int tp = st.top();
        st.pop();
        // if stack is not empty than previous smaller of recently popped element 
        // will be on the top of stack
        //If stack is empty then there is no previous smaller for recently 
        //popped element.
        curr = histogram[tp]*((st.size())?(histogram.size()-st.top()-1 ): histogram.size());
        res = max(res,curr);

    }
    return res;
}

int largestAreaInHistogramNaive(vector<int> &histogram)
{
    int largestArea = 0;
    int currentArea = 0;
    for (int i = 0; i < histogram.size(); i++)
    {

        // find area in left of ith bar of histogram.
        for (int j = i - 1; j >= 0; j--)
        {
            if (histogram[j] >= histogram[i])
            {
                currentArea += histogram[i]; // add height of the current bar.
            }
            else
            {
                break;
            }
        }
        // find area in right of ith bar of histogram.
        for (int j = i + 1; j < histogram.size(); j++)
        {
            if (histogram[j] >= histogram[i])
            {
                currentArea += histogram[i]; // add height of the current bar.
            }
            else
            {
                break;
            }
        }
        // update largest Area.
        largestArea = (largestArea > currentArea) ? largestArea : currentArea;
        // prepare currentArea variable to calculate next area associated with (i+1)th bar.
        currentArea = 0;
    }
    return largestArea;
}

// Efficient Approach.
int largestAreaInHistogram(vector<int> &histogram)
{
    int largestArea = 0;
    int currentArea = 0;
    // preprocess the array and generate two array previous smaller and next greater.
    vector<int> previousSmaller;
    vector<int> nextSmaller;
    stack<int> st;

    for (int i = 0; i < histogram.size(); i++)
    {
        while (st.size() and histogram[st.top()] >= histogram[i])
        {
            st.pop();
        }
        int temp = (st.size()) ? st.top() : -1;
        previousSmaller.push_back(temp);
        st.push(i);
    }
    // now pop all element from stack.
    while (st.size())
        st.pop();
    // generate next smaller for every element in histogram
    for (int i = histogram.size() - 1; i >= 0; i--)
    {
        while (st.size() and histogram[st.top()] >= histogram[i])
        {
            st.pop();
        }
        int temp = (st.size())?st.top():histogram.size();
        nextSmaller.push_back(temp);
        st.push(i);
    }
    // now we have to reverse the nextSmaller array because it gets generated in reverse order
    reverse(nextSmaller.begin(),nextSmaller.end());

    //now we will calculate the largest rectangular area of histogram
    for(int i = 0;i<histogram.size();i++){
        currentArea = histogram[i];
        currentArea += (i-previousSmaller[i]-1)*histogram[i];//area b/w current bar and previous smaller bar.
        currentArea += (nextSmaller[i] - i - 1)*histogram[i];//area b/w current bar and next smaller bar.
        //now update the largest area 
        largestArea = max(currentArea,largestArea);
    }
    return largestArea;

}

int main()
{
    vector<int> v = {2,4};
    cout << LAIH(v);
}