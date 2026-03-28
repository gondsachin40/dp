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
const char nl = '\n';
/**/
struct node{
    int lazy = 0;
    int last = 0;
};
int binpow(int x, int n) {
    int result = 1;
    x %= mod;

    while (n > 0) {
        if (n & 1)
            result = (result * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }

    return result;
}

int modInverse(int x) {
    return binpow(x, mod - 2);
}
int ap(int a, int n) {
    if(n <= 0) return 0;

    int res = (n % mod) * ((n + 1) % mod) % mod;
    res = (res * modInverse(2)) % mod;  
    res = (res * (a % mod)) % mod;

    return res;
}

class Segment_tree{
    public:
    vector<node> lazy;
    vector<int> tree;
    vector<bool> islazy;
    Segment_tree(int n){
        lazy.resize(n * 4 + 1);
        tree.resize(n * 4 + 1 , 0);
        islazy.resize(n * 4 + 1 , false);
    }
    int left(int node){
        return 2 * node + 1;
    }
    int right(int node){
        return 2 * node + 2;
    }
    void pull(int node){
        tree[node] = (tree[left(node)] + tree[right(node)]) % mod;
    }
    int operate(int a , int b){
        return (a + b) % mod;
    }
    void push(int node , int sp , int ep){
        if(islazy[node] == false) return;
        tree[node] = (ap(lazy[node].lazy , ep - lazy[node].last + 1) 
            - ap(lazy[node].lazy , sp - lazy[node].last) + mod) % mod;
        if(sp != ep){
            lazy[left(node)] = lazy[node];
            lazy[right(node)] = lazy[node];

            islazy[left(node)] = true;
            islazy[right(node)] = true;
        }

        lazy[node].lazy = 0;
        lazy[node].last = 0;
        islazy[node] = false;
}
    void build(int node , int sp , int ep , vector<int> &a){
        if(sp == ep){
            tree[node] = a[sp];
        }else{
            int mid = (sp + ep) >> 1;
            build(left(node) , sp , mid , a);
            build(right(node) , mid + 1 , ep , a);

            pull(node);
        }
    }
    int query(int node , int sp , int ep , int l , int r){
        push(node , sp , ep);
        if(sp > r || ep < l) return 0;

        if(l <= sp && ep <= r){
            return tree[node];
        }
        int mid = (sp + ep) >> 1;
        int q1 = query(left(node) , sp , mid , l , r);
        int q2 = query(right(node) , mid + 1 , ep , l , r);
        
        return operate(q1 , q2);
    }
    void update(int node , int sp , int ep , int l , int r , int last , int val){
        push(node , sp , ep);
        if(sp > r || ep < l) return;
        if(l <= sp && ep <= r){
            lazy[node].last = last;
            lazy[node].lazy = val;
            islazy[node] = true;
            push(node , sp , ep);
            return;
        }
        int mid = (sp + ep) >> 1;
        update(left(node) , sp , mid , l , r , last , val);
        update(right(node) , mid + 1 , ep , l ,r , last , val);    
        pull(node);
    }
};
void solve(){
    int n;
    cin >> n;
    vi a(n);
    L(i , 0 , n - 1) cin >> a[i];
    int q;
    cin >> q;
    int sum = 0;
    Segment_tree st(n);
    st.build(0 , 0 , n - 1 , a);
    L(i,  1,  q){
        int type;
        cin >> type;
        int l , r;
        cin >> l >> r;
        if(type == 1){

            int val = st.query(0 , 0 , n - 1 , l , l);
            st.update(0 , 0 , n - 1 , l , r , l , val);
        }else{
            int ans = st.query(0 , 0 , n - 1 , l , r);
            sum += ans;
        }
    }
    cout<<sum<<nl;

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
