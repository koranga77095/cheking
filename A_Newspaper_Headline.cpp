#include<bits/stdc++.h>
using namespace std;
set<int>g[26];
string s1,s2;
int p=-1,z=1;
int main(){
	cin>>s1>>s2;
	for(int i=0;s1[i];i++)g[s1[i]-'a'].insert(i);
	for(int i=0;s2[i];i++){
		if(g[s2[i]-'a'].empty())return cout<<-1,0;
		if(g[s2[i]-'a'].upper_bound(p)==g[s2[i]-'a'].end())p=-1,z++;	
		p=*g[s2[i]-'a'].upper_bound(p);
	}
	cout<<z;
	return 0;
}