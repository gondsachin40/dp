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
/*-*/
vi parent , depth;
vector<vector<pair<int,int>>> adj;
vector<vector<int>> up;
vector<int> dis;
int LOG = 20;
void dfs(int u ,int p){
	parent[u] = p;
	depth[u] = (p == -1 ? 0 : depth[p] + 1);
	up[u][0] = (p == -1 ? u : p);
	for(int j = 1;j < LOG;j++){
		up[u][j] = up[up[u][j - 1]][j - 1];
	}
	for(auto &[v , c] : adj[u]){
		if(v != p){
		  dis[v] = dis[u] + c;
			dfs(v , u);
		}
	}
}
int get_lca(int a ,int b){
	if(depth[a] < depth[b])
	swap(a , b);
	int k = depth[a] - depth[b];
	for(int j = LOG - 1;j >= 0;j--){
		if(k &(1 << j)){
			a = up[a][j];
		}
	}
	if(a == b){
		return a;
	}
	for(int j = LOG - 1;j >= 0;j--){
		if(up[a][j] != up[b][j]){
			a = up[a][j];
			b = up[b][j];
		}
	}
	return up[a][0];
}
int dist(int x , int y){
	return dis[x] + dis[y] - 2 * dis[get_lca(x , y)];
}
void solve(){
 int n;
 cin >> n;
 adj = vector<vector<pair<int,int>>>(n, vector<pair<int,int>>());
 up = vector<vector<int>>(n , vector<int>(LOG , 0));
 depth = vector<int>(n + 1);
 parent = vector<int>(n + 1);
 dis = vector<int>(n , 0);
 while(n-- > 1){
 	int x , y , c;
 	cin >> x >> y >> c;
 	x--;
 	y--;
 	adj[x].push_back({y , c});
 	adj[y].push_back({x , c});
 }		
 dfs(0 , -1);
 int q , k;
 cin >> q >> k;
 k--;
 while(q--){
 	int l , r;
 	cin >> l >> r;
 	l--;
 	r--;
 	int ans = dist(l , k) + dist(k , r);
 	cout<<ans<<nl;
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
