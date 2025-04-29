Paint house problem where you have to pick color and then dont pick same color next means no adjacent allowed , here r = 0 , g = 1 , b = 2 for making memoization easy 

link


https://www.geeksforgeeks.org/problems/distinct-coloring--170645/0







#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i) 
#define vi vector<int>
#define sz(a) ((int) (a).size())
#define ll long long 
#define ull unsigned long long
#define me(a, x) memset(a, x, sizeof(a)) 
#define pb emplace_back
#define all(a) (a).begin(), (a).end()
#define print(a) for(auto x : a) cout << x << " " ; cout << endl;
using namespace std;

const int N = 1e6 + 7, mod = 1e9 + 7;
vector<vector<ll>> dp;
ll fun(char prev, int n, vi &r, vi &g, vi &b, int i) {
        if(i == n) {
        return 0LL;
    }
    if(dp[i][prev] != -1)
    return dp[i][prev];
    ll res = LLONG_MAX;
    if(prev == 0) {
        ll t1 = g[i] + fun(1, n, r, g, b, i + 1);
        ll t2 = b[i] + fun(2, n, r, g, b, i + 1);
        res = min(t1, t2);
    } else if(prev == 1) {
        ll t1 = r[i] + fun(0, n, r, g, b, i + 1);
        ll t2 = b[i] + fun(2, n, r, g, b, i + 1);
        res = min(t1, t2);
    } else if(prev == 2) {
        ll t1 = r[i] + fun(0, n, r, g, b, i + 1);
        ll t2 = g[i] + fun(1, n, r, g, b, i + 1);
        res = min(t1, t2);
    }

    dp[i][prev] = res;
    return res;
}

ll distinctColoring(int n, vi &r, vi &g, vi &b) {
    dp.clear();
    dp.resize(n + 1 , vector<ll>(3 , -1));
    ll ans1 = fun(0, n, r, g, b, 0);
    ll ans2 = fun(1, n, r, g, b, 0);
    ll ans3 = fun(2 , n, r, g, b, 0);
    return min({ans1, ans2, ans3});
}

void solve() {
    int n;
    cin >> n;
    vi r(n), g(n), b(n);
    L(i, 0, n - 1) cin >> r[i];
    L(i, 0, n - 1) cin >> g[i];
    L(i, 0, n - 1) cin >> b[i];

    cout << distinctColoring(n, r, g, b) << endl;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}
