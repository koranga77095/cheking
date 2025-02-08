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
    int n;
    cin >> n;
    vector<vector<char>> v(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    // dp[0][0] = 1;
    dp[0][0] = (v[0][0] == '*') ? 0 : 1;
    bool flag = true;
    for (int i = 1; i < n; i++)
    {
        dp[0][i] = (v[0][i] == '*') ? 0 : dp[0][i - 1];
    }
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = (v[i][0] == '*') ? 0 : dp[i - 1][0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (v[i][j] == '*')
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
            }
        }
    }
    cout << dp[n - 1][n - 1] << endl;

    return 0;
}