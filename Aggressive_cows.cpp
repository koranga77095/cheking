#include <bits/stdc++.h>
using namespace std;

// Function to check if it's possible to place C cows with at least distance 'dist'
bool canPlaceCows(vector<int>& stalls, int n, int c, int dist) {
    int count = 1; // Place the first cow in the first stall
    int lastPlaced = stalls[0];
    for (int i = 1; i < n; i++) {
        if (stalls[i] - lastPlaced >= dist) {
            count++;
            lastPlaced = stalls[i];
        }
        if (count >= c) {
            return true;
        }
    }
    return false;
}

int largestMinDistance(vector<int>& stalls, int n, int c) {
    sort(stalls.begin(), stalls.end()); // Sort the stall positions
    int low = 1; // Minimum possible distance
    int high = stalls[n - 1] - stalls[0]; // Maximum possible distance
    int result = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (canPlaceCows(stalls, n, c, mid)) {
            result = mid; // Update result if feasible
            low = mid + 1; // Try for a larger distance
        } else {
            high = mid - 1; // Try for a smaller distance
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, c;
        cin >> n >> c;
        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        cout << largestMinDistance(stalls, n, c) << endl;
    }

    return 0;
}
