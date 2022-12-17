#include <iostream>
using namespace std;
/**
 * Proble Statement:
 * 1. You are given a string you have to find frequencies in that string .
 *    string will consist of Uppercase & Lowercase letters both.
 * 2. You need to find frequencies for Lowercase letters and Uppercase letters saperately.
 * 
 * 3. Now you have to find the Maximum of lowecase frequencies and maximum of uppercase letters too.
 *      if there are more than one letters having maximum(same) frequency you have to consider all the letters.
 * 4. At last you should tell me about the maximum of lowercase & Uppercase.
 * 
 * example:
 *  str = "giVenStringTOTesTNOWtestthisstring";
 *  1.   find frequencies of all lower & uppercase letters.
 *  2.   Now Max of small letters is : t count is 5.
 *  3.   Max of Capital Letter is    : O count is 2
 *  4.   Max of Capital_max & small_max if 't' which has count of 5.
 * 
*/




int main()
{
    string str = "giVenStringTOTesTNOWtestthisstring";
    int sml_count[26] = {0};
    int caps_count[26] = {0};

    for (int i = 0; i < str.length(); i++)
    {
        char letter = str[i];

        if (letter >= 'a' && letter <= 'z')
            sml_count[letter - 'a'] += 1;

        else if (letter >= 'A' && letter <= 'Z')
            caps_count[letter - 'A'] += 1;
    }
    // Get Maximum frequency letter

    char small_letter = 'a';
    int small_frequency = 0;
    char capital_letter = ' ';
    int capital_frequency = 0;

    for (int i = 0; i < 26; i++)
    {
        if (sml_count[i] > small_frequency)
        {
            small_frequency = sml_count[i];
            small_letter = i + 'a';
        }
        else if (caps_count[i] > capital_frequency)
        {
            capital_frequency = caps_count[i];
            capital_letter = i + 'A';
        }
    }
    // You can check if there exist more than one max_frequency elements 
    // Your code here.

    cout << "Capital Letter : " << capital_letter << "  count  : " << capital_frequency<< endl;
    cout << "Small Letter : " << small_letter << "  count : " << small_frequency << endl;
    cout << "Max of capital and small is : " 
         << ((capital_frequency > small_frequency)?capital_letter:small_letter )
         << " Count is " << ((capital_frequency> small_frequency)?capital_frequency:small_frequency);
    return 0;
}