// In the name of God
#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 100;

#define fast_io                  \
	ios::sync_with_stdio(false); \
	cin.tie(0);                  \
	cout.tie(0);

int n, t, a[maxn];
long long ps[maxn];

int main()
{
	fast_io;

	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			ps[i] = ps[i - 1] + a[i];
		}
		if (ps[n] != 0)
		{
			cout << "No\n";
			continue;
		}
		bool ok = 1;
		for (int i = 1; i <= n; i++)
		{
			if (ps[i] < 0)
				ok = 0;
		}
		bool visited_zero = 0;
		for (int i = 1; i <= n; i++)
		{
			if (ps[i] == 0)
				visited_zero = 1;
			else if (visited_zero)
				ok = 0;
		}
		if (ok)
			cout << "Yes\n";
		else
			cout << "No\n";
	}

	return 0;
}