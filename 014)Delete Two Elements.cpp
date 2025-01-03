/*
statement : to find mean of array let k and then delete 2 element (i < j) such that after deleting them the mean is still the same find the total number of such pair 
*/

problem : https://codeforces.com/problemset/problem/1598/C

//works in c++20
#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define pb push_back
#define FIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define print(a) for(auto x : a) cout << x << " " ; cout<< endl;
using namespace std;
using ull = unsigned long long;
int a[200001];
void solve(){
	int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long sum = accumulate(a, a + n, 0LL);
    __int128 need = __int128(sum) * (n - 2);
    if (need % n != 0) {
        cout << 0 << '\n';
        return;
    }
    long long k = sum - (long long)(need / n);

    map<long long, int> mp;
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        if (mp.find(a[i]) != mp.end()) {
            ans += mp[a[i]];
        }
        mp[k - a[i]]++;
    }

    cout << ans << '\n';

}
int main(){
 int t = 1;
 cin >> t;
 while(t--)
 solve();
}
