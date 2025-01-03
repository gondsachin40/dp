//the basic idea was to pre compute all the answers 
proble : https://codeforces.com/contest/1926/problem/C


#include<bits/stdc++.h>
#define ll long long int 
#define F first
#define S second
#define pb push_back
#define FIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define print(a) for(auto x : a) cout << x << " " ; cout<< endl;
using namespace std;
int dp[200001];
int s = 0;
int num = 0 , n = 0;
void make(){
	for(int i = 1;i<200001;i++)
	{
		num = i;
		while(num != 0)
		{
			s += num % 10;
			num = num / 10;
		}
		dp[i] = s;
	}
}
void solve(){
	cin >> n;
	cout<<dp[n]<<"\n";
}
int main(){
 // FIO;
 int t = 1;
 cin >> t;
 make();
 while(t--)
 solve();
}
