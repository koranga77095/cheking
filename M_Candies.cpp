#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];

    vector<int> dp(K + 1, 0), prefix(K + 2, 0);
    dp[0] = 1; // One way to give 0 candies

    for (int i = 0; i < N; i++)
    {
        vector<int> new_dp(K + 1, 0);
        prefix[0] = dp[0];

        for (int j = 1; j <= K; j++)
            prefix[j] = (prefix[j - 1] + dp[j]) % MOD;

        for (int j = 0; j <= K; j++)
        {
            new_dp[j] = prefix[j];
            if (j - a[i] - 1 >= 0)
                new_dp[j] = (new_dp[j] - prefix[j - a[i] - 1] + MOD) % MOD;
        }

        dp = new_dp; // Update dp array
    }

    cout << dp[K] << endl;
    return 0;
}
