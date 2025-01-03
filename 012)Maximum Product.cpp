/*
statement : given an array u have to find the maximum product of any 5 element

my approach : to sort the array to find the 5 greater element from the left which will of positive sign and 5 with negative sign(absolute value of them will be greater) 
if n >= 10 then we can pick 5-5 from both side otherwise between 5 - 10 

then we will find all subset product of size 5 and return the maximum among all of them 
space 
O(n)
analysis of time complexity :
o(n) to iterate
k = size of element picked from left and right
kmax = 10
to find subset  if we store in some data structure
{
o(k * 2 ^ n)  
o(10 * 2 ^ 10)
o(10240)
}
but here we are using that only so (2 ^ 10)
1024 iteration which is O(10^3) < O(n)

so the overall time complexity become O(n)
n -> size of array
*/


#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define pb push_back
#define FIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define print(a) for(auto x : a) cout << x << " " ; cout<< endl;
using namespace std;
int a[100001];
void printr(int *a , int n)
{
	for(int i = 0;i<n;i++)
	cout<<a[i]<<" ";
	cout<<endl;
}
ll ans = LLONG_MIN;
void subset(vector<int>&temp , int n , int i, ll curr ,int count)
{
	if(i == n)
	{
		if(count == 5)
		{
		ans = max(ans , curr);
        }
		return;
	}
	subset(temp , n , i + 1 , curr * (ll)temp[i] ,count + 1);
	subset(temp , n , i + 1 , curr , count);
}
void solve(){
	int n;
	cin >> n;
	for(int i = 0;i<n;i++)
	{
		cin >> a[i];
	}
	sort(a , a + n , greater<int>());
	vector<int> temp;
  //to pick from left
	for(int i = 0 , j = 0;i<5 && j < 5;i++,j++)
	{
	    temp.push_back(a[i]);
	}
	int k = 5;
  //to pick from left and to not take left elements again so k = 5
	for(int i = n - 1 , j = 0 ;i >= k && j < 5;i-- , j++)
	{
		temp.push_back(a[i]);
	}
	// print(temp);
  //ans can be large so LLONG_MIN
	ans = LLONG_MIN;
	subset(temp , temp.size() , 0 , 1LL , 0);
	cout<<ans<<"\n";
}
int main(){
 int t = 1;
 cin >> t;
 while(t--)
 solve();
}
