#include <bits/stdc++.h>
using namespace std;

int minSecondsToMakeNonDecreasing(vector<int> &a)
{
    int n = a.size();
    int maxDiff = 0, b = a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] < b)
        {
            maxDiff = max(maxDiff, b - a[i]);
        }
        b = max(b, a[i]);
    }

    if (maxDiff == 0)
        return 0;
    int result = (maxDiff == 0) ? 0 : 1 +log2(maxDiff);
    return result;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        cout << minSecondsToMakeNonDecreasing(a) << endl;
    }
    return 0;
}
