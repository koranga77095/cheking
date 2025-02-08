// #include <bits/stdc++.h>
// using namespace std;
// #define vi vector<int>
// #define ll long long
// #define vll vector<ll>
// #define all(a) a.begin(), a.end()
// #define yy cout << "YES" << endl
// #define nn cout << "NO" << endl
// #define co cout <<
// #define el << endl;
// #define fi(n, v)                \
//     vector<int> v(n);           \
//     for (int i = 0; i < n; i++) \
//         cin >> v[i];
// #define fr(n) \
//     for (int i = 0; i < n; i++)
// #define pre_array(n, v)                           \
//     vector<long long> prefix_sum(n);              \
//     prefix_sum[0] = v[0];                         \
//     for (int i = 1; i < n; i++)                   \
//     {                                             \
//         prefix_sum[i] = prefix_sum[i - 1] + v[i]; \
//     }
// #define d 256
// const ll mod = 1000000007;
// const int mx = 1e9;
// const int mn = -2147483648;
// bool is_prime(int n)
// {
//     if (n <= 1)
//         return false;
//     for (int i = 2; i <= sqrt(n); ++i)
//     {
//         if (n % i == 0)
//             return false;
//     }
//     return true;
// }
// int ceil(int a, int b)
// {
//     return (a + b - 1) / b;
// }
// void removeDuplicates(vector<int> &nums)
// {
//     sort(nums.begin(), nums.end());
//     auto last = unique(nums.begin(), nums.end());
//     nums.erase(last, nums.end());
// }
// void printPrimes(int n, vector<int> &prime)
// {
//     vector<bool> isPrime(n + 1, true);
//     isPrime[0] = isPrime[1] = false;
//     for (int i = 2; i * i <= n; i++)
//     {
//         if (isPrime[i])
//         {
//             for (int j = i * i; j <= n; j += i)
//             {
//                 isPrime[j] = false;
//             }
//         }
//     }
//     for (int i = 2; i <= n; i++)
//     {
//         if (isPrime[i])
//         {
//             prime.push_back(i);
//         }
//     }
// }
// int solve(int l, int r, int t, vector<int> v)
// {
//     int mid = 0;
//     while (l <= r)
//     {
//         mid = l + (r - l) / 2; // Avoid overflow
//         //  cout << mid << endl;

//         ll check = 0; // Use long long to handle large sums
//         for (int i = 0; i < v.size(); i++)
//         {
//             check += mid / v[i];
//             if (check >= t)
//                 break; // Early exit for optimization
//         }

//         if (check >= t)
//         {
//             r = mid - 1; // Move to the left half
//         }
//         else
//         {
//             l = mid + 1; // Move to the right half
//         }
//     }

//     return mid;
// }
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int n, t;
//     cin >> n >> t;
//     fi(n, v);
//     int chota = *min_element(all(v));
//     int bada = *max_element(all(v));
//     int l = t * chota;
//     int r = t * bada;
//     int res = solve(0, INFINITY, t, v);
//     cout << res << endl;
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; 
    long long x;
    cin >> n >> x;
    
    vector<long long> machines(n);
    for (int i = 0; i < n; i++) {
        cin >> machines[i];
    }

    // Binary search bounds
    long long left = 1, right = *max_element(machines.begin(), machines.end()) * x;
    long long result = right;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        
        // Calculate the total products that can be produced in 'mid' time
        long long products = 0;
        for (long long t : machines) {
            products += mid / t;
            if (products >= x) break; // Avoid overflow and unnecessary calculations
        }

        if (products >= x) {
            result = mid; // Try for a smaller time
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << result << endl;
    return 0;
}
