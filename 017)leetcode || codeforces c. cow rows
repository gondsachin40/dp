https://codeforces.com/problemset/problem/1555/C
same as 
https://leetcode.com/problems/grid-game/description/ 
grid game
//leetcode submission 
struct pair{
    long long f;
    long long s;
};
long long gridGame(int** g, int m, int* gn) {
    int n = *gn;
    struct pair* a = (struct pair*)malloc(n * sizeof(struct pair));
    long long leftsum = 0 , rightsum = 0 , i = 0 , j = n - 1 , ans = LLONG_MAX , x = 0;
    for(int i = n - 1;i >= 0;i--)
    {
        a[i].s = rightsum;
        rightsum += (long long)g[0][i];
    }
    for(int i = 0;i<n;i++)
    {
        a[i].f = leftsum;
        leftsum += (long long)g[1][i];
    }
    for (int i = 0; i < n; i++) {
        x = (a[i].f > a[i].s) ? a[i].f : a[i].s;
        if (x < ans) {
            ans = x;
        }
    }
    return ans;
}














//codeforces submission 


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
const int N = 1e5 + 1, mod = 1e9 + 7;
int g[2][N];
struct Pair{
    int f;
    int s;
};
void solve(struct Pair *a){
	int n;
	cin >> n;
	L(i , 0 , 1){
		L(j , 0 , n - 1){
			cin >> g[i][j];
		}
	}
	ll leftsum = 0 , rightsum = 0;
	R(i , n - 1 , 0){
		a[i].s = rightsum;
		rightsum += g[0][i];
	}
	L(i , 0 , n - 1){
		a[i].f = leftsum;
		leftsum += g[1][i];
	}
	ll ans = LLONG_MAX;
	L(i , 0 , n - 1){
		ll x = max(a[i].f , a[i].s);
		if(x < ans)
		ans = x;
	}
	cout<<ans<<"\n";
}
int main(){
 int t = 1;
 cin >> t;
 struct Pair* a = (struct Pair*)malloc(N * sizeof(struct Pair));
 while(t--)
 solve(a);
}
