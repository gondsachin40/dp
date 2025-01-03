//the basic idea was to make a hash map and check if it contatin all element then use formula to compute substring n * (n + 1)/2

problem : https://codeforces.com/contest/1272/problem/C

#include<bits/stdc++.h>
#define ll long long int 
#define F first
#define S second
#define pb push_back
#define FIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define print(a) for(auto x : a) cout << x << " " ; cout<< endl;
using namespace std;
void solve(){
	int n;
	cin >> n;
	int k;
	cin >> k;
	char s[n];
	scanf("%s",s);
	vector<int> has(26 , 0);
	for(int i = 0;i<k;i++)
	{
		char x;
		cin >> x;
		has[x - 'a']++;
	}
	ll ans = 0;
	ll cnt = 0;
	for(int i = 0;i<n;i++)
	{
		if(has[s[i] - 'a'])
		{
			cnt++;
		}else{
			ans += (cnt * (cnt + 1)/2);
			cnt = 0;
		}
	}
	ans += (cnt * (cnt + 1)/2);
	cout<<ans<<"\n";
}
int main(){
 // FIO;
 int t = 1;
 // cin >> t;
 while(t--)
 solve();
}
