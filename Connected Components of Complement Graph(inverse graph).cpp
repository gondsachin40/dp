//inverse of a graph is such that if there is a graph G and there is edge(u , v) in the inverse or complement graph G' there is not an edge between (u , v) 
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
int cc = 0;
vector<set<int>> adj;
set<int> seen;
vector<vector<int>> ans;
void dfs(int u ){
	ans[cc].push_back(u);
	seen.erase(u);
	int v = -1;
	while(true){
		auto it = seen.upper_bound(v);
		if(it == seen.end()) break;
		v = *it;
		if(adj[u].count(v))continue;
		dfs(v);
	}
}
void solve(){
 int n , m;
 cin >> n >> m;
 adj.resize(n , set<int>());
 ans.resize(n , vector<int>());
 while(m--){
 	int x , y;
 	cin >> x >> y;
 	adj[x].insert(y);
 	adj[y].insert(x);
 }
 L(i , 0 , n - 1){
 	seen.insert(i);
 }
 L(i , 0 , n - 1){
 	if(seen.count(i)){
 		dfs(i);
 		cc++;
 	}
 }
 cout<<cc<<nl;
 L(i , 0 , cc - 1){
	cout<<sz(ans[i])<<" ";
	print(ans[i]);
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
