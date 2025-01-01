https://codeforces.com/problemset/problem/1472/D

//greedy
#include<bits/stdc++.h>
#define ll long long int 
#define F first
#define S second
#define pb push_back
#define FIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define print(a) for(auto x : a) cout << x << " " ; cout<< endl;
using namespace std;
int x;
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int k = 0;k<n;k++)
	{
		cin >> a[k];
	}
	sort(a.rbegin() , a.rend());
	ll alice = 0;
	for(int k = 0;k<n;k++)
	{
		if(k % 2 == 0){
			if(a[k] % 2 == 0)
			{
				alice += a[k];
			}
		}else{
			if(a[k] % 2)
			alice -= a[k];
		}
	}
	if(alice == 0)
	cout<<"Tie"<<"\n";
	else if(alice > 0)
	cout<<"Alice"<<"\n";
	else
	cout<<"Bob"<<"\n";
}
int main(){
 // FIO;
 int t = 1;
 cin >> t;
 while(t--)
 solve();
}
