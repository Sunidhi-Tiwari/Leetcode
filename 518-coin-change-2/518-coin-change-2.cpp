class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        
        return f(n-1, amount, coins, dp);
        
    }
    
    int f(int ind, int tar, vector<int>& coins,  vector<vector<int>> &dp )
    {
        if(ind == 0)
        {
            if(tar%coins[0] == 0) return 1;
            else return 0;
        }
        
        if(dp[ind][tar] != -1) return dp[ind][tar];
        
        int nottake = f(ind-1, tar, coins, dp);
        int take = 0;
        if(coins[ind] <= tar) take = f(ind, tar-coins[ind], coins, dp);
        
       return dp[ind][tar] = take + nottake;
            
    }
};