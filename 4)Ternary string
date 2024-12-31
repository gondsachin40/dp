problem : https://codeforces.com/contest/1354/problem/B
https://codeforces.com/contest/1354
If the first character of the substring appears somewhere else in it, it can be deleted. The same applies for the last character. 
So, the first and the last characters should be different, 
and should not appear anywhere else within the string. Since there are only three types of characters, the answer always looks like abb...bbbbbc.

..solution 
#include<bits/stdc++.h>
#define ll long long int 
#define F first
#define S second
#define pb push_back
#define FIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define print(a) for(auto x : a) cout << x << " " ; cout<< endl;
using namespace std;
char s[200001];
bool check(vector<int>&has){
	if(has[1] && has[2] && has[3])
	return true;
	return false;
}
void solve(){
	scanf("%s",s);
	int ans = INT_MAX;
	int n = strlen(s);
	vector<int> has(4 , 0);
	int st = 0;
	char prev = '1';
	for(int i = 0;i<n && st < n;)
	{
			if(check(has))
			{
			while(true){
				has[s[st] - 48]--;
				st++;
				if(check(has) == false)
				{	
				st--;
				has[s[st] - 48]++;
			break;
				}	
	 		}
			ans =  min(ans , i - st);
			has[s[st] - 48]--;
			st++;
		}else{
		    has[s[i] - 48]++;
		    i++;
		}
	}
	if(check(has)){
	    	while(true){
				has[s[st] - 48]--;
				st++;
				if(check(has) == false)
				{	
				st--;
				has[s[st] - 48]++;
			break;
				}	
	 		}
			ans =  min(ans , n - st);
	}
	if(ans == INT_MAX)
	cout<<0<<"\n";
	else
	cout<<ans<<"\n";
}
int main(){
 // FIO;
 int t = 1;
 cin >> t;
 while(t--)
 solve();
}




//clean code with single loop 
#include<bits/stdc++.h>

using namespace std;

char buf[200043];

int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++)
	{
		scanf("%s", buf);
		string s = buf;
		int ans = int(1e9);
		int n = s.size();
		vector<pair<char, int> > c;
		for(auto x : s)
		{
			if(c.empty() || c.back().first != x)
				c.push_back(make_pair(x, 1));
			else
				c.back().second++;
		}
		int m = c.size();
		for(int i = 1; i < m - 1; i++)
			if(c[i - 1].first != c[i + 1].first)
				ans = min(ans, c[i].second + 2);
		if(ans > n)
			ans = 0;
		printf("%d\n", ans);
	}
}
