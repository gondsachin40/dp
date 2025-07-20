#include<bits/stdc++.h>
#define int long long int
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i) 
#define vi vector < int >
#define sz(a) ((int) (a).size())
#define ll long long 
#define ull unsigned long long
#define pb push_back
#define all(a) (a).begin(),(a).end()
#define print(a) for(auto x : a) cout << x << " " ; cout<< endl;

using namespace std;
const int N = 1e6 + 7, mod = 1e9 + 7;
const char nl = '\n';
/*
Sparse table work with overlapping interval can work for minimum , maximum , gcd query
in any range find 
min(l , x);
min(x , r);
l , x , r can overlap
L --------- R
L ------x
    x------ R

*/
vector<vector<int>> dp;
void solve(){
	int n;
	cin >> n;
	vi a(n);
	L(i , 0 , n - 1) cin  >> a[i];
	int q;
	cin >> q;
	int LOG = __lg(n) + 1;
	dp = vector<vector<int>>(n , vector<int>(LOG + 1));	
	L(i , 0 ,n - 1){
		dp[i][0] = a[i];
	}
	L(k , 1 ,LOG){
		L(i , 0 , n - 1){
			int x = i + (1 << (k - 1));
			if(x < n){	
			dp[i][k] = min(dp[i][k - 1] , dp[x][k - 1]);
			}
		}
	}
	while(q--){
		int l , r;
		cin >> l >> r;
		int len = r - l + 1;
		int k = __lg(len);
		int x = (1 << k);
		cout<<min(dp[l][k] , dp[r - x + 1][k])<<nl;
	}
}
int32_t main(){
 ios_base::sync_with_stdio(false),cin.tie(0);
 cout.tie(0);
 int t = 1;
 // cin >> t;
 while(t--)
 solve();
 return 0;
}
