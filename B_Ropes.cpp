#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

bool canCut(const vector<double> &ropes, double length,   double k)
{
      double count = 0;
    for (double rope : ropes)
    {
        count += static_cast<int>(rope / length); // Count pieces of length
        if (count >= k)
            return true; // Early exit if enough pieces are possible
    }
    return count >= k;
}

int main()
{
      double n, k;
    cin >> n >> k;

    vector<double> ropes(n);
    double maxLength = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> ropes[i];
        maxLength = max(maxLength, ropes[i]);
    }

    double left = 0, right = maxLength, mid, result = 0;

    // Binary search to find the maximum length
    while (right - left > 1e-7)
    { // Precision threshold
        mid = (left + right) / 2;
        if (canCut(ropes, mid, k))
        {
            result = mid; // Update the best length found
            left = mid;   // Search for a larger length
        }
        else
        {
            right = mid; // Search for a smaller length
        }
    }

    cout << fixed << setprecision(6) << result << endl;
    return 0;
}
