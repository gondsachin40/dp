/*
house robber problem
pick one element fromt the array and then we can't select the adjacent element present to it , add that price to sum and at the end we have to maximize the sum 

 the state will be : if we have selected that element then we will skip its next element and on the other side we will not take element 
*/
int Rob(vector<int> nums, int n, vector<int>& dp) {
        if (n < 0)
            return 0;
        if (n == 0)
            return nums[0];
        if (dp[n] != -1)
            return dp[n];
        //taking that element and skiping next element
        int a = Rob(nums, n - 2, dp) + nums[n];
        //skiping that element
        int b = Rob(nums, n - 1, dp);
        //maximum of both the query
        return dp[n] = max(a, b);
    }
    int rob(vector<int>& a) {
        int n = a.size();
        vector<int> dp(n, -1);
        return Rob(a, a.size() - 1, dp);
    }
