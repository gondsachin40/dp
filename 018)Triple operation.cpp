problem : Triple Operations
link : 
https://codeforces.com/contest/1999/problem/E





#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i) 
#define vi vector < int >
#define sz(a) ((int) (a).size())
#define ll long long 
#define ull unsigned long long
#define me(a, x) memset(a, x, sizeof(a)) 
#define pb emplace_back
#define FIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define all(a) (a).begin(),(a).end()
#define print(a) for(auto x : a) cout << x << " " ; cout<< endl;
using namespace std;
const int N = 2e5 + 2, mod = 1e9 + 7;
int use[N];
int findans(int n){
	int cnt = 0;
	while(n){
		n = n / 3;
		++cnt;
	}
	return cnt;
}
void compute(){
	L(i , 1 , N){
		use[i] = findans(i);
	}
}	
void solve(){
	//first make smallest number 0 then perform division operation on remaining elements
	int l , r;
	cin >> l >> r;
	int ans = 0;
	ans += use[l];
	l++;
	bool flag = true;
	int temp = 0;
	int cnt = 0;
	L(i , 1 , ans){
		if(flag){
			temp = r;
			r--;
			flag = false;
		}
		cnt++;
	}
	L(i , l , r){
		ans += use[i];
	}
	if(temp != 0){
		ans += cnt;
		ans += use[temp];
	}
	cout<<ans<<endl;
}
int main(){
 int t = 1;
  cin >> t;
 compute();
 while(t--)
 solve();
}
