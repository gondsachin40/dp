#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i) 
#define vi vector < int >
#define sz(a) ((int) (a).size())
#define ll long long 
#define all(a) (a).begin(),(a).end()
#define print(a) for(auto x : a) cout << x << " " ; cout<< endl;
class Solution {
public:
    const int N = 1e4 + 7;
    ll t  , sum , x;
    bool can(ll y){
        ll k = (t * y) - (sum);
        bool flag = abs(k % x);
        if(flag)
        return false;
        return true;
    }
    int minOperations(vector<vector<int>>& a, int xx) {
        x = xx;
        bool odd = false , even = false;
        int m = sz(a) , n = sz(a[0]);
        vector<int> has(N , 0);
        sum = 0;
        t = m * n;
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(a[i][j] & 1)
                even = true;
                else
                odd = true;
                has[a[i][j]]++;
                sum += a[i][j];
            }
        }
        if(x % 2 == 0){
            if(odd && even)
            return -1;
        }
        ll low = 0 , high = 100;
        ll ans = high;
        while(low <= high)
        {
            ll mid = (low + high) / 2;
            if(can(mid)){
                ll ans1 = (t * mid - sum) / x;
                cout<<ans<<endl;
                ans = min(ans , abs(ans1));
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};
