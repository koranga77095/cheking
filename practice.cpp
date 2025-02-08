#include <bits/stdc++.h>
using namespace std;
int main()
{
   // added filles 
  vector<int> v(5);
   // v[0] = 3;
  int check = upper_bound(v.begin(), v.end(), 2) - v.begin();
  cout << check << endl;

  return 0;
}
