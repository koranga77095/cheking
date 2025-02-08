#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    int maxSum = accumulate(coins.begin(), coins.end(), 0);
    vector<bool> dp(maxSum + 1, false);
    dp[0] = true;

    for (int j =0; j<coins.size(); j++)
    {
        for (int sum = maxSum; sum >= coins[j]; sum--)
        {
            dp[sum] = dp[sum] || dp[sum - coins[j]];
        }
    }
    

    vector<int> possibleSums;
    for (int i = 1; i <= maxSum; i++)
    {
        if (dp[i])
        {
            possibleSums.push_back(i);
        }
    }

    cout << possibleSums.size() << endl;
    for (int sum : possibleSums)
    {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}