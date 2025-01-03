//i used the concept of 2-d hashing
#include<bits/stdc++.h>
#define ll long long int 
#define F first
#define S second
#define pb push_back
#define FIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define print(a) for(auto x : a) cout << x << " " ; cout<< endl;
using namespace std;
void solve(){
	int n , q;
	cin >> n >> q;
	string a , b;
	cin >> a >> b;
	vector<array<int,26>> has(n + 1);
	for(int i = 0;i<n;i++)
	{
		has[i + 1] = has[i];
		has[i + 1][a[i] - 97]++;
		has[i + 1][b[i] - 97]--;
	}
	while(q--){
		int l , r;
		cin >> l >> r;
		int ans = 0;
		for(int i = 0;i<26;i++){
			ans += max(0 , has[r][i] - has[l - 1][i]);
		}
		cout<<ans<<"\n";
	}
}
int main(){
 int t = 1;
 cin >> t;
 while(t--)
 solve();
}
