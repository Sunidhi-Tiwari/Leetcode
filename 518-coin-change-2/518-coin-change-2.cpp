class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount+1,0));
        
        return f(n, amount, coins, dp);
        
    }
    
    int f(int n, int target, vector<int>& coins,  vector<vector<int>> &dp )
    {
        
        for(int i = 0; i<=target; i++)
            if(i%coins[0] == 0) dp[0][i] = 1;
    
        
       for(int ind = 1; ind<n; ind++)
       {
           for(int tar = 0; tar<=target; tar++)
           {
               int nottake = dp[ind-1][tar];
               int take = 0;
               if(coins[ind] <= tar) take = dp[ind][tar-coins[ind]];
        
               dp[ind][tar] = take + nottake;
           }
       }
            return dp[n-1][target];
    }
};