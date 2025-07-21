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
for lca in O(1)
first making euler path 
then levels which will tell , node is present in which level
h will tell the first occurence of node in Euler path => idx
then find value of h[u] and h[v] let them be l , r and then perform 
range minimum(l .... r) in levels and get the index which is minimum, 
let say that index if k then lca(u , v) = Euler[k]
*/
vector<vector<int>> adj;
vector<bool> vis;
vector<int> euler;
vector<int> levels;
vector<int> h;
vector<vector<int>> dp;
vector<vector<int>> idx; 
void dfs(int u , int level){
	vis[u] = true;
	euler.push_back(u);
	levels.push_back(level);
	for(int v : adj[u]){
		if(vis[v] == false){
			dfs(v , level + 1);
			euler.push_back(u);
			levels.push_back(level);
		}
	}
}
void solve2(){
	int n = sz(levels);
	int LOG = __lg(n) + 1;
	dp = vector<vector<int>>(n, vector<int>(LOG + 1));	
	idx = vector<vector<int>>(n, vector<int>(LOG + 1));
	L(i , 0 ,n - 1){
		dp[i][0] = levels[i];
			idx[i][0] = i;
	}
	L(k , 1 , LOG){
    L(i , 0 , n - 1){
        int x = i + (1 << (k - 1));
        if (x < n){
            if (dp[i][k - 1] <= dp[x][k - 1]){
                dp[i][k] = dp[i][k - 1];
                idx[i][k] = idx[i][k - 1];
            } else {
                dp[i][k] = dp[x][k - 1];
                idx[i][k] = idx[x][k - 1];
            }
        }else{
        	break;
        }
    }
    }
}
int query_min(int l , int r){
	if(l > r) swap(l , r);
	int len = r - l + 1;
	int k = __lg(len);
	int left = idx[l][k];
	int right = idx[r - (1 << k) + 1][k];
	if(levels[left] <= levels[right])
	return left;
	else
	return right;
}

void solve(){
	int n;
	cin >> n;
	adj = vector<vector<int>> (n , vector<int>());
	vis = vector<bool> (n , false);
	int q;
	cin >> q;
	h = vector<int>(n , -1);
	L(i , 1 , n - 1){
		int u = i;
		int v;
		cin >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0 , 0);
	L(i , 0 , sz(euler) - 1){
		if(h[euler[i]] == -1){
			h[euler[i]] = i;
		}
	}
	solve2();
	while(q--){
		int l , r;
		cin >> l >> r;
		l = h[l];
		r = h[r];
		int k = query_min(l , r);
		cout<<euler[k]<<nl;
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
