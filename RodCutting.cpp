/*
Rod cutting problem 
for example given an array of prices 
[1 , 3 , 2]
indexing:
[1 , 2 , 3]
given (size) n  = 3
it can cut like following
1 + 1 + 1 
1 + 2
2 + 1
3

so cutting price of 1 is 1
cutting price of 2 is 3
cutting price of 3 is 2
so
1 + 1 + 1 = 3 
1 + 2 = 4 
3 = 2

so maximum out of all is 4 so answer become false

how?
to cut any index out of 1,2,3 .... n
and recursively it will do same thing again
dp: using memoization to store the answer
space complexity O(n)
Time complextiy O(n * n ) = O(n^2)
*/
#include<bits/stdc++.h>
#define ll long long int 
#define F first
#define S second
#define pb push_back
#define FIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define print(a) for(auto x : a) cout << x << " " ; cout<< endl;
using namespace std;
  vector<int> dp;
  int solve(int n , vector<int>&a, int curr){
        if(n == 0)
        {
            return 0;
        }
        if(n < 0)
        return INT_MIN;
        if(dp[n] != -1)
        return dp[n];
        int sum = 0;
        for(int i = 0;i<a.size();i++)
        {
            sum =max(sum , a[i] + solve(n - i - 1,a, curr + a[i]));
        }f
        return dp[n] = sum;
}
int cutRod_memo(vector<int>&a){
	int n = a.size();
	dp.resize(n + 1, -1);
	return solve(n , a , 0);
}
int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0;i<n;i++)
	cin >> a[i];
	cout<<cutRod(a);
	
}
