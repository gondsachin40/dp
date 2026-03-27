#include <bits/stdc++.h>
#define int long long int
using namespace std;
int oo = 1e16;
int mod = (int)1e9 + 7;
int mul(int a , int b){
    return ((a % mod) * (b % mod)) % mod;
}
int add(int a , int b){
    return (a % mod + b % mod) % mod;
}
class Segment_tree{
    public:
    vector<int> tree;
    vector<int> lazy;
    vector<bool> isLazy;
    Segment_tree(int n){
        tree.resize(4 * n + 1 , 0);
        lazy.resize(4 * n + 1 , 1);
        isLazy.resize(4 * n + 1 , false);
    }
    int left(int node){
        return 2 * node + 1;
    }
    int right(int node){
        return 2 * node + 2;
    }
    void pull(int node){
        tree[node] = add( tree[left(node)] , tree[right(node)] );
    }
    void push(int node , int sp , int ep){
        if(!isLazy[node]) return;
        
        tree[node] = mul(tree[node] , lazy[node]);
        
        if(sp != ep){
            lazy[left(node)] = mul(lazy[left(node)], lazy[node]);
            lazy[right(node)] = mul(lazy[right(node)], lazy[node]);

            isLazy[left(node)] = true;
            isLazy[right(node)] = true;
        }
        lazy[node] = 1;
        isLazy[node] = false;
    }
    int operate(int a , int b){
        return add(a , b);;
    }
    bool bwn(int p , int q , int r , int s){
        return (p <= q && r <= s);
    }
    void build(int node , int sp , int ep , vector<int> &a){
        if(sp == ep){
            tree[node] = a[sp];
        }else{
            int mid = (sp + ep) >> 1;
            
            build(left(node) , sp , mid , a);
            build(right(node) , mid + 1 ,ep , a);
            
            pull(node);
        }
    }
    int query(int node , int sp , int ep , int l , int r){
        push(node , sp , ep);
        if(sp > r || ep < l) return 0;
        
        if(bwn(l , sp , ep , r)) return tree[node];
        
        int mid = (sp + ep) >> 1;
        int q1 = query(left(node) , sp , mid , l , r);
        int q2 = query(right(node) , mid + 1 , ep , l , r);
        
        return operate(q1 , q2);
    }
    void update(int node , int sp , int ep , int l , int r,  int val){
        push(node , sp , ep);
        if(sp > r || ep < l) return;
        if(bwn(l , sp , ep , r)){
            lazy[node] = val;
            isLazy[node] = true;
            push(node , sp , ep);
            return;
        }
        int mid = (sp + ep) >> 1;
        update(left(node) , sp , mid , l , r , val);
        update(right(node) , mid + 1 , ep , l , r , val);
        
        pull(node);
    }
    void print(int n){
        n *= 4;
        for(int i = 0;i <= n;i++){
            cout<<tree[i]<<" ";
        }
        cout<<endl;
    }
};
signed main() {
    int n;
    cin >> n;
    int q;
    cin >> q;
    vector<int> a(n , 1);
    Segment_tree st(n);
    st.build(0 , 0 , n - 1 , a);
    
    for(int i = 1;i <= q;++i){
        int type;
        cin >> type;
        if(type == 1){
            int l , r , val;
            cin >> l >> r >> val;
            val = val % mod;
            r--;
            st.update(0 , 0 , n - 1 , l , r , val);
        }else{
            int l , r;
            cin >> l >> r;
            r--;
            int ans = st.query(0 , 0 , n - 1 , l , r);
            cout<<ans<<"\n";
        }
        
    }
    
    
}
