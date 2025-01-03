/*
statement : in the problem there are 3 array of same size n and we want to maximize the pick of 3 element such that from one array we have to pick one element only and if we
pick element at particular index we can't pick element at corresponding index from other array
n >= 3
approach: we sort three array, with their index and check all permutation of them 
*/
problem : https://codeforces.com/contest/1914/problem/D

#include<bits/stdc++.h>
#define ll long long int 
#define F first
#define S second
#define pb push_back
#define FIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define print(a) for(auto x : a) cout << x << " " ; cout<< endl;
using namespace std;
int N = 200001;
pair<int , int> a[200001] , b[200001] , c[200001];
void solve(){
	int n;
	cin >> n;
	int x;
	for(int i = 0;i < n;i++)
	{
		cin >> x;
		a[i] = {x , i};
	}
	for(int i = 0;i < n;i++)
	{
		cin >> x;
		b[i] = {x , i};
	}
	for(int i = 0;i < n;i++)
	{
		cin >> x;
		c[i] = {x , i};
	}
	sort(a , a + n , greater<pair<int,int>>());
	sort(b , b + n , greater<pair<int,int>>());
	sort(c , c + n , greater<pair<int,int>>());
	int ans = 0;
	for(int i = 0;i<=2;i++)
	{
		for(int j = 0;j<=2;j++)
		{
			for(int k = 0;k<=2;k++)
			{
				if(a[i].second != b[j].second && b[j].second != c[k].second && a[i].second != c[k].second){
				// cout<<a[i].first<<" "<<b[j].first<<" "<<c[k].first<<endl;
				ans = max(ans , a[i].first + b[j].first + c[k].first);
					
				}
			}
		}
	}
	printf("%d\n",ans);
}
int main(){
 int t = 1;
 cin >> t;
 while(t--)
 solve();
}
