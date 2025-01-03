problem = https://codeforces.com/problemset/problem/1097/B
/*
Pick , no pick like idea but here we are subtracting and adding that element to current sum 
and if its modulas 360 become zero then it means rotation is complete and pointer is on zero again
2-d dp because it depends on two things current sum and index 
  */
#include<bits/stdc++.h>
using namespace std;
bool flag = false;
int dp[16][3000];
bool fun(int i , vector<int>&a ,int curr)
{
	if(i == (int)a.size())
	{
		curr = abs(curr);
		if(curr % 360 == 0)
		{
		dp[i][curr] = 1;
		return true;
		}
		dp[i][curr] = 0;
		return false;
	}
	if(dp[i][abs(curr)] != -1)
	return dp[i][abs(curr)];
	//if any condition is true it will return true
	return dp[i][curr] = fun(i + 1,a,curr - a[i]) | fun(i + 1,a,curr + a[i]);
}
void solve(){
  int n; 
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
	cin >> a[i];
  }
  memset(dp , -1 , sizeof(dp));
  if(fun(0 , a , 0))
  cout<<"YES";
  else
  cout<<"NO"; 
}
int main(){
 // FIO;
 int t = 1;
 // cin >> t;
 while(t--)
 solve();
}
