#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to build the LPS (Longest Prefix Suffix) array
 vector<int> buildLPS(const string &pattern)
{
    int m = pattern.size();
    vector<int> lps(m, 0);
    int len = 0; // Length of the previous longest prefix suffix
    int i = 1;

    while (i < m)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1]; // Reset len using LPS
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}
int main()
{
    string text = "fixprefixsuffix";
    vector<int> res = buildLPS(text);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}