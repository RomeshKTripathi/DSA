#include <iostream>
#include <vector>
using namespace std;

vector<int> repeatAndMissing(vector<int> &A)
{
    vector<int> ans;
    int size = A.size();
    for (int i = 0; i < size; i++)
    {
        int index = abs(A[i]) - 1;
        if (A[index] < 0)
        {
            ans.push_back(index + 1);
            break;
        }
        A[index] = -A[index];
    }

    for (int i = 0; i < size; i++)
    {
        if (A[i] > 0)
        {
            ans.push_back(i + 1);
            return ans;
        }
    }
    return ans;
}

int main(){
    vector<int> test = {1, 3, 4,5,6,7,7};
    vector<int> res = repeatAndMissing(test);
    cout << "Repeat : " << res[0] << "\nMissing : " << res[1];
}