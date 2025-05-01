/*
problem statement  = 
Code
Testcase
Test Result
Test Result
188. Best Time to Buy and Sell Stock IV
Solved
Hard
Topics
Companies
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.


problem link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
submission link = https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/submissions/1622594756/

Thi idead was to wheter buy that particular stock or not , or sell that 
if we can buy or sell that depend on the previous condition wheter we have buy that previously or not for that flag initial was true(1) means we have to buy a stock in that condition 
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
class Solution {
public:
    vector<vector<int>> dp;
    /*
    void fun(int i , int k , vi &a , bool flag , int sum , int ans){
        if(k == 0 || i == sz(a)){
            cout<<ans<<endl;
            return;
        }
        if(flag){
            fun(i + 1 , k , a , true , sum , ans);
            fun(i + 1 , k , a , false , sum + a[i] , ans);
        }else{
            fun(i + 1, k, a , false ,sum , ans);
            if(a[i] >= sum){
                int pro = a[i] - sum;
                fun(i + 1, k - 1, a , true ,0, ans + pro);
            }
        }
    }
    */
    int fun(int i , int k , vi &a , bool flag , int sum){
        if(k == 0 || i == sz(a)){
            return 0;
        }
        if(k < 0)
        return INT_MIN;
        // if(dp[i][sum] != -1)
        // return dp[i][sum];
        int ans = -1;
        if(flag){
            ans = max(ans,fun(i + 1 , k , a , true , sum));
            ans = max(ans , fun(i + 1 , k , a , false , sum + a[i]));
        }else{
            ans = max(ans ,fun(i + 1, k, a , false , sum));
            if(a[i] >= sum)
            {
            int pro = a[i] - sum;
            ans = max(ans , pro + fun(i + 1, k - 1 , a , true , 0));
            }
        }
        return dp[i][sum] = ans;
        return ans;
    }
    int maxProfit(int k, vector<int>& a) {
        
        dp.resize(sz(a) + 1 , vector<int>(1100, -1));
    //   cout<< fun(0 , k , a , true , 0 , 0)<<endl;
        // fun(0 , k , a , true , 0 , 0 );
        return fun(0 , k , a , true , 0);
        // return 1;
    }
};
/*
void solve(){
    Solution S;
    int n;
    cin >> n;
    int k;
    cin >> k;
    vi a(n);
    L(i , 0 , n - 1)
    cin >> a[i];
	cout<<endl<<S.maxProfit(k , a);
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
*/

/*
this idead was to make 4d dp of i , sum , k , flag but to reduce its and space and make it more optimize we take state of sum what it does to our result if we buy a particular stock we have to sell it letter means 
it is actually effecting our result in -ve manner so -a[i] for that and if we are selling we are gaining some profit based on that it effect in +ve so we can reduce sum in our dp 

so the approximately time complexity become O(n * k * 2) where n is the size of the array , k is the maximum transition allowed and 2 is state for representing flag



Final Code with memoization
*/


class Solution {
    private int[][][] dp;
    public int maxProfit(int k, int[] a) {
        int n = a.length;
        dp = new int[n][k + 1][2];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                Arrays.fill(dp[i][j], -1);
            }
        }

        return fun(0, k, a, 1);
    }

    private int fun(int i, int k, int[] a, int flag) {
        if (k == 0 || i == a.length) 
        return 0;
        
        if (dp[i][k][flag] != -1) 
        return dp[i][k][flag];
        int ans = -1;
        if (flag == 1) {
            ans = Math.max(ans, fun(i + 1, k, a, 1));
            ans = Math.max(ans, fun(i + 1, k, a, 0) - a[i]);
        } else {
            ans = Math.max(ans, fun(i + 1, k, a, 0));
            if (k > 0) {
                ans = Math.max(ans, fun(i + 1, k - 1, a, 1) + a[i]);
            }
        }

        return dp[i][k][flag] = ans;
    }
}
