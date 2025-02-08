#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ll long long
#define vll vector<ll>
#define all(a) a.begin(), a.end()
#define yy cout << "YES" << endl
#define nn cout << "NO" << endl
#define co cout <<
#define el << endl;
#define fi(n, v)                \
    vector<int> v(n);           \
    for (int i = 0; i < n; i++) \
        cin >> v[i];
#define fr(n) \
    for (int i = 0; i < n; i++)
#define pre_array(n, v)                           \
    vector<long long> prefix_sum(n);              \
    prefix_sum[0] = v[0];                         \
    for (int i = 1; i < n; i++)                   \
    {                                             \
        prefix_sum[i] = prefix_sum[i - 1] + v[i]; \
    }
#define d 256
const ll mod = 1000000007;
const int mx = 1e9;
const int mn = -2147483648;
bool is_prime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int ceil(int a, int b)
{
    return (a + b - 1) / b;
}
void removeDuplicates(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    auto last = unique(nums.begin(), nums.end());
    nums.erase(last, nums.end());
}
void printPrimes(int n, vector<int> &prime)
{
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            prime.push_back(i);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s1;
    string s2;
    cin >> s1 >> s2;
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
   // dp[0][0] = 0;
    for (int i = 0; i <= n; i++)
    {
        // dp[0][i] = i;
           dp[i][0] =i;
    }
    for (int j = 0; j <= m; j++)
    {
        // dp[j][0] = j;
          dp[0][j] =j;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}