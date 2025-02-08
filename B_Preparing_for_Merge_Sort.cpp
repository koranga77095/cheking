#include <bits/stdc++.h>
using namespace std;
int n, x, p;
vector<int> v[200003];
int main()
{
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++)
  {
    cin >> x;
    p = lower_bound(a.begin(), a.end(), x) - a.begin() - 1;
    // cout << p << endl;
    a[p] = x;
    v[p].push_back(x);
    // cout << "the element is  at the index : " << p << endl;
  }

  for (int i = n; i >= 0 && v[i].size(); i--)
  {
    for (int j = 0; j < v[i].size(); j++)
      cout << v[i][j] << ' ';
    cout << endl;
  }
}