//find number of pair such that a[i] > a[j] and i < j

#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i) 
#define vi vector < int >
#define sz(a) ((int) (a).size())
#define ll long long 
#define ull unsigned long long
#define me(a, x) memset(a, x, sizeof(a)) 
#define pb emplace_back
#define all(a) (a).begin(),(a).end()
#define print(a) for(auto x : a) cout << x << " " ; cout<< endl;
#define ld __float128
using namespace std;
const int N = 1e6 + 7, mod = 1e9 + 7;
const char nl = '\n';
ll merge(vi &a , int l ,int mid , int r){
 int n1 = mid - l + 1 , n2 = r - mid;
 vi left(n1) , right(n2);
 L(i , 0 , n1 - 1)
 left[i] = a[i + l];
 L(i , 0 , n2 - 1)
 right[i] = a[mid + 1 + i];
 
 ll ans = 0;
 int i = 0 , j = 0 , k = l;
 while(i < n1 && j < n2){
 	if(left[i] <= right[j])
 	a[k++] = left[i++];
 	else{
 		a[k++] = right[j++];
 		ans += (n1 - i);
 	}
 }
 while(i < n1){
 	a[k++] = left[i++];
 }
 while(j < n2){
 	a[k++] = right[j++];
 }
 return ans;
}
ll inversionCount(vi &a , int l , int r){
	ll ans = 0;
	if(l < r){
		int mid = (l + r) / 2;
		ans += inversionCount(a , l , mid);
		ans += inversionCount(a , mid + 1 , r);
		ans += merge(a , l , mid , r);
	}
	return ans;
}
void solve(){
 int n;
 cin >> n;
 vi a(n);
 L(i , 0 , n - 1) cin >> a[i];
 cout<<inversionCount(a , 0 , n - 1);
}
int main(){
 ios_base::sync_with_stdio(false),cin.tie(0);
 cout.tie(0);
 int t = 1;
 // cin >> t;
 while(t--)
 solve();
 return 0;
}
