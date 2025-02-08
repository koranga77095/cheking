#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ll long long
using ull = unsigned long long;
#define vll vector<ll>
#define vvi vector<vi>
#define mi map<int, int>
#define ml map<ll, ll>
#define vpi vector<pair<int, int>>
#define all(a) a.begin(), a.end()
#define yy cout << "YES" << endl
#define nn cout << "NO" << endl
#define co cout <<
#define el << endl;
#define fl(n, v)                \
    vector<long long> v(n);     \
    for (int i = 0; i < n; i++) \
        cin >> v[i];
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
const ll MOD = 1000000007;
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
  vector<int> buildlps(){
    
  }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        string pat;
        cin >> pat;
    }
    return 0;
}