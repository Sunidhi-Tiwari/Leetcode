class Solution {
public:
    
    
//     int f(int ind, int buy, vector<int>& prices, int n, vector<vector<int>> &dp)
//     {
//         if(ind == n) return 0;
        
//         if(dp[ind][buy] != -1) return dp[ind][buy];
        
//         if(buy)
//         {
//             dp[ind][buy] = max(-prices[ind] + f(ind+1, 0, prices, n, dp ), f(ind+1, 1, prices, n, dp));
//         }
//         else
//         {
//             dp[ind][buy] = max(prices[ind] + f(ind+1, 1, prices, n, dp) , f(ind+1, 0, prices, n, dp));
            
//         }
        
//         return dp[ind][buy];
//     }
        
        
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        
        dp[n][0] = dp[n][1] = 0;
        
        for(int i = n-1; i>=0; i--)
        {
            for(int buy = 0; buy<=1; buy++)
            {
                if(buy)
                {
                    dp[i][buy] = max(-prices[i] + dp[i+1][0], dp[i+1][1]);
                }
                else
                {
                    dp[i][buy] = max(prices[i] + dp[i+1][1], dp[i+1][0]);
                }
            }
            
            

        }
        
        return dp[0][1];
        
        
    }
};