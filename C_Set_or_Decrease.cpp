#include <bits/stdc++.h>
using namespace std;

long long accurateFloor(long long a, long long b) {
    return (a >= 0) ? (a / b) : ((a - b + 1) / b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        long long k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end());
        vector<long long> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + a[i];
        }

        long long ans = LLONG_MAX;

        for (int y = 0; y < n; y++) {
            long long x = a[0] - accurateFloor(k - prefixSum[n - y] + a[0], y + 1);
            ans = min(ans, y + max(0LL, x));
        }

        cout << ans << endl;
    }

    return 0;
}
