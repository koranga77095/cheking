#include <bits/stdc++.h>
using namespace std;

struct Project
{
    long long start, end, reward;
};

bool cmp(Project &a, Project &b)
{
    return a.end < b.end;
}

// Function to find the last non-overlapping project using binary search
int findLastNonOverlapping(vector<Project> &projects, int index)
{
    int left = 0, right = index - 1, ans = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (projects[mid].end < projects[index].start)
        {
            ans = mid;
            left = mid + 1; // Try to find a later project that still fits
        }
        else
        {
            right = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<Project> projects(n);

    for (int i = 0; i < n; i++)
    {
        cin >> projects[i].start >> projects[i].end >> projects[i].reward;
    }

    // Sort projects by their end time
    sort(projects.begin(), projects.end(), cmp);

    vector<long long> dp(n);
    dp[0] = projects[0].reward;

    for (int i = 1; i < n; i++)
    {
        long long includeReward = projects[i].reward;
        int last = findLastNonOverlapping(projects, i);
        if (last != -1)
        {
            includeReward += dp[last];
        }

        // Maximum of taking the current project or skipping it
        dp[i] = max(dp[i - 1], includeReward);
    }

    cout << dp[n - 1] << "\n";
    return 0;
}
