//greedy
problem : https://codeforces.com/contest/1355/problem/B


#include<bits/stdc++.h>
#define ll long long int 
#define F first
#define S second
#define pb push_back
#define FIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define print(a) for(auto x : a) cout << x << " " ; cout<< endl;
using namespace std;
int a[200001];
void solve(){
	int n;
	cin >> n;
	for(int i = 0;i<n;i++)
	{
		cin >> a[i];
	}
	sort(a , a + n);
	int size = 0 , cnt = 0;
	for(int i = 0;i<n;i++)
	{
		if(i - size + 1 >= a[i])
		{
		cnt++;
		size = i + 1;
		}
	}
	cout<<cnt<<"\n";
}
int main(){
 int t = 1;
 cin >> t;
 while(t--)
 solve();
}
