#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int main()
{
    int n;
    cin >> n;

    int zD = 1, zABC = 0;
    for (int i = 1; i <= n; i++)
    {
        int nzD =  zABC * 3 % MOD;
        int nzABC = (zABC * 2 + zD) % MOD;
        zD = nzD;
        zABC = nzABC;
    }

    cout << zD << endl;
    return 0;
}
