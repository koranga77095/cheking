#include <bits/stdc++.h>
using namespace std;

void solve() {
    unordered_map<char, char> winBy = {{'R', 'P'}, {'S', 'R'}, {'P', 'S'}};

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;

        char maxCnt = max_element(freq.begin(), freq.end(), [](const auto &a, const auto &b) {
            return a.second < b.second;
        })->first;

        cout << string(s.length(), winBy[maxCnt]) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
