/*
statement : There are n houses arranged in a circle, each with a certain value. 
A thief wants to maximize the value he can steal, 
but he cannot steal from two adjacent houses, as the owners will notify their neighbors. 
Given an integer array arr, 
where each element represents the value of a house, 
determine the maximum value the thief can steal without alerting the neighbors.

as there can be other possible solution but i am using the previous Robber1.cpp solution idea
*/
    vector<int> dp;
    int n = 0;
    int solve(int i , vector<int>&a){
        if(i >= n)
        {
            return 0;
        }
        if(dp[i] != -1)
        return dp[i];
        int l = a[i] + solve(i + 2, a);
        int r = solve(i + 1 , a);
        return dp[i] = max(l , r);    
    }
    int maxValue(vector<int>& a) {
          n = a.size();
        if (n == 0) return 0;  
        if (n == 1) return a[0];
        dp.resize(n + 1, -1);
        //changing n only upto a.end() - 1 and the starting index will be 1
        n = a.size() - 1;
        int first = solve(0 , a);
        fill(dp.begin() , dp.end() , -1);
        //starting index will be 1 and upto a.end();
        n = a.size();
        int second = solve(1, a);
        // The Result will be the maximum of both the query
        return max(first , second);
    }
