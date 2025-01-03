/*
statement : given two array first, second , you can pick element from only if it's respective index from second array contain 1, simply second array contatin only 1 or 0 
you can choose one index and make [i , i + k - 1] in second array 1 so you have to maximize the sum from first array

idea : 
the brute force will be to go at the element which have zero and check[i , i + k] and add to the sum  make sum for all the 0 in second array and at last return the maximum among them

here my idea is to use prefix sum only for element which have corresponding zero's in second array
and check(the maximum among) pre[i + k] - pre[i] and add them 
*/

problem : https://codeforces.com/contest/961/problem/B


#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define pb push_back
#define FIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define print(a) for(auto x : a) cout << x << " " ; cout<< endl;
using namespace std;
void solve(){
	int n;
	cin >> n;
	int k;
	cin >> k;
	int sum = 0;
	vector<int> a(n);
	vector<int> b(n);
	
	for(int i = 0;i<n;i++)
	cin >> a[i];
	for(int i = 0;i<n;i++)
	cin >> b[i];
	vector<int> pre(n + k + 1);
	for(int i  = 1;i<=n;i++)
	{
		if(b[i - 1] == 0)
		pre[i] = a[i - 1];
	}
	for(int i = 1;i<n + k + 1;i++)
	{
		pre[i] += pre[i - 1];
	}
	if(k >= n)
	{
	sum = accumulate(a.begin() , a.end() ,0);
	cout<<sum;
	return;
	}
	int start = -1 , end = -1;
	int temp2 = INT_MIN;
	for(int i = 0;i<n;i++)
	{
		if(b[i] == 0)
		{
			int temp = pre[i + k] - pre[i];
			if(temp > temp2)
			{
				temp2=  temp;
				start = i;
				end = i + k - 1;
			}
		}
	}
	sum = 0;
	for(int i  = 0;i<n;i++)
	{
		if(i >= start && i <= end)
		{
			sum += a[i];
		}
		else if(b[i])
		{
			sum += a[i];
		}
	}
	cout<<sum;
}
int main(){
 int t = 1;
 // cin >> t;
 while(t--)
 solve();
}

