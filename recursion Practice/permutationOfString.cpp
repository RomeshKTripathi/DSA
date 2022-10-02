#include <iostream>
using namespace std;

void permutation(string &str, int i = 0)
{
    // whent i becomes equal to str size it means 
    // all characters have been traversed.
    if (i == str.size())
    {
        cout << str << endl;
    }
    // replace ith character with jth character to generate all
    // permutations starting with jth character. 
    for (int j = i; j < str.size(); j++)
    {
        // replacing the character
        swap(str[j], str[i]);
        // now do same for remaining characters
        permutation(str, i + 1);
        //Back to original state
        swap(str[j], str[i]);
    }
}

int main()
{
    string str = "ab";
    permutation(str);
}