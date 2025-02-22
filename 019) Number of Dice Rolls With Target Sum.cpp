Number of Dice Rolls With Target Sum
link : 
https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/


// memoization

#define me(a, x) memset(a, x, sizeof(a)) 
const int mod = 1e9 + 7;
class Solution {
public:
    int k;
    int dp[31][1005];
    int fun(int n , int target)
    {
        if(n == 0 && target == 0)
        return 1;
        if(n == 0)
        return 0;
        if(dp[n][target] != -1)
        return dp[n][target];
        int sum = 0;
        for(int i = 1;i <= k;i++)
        {
            if(target - i < 0) break;
            sum = (sum % mod + fun(n - 1 , target - i) % mod) % mod;
        }
        sum = sum % mod;
        return  dp[n][target] = sum;
    }
    int numRollsToTarget(int n, int kk, int target) {
       k = kk;
       me(dp , -1);
       return fun(n , target);
    }
};




//bottum up 



int dp[31][1005];
const int mod = 1000000007;
int numRollsToTarget(int n, int k, int target) {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int idx = 1;idx <= n;idx++) {
        for(int t = 0;t<=target;t++) {
            int sum = 0;
            for(int i = 1;i<=k;i++){
                if (t - i < 0)
                    break;
                sum = (sum % mod + dp[idx - 1][t - i]) % mod;
            }
            dp[idx][t] = sum % mod;
        }
    }
    return dp[n][target];
}
