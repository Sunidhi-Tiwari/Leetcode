class Solution {
public:
    
//     int f(int ind, int prev, vector<int>& nums, vector<vector<int>> &dp)
//     {
//         if(ind == nums.size()) return 0;
        
//         if(dp[ind][prev+1] != -1) return dp[ind][prev+1];
        
//         int pick, notpick;
        
//         if(prev == -1 || nums[ind]>nums[prev]) 
//             pick = 1 + f(ind+1, ind, nums, dp);
        
//             notpick = f(ind+1, prev, nums, dp);
        
//          return  dp[ind][prev+1] = max(pick, notpick);
//     }
    
    
    int lengthOfLIS(vector<int>& nums) {
     
       int n = nums.size();
        if (n == 0) return 0;
       vector<int> dp(n,1);
       
        int ans = 1;
        for(int i = 1; i<n; i++)
        {
            for(int j = 0; j<i; j++)
            {
                if(nums[j] < nums[i]) if(dp[j] >= dp[i]) dp[i] = 1+dp[j];
            }
            
            ans = max(ans, dp[i]);
        }
       
    
        return ans;
        
    }
};