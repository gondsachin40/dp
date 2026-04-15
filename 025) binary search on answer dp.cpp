/*
https://usaco.org/index.php?page=viewproblem2&cpid=839

*/


#include<bits/stdc++.h>
#define int long long int
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i) 
#define vi vector < int >
#define vii vector < vector <int>  >
#define sz(a) ((int) (a).size())
#define ll long long 
#define ull unsigned long long
#define ld long double
#define pb push_back
#define all(a) (a).begin(),(a).end()
#define print(a) for(auto x : a) cout << x << " " ; cout<< endl;

using namespace std;
const int N = 1e6 + 7, mod = 1e9 + 7;
const int inf = 1e17;
const char nl = '\n';
/*
    given
    n , w
    w1 , t1
    w2 , t2
    w3 , t3

    find the maximum ration = sigma(ti) / sigma(wi)

    dp[i][Weight][Talent] = max(
        get(i + 1 , Weight + wi , Talent + ti),
        get(i + 1 , Weight , Talent);
    )

    time complexity would be like O(n * w * t)
    tle !!!

    let Ratio:
        r1 < r2 , r3 , rn

        if ratio is possible then r1 , r2 , r3 can be also possible or ratio less than rn is also possible

        so we can use binary search for the ratio

    

    sigma(ti) / sigma(wi) >= r



    //k from 0 to 
    dp[k] = sigma(ti) - sigma(wi) * r >= 0

    check if it possible to form dp[k] >= 0
*/
/*
    get(i, w):
    if i == n:
        return (w >= W ? 0 : -inf)


    # dp[n][w]
    ans = get(i+1, w)

    ans = max(ans,
              (ti - r*wi) + get(i+1, w + wi))

    return ans
*/
struct pairs{
    int w;
    int t;
};
bool possible(vector<pairs>& a, double r, int n, int W) {

    vector<double> dp(W + 1, -inf);
    dp[0] = 0;

    L(i , 0 , n - 1) {

        int wi = a[i].w;
        int ti = a[i].t;
        double val = ti - r * wi;

        R(w , W , 0) {
            if (dp[w] < -inf) continue;
            int nw = min(W, w + wi);

            dp[nw] = max(dp[nw], dp[w] + val);
        }
    }

    return dp[W] >= 0;
}
void solve(){
   int n , w;
   cin >> n >> w;
   vector<pairs> a(n);
   L(i , 0 , n - 1){
    cin >> a[i].w >> a[i].t;
   }
   double lo = 0 , hi = 1000;
   double eps = 1e-6;
   double ans = -1;
//    cout<<setprecision(10)<<fixed<<eps<<nl;
   while(hi - lo > eps){
    double mid = (lo + hi) / 2.0;
    if(possible(a , mid , n , w)){
        ans = mid;
        lo = mid;
    }else{
        hi = mid;
    }
   }
   ans *= 1000;
   cout<<floor(ans)<<nl;
}
int32_t main(){
 ios_base::sync_with_stdio(false),cin.tie(0);
 cout.tie(0);

 int t = 1;
 //cin >> t;
 for(int i = 1; i <= t; ++i){
  solve();
 }
 return 0;
}
//DON'T GO WITH Intuition ❌, GO WITH MATHEMATICAL PROOF ✅
