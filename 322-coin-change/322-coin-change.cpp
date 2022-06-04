class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1,-1));
        int target = amount;
        
        
        for(int i = 0; i<=target; i++)
            if(i%coins[0] == 0) dp[0][i] = i/coins[0];
            else dp[0][i] = 1e9;
        
        
        for(int i = 1; i<n; i++)
        {
            for(int t = 0; t<= target; t++)
            {
                 int nottake = 0 + dp[i-1][t];
                 int take = 1e9;
        
                 if(coins[i] <= t) take = 1 + dp[i][t-coins[i]];
                
                 dp[i][t] = min(take, nottake);
            }
        }
        
        if(dp[n-1][target] >= 1e9)
            return -1;
        else
            return dp[n-1][target];
            
        
    }
};
                               
//     int f(int ind, int target, vector<int>& coins,   vector<vector<int>> &dp)
//     {
//                   if(ind == 0)
//                   {
//                       if(target%coins[ind] == 0)
//                           return target/coins[ind];
//                       else 
//                           return 1e9;
//                   }
        
//         if(dp[ind][target] != -1) return dp[ind][target];
        
//         int nottake = 0 + f(ind-1, target, coins, dp);
//         int take = 1e9;
        
//         if(coins[ind] <= target) take = 1 + f(ind, target- coins[ind],coins, dp);
        
//         return dp[ind][target] = min(take, nottake);
        
//     }
